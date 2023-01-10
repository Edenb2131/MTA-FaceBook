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
        int timeLen = posts[i]->getTimePostPosted().size();
        string postTime = posts[i]->getTimePostPosted();

        if (typeid(post).name() == typeid(Status).name())
            outFile.write((char*)StatusOptions::TextPost, sizeof(int));
        else if (typeid(post).name() == typeid(StatusWithImage).name())
            outFile.write((char*)StatusOptions::ImagePost, sizeof(int));
        else
            outFile.write((char*)StatusOptions::VideoPost, sizeof(int));

        outFile.write((char*)postLen, sizeof(int));
        outFile.write((char*)&post, sizeof(string));
        outFile.write((char*)timeLen, sizeof(int));
        outFile.write((char*)&postTime, sizeof(string));
    }
}

void FileHandler::saveFriendsAndLikedPages(std::vector<Member *> friends, std::vector<FanPage *> likedPages, std::ofstream &outFile) {
    int numOfFriends = friends.size(), numOfLikedPages = likedPages.size(), i;
    for (i = 0; i < numOfFriends; i++) {
        saveName(friends[i]->getName(), outFile);
    }
    for (i = 0; i < numOfLikedPages; i++) {
        saveName(likedPages[i]->getName(), outFile);
    }
}
