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
    //constructor and destructor
    FanPage(char *name);
    ~FanPage();

    FanPage(const FanPage&) = delete;

    //getters :
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
    void addPost(const char* content);
    void printAllPosts() const;
    void printFanPage() const;
    void addFan(Member* fanToAdd);
    void removeFan(Member* fanToRemove);
};

#endif //MTA_FACEBOOK_FANPAGE_H
