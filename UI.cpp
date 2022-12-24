#include "UI.h"
#include <exception>
using namespace std;

UI::UI(FaceBook* fb) {
    if (fb != nullptr)
        FB = fb;
    else
       // TODO: fix exception;
        throw exception();
}

int UI::menu() const {
    cout << endl;
    int choice;
    cout << "Please choose an action from the list below: " << endl;
    cout << "Enter 1 to register to FaceBook as a member" << endl;
    cout << "Enter 2 to register to FaceBook as a fan page" << endl;
    cout << "Enter 3 to write a post as a member" << endl;
    cout << "Enter 4 to write a post as a fan page" << endl;
    cout << "Enter 5 to see all posts of a member in Facebook" << endl;
    cout << "Enter 6 to see all posts of a fan pages you liked" << endl;
    cout << "Enter 7 to see ten latest posts of your friends" << endl;
    cout << "Enter 8 to add a friend" << endl;
    cout << "Enter 9 to delete a friend" << endl;
    cout << "Enter 10 to like a fan page" << endl;
    cout << "Enter 11 to unlike a fan page" << endl;
    cout << "Enter 12 to see all entities on FaceBook" << endl;
    cout << "Enter 13 to see all your friends" << endl;
    cout << "Enter 14 to see all your liked fan pages" << endl;
    cout << "Enter 15 to see all fans of a fan page" << endl;
    cout << "Enter 16 to exit" << endl;

    cin >> choice;
    return choice;
}

void UI::process() {
    bool finish = false;
    int choice = menu();

    while (!finish) {
        switch (choice) {
            case 1: {
                FB->addNewMember();
                break;
            }
            case 2: {
                FB->addNewPage();
                break;
            }
            case 3: {
                int memberIndex = FB->findMember();
                FB->getMembers()[memberIndex]->addPost();
                break;
            }
            case 4: {
                int fanPageIndex = FB->findFanPage();
                FB->getFanPages()[fanPageIndex]->addPost();
                break;
            }
            case 5: {
                int memberIndex = FB->findMember();
                FB->getMembers()[memberIndex]->printAllPosts();
                break;
            }
            case 6: {
                int memberIndex = FB->findMember();
                if (FB->getMembers()[memberIndex]->getFanPages().size() == 0) {
                    cout << "You have no Liked pages !" << endl;
                    break;
                }

                for (int i = 0; i < FB->getMembers()[memberIndex]->getFanPages().size(); i++){
                    FB->getMembers()[memberIndex]->getFanPages()[i]->printAllPosts();
                }
                break;
            }
            case 7: {
                int memberIndex = FB->findMember();
                FB->getMembers()[memberIndex]->printTenLatestPostsOfFriends();
                break;
            }
            case 8: {
                cout << "Please choose the first member: " << endl;
                int firstMemberIndex = FB->findMember();
                cout << "Please choose the second member: " << endl;
                int secondMemberIndex = FB->findMember();

                FB->connectTwoMembers(firstMemberIndex, secondMemberIndex);
                break;
            }
            case 9: {
                cout << "Please choose the first member: " << endl;
                int firstMemberIndex = FB->findMember();
                cout << "Please choose the second member: " << endl;
                int secondMemberIndex = FB->findMemberByMember(*FB->getMembers()[firstMemberIndex]);
                FB->disconnectTwoMembers(firstMemberIndex, secondMemberIndex);
                break;
            }
            case 10: {
                int memberIndex = FB->findMember();
                int fanPageIndex = FB->findFanPage();
                FB->connectMemberAndFanPage(memberIndex, fanPageIndex);
                break;
            }
            case 11: {
                int memberIndex = FB->findMember();
                int fanPageIndex = FB->findFanPageByMember(*FB->getMembers()[memberIndex]);
                FB->disconnectMemberAndFanPage(memberIndex, fanPageIndex);
                break;
            }
            case 12: {
                FB->printAllEntities();
                FB->printAllEntitiesAndTheirData();
                break;
            }
            case 13: {
                int memberIndex = FB->findMember();
                FB->getMembers()[memberIndex]->printFriends();
                break;
            }
            case 14: {
                int memberIndex = FB->findMember();
                FB->getMembers()[memberIndex]->printLikedPages();
                break;
            }
            case 15: {
                int fanPageIndex = FB->findFanPage();
                FB->getFanPages()[fanPageIndex]->printFans();
                break;
            }
            case 16: {
                cout << "Thank you for using FaceBook, hope to see you again soon!" << endl;
                finish = true;
                break;
            }
        }
        if (!finish)
            choice = menu();
    }
}

MemberInfo UI::getMemberInfoFromUser() {
    int day, month, year;
    getchar();
    string name;
    cout << "Enter member's name: " << endl;

    // Check if the name is already in the system or name is valid
    try{
        getline(cin, name);
        if (name.empty())
            throw "Name is empty. Exiting...";
        if(name.length() > 20)
            throw "Name is too long.Exiting...";

        for(int i = 0; i < FB->getMembers().size(); i++)
            //Check to see if there is another member with the same name
            if(FB->getMembers()[i]->getName() == name)
                throw "Name already exists. Exiting...";
    }
    catch (const char* msg){
        cout << msg << endl;
        exit(1);
    }

    // if name is legal we continue to get the date until its right
    cout << "Enter member's birthday: (Day Month Year)" << endl;

    cin >> day ;
    while (day < 1 || day > 31) {
        cout << "Invalid day! Please enter a valid day: " << endl;
        cin >> day;
    }

    cin >> month ;
    while (month < 1 || month > 12) {
        cout << "Invalid month! Please enter a valid month: " << endl;
        cin >> month;
    }

    cin >> year;
    while (year < 1900 || year > 2022) {
        cout << "Invalid year! Please enter a valid year: " << endl;
        cin >> year;
    }

    getchar(); // This is to flush the buffer

    return MemberInfo(name, Date(day, month, year));
}

