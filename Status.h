
#ifndef MTA_FACEBOOK_STATUS_H
#define MTA_FACEBOOK_STATUS_H

#include <iostream>
using namespace std;
#include <string>
#include <ctime>

class Status {
    char* Content;
    time_t pTime;
public:

    //constructors and destructor
    Status();
    Status(const char* content);
    ~Status();

    // Operator overloading
    bool operator==(const Status& other) const; // Equality operator - required
    bool operator!=(const Status& other) const; // Inequality operator - required


    //Functions :
    char* getContent() const;
    void setContent(char* content);
    void printStatus();
    char* getTimePostPosted();
};

#endif //MTA_FACEBOOK_STATUS_H
