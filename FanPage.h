#ifndef MTA_FACEBOOK_FANPAGE_H
#define MTA_FACEBOOK_FANPAGE_H

#include <iostream>
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

    //operators :
    void operator+=(Member* fanToAdd); // Add fan operator - required
    void operator-=(Member* fanToRemove); // Remove fan operator - required
    bool operator>(const FanPage& other) const; // Greater than operator - required
    bool operator<(const FanPage& other) const; // Less than operator - required
    bool operator>=(const FanPage& other) const;
    bool operator<=(const FanPage& other) const;


    //functions :
    void addPost();
    void addPost(const char* content);
    void printAllPosts() const;
    void printFans() const;
    void printFanPage() const;
    void addFan(Member* fanToAdd);
    void removeFan(Member* fanToRemove);
};

#endif //MTA_FACEBOOK_FANPAGE_H
