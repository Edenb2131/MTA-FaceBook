
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
    std::string Name;
    Date birthDate;
};

Info getInfoFromUser(FaceBook& fb); //Getting info from the user
void enterDataToStartWith(FaceBook& fb); // Preload data to the facebook application as requested

#endif //MTA_FACEBOOK_FUNCTIONS_H
