
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
    FanPage** FanPages;
    int NumOfFanPages;

public:
    //constructors and destructor
    Member() = default;
    Member(Info infoFromUser);
    Member(const char* name, int day, int month, int year );
    ~Member();

    Member(const Member&) = delete;

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
    void setName(char *name);
    void setBirthday(Date birthday);
    void setFriends(Member** friends);
    void setNumOfFriends(int numOfFriends);
    void setPosts(Status** posts);
    void setNumOfPosts(int numOfPosts);
    void setFanPages(FanPage** fanPages);
    void setNumOfFanPages(int numOfFanPages);

    //functions :
    void addPost();
    void addPost(const char* content);
    void printAllPosts();
    void printFriends();
    void printLikedPages();
    void printMember();
    void addFriend(Member *friendToAdd, int neededToBeAdded = false);
    void removeFriend(Member *friendToRemove);
    void likeFanPage(FanPage *fanPageToLike);
    void unlikeFanPage(FanPage *fanPageToUnlike);
    void printLatestPost();
    void printTenLatestPosts();
    void printFriendsTenLatestPosts(Member *friendToPrintLatestPosts);
    void printTenLatestPostsOfFriends();
};

#endif //MTA_FACEBOOK_MEMBER_H
