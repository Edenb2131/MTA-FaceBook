
#ifndef MTA_FACEBOOK_FACEBOOK_H
#define MTA_FACEBOOK_FACEBOOK_H

#include <iostream>
#include <string>
#include <vector>
#include "Member.h"
#include "FanPage.h"

class FaceBook {
    std::vector<Member*> Members;
    std::vector<FanPage*> FanPages;

public:
    //constructor destructor
    //TODO: ask Eyal about deleting the constructor "default"!!!
    FaceBook() = default;
    ~FaceBook();
    FaceBook(const FaceBook&) = delete;

    //getters :
    std::vector<Member*>& getMembers() ;
    std::vector<FanPage*>& getFanPages() ;

    //functions :
    void addNewMember(MemberInfo memberInfo); // add new member to the facebook
    void addNewPage(std::string name); // add new page to the facebook
    void printAllMembers() const; // print all the members in the facebook
    void printAllFanPages() const; // print all the fan pages in the facebook
    void printAllEntitiesAndTheirData() const; // print all the members and fan pages in the facebook
    void printAllEntities() const; // print all the members and fan pages in the facebook
    void connectTwoMembers(int firstMemberIndex, int secondMemberIndex); // connect two members
    void disconnectTwoMembers(int firstMemberIndex, int secondMemberIndex); // disconnect two members
    void connectMemberAndFanPage(int memberIndex, int fanPageIndex); // connect member and fan page
    void disconnectMemberAndFanPage(int memberIndex, int fanPageIndex); // disconnect member and fan page
};

#endif //MTA_FACEBOOK_FACEBOOK_H
