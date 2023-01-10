#ifndef MTA_FACEBOOK_FILEHANDLER_H
#define MTA_FACEBOOK_FILEHANDLER_H

#include <fstream>
#include <string>
#include <ctime>
#include "FaceBook.h"

enum class StatusOptions {TextPost, ImagePost, VideoPost};

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
};

#endif //MTA_FACEBOOK_FILEHANDLER_H
