#ifndef MTA_FACEBOOK_UI_H
#define MTA_FACEBOOK_UI_H
#include "FaceBook.h"
#include "Common.h"

enum class MenuOptions {RegisterToFaceBookAsMember = 1,RegisterToFaceBookAsFanPage,
    WritePostAsMember,WritePostAsFanPage,PrintAllPostOfAMember,PrintAllPostOfAFanPage,
    PrintTenLastPostOfAMember,AddAFriend,DeleteAFriend,LikeAFanPage,
    UnLikeAFanPage,PrintAllEntitiesAndTheirData,PrintAllMembersFriends,
    PrintAllFanPagesOfMember,PrintAllFansOfAFanPage,CompareTwoMembers,
    CompareTwoFanPages,CompareBetweenPosts,Exit};

class UI {
private:
  FaceBook* FB;

public:
    UI(FaceBook* fb);

    MenuOptions menu() const;
    void process();
    MemberInfo getMemberInfoFromUser() const;
    std::string getFanPageNameFromUser() const;
    int chooseMember() const;
    int chooseFriendOfMember(const Member& member) const;
    int chooseStatusOfMember(const Member& member) const;
    int chooseFanPage() const;
    int chooseFanPageOfMember(const Member& member)  const;
    int chooseStatusOfFanPage(const FanPage& fanPage) const;
    bool handleComparingBetweenMembers() const;
    bool handleComparingBetweenFanPages() const;
    bool handleComparingBetweenEntities() const;
    std::string getStatusFromUser(int& choice) const;
};


class InvalidInputException : public std::exception {
private:
    std::string data;
public:
    InvalidInputException(const std::string& str){
        data = str;
    }

    const char* what() const noexcept override {
        return data.c_str();
    }
};

#endif //MTA_FACEBOOK_UI_H
