
#ifndef MTA_FACEBOOK_FUNCTIONS_H
#define MTA_FACEBOOK_FUNCTIONS_H

#include <iostream>
using namespace std;
#include <string>

struct Date{
    int day;
    int month;
    int year;
};

struct Info{
    char* Name;
    Date birthDate;
};

void checkMemoryAllocation(void* ptr); // Checks if the memory allocation was successful

char* getDynamicString(); //Getting a string with unknown length from the user

Info getInfoFromUser(); //Getting info from the user

#endif //MTA_FACEBOOK_FUNCTIONS_H
