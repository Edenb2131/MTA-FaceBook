
#ifndef MTA_FACEBOOK_FACEBOOK_H
#define MTA_FACEBOOK_FACEBOOK_H

#include <iostream>
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

    FaceBook(const FaceBook&) = delete;

    //getters :
    Member** getMembers() const;
    int getNumOfMembersOverAll() const;
    FanPage** getFanPages() const;
    int getNumOfFanPagesOverAll() const;

    //setters :
    void setNumOfMembersOverAll(int NumOfMembersOverAll);
    void setNumOfFanPagesOverAll(int NumOfFanPagesOverAll);

    //functions :
    int menu() const; // return the choice of the user
    void process(); // process the choice of the user
    void addNewMember(); // add new member to the facebook
    void addNewMember(const char* name, int day, int month, int year ); // add new member to the facebook
    void addNewPage(); // add new page to the facebook
    void addNewPage(const char* name); // add new page to the facebook
    void printAllMembers() const; // print all the members in the facebook
    void printAllFanPages() const; // print all the fan pages in the facebook
    void printAllEntitiesAndTheirData() const; // print all the members and fan pages in the facebook
    void printAllEntities() const; // print all the members and fan pages in the facebook
    int findMember() const; // finds a member in order to do actions on him (add post and so on..) returns index of the member
    int findMemberByMember(const Member& member) const; // finds a member in .returns index of the member
    int findFanPage() const; // finds a fan page in order to do actions on him (add post and so on..) returns index of the fan page
    int findFanPageByMember(const Member& member)  const; // finds a fan page in order to do actions on him by a member
    void connectTwoMembers(int firstMemberIndex, int secondMemberIndex); // connect two members
    void disconnectTwoMembers(int firstMemberIndex, int secondMemberIndex); // disconnect two members
    void connectMemberAndFanPage(int memberIndex, int fanPageIndex); // connect member and fan page
    void disconnectMemberAndFanPage(int memberIndex, int fanPageIndex); // disconnect member and fan page
};

#endif //MTA_FACEBOOK_FACEBOOK_H
