#ifndef MTA_FACEBOOK_FANPAGE_H
#define MTA_FACEBOOK_FANPAGE_H

#include <iostream>
using namespace std;
#include <string>
#include "Member.h"
#include "Status.h"


class FanPage {
    char *Name;
    Member *Fans;
    int NumOfFans;
    Status *Posts;
    int NumOfPosts;

public:
    //constructor
    FanPage(char *name);

    //getters  :
    char* getName() const;
    Member* getFans() const;
    int getNumOfFans() const;
    Status* getPosts() const;
    int getNumOfPosts() const;

    //setters :
    void setName(char *name);
    void setFans(Member *fans);
    void setNumOfFans(int numOfFans);
    void setPosts(Status *posts);
    void setNumOfPosts(int numOfPosts);

    //functions :
    //void addFan(Member *fanToAdd);
    //maybe replace this function with "LikePage" in member because a page does not add fans but a member can like a page.
    //same about deletePage (should be replaced with "UnLikePage").
    void addPost(Status *postToAdd);
    void printAllPosts() const;
};

#endif //MTA_FACEBOOK_FANPAGE_H
