
#ifndef MTA_FACEBOOK_MEMBER_H
#define MTA_FACEBOOK_MEMBER_H

#include <iostream>
using namespace std;
#include "Status.h"

class FanPage; // Forward declaration
class Status;

struct Date{
    int day;
    int month;
    int year;
};

struct Info{
    char* Name;
    Date birthDate;
};

class Member {
    char *Name;
    Date Birthday{};
    Member *Friends;
    int NumOfFriends;
    Status* Posts;
    int NumOfPosts;
    FanPage *fanPages;

public:
    //constructor
    Member() = default;
    Member(Info infoFromUser);

    //getters :
    char* getName() const;
    Date getBirthday() const;
    Member* getFriends() const;
    int getNumOfFriends() const;
    //char** getPosts() const;
    Status* getPosts() const;
    int getNumOfPosts() const;
    FanPage* getFanPages() const;

    //setters :
    void setName(char *name);
    void setBirthday(Date birthday);
    void setFriends(Member *friends);
    void setNumOfFriends(int numOfFriends);
    void setPosts(Status* posts);
    void setNumOfPosts(int numOfPosts);

    //functions :
    void addFriend(Member *friendToAdd, int a = 0);
    void removeFriend(Member *friendToRemove);
//    void addPost();
    void removePost(Status *postToRemove);
    void printLatestPosts();
    void printAllPosts();
    void printTenLatestPosts();
    void printFriends();
    void printMember();
};

Info getInfoFromUser();
char* getDynamicString();

#endif //MTA_FACEBOOK_MEMBER_H
