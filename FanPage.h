#ifndef MTA_FACEBOOK_FANPAGE_H
#define MTA_FACEBOOK_FANPAGE_H

#include <iostream>
#include <string>
#include <vector>
#include "Status.h"

class Member;

class FanPage {
    std::string Name;
    std::vector<Member*> Fans;
    std::vector<Status*> Posts;

public:
    //constructor and destructor
    FanPage(std::string name);

    //getters  :
    std::string getName() const;
    std::vector<Member*> getFans() const;
    std::vector<Status*> getPosts() const;

    //operators :
    const FanPage& operator+=(Member* fanToAdd); // Add fan operator - required
    const FanPage& operator-=(Member* fanToRemove); // Remove fan operator - required
    bool operator>(const FanPage& other) const; // Greater than operator - required
    bool operator<(const FanPage& other) const; // Less than operator - required
    bool operator>=(const FanPage& other) const;
    bool operator<=(const FanPage& other) const;


    //functions :
    void addPost(std::string content);
    void printAllPosts() const;
    void printFans() const;
    void printFanPage() const;
    void addFan(Member* fanToAdd);
    void removeFan(Member* fanToRemove, bool isConnection = false);
};





class FanPageException : public std::exception {
    std::string message;
    
public:
    FanPageException(std::string message) : message(message) {}
    
    FanPageException(const char* message) : message(message) {
        std::cout << message << std::endl;
    }
    
    const char* what() const noexcept override {
        return message.c_str();
    }
    
};


#endif //MTA_FACEBOOK_FANPAGE_H
