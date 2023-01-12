
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
    FaceBook() = default;
    ~FaceBook();
    FaceBook(const FaceBook&) = delete;

    //getters :
    const std::vector<Member*>& getMembers() const;
    const std::vector<FanPage*>& getFanPages() const;

    //functions :
    void addNewMember(MemberInfo memberInfo); // add new member to the facebook
    void addNewPage(std::string name); // add new page to the facebook
    void writePostAsMember(int memberIndex, std::string post);
    void writePostWithImageAsMember(int memberIndex, std::string post, std::string image);
    void writePostWithVideoAsMember(int memberIndex, std::string post, std::string video);
    void writePostAsFanPage(int fanPageIndex, std::string post);
    void writePostWithImageAsFanPage(int fanPageIndex, std::string post, std::string image);
    void writePostWithVideoAsFanPage(int fanPageIndex, std::string post, std::string video);
    void printAllPostOfAMember(int memberIndex) const;
    void printAllPostOfAFanPage(int memberIndex) const;
    void printTenLastPostOfAMember(int memberIndex) const;
    void printAllMembers() const; // print all the members in the facebook
    void printAllFanPages() const; // print all the fan pages in the facebook
    void printAllEntitiesAndTheirData() const; // print all the members and fan pages in the facebook
    void printAllEntities() const; // print all the members and fan pages in the facebook
    void connectTwoMembers(int firstMemberIndex, int secondMemberIndex); // connect two members
    void disconnectTwoMembers(int firstMemberIndex, int secondMemberIndex); // disconnect two members
    void connectMemberAndFanPage(int memberIndex, int fanPageIndex); // connect member and fan page
    void disconnectMemberAndFanPage(int memberIndex, int fanPageIndex); // disconnect member and fan page
    void printAllMembersFriends(int memberIndex) const;
    void printAllFanPagesOfMember(int memberIndex) const;
    void printAllFansOfAFanPage(int fanPageIndex) const;

    Member* operator[](std::string name); // returns the member with the same name
    FanPage* operator()(std::string name); // returns the fan page with the same name
};



class FaceBookException : public std::exception {
    std::string message;
    
public:
    
    
    FaceBookException(const char* message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif //MTA_FACEBOOK_FACEBOOK_H
