
#ifndef MTA_FACEBOOK_STATUS_H
#define MTA_FACEBOOK_STATUS_H

#include <iostream>
using namespace std;
#include <string>


class Status {
    char* Content;

public:

    Status(char* content);
    char* getContent() const;
    void setContent(char* content);
    void printStatus();
};


#endif //MTA_FACEBOOK_STATUS_H
