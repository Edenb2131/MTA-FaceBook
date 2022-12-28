#ifndef MTA_FACEBOOK_MEMBER_H
#define MTA_FACEBOOK_MEMBER_H

#include <iostream>
#include <string>
#include <vector>
#include "Status.h"
#include "Common.h"

class FanPage; // Forward declaration
class Status;  // Forward declaration

class Member {
    std::string Name;
    Date Birthday;
    std::vector<Member*> Friends;
    std::vector<Status*> Posts;
    std::vector<FanPage*> FanPages;

public:
    //constructor
    Member(const MemberInfo& infoFromUser);

    //getters :
    std::string getName() const;
    Date getBirthday() const;
    std::vector<Member*> getFriends() const;
    std::vector<Status*> getPosts() const;
    std::vector<FanPage*> getFanPages() const;

    //operators :
    //Member& operator=(const Member& other); // Assignment operator
    bool operator<(const Member& other) const; // Less than operator - required
    bool operator>(const Member& other) const; // Greater than operator - required
    bool operator<=(const Member& other) const;
    bool operator>=(const Member& other) const;
    const Member& operator+=(Member* friendToAdd); // Add friend operator - required
    const Member& operator-=(Member* friendToRemove); // Remove friend operator - required
    
    //comparing between different entities (member, fan page) : (not clear if required)
    bool operator>(const FanPage& other) const; // Greater than operator - required

    friend std::ostream& operator<<(std::ostream& os, const Member& member);
    //friend std::istream& operator>>(std::istream& is, Member& member);


    //functions :
    void addPost(std::string content); // Add a post to the member's posts
    void printAllPosts() const; // Print all the posts of the member
    void printFriends() const; // Print all the friends of the member
    void printLikedPages() const; // Print all the liked pages of the member
    void printMember() const; // Print all the member's info
    void addFriend(Member *friendToAdd, int connected = false); // Add a friend to the member's friends
    void removeFriend(Member *friendToRemove, int connected = false); // Remove a friend from the member's friends
    void likeFanPage(FanPage *fanPageToLike, int connected = false); // Like a fan page
    void unlikeFanPage(FanPage *fanPageToUnlike, int connected = false); // Unlike a fan page
    void printTenLatestPosts() const; // Print the ten latest posts of the member
    void printTenLatestPostsOfFriends() const; // Print the latest 10 posts of all the member's friends
};

class MemberException : public std::exception {
    std::string message;
public:
    
    explicit MemberException(const char* message) : message(message) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
    

};

#endif //MTA_FACEBOOK_MEMBER_H
