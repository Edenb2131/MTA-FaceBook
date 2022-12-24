#ifndef MTA_FACEBOOK_UI_H
#define MTA_FACEBOOK_UI_H
#include "FaceBook.h"
#include "Common.h"

class UI {
private:
  FaceBook* FB;

public:
    UI(FaceBook* fb);

    int menu() const;
    void process();
    MemberInfo getMemberInfoFromUser() const;
    std::string getFanPageNameFromUser() const;
    int chooseMember() const;
    int chooseFriendOfMember(const Member& member) const;
    int chooseFanPage() const;
    int chooseFanPageOfMember(const Member& member)  const;
    std::string getStatusFromUser() const;
};


#endif //MTA_FACEBOOK_UI_H
