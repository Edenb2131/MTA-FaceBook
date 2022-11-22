
#include "Functions.h"
#define LEN 100

void checkMemoryAllocation(void* ptr) {
    if (ptr == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }
}

//Getting a string with unknown length from the user
char* getDynamicString() {
    char *str = new char[100];
    cin.getline(str, 100);
    return str;
}


Info getInfoFromUser() {
    Info infoFromUser;
    cout << "Enter member's name: " << endl;
    infoFromUser.Name = getDynamicString();
    cout << "Enter member's birthday: (Day Month Year)" << endl;

    cin >> infoFromUser.birthDate.day ;
    while ( infoFromUser.birthDate.day < 1 || infoFromUser.birthDate.day > 31) {
        cout << "Invalid day! Please enter a valid day: " << endl;
        cin >> infoFromUser.birthDate.day;
    }

    cin >> infoFromUser.birthDate.month ;
    while ( infoFromUser.birthDate.month < 1 || infoFromUser.birthDate.month > 12) {
        cout << "Invalid month! Please enter a valid month: " << endl;
        cin >> infoFromUser.birthDate.month;
    }


    cin>> infoFromUser.birthDate.year;
    while ( infoFromUser.birthDate.year < 1900 || infoFromUser.birthDate.year > 2022) {
        cout << "Invalid year! Please enter a valid year: " << endl;
        cin >> infoFromUser.birthDate.year;
    }


    getchar(); // This is to flush the buffer

    return infoFromUser;
}



