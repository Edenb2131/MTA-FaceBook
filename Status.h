
#ifndef MTA_FACEBOOK_STATUS_H
#define MTA_FACEBOOK_STATUS_H

#include <iostream>
using namespace std;
#include <string>
#include <ctime>

class Status {
    char* Content;
    // need to insert time to a status !!!!!
    char* pTime;
public:

    //constructors and destructor
    Status();
    Status(const char* content);
    ~Status();

    char* getContent() const;
    void setContent(char* content);
    void printStatus();
    char* getTimePostPosted();
};

#endif //MTA_FACEBOOK_STATUS_H
