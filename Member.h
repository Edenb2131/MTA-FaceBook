//
// Created by Eden Bar on 16/11/2022.
//

#ifndef MTA_FACEBOOK_MEMBER_H
#define MTA_FACEBOOK_MEMBER_H

struct Date{
    int day;
    int month;
    int year;
};

class Member {
    char *name;
    Date birthday;
    Member *friends;
    int numOfFriends;
    char** posts;
    int numOfPosts;
    //fanPage *fanPages;

public:
    //constructor
    Member(char *name, Date birthday);


    //getters :
    char* getName() const;
    Date getBirthday() const;
    Member* getFriends() const;
    int getNumOfFriends() const;
    char** getPosts() const;
    int getNumOfPosts() const;
    //fanPage* getFanPages() const;

    //setters :
    void setName(const char *name);
    void setBirthday(Date birthday);
    void setFriends(Member *friends);
    void setNumOfFriends(int numOfFriends);
    void setPosts(char** posts);
    void setNumOfPosts(int numOfPosts);

    //functions :
    void addFriend(Member *friendToAdd);
    void removeFriend(Member *friendToRemove);
    void addPost(char *postToAdd);
    void removePost(char *postToRemove);
    void printPosts();
    void printFriends();
    void printMember();


};


#endif //MTA_FACEBOOK_MEMBER_H
