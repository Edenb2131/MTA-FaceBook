
#include "FaceBook.h"

//constructor
FaceBook::FaceBook() {
    Members = nullptr;
    NumOfMembersOverAll = 0;
    FanPages = nullptr;
    NumOfFanPagesOverAll = 0;
}

//destructor
FaceBook::~FaceBook() {
    int i;
    for (i = 0; i < NumOfMembersOverAll; i++) {
        delete Members[i];
    }
    delete [] Members;

    for (i = 0; i <NumOfFanPagesOverAll; i++) {
        delete FanPages[i];
    }
    delete [] FanPages;
}

void FaceBook::process() {
    bool finish = false;
    int choice = menu();

    while (!finish) {
        switch (choice) {
            case 1: {
                addNewMember();
                break;
            }
            case 2: {
                addNewPage();
                break;
            }
            case 3: {
                int memberIndex = findMember();
                getMembers()[memberIndex]->addPost();
                break;
            }
            case 4: {
                int fanPageIndex = findFanPage();
                getFanPages()[fanPageIndex]->addPost();
                break;
            }
            case 5: {
                int memberIndex = findMember();
                getMembers()[memberIndex]->printAllPosts();
                break;
            }
            case 6: {
                int fanPageIndex = findFanPage();
                getFanPages()[fanPageIndex]->printAllPosts();
                break;
            }
            case 7: {
                for (int i = 0; i < getNumOfMembersOverAll(); i++) {
                    getMembers()[i]->printTenLatestPosts();
                }
                break;
            }
            case 8: {
                cout << "Please choose the first member: " << endl;
                int firstMemberIndex = findMember();
                cout << "Please choose the second member: " << endl;
                int secondMemberIndex = findMember();

                connectTwoMembers(firstMemberIndex, secondMemberIndex);
                break;
            }
            case 9: {
                cout << "Please choose the first member: " << endl;
                int firstMemberIndex = findMember();
                cout << "Please choose the second member: " << endl;
                int secondMemberIndex = findMember();

                disconnectTwoMembers(firstMemberIndex, secondMemberIndex);
                break;
            }
            case 10: {
                int memberIndex = findMember();
                int fanPageIndex = findFanPage();
                connectMemberAndFanPage(memberIndex, fanPageIndex);
                break;
            }
            case 11: {
                int memberIndex = findMember();
                int fanPageIndex = findFanPage();
                disconnectMemberAndFanPage(memberIndex, fanPageIndex);
                break;
            }
            case 12: {
                printAllEntities();
                printAllEntitiesAndTheirData();
                break;
            }
            case 13: {
                int memberIndex = findMember();
                getMembers()[memberIndex]->printFriends();
                break;
            }
            case 14: {
                int memberIndex = findMember();
                getMembers()[memberIndex]->printLikedPages();
                break;
            }
            case 15: {
                cout << "Thank you for using FaceBook, hope to see you again soon!" << endl;
                finish = true;
                break;
            }
        }
        if (!finish)
            choice = menu();
    }
}

int FaceBook::menu() {
    int choice;
    cout << "Please choose an action from the list below: " << endl;
    cout << "Enter 1 to register to FaceBook as a member" << endl;
    cout << "Enter 2 to register to FaceBook as a fan page" << endl;
    cout << "Enter 3 to write a post as a member" << endl;
    cout << "Enter 4 to write a post as a fan page" << endl;
    cout << "Enter 5 to see all posts of your friends" << endl;
    cout << "Enter 6 to see all posts of fan pages you liked" << endl;
    cout << "Enter 7 to see ten latest posts of your friends" << endl;
    cout << "Enter 8 to add a friend" << endl;
    cout << "Enter 9 to delete a friend" << endl;
    cout << "Enter 10 to like a fan page" << endl;
    cout << "Enter 11 to unlike a fan page" << endl;
    cout << "Enter 12 to see all entities on FaceBook" << endl;
    cout << "Enter 13 to see all your friends" << endl;
    cout << "Enter 14 to see all your liked fan pages" << endl;
    cout << "Enter 15 to exit" << endl;

    cin >> choice;
    return choice;
}

Member **FaceBook::getMembers() const {
    return Members;
}

int FaceBook::getNumOfMembersOverAll() const {
    return NumOfMembersOverAll;
}

FanPage **FaceBook::getFanPages() const {
    return FanPages;
}

int FaceBook::getNumOfFanPagesOverAll() const {
    return NumOfFanPagesOverAll;
}

void FaceBook::setMembers(Member **members) {
    Members = members;
}

void FaceBook::setNumOfMembersOverAll(int numOfMembersOverAll) {
    NumOfMembersOverAll = numOfMembersOverAll;
}

void FaceBook::setFanPages(FanPage **fanPages) {
    FanPages = fanPages;
}

void FaceBook::setNumOfFanPagesOverAll(int numOfFanPagesOverAll) {
    NumOfFanPagesOverAll = numOfFanPagesOverAll;
}


void FaceBook::addNewMember() {
    Info infoFromUser = getInfoFromUser();
    Member* newMember = new Member(infoFromUser);

    if (NumOfMembersOverAll){
        Member** newMembers = new Member*[NumOfMembersOverAll + 1];
        for (int i = 0; i < NumOfMembersOverAll; i++){
            newMembers[i] = Members[i];
        }
        newMembers[NumOfMembersOverAll] = newMember;
        delete [] Members;
        Members = newMembers;
    }
    else {
        Members = new Member*;
        Members[0] = newMember;
    }
    NumOfMembersOverAll++;
}

void FaceBook::addNewMember(const char* name, int day, int month, int year ) {

    Member* newMember = new Member(name, day, month, year);
    if (NumOfMembersOverAll){
        Member** newMembers = new Member*[NumOfMembersOverAll + 1];
        for (int i = 0; i < NumOfMembersOverAll; i++){
            newMembers[i] = Members[i];
        }
        newMembers[NumOfMembersOverAll] = newMember;
        delete [] Members;
        Members = newMembers;
    }
    else {
        Members = new Member*;
        Members[0] = newMember;
    }
    NumOfMembersOverAll++;

}


void FaceBook::addNewPage(){
    cout << "Please enter page's name:" << endl;
    char* name = getDynamicString();
    FanPage* newPage = new FanPage(name);

    if (NumOfFanPagesOverAll){
        FanPage** newPages = new FanPage*[NumOfFanPagesOverAll + 1];
        for (int i = 0; i <NumOfFanPagesOverAll; i++){
            newPages[i] = FanPages[i];
        }
        newPages[NumOfFanPagesOverAll] = newPage;
        delete [] FanPages;
        FanPages = newPages;
    }
    else {
        FanPages = new FanPage*;
        FanPages[0] = newPage;
    }
    NumOfFanPagesOverAll++;
}

void FaceBook::addNewPage(const char* name){
    FanPage* newPage = new FanPage((char*)name);

    if (NumOfFanPagesOverAll){
        FanPage** newPages = new FanPage*[NumOfFanPagesOverAll + 1];
        for (int i = 0; i <NumOfFanPagesOverAll; i++){
            newPages[i] = FanPages[i];
        }
        newPages[NumOfFanPagesOverAll] = newPage;
        delete [] FanPages;
        FanPages = newPages;
    }
    else {
        FanPages = new FanPage*;
        FanPages[0] = newPage;
    }
    NumOfFanPagesOverAll++;
}

void FaceBook::printAllMembers() const {
    for (int i = 0; i < NumOfMembersOverAll; i++){
        Members[i]->printMember();
    }
}

void FaceBook::printAllFanPages() const {
    for (int i = 0; i < NumOfFanPagesOverAll; i++){
        FanPages[i]->printFanPage();
    }
}

void FaceBook::printAllEntitiesAndTheirData() const {
    printAllMembers();
    printAllFanPages();
}

void FaceBook::printAllEntities() const {
    cout << "All entities are:" << endl;

    cout << "Members: " ;
    for (int i = 0; i < NumOfMembersOverAll - 1; i++) {
        cout << Members[i]->getName() << ", ";
    }
    cout << Members[NumOfMembersOverAll - 1]->getName() << endl;

    cout << "Fan Pages: " ;
    for (int i = 0; i < NumOfFanPagesOverAll - 1; i++){
        cout << FanPages[i]->getName() << ", ";
    }
    cout << FanPages[NumOfFanPagesOverAll - 1]->getName() << endl;
}

int FaceBook::findMember() {
    int index = -1;
    cout << "Please choose a member from the list below:" << endl;
    for (int i = 0; i < NumOfMembersOverAll; i++) {
        cout << i+1 << " for " << Members[i]->getName() << endl;
    }
    cin >> index;
    return index - 1;
}

int FaceBook::findFanPage() {
    int index = -1;
    cout << "Please choose a fan page from the list below:" << endl;
    for (int i = 0; i < NumOfFanPagesOverAll; i++) {
        cout << i+1 << " for " << FanPages[i]->getName() << endl;
    }
    cin >> index;
    return index - 1;
}

void FaceBook::connectTwoMembers(int firstMemberIndex, int secondMemberIndex) {
    for (int i = 0; i < Members[firstMemberIndex]->getNumOfFriends(); i++) {
        char* friend1Name = Members[firstMemberIndex]->getFriends()[i]->getName();
        char* friend2Name = Members[secondMemberIndex]->getName();
        if (strcmp (friend1Name, friend2Name) == 0) {
            cout << "Friends are already connected!" << endl;
            return;
        }
    }
    Members[firstMemberIndex]->addFriend(Members[secondMemberIndex]);
    cout << "Friends connected successfully!" << endl;
}

void FaceBook::disconnectTwoMembers(int firstMemberIndex, int secondMemberIndex) {
    bool connected = false;
    for (int i = 0; i < Members[firstMemberIndex]->getNumOfFriends(); i++) {
        char* friend1Name = Members[firstMemberIndex]->getFriends()[i]->getName();
        char* friend2Name = Members[secondMemberIndex]->getName();
        if (strcmp (friend1Name, friend2Name) != 0) {
            connected = false;
        }
        else {
            connected = true;
            break;
        }
    }
    if (!connected) {
        cout << "Friends are not connected!" << endl;
        return;
    }
    Members[firstMemberIndex]->removeFriend(Members[secondMemberIndex]);
    cout << "Friends disconnected successfully!" << endl;
}

void FaceBook::connectMemberAndFanPage(int memberIndex, int fanPageIndex) {
    for (int i = 0; i < Members[memberIndex]->getNumOfFanPages(); i++) {
        char* page1Name = Members[memberIndex]->getFanPages()[i]->getName();
        char* page2Name = FanPages[fanPageIndex]->getName();
        if (strcmp(page1Name, page2Name) == 0) {
            cout << "This member already likes this page!" << endl;
            return;
        }
    }
    Members[memberIndex]->likeFanPage(FanPages[fanPageIndex]);
    cout << "Page liked successfully!" << endl;
}

void FaceBook::disconnectMemberAndFanPage(int memberIndex, int fanPageIndex) {
    bool connected = false;
    for (int i = 0; i < Members[memberIndex]->getNumOfFanPages(); i++) {
        char *page1Name = Members[memberIndex]->getFanPages()[i]->getName();
        char *page2Name = FanPages[fanPageIndex]->getName();
        if (strcmp(page1Name, page2Name) != 0) {
            connected = false;
        }
        else {
            connected = true;
            break;
        }
    }

    if (!connected) {
        cout << "This member does not like this page!" << endl;
        return;
    }
    Members[memberIndex]->unlikeFanPage(FanPages[fanPageIndex]);
    cout << "Page unliked successfully!" << endl;
}


