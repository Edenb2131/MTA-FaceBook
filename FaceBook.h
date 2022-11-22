
#ifndef MTA_FACEBOOK_FACEBOOK_H
#define MTA_FACEBOOK_FACEBOOK_H

#include <iostream>
using namespace std;
#include <string>
#include "Member.h"
#include "FanPage.h"

class FaceBook {

    Member **Members;
    int NumOfMembersOverAll;
    FanPage **FanPages;
    int NumOfFanPagesOverAll;

public:

    //constructor
    FaceBook();

    //getters :
    Member** getMembers() const;
    int getNumOfMembersOverAll() const;
    FanPage** getFanPages() const;
    int getNumOfFanPagesOverAll() const;

    //setters :
    void setMembers(Member** members);
    void setNumOfMembersOverAll(int NumOfMembersOverAll);
    void setFanPages(FanPage** fanPages);
    void setNumOfFanPagesOverAll(int NumOfFanPagesOverAll);

    void addNewMember();
    void addNewPage();
};


#endif //MTA_FACEBOOK_FACEBOOK_H
