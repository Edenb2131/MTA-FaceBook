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
    outFile.write((char*)numOfMembers, sizeof(int));
    for (i = 0; i < numOfMembers; i++) {
        // saving member's name
        saveName(FB->getMembers()[i]->getName(), outFile);

        // saving member's birthdate
        saveBirthDate(FB->getMembers()[i]->getBirthday(), outFile);

        // saving member's posts
        savePosts(FB->getMembers()[i]->getPosts(), outFile);
    }

    // saving data of fan pages.
    outFile.write((char*)numOfFanPages, sizeof(int));
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
    outFile.write((char*)nameLen, sizeof(int));
    outFile.write((char*)&name, sizeof(string));
}

void FileHandler::saveBirthDate(Date birthDate, std::ofstream &outFile) {
    int day = birthDate.day;
    int month = birthDate.month;
    int year = birthDate.year;
    outFile.write((char*)day, sizeof(int));
    outFile.write((char*)month, sizeof(int));
    outFile.write((char*)year, sizeof(int));
}

void FileHandler::savePosts(std::vector<Status *> posts, std::ofstream &outFile) {
    int numOfPosts = posts.size();
    outFile.write((char*)numOfPosts, sizeof(int));

    for (int i = 0; i < numOfPosts; i++) {
        int postLen = posts[i]->getContent().size();
        string post = posts[i]->getContent();
        time_t time = posts[i]->getTime();

        if (typeid(post).name() == typeid(Status).name())
            outFile.write((char*)StatusOptions::TextPost, sizeof(int));
        else if (typeid(post).name() == typeid(StatusWithImage).name())
            outFile.write((char*)StatusOptions::ImagePost, sizeof(int));
        else
            outFile.write((char*)StatusOptions::VideoPost, sizeof(int));

        outFile.write((char*)postLen, sizeof(int));
        outFile.write((char*)&post, sizeof(string));
        outFile.write((char*)time, sizeof(time_t));
    }
}

void FileHandler::saveFriendsAndLikedPages(std::vector<Member *> friends, std::vector<FanPage *> likedPages, std::ofstream &outFile) {
    int numOfFriends = friends.size(), numOfLikedPages = likedPages.size(), i;

    outFile.write((char*)numOfFriends, sizeof(int));
    for (i = 0; i < numOfFriends; i++) {
        saveName(friends[i]->getName(), outFile);
    }

    outFile.write((char*)numOfLikedPages, sizeof(int));
    for (i = 0; i < numOfLikedPages; i++) {
        saveName(likedPages[i]->getName(), outFile);
    }
}

void FileHandler::loadDataFromFileToFacebook(const std::string &fileName) {
    int numOfMembers, numOfFanPages, numOfFriends, numOfLikedPages, i, j;
    ifstream inFile(fileName, ios::in|ios::binary);

    inFile.read((char*)numOfMembers, sizeof(int));
    for (i = 0; i < numOfMembers; i++) {
        FB->addNewMember(MemberInfo(readString(inFile), readBirthDate(inFile)));
        readPostsFromFileAndAddToMember(inFile, FB->getMembers()[i]);
    }

    inFile.read((char*)numOfFanPages, sizeof(int));
    for (i = 0; i < numOfFanPages; i++) {
        FB->addNewPage(readString(inFile));
        readPostsFromFileAndAddToFanPage(inFile, FB->getFanPages()[i]);
    }

    // TODO: after adding connections think how to avoid unnecessary prints (like "already friends" and so on).
    for (i = 0; i < numOfMembers; i++) {
        inFile.read((char*)numOfFriends, sizeof(int));
        for (j = 0; j < numOfFriends; j++) {
            string name = readString(inFile);
            FB->getMembers()[i]->addFriend((*FB)[name]);
        }

        inFile.read((char*)numOfFanPages, sizeof(int));
        for (j = 0; j < numOfFanPages; j++) {
            string name = readString(inFile);
            FB->getMembers()[j]->likeFanPage((*FB)(name));
        }
    }
    inFile.close();
}

string FileHandler::readString(std::ifstream &inFile) {
    int len;
    string str;

    inFile.read((char*)len, sizeof(int));
    char* temp = new char[len + 1];
    inFile.read(temp, len);
    temp[len] = '\0';
    str = temp;
    delete [] temp;
    return str;
}

Date FileHandler::readBirthDate(std::ifstream &inFile) {
    int day, month, year;
    inFile.read((char*)day, sizeof(int));
    inFile.read((char*)month, sizeof(int));
    inFile.read((char*)year, sizeof(int));

    return Date(day, month, year);
}

time_t FileHandler::readPostTime(std::ifstream &inFile) {
    time_t time;
    inFile.read((char*)time, sizeof(time_t));
    return time;
}

void FileHandler::readPostsFromFileAndAddToMember(std::ifstream &inFile, Member *member) {
    int numOfPosts;
    StatusOptions op;

    inFile.read((char *) numOfPosts, sizeof(int));
    for (int i = 0; i < numOfPosts; i++) {
        inFile.read((char *) op, sizeof(StatusOptions));
        string post = readString(inFile);
        time_t time = readPostTime(inFile);
        switch (op) {
            case StatusOptions::TextPost:
                member->addPost(post);
                break;
            case StatusOptions::ImagePost:
                member->addPostWithImage(post, "Image");
                break;
            case StatusOptions::VideoPost:
                member->addPostWithVideo(post, "Video");
                break;
        }
        member->getPosts()[i]->setTime(time);
    }
}

void FileHandler::readPostsFromFileAndAddToFanPage(std::ifstream &inFile, FanPage *page) {
    int numOfPosts;
    StatusOptions op;

    inFile.read((char *) numOfPosts, sizeof(int));
    for (int i = 0; i < numOfPosts; i++) {
        inFile.read((char *) op, sizeof(StatusOptions));
        string post = readString(inFile);
        time_t time = readPostTime(inFile);
        switch (op) {
            case StatusOptions::TextPost:
                page->addPost(post);
                break;
            case StatusOptions::ImagePost:
                page->addPostWithImage(post, "Image");
                break;
            case StatusOptions::VideoPost:
                page->addPostWithVideo(post, "Video");
                break;
        }
        page->getPosts()[i]->setTime(time);
    }
}

