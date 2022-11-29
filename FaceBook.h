
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

    //constructor and destructor
    FaceBook();
    ~FaceBook();

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

    //functions :
    int menu();
    void addNewMember();
    void addNewMember(const char* name, int day, int month, int year );
    void addNewPage();
    void addNewPage(const char* name);
    void printAllMembers() const;
    void printAllFanPages() const;
    void printAllEntitiesAndTheirData() const;
    void printAllEntities() const;
    int findMember(); // finds a member in order to do actions on him (add post and so on..)
    int findFanPage(); // finds a fan page in order to do actions on him (add post and so on..)
    void connectTwoMembers(int firstMemberIndex, int secondMemberIndex);
    void disconnectTwoMembers(int firstMemberIndex, int secondMemberIndex);
    void connectMemberAndFanPage(int memberIndex, int fanPageIndex);
    void disconnectMemberAndFanPage(int memberIndex, int fanPageIndex);
};


#endif //MTA_FACEBOOK_FACEBOOK_H
