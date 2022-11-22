#ifndef MTA_FACEBOOK_FANPAGE_H
#define MTA_FACEBOOK_FANPAGE_H

#include <iostream>
using namespace std;
#include <string>
#include "Status.h"

class Member;

class FanPage {
    char *Name;
    Member** Fans;
    int NumOfFans;
    Status** Posts;
    int NumOfPosts;

public:
    //constructor
    FanPage(char *name);

    //getters  :
    char* getName() const;
    Member** getFans() const;
    int getNumOfFans() const;
    Status** getPosts() const;
    int getNumOfPosts() const;

    //setters :
    void setName(char *name);
    void setFans(Member **fans);
    void setNumOfFans(int numOfFans);
    void setPosts(Status **posts);
    void setNumOfPosts(int numOfPosts);

    //functions :
    void addPost();
    void printAllPosts() const;
    ////void printFans() const; //// Need to implement
    void printFanPage() const;
};

#endif //MTA_FACEBOOK_FANPAGE_H
