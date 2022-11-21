
#ifndef MTA_FACEBOOK_MEMBER_H
#define MTA_FACEBOOK_MEMBER_H

#include <iostream>
using namespace std;
#include <string>
#include "Functions.h"

class Status; // Forward declaration

struct Date{
    int day;
    int month;
    int year;
};

class Member {
    char *Name;
    Date Birthday;
    Member *Friends;
    int NumOfFriends;
    Status* Posts;
    int NumOfPosts;
    //FanPage *fanPages;

public:
    //constructor
    Member();

    //getters :
    char* getName() const;
    Date getBirthday() const;
    Member* getFriends() const;
    int getNumOfFriends() const;
    //char** getPosts() const;
    Status* getPosts() const;
    int getNumOfPosts() const;
    //fanPage* getFanPages() const;

    //setters :
    void setName(const char *name);
    void setBirthday(Date birthday);
    void setFriends(Member *friends);
    void setNumOfFriends(int numOfFriends);
    void setPosts(Status* posts);
    void setNumOfPosts(int numOfPosts);

    //functions :
    void addFriend(Member *friendToAdd);
    void removeFriend(Member *friendToRemove);
    void addPost(Status *postToAdd);
    void removePost(Status *postToRemove);
    //void printPosts();
    void printFriends();
    void printMember();


};


#endif //MTA_FACEBOOK_MEMBER_H
