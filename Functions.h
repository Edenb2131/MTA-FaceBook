
#ifndef MTA_FACEBOOK_FUNCTIONS_H
#define MTA_FACEBOOK_FUNCTIONS_H

#include <iostream>
#include <string>

class FaceBook;

struct Date{
    int day;
    int month;
    int year;

    Date() = default;
    Date(int day, int month, int year){ this->day = day; this->month = month; this->year = year; }
};

struct Info{
    char* Name;
    Date birthDate;
};

void checkMemoryAllocation(void* ptr); // Checks if the memory allocation was successful
char* getDynamicString(); //Getting a string with unknown length from the user
Info getInfoFromUser(); //Getting info from the user
void enterDataToStartWith(FaceBook& fb); // Preload data to the facebook application as requested

#endif //MTA_FACEBOOK_FUNCTIONS_H
