#include "Functions.h"
#include "FaceBook.h"
#include <string>

using namespace std;

#define LEN 100

//Getting a string with unknown length from the user
char* getDynamicString() {
    char *str = new char[LEN];
    cin.getline(str, LEN);
    return str;
}

//Getting info from a new user
Info getInfoFromUser() {
    Info infoFromUser;
    getchar();
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

//
void enterDataToStartWith(FaceBook& fb){
Member** my_arr;
    //Member 1:
    fb.addNewMember("Eden Bar" , 22 ,8 , 1997);
    fb.getMembers()[0]->addPost("I like ICE-CREAM !");
    fb.getMembers()[0]->addPost("Let's go to paris  !");

    //Member 2:
    fb.addNewMember("Avivit Cohen" , 10 ,10 , 2000);
    fb.getMembers()[1]->addPost("I love Computer Science !");
    fb.getMembers()[1]->addPost("Who wants to watch FRIENDS with me ?!");
    fb.getMembers()[1]->addPost("Im board.... ?!");

    //Member 3:
    fb.addNewMember("Liri Cohen" , 18 ,8 , 1997);
    fb.getMembers()[2]->addPost("Who wants to play basketball this afternoon?!");
    fb.getMembers()[2]->addPost("With my friends at tha mall (:!");


    // Linking between friends
    fb.getMembers()[0]->addFriend(fb.getMembers()[1]); // Eden and Avivit are friends.
    fb.getMembers()[0]->addFriend(fb.getMembers()[2]); // Eden and Liri are friends.


    //FanPage 1:
    fb.addNewPage("Wakanda 4Ever");
    fb.getFanPages()[0]->addPost("Wakanda FOREVER!");
    fb.getFanPages()[0]->addPost("Let's go to W-A-R!");

    //FanPage 2:
    fb.addNewPage("Marvel fans!");
    fb.getFanPages()[1]->addPost("I love Spider-Man!");
    fb.getFanPages()[1]->addPost("I love Thor!");
    fb.getFanPages()[1]->addPost("I love Caption America!");

    //FanPage 3:
    fb.addNewPage("Thanos was right!");
    fb.getFanPages()[2]->addPost("The population of the world need to be cut in half...");
    fb.getFanPages()[2]->addPost("We want THANOS !");

    //Linking between friends and fan pages
    fb.getMembers()[0]->likeFanPage(fb.getFanPages()[0]); // Eden likes the Wakanda page.
    fb.getMembers()[1]->likeFanPage(fb.getFanPages()[1]); // Avivit likes the Marvel fans page.
    fb.getMembers()[0]->likeFanPage(fb.getFanPages()[2]); // Eden likes the Thanos was right page.
    fb.getMembers()[2]->likeFanPage(fb.getFanPages()[2]); // Liri likes the Thanos was right page.
}




