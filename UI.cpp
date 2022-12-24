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
                FB->addNewMember(getMemberInfoFromUser());
                break;
            }
            case 2: {
                FB->addNewPage(getFanPageNameFromUser());
                break;
            }
            case 3: {
                int memberIndex = chooseMember();
                FB->getMembers()[memberIndex]->addPost(getStatusFromUser());
                break;
            }
            case 4: {
                int fanPageIndex = chooseFanPage();
                FB->getFanPages()[fanPageIndex]->addPost(getStatusFromUser());
                break;
            }
            case 5: {
                int memberIndex = chooseMember();
                FB->getMembers()[memberIndex]->printAllPosts();
                break;
            }
            case 6: {
                int memberIndex = chooseMember();
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
                int memberIndex = chooseMember();
                FB->getMembers()[memberIndex]->printTenLatestPostsOfFriends();
                break;
            }
            case 8: {
                cout << "Please choose the first member: " << endl;
                int firstMemberIndex = chooseMember();
                cout << "Please choose the second member: " << endl;
                int secondMemberIndex = chooseMember();

                FB->connectTwoMembers(firstMemberIndex, secondMemberIndex);
                break;
            }
            case 9: {
                cout << "Please choose the first member: " << endl;
                int firstMemberIndex = chooseMember();
                cout << "Please choose the second member: " << endl;
                int secondMemberIndex = chooseFriendOfMember(*FB->getMembers()[firstMemberIndex]);
                FB->disconnectTwoMembers(firstMemberIndex, secondMemberIndex);
                break;
            }
            case 10: {
                int memberIndex = chooseMember();
                int fanPageIndex = chooseFanPage();
                FB->connectMemberAndFanPage(memberIndex, fanPageIndex);
                break;
            }
            case 11: {
                int memberIndex = chooseMember();
                int fanPageIndex = chooseFanPageOfMember(*FB->getMembers()[memberIndex]);
                FB->disconnectMemberAndFanPage(memberIndex, fanPageIndex);
                break;
            }
            case 12: {
                FB->printAllEntities();
                FB->printAllEntitiesAndTheirData();
                break;
            }
            case 13: {
                int memberIndex = chooseMember();
                FB->getMembers()[memberIndex]->printFriends();
                break;
            }
            case 14: {
                int memberIndex = chooseMember();
                FB->getMembers()[memberIndex]->printLikedPages();
                break;
            }
            case 15: {
                int fanPageIndex = chooseFanPage();
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

MemberInfo UI::getMemberInfoFromUser() const {
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

string UI::getFanPageNameFromUser() const {
    cin.ignore();
    string name;
    cout << "Please enter page's name:" << endl;
    getline(cin, name);
    return name;
}

int UI::chooseMember() const {
    int index = -1;
    int numOfMembersOverAll = (int)FB->getMembers().size();

    if (numOfMembersOverAll == 0) {
        cout << "There are no members using FaceBook!" << endl;
        return index;
    }

    cout << "Please choose a member from the list below:" << endl;
    while (index < 0 || index > numOfMembersOverAll) {
        for (int i = 0; i < numOfMembersOverAll; i++) {
            cout << "Enter " << i + 1 << " for " << FB->getMembers()[i]->getName() << endl;
        }
        cin >> index;
        if(index < 0 || index > numOfMembersOverAll)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

int UI::chooseFriendOfMember(const Member &member) const {
    int index = -1;
    int numOfFriends = (int)member.getFriends().size();
    if (numOfFriends == 0){
        cout << "This member has no friends." << endl;
        return index;
    }

    cout << "Please choose a member from the list below:" << endl;
    while(index < 0 || index > numOfFriends) {
        for (int i = 0; i < numOfFriends; i++) {
            cout << "Enter " << i + 1 << " for " << member.getFriends()[i]->getName() << endl;
        }
        cin >> index;
        if(index < 0 || index > numOfFriends)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

int UI::chooseFanPage() const {
    int index = -1;
    int numOfFanPagesOverAll = (int)FB->getFanPages().size();

    if (numOfFanPagesOverAll == 0) {
        cout << "There are no fan pages in facebook!" << endl;
        return index;
    }
    cout << "Please choose a fan page from the list below:" << endl;
    while(index < 0 || index > numOfFanPagesOverAll) {
        for (int i = 0; i < numOfFanPagesOverAll; i++) {
            cout << "Enter " << i + 1 << " for " << FB->getFanPages()[i]->getName() << endl;
        }
        cin >> index;
        if(index < 0 || index > numOfFanPagesOverAll)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

int UI::chooseFanPageOfMember(const Member &member) const {
    int index = -1;
    int numOfFanPages = (int)member.getFanPages().size();
    if(numOfFanPages == 0){
        cout << "This member has no liked fan pages." << endl;
        return index;
    }

    cout << "Please choose a fan page from the list below:" << endl;
    while(index < 0 || index > numOfFanPages) {
        for (int i = 0; i < numOfFanPages; i++) {
            cout << "Enter " << i + 1 << " for " << member.getFanPages()[i]->getName() << endl;
        }
        cin >> index;
        if(index < 0 || index > numOfFanPages)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

string UI::getStatusFromUser() const {
    cin.ignore();
    string name;
    cout << "Please enter your status:" << endl;
    getline(cin, name);
    return name;
}

