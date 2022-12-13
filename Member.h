
#ifndef MTA_FACEBOOK_MEMBER_H
#define MTA_FACEBOOK_MEMBER_H

#include <iostream>
#include "Status.h"
#include "Functions.h"


class FanPage; // Forward declaration
class Status;  // Forward declaration


class Member {
    char *Name;
    Date Birthday{};
    Member** Friends;
    int NumOfFriends;
    Status** Posts;
    int NumOfPosts;
    FanPage** FanPages;
    int NumOfFanPages;

public:
    //constructors and destructor
    Member() = default;
    Member(Info infoFromUser);
    Member(const char* name, int day, int month, int year );
    ~Member();

    Member(const Member&) = delete; // copy constructor
    Member(Member&&) = delete; // move constructor

    //getters :
    char* getName() const;
    Date getBirthday() const;
    Member** getFriends() const;
    int getNumOfFriends() const;
    Status** getPosts() const;
    int getNumOfPosts() const;
    FanPage** getFanPages() const;
    int getNumOfFanPages() const;

    //setters :
    void setNumOfFriends(int numOfFriends);
    void setNumOfPosts(int numOfPosts);
    void setNumOfFanPages(int numOfFanPages);

    //operators :
    //Member& operator=(const Member& other); // Assignment operator
    bool operator<(const Member& other) const; // Less than operator - required
    bool operator>(const Member& other) const; // Greater than operator - required
    bool operator<=(const Member& other) const;
    bool operator>=(const Member& other) const;
    void operator+=(Member* friendToAdd); // Add friend operator - required
    void operator-=(Member* friendToRemove); // Remove friend operator - required

    friend ostream& operator<<(ostream& os, const Member& member);
    friend istream& operator>>(istream& is, Member& member);


    //functions :
    void addPost(); // Add a post to the member's posts
    void addPost(const char* content); // Add a post to the member's posts
    void printAllPosts(); // Print all the posts of the member
    void printFriends(); // Print all the friends of the member
    void printLikedPages(); // Print all the liked pages of the member
    void printMember(); // Print all the member's info
    void addFriend(Member *friendToAdd, int neededToBeAdded = false); // Add a friend to the member's friends
    void removeFriend(Member *friendToRemove); // Remove a friend from the member's friends
    void likeFanPage(FanPage *fanPageToLike); // Like a fan page
    void unlikeFanPage(FanPage *fanPageToUnlike); // Unlike a fan page
    void printLatestPost(); // Print the latest post of the member
    void printTenLatestPosts(); // Print the ten latest posts of the member
    void printFriendsTenLatestPosts(Member *friendToPrintLatestPosts); // Print the latest 10 posts of a friend
    void printTenLatestPostsOfFriends(); // Print the latest 10 posts of all the member's friends
};

#endif //MTA_FACEBOOK_MEMBER_H
