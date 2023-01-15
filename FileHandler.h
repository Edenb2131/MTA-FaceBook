#ifndef MTA_FACEBOOK_FILEHANDLER_H
#define MTA_FACEBOOK_FILEHANDLER_H

#include <fstream>
#include <string>
#include <ctime>
#include "FaceBook.h"
#include "Common.h"


/*
How we save the data to the file :
1. Save number of members in facebook.
2. Save the Members in facebook -> Name(length, content), BirthDay, number of posts ,Posts(type, length, content, time).
3. Save the number of Fan pages in facebook
4. Save the Fan Page -> Name(length, content), number of posts, Posts(type, length, content, time).
5. Then we save the number of Friends and fan pages of each member by the order ->
    number of friends, friends name,  number of fan pages, fan pages names.

*/

class FileHandler {
private:
    FaceBook* FB;

public:
    FileHandler(FaceBook* fb);
    void saveDataToFile(const std::string& fileName);
    void saveName(std::string name, std::ofstream& outFile);
    void saveBirthDate(Date birthDate, std::ofstream& outFile);
    void savePosts(std::vector<Status*> posts, std::ofstream& outFile);
    void saveFriendsAndLikedPages(std::vector<Member*> friends, std::vector<FanPage*> likedPages, std::ofstream& outFile);
    void loadDataFromFileToFacebook(const std::string& fileName);
    std::string readString(std::ifstream& inFile);
    Date readBirthDate(std::ifstream& inFile);
    time_t readPostTime(std::ifstream& inFile);
    void readPostsFromFileAndAddToMember(std::ifstream& inFile, Member* member);
    void readPostsFromFileAndAddToFanPage(std::ifstream& inFile, FanPage* page);
};

#endif //MTA_FACEBOOK_FILEHANDLER_H
