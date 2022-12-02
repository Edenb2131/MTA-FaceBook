
#ifndef MTA_FACEBOOK_FUNCTIONS_H
#define MTA_FACEBOOK_FUNCTIONS_H

#include <iostream>
using namespace std;
#include <string>
class FaceBook;

struct Date{
    int day;
    int month;
    int year;
};

struct Info{
    char* Name;
    Date birthDate;
};

char* getDynamicString(); //Getting a string with unknown length from the user
Info getInfoFromUser(); //Getting info from the user
void enterDataToStartWith(FaceBook& fb); // Preload data to the facebook application as requested

#endif //MTA_FACEBOOK_FUNCTIONS_H
