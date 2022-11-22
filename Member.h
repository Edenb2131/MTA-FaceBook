
#ifndef MTA_FACEBOOK_MEMBER_H
#define MTA_FACEBOOK_MEMBER_H

#include <iostream>
using namespace std;
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
    FanPage** fanPages;

public:
    //constructor
    Member() = default;
    Member(Info infoFromUser);

    //getters :
    char* getName() const;
    Date getBirthday() const;
    Member** getFriends() const;
    int getNumOfFriends() const;
    ////char** getPosts() const; ////
    Status** getPosts() const;
    int getNumOfPosts() const;
    /////FanPage** getFanPages() const; ////

    //setters :
    void setName(char *name);
    void setBirthday(Date birthday);
    void setFriends(Member** friends);
    void setNumOfFriends(int numOfFriends);
    void setPosts(Status** posts);
    void setNumOfPosts(int numOfPosts);

    //functions :
    void addPost();
    void printAllPosts();
    void printFriends();
    void printMember();


    void addFriend(Member *friendToAdd, int a = 0); // a = 0 means that we didn't add the friend to his friend list
    ////void removeFriend(Member *friendToRemove);
    void printLatestPost();
    void printTenLatestPosts();
    void printFriendsTenLatestPosts(Member *friendToPrintLatestPosts);
    void printTenLatestPostsOfFriends();
};


#endif //MTA_FACEBOOK_MEMBER_H
