//
// Created by Eden Bar on 17/11/2022.
//

#ifndef MTA_FACEBOOK_STATUS_H
#define MTA_FACEBOOK_STATUS_H

#include <iostream>
using namespace std;
#include <string>
#include "Status.h"

class Status {
    char* Content;

public:
    Status(char* content);
    char* getContent() const;
    void setContent(char* content);
    void printStatus();
};


#endif //MTA_FACEBOOK_STATUS_H
