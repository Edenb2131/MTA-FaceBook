#include "FileHandler.h"
using namespace std;

FileHandler::FileHandler(FaceBook *fb) {
    if (fb != nullptr)
        FB = fb;
    else
        throw FaceBookException("Pointer to faceBook cannot be NULL! ");
}

void FileHandler::saveDataToFile(const std::string &fileName) {
    ofstream outFile(fileName, ios::out|ios::binary|ios::trunc);
    int i, numOfMembers = FB->getMembers().size(), numOfFanPages = FB->getFanPages().size();

    // saving data of members
    outFile.write((char*)&numOfMembers, sizeof(int)); // save number of members
    for (i = 0; i < numOfMembers; i++) {
        // saving member's name
        saveName(FB->getMembers()[i]->getName(), outFile);

        // saving member's birthdate
        saveBirthDate(FB->getMembers()[i]->getBirthday(), outFile);

        // saving member's posts
        savePosts(FB->getMembers()[i]->getPosts(), outFile);
    }

    // saving data of fan pages.
    outFile.write((char*)&numOfFanPages, sizeof(int)); // save number of fan pages
    for (i = 0; i < numOfFanPages; i++) {
        // saving fan page's name
        saveName(FB->getFanPages()[i]->getName(), outFile);

        // saving fan page's posts
        savePosts(FB->getFanPages()[i]->getPosts(), outFile);
    }

    //saving data about the connections between a member to his friends and his likes fan pages.
    for (i = 0; i < numOfMembers; i++) {
        saveFriendsAndLikedPages(FB->getMembers()[i]->getFriends(), FB->getMembers()[i]->getFanPages(), outFile);
    }
    
    outFile.close();
}

void FileHandler::saveName(string name, ofstream& outFile) {
    int nameLen = name.size();
    outFile.write((char*)&nameLen, sizeof(int)); // save name length
    outFile.write((char*)name.c_str(), sizeof(char)*nameLen); // save name
}

void FileHandler::saveBirthDate(Date birthDate, std::ofstream &outFile) {
    int day = birthDate.day;
    int month = birthDate.month;
    int year = birthDate.year;
    outFile.write((char*)&day, sizeof(int));
    outFile.write((char*)&month, sizeof(int));
    outFile.write((char*)&year, sizeof(int));
}

void FileHandler::savePosts(std::vector<Status *> posts, std::ofstream &outFile) {
    int textPost = 1, imagePost = 2, videoPost = 3;
    int numOfPosts = posts.size();
    
    outFile.write((char*)&numOfPosts, sizeof(int)); // save number of posts

    for (int i = 0; i < numOfPosts; i++) {
        int postLen = posts[i]->getContent().size(); // post's length
        string post = posts[i]->getContent(); // post's content
        time_t time = posts[i]->getTime(); // time of post

        // save post's type
        if (typeid(*posts[i]) == typeid(Status)) {
            outFile.write((char *) &textPost, sizeof(int));
        }
        else if (typeid(*posts[i]) == typeid(StatusWithImage)) {
            outFile.write((char *) &imagePost, sizeof(int));
        }
        else {
            outFile.write((char *) &videoPost, sizeof(int));
        }

        outFile.write((char*)&postLen, sizeof(int)); // save post's length
        outFile.write((char*)post.c_str(), sizeof(char)*postLen); // save post's content
        outFile.write((char*)&time, sizeof(time)); // save time of post
    }
}

void FileHandler::saveFriendsAndLikedPages(std::vector<Member *> friends, std::vector<FanPage *> likedPages, std::ofstream &outFile) {
    int numOfFriends = friends.size(), numOfLikedPages = likedPages.size(), i;

    outFile.write((char*)&numOfFriends, sizeof(int)); // saving number of friends
    for (i = 0; i < numOfFriends; i++) {
        saveName(friends[i]->getName(), outFile); // Saving the name of the friend
    }

    outFile.write((char*)&numOfLikedPages, sizeof(int)); // saving number of liked pages
    for (i = 0; i < numOfLikedPages; i++) {
        saveName(likedPages[i]->getName(), outFile); // Saving the name of the liked page
    }
}

void FileHandler::loadDataFromFileToFacebook(const std::string &fileName) {
    int numOfMembers, numOfFanPages, numOfFriends, numOfLikedPages, i, j;
    ifstream inFile(fileName, ios::in|ios::binary);

    inFile.read((char*)&numOfMembers, sizeof(int)); // read number of members
    for (i = 0; i < numOfMembers; i++) {
        // loading member's name and birthdate
        string name = readString(inFile);
        Date birthDate = readBirthDate(inFile);
        FB->addNewMember(MemberInfo(name, birthDate));
        // loading member's posts
        readPostsFromFileAndAddToMember(inFile, FB->getMembers()[i]);
    }

    inFile.read((char*)&numOfFanPages, sizeof(int));
    for (i = 0; i < numOfFanPages; i++) {
        string name = readString(inFile);
        FB->addNewPage(name);
        readPostsFromFileAndAddToFanPage(inFile, FB->getFanPages()[i]);
    }

    for (i = 0; i < numOfMembers; i++) {
        inFile.read((char*)&numOfFriends, sizeof(int));
        for (j = 0; j < numOfFriends; j++) {
            string name = readString(inFile);
            FB->getMembers()[i]->addFriend((*FB)[name], true);
        }

        inFile.read((char*)&numOfLikedPages, sizeof(int));
        for (j = 0; j < numOfLikedPages; j++) {
            string name = readString(inFile);
            FB->getMembers()[j]->likeFanPage((*FB)(name));
        }
    }
    inFile.close();
}

string FileHandler::readString(std::ifstream &inFile) {
    int len;
    string str;

    inFile.read((char*)&len, sizeof(int)); // get Strings length
    char* temp = new char[len + 1];
    inFile.read(temp, len);
    temp[len] = '\0';
    str = temp;
    delete [] temp;
    return str;
}

Date FileHandler::readBirthDate(std::ifstream &inFile) {
    int day, month, year;
    
    inFile.read((char*)&day, sizeof(int));
    inFile.read((char*)&month, sizeof(int));
    inFile.read((char*)&year, sizeof(int));

    return Date(day, month, year);
}

time_t FileHandler::readPostTime(std::ifstream &inFile) {
    time_t time;
    inFile.read((char*)&time, sizeof(time));
    return time;
}

void FileHandler::readPostsFromFileAndAddToMember(std::ifstream &inFile, Member *member) {
    int numOfPosts;
    int op;

    inFile.read((char *)&numOfPosts, sizeof(int)); // read number of posts
    for (int i = 0; i < numOfPosts; i++) {
        inFile.read((char *)&op, sizeof(int)); // read post's type
        string post = readString(inFile); // read post's content
        time_t time = readPostTime(inFile); // read time of post
        switch (op) {
            case 1:
                member->addPost(post);
                break;
            case 2:
                member->addPostWithImage(post, "Image");
                break;
            case 3:
                member->addPostWithVideo(post, "Video");
                break;
        }
        member->getPosts()[i]->setTime(time);
    }
}

void FileHandler::readPostsFromFileAndAddToFanPage(std::ifstream &inFile, FanPage *page) {
    int numOfPosts;
    int op;

    inFile.read((char *)&numOfPosts, sizeof(int)); // read number of posts
    for (int i = 0; i < numOfPosts; i++) {
        inFile.read((char *)&op, sizeof(int)); // read post's type
        string post = readString(inFile); // read post's content
        time_t time = readPostTime(inFile); // read time of post
        switch (op) {
            case 1:
                page->addPost(post);
                break;
            case 2:
                page->addPostWithImage(post, "Image");
                break;
            case 3:
                page->addPostWithVideo(post, "Video");
                break;
        }
        page->getPosts()[i]->setTime(time);
    }
}


