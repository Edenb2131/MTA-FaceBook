#ifndef MTA_FACEBOOK_UI_H
#define MTA_FACEBOOK_UI_H
#include "FaceBook.h"
#include "Common.h"

enum MenuOptions {RegisterToFaceBookAsMember = 1,RegisterToFaceBookAsFanPage,
    WritePostAsMember,WritePostAsFanPage,PrintAllPostOfAMember,PrintAllPostOfAFanPage,
    PrintTenLastPostOfAMember,AddAFriend,DeleteAFriend,LikeAFanPage,
    UnLikeAFanPage,PrintAllEntitiesAndTheirData,PrintAllMembersFriends,
    PrintAllFanPagesFans,PrintAllFansOfAFanPage,CompareTwoMembers,
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
    bool handleComparingBetweenEntities() const;
    std::string getStatusFromUser() const;
};


#endif //MTA_FACEBOOK_UI_H
