
#ifndef MTA_FACEBOOK_COMMON_H
#define MTA_FACEBOOK_COMMON_H

#include <iostream>
#include <string>

class FaceBook;

struct Date {
    int day;
    int month;
    int year;

    Date(int day, int month, int year){ this->day = day; this->month = month; this->year = year; }
    void printDate() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

struct MemberInfo {
    std::string Name;
    Date birthDate;

    MemberInfo(std:: string name, Date date):Name(name), birthDate(date) {};
};
void enterDataToStartWith(FaceBook& fb); // Preload data to the facebook application as requested

#endif //MTA_FACEBOOK_COMMON_H
