
#ifndef MTA_FACEBOOK_STATUS_H
#define MTA_FACEBOOK_STATUS_H

#include <iostream>
#include <string>
#include <ctime>

class Status {
    std::string Content;
    time_t pTime;
public:

    //constructor
    Status(std::string content);

    // Operator overloading
    bool operator==(const Status& other) const; // Equality operator - required
    bool operator!=(const Status& other) const; // Inequality operator - required

    //Functions :
    const std::string getContent() const;
    void printStatus();
    std::string getTimePostPosted();
};


///// Do we even need this? /////
class statusException : public std::exception {
    std::string message;
public:
    
    statusException(std::string message) : message(message) {}
    
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif //MTA_FACEBOOK_STATUS_H
