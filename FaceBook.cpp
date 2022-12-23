#include "FaceBook.h"
using namespace std;

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
                Members[memberIndex]->addPost();
                break;
            }
            case 4: {
                int fanPageIndex = findFanPage();
                FanPages[fanPageIndex]->addPost();
                break;
            }
            case 5: {
                int memberIndex = findMember();
                Members[memberIndex]->printAllPosts();
                break;
            }
            case 6: {
                int memberIndex = findMember();
                if (Members[memberIndex]->getFanPages().size() == 0) {
                    cout << "You have no Liked pages !" << endl;
                    break;
                }

                for (int i = 0; i < Members[memberIndex]->getFanPages().size(); i++){
                    Members[memberIndex]->getFanPages()[i]->printAllPosts();
                }
                break;
            }
            case 7: {
                int memberIndex = findMember();
                Members[memberIndex]->printTenLatestPostsOfFriends();
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
                int secondMemberIndex = findMemberByMember(*Members[firstMemberIndex]);
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
                int fanPageIndex = findFanPageByMember(*Members[memberIndex]);
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
                Members[memberIndex]->printFriends();
                break;
            }
            case 14: {
                int memberIndex = findMember();
                Members[memberIndex]->printLikedPages();
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

int FaceBook::menu() const {
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
    cout << "Enter 15 to exit" << endl;

    cin >> choice;
    return choice;
}

FaceBook::~FaceBook() {
    for(auto & Member : Members)
        delete Member;
    
    for(auto& FanPage : FanPages)
        delete FanPage;
    
    // Members and FanPages are deleted in the destructor of vector
}


 vector<Member*>& FaceBook::getMembers() {
    return Members;
}

vector<FanPage*>& FaceBook::getFanPages() {
    return FanPages;
}

void FaceBook::addNewMember() {
    Info infoFromUser = getInfoFromUser(*this);
    Member* newMember = new Member(infoFromUser);
    Members.push_back(newMember);
}

void FaceBook::addNewMember(string name, int day, int month, int year ) {

    Member* newMember = new Member(name, day, month, year);
    Members.push_back(newMember);
}

void FaceBook::addNewPage(){
    cin.ignore();
    string name;
    cout << "Please enter page's name:" << endl;
    getline(cin, name);
    FanPage* newPage = new FanPage(name);
    FanPages.push_back(newPage);
}

void FaceBook::addNewPage(string name){
    FanPage* newPage = new FanPage(name);
    FanPages.push_back(newPage);
}

void FaceBook::printAllMembers() const {
    int size = Members.size();
    for (int i = 0; i < size; i++){
        Members[i]->printMember();
    }
}

void FaceBook::printAllFanPages() const {
    int size = FanPages.size();
    for (int i = 0; i < size; i++){
        FanPages[i]->printFanPage();
    }
}

void FaceBook::printAllEntitiesAndTheirData() const {
    printAllMembers();
    printAllFanPages();
}

void FaceBook::printAllEntities() const {
    int numOfMembersOverAll = (int)Members.size();
    int numOfFanPagesOverAll = (int)FanPages.size();
    cout << "All entities are:" << endl;

    cout << "Members: " ;
    for (int i = 0; i < numOfMembersOverAll - 1; i++) {
        cout << Members[i]->getName() << ", ";
    }
    cout << Members[numOfMembersOverAll - 1]->getName() << endl;

    cout << "Fan Pages: " ;
    for (int i = 0; i < numOfFanPagesOverAll - 1; i++){
        cout << FanPages[i]->getName() << ", ";
    }
    cout << FanPages[numOfFanPagesOverAll - 1]->getName() << endl;

    cout << endl;
}

int FaceBook::findMember() const {
    int index = -1;
    int numOfMembersOverAll = (int)Members.size();

    if (numOfMembersOverAll == 0) {
        cout << "There are no members using FaceBook!" << endl;
        return index;
    }

    cout << "Please choose a member from the list below:" << endl;
    while (index < 0 || index > numOfMembersOverAll) {
        for (int i = 0; i < numOfMembersOverAll; i++) {
            cout << "Enter " << i + 1 << " for " << Members[i]->getName() << endl;
        }
        cin >> index;
        if(index < 0 || index > numOfMembersOverAll)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

int FaceBook::findMemberByMember(const Member& member) const{
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

int FaceBook::findFanPage() const {
    int index = -1;
    int numOfFanPagesOverAll = (int)FanPages.size();

    if (numOfFanPagesOverAll == 0) {
        cout << "There are no fan pages in facebook!" << endl;
        return index;
    }
    cout << "Please choose a fan page from the list below:" << endl;
    while(index < 0 || index > numOfFanPagesOverAll) {
        for (int i = 0; i < numOfFanPagesOverAll; i++) {
            cout << "Enter " << i + 1 << " for " << FanPages[i]->getName() << endl;
        }
        cin >> index;
        if(index < 0 || index > numOfFanPagesOverAll)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

int FaceBook::findFanPageByMember(const Member& member) const {
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

void FaceBook::connectTwoMembers(int firstMemberIndex, int secondMemberIndex) {

    if(firstMemberIndex == secondMemberIndex){
        cout << "You can't connect a member to himself." << endl;
        return;
    }

    for (int i = 0; i < Members[firstMemberIndex]->getFriends().size(); i++) {
        string friend1Name = Members[firstMemberIndex]->getFriends()[i]->getName();
        string friend2Name = Members[secondMemberIndex]->getName();
        if (friend1Name == friend2Name) {
            cout << "Friends are already connected!" << endl;
            return;
        }
    }

    Members[firstMemberIndex]->addFriend(Members[secondMemberIndex]);
    cout << "Friends connected successfully!" << endl;
}

void FaceBook::disconnectTwoMembers(int firstMemberIndex, int secondMemberIndex) {

    if(Members[firstMemberIndex]->getFriends().empty()){
        return;
    }
    Members[firstMemberIndex]->removeFriend(Members[firstMemberIndex]->getFriends()[secondMemberIndex]);
    cout << "Friends disconnected successfully!" << endl;
}

void FaceBook::connectMemberAndFanPage(int memberIndex, int fanPageIndex) {
    for (int i = 0; i < Members[memberIndex]->getFriends().size(); i++) {
        string page1Name = Members[memberIndex]->getFanPages()[i]->getName();
        string page2Name = FanPages[fanPageIndex]->getName();
        if (page1Name == page2Name) {
            cout << "This member already likes this page!" << endl;
            return;
        }
    }
    Members[memberIndex]->likeFanPage(FanPages[fanPageIndex]);
    cout << "Page liked successfully!" << endl;
}

void FaceBook::disconnectMemberAndFanPage(int memberIndex, int fanPageIndex) {
    int i;
    int size = getFanPages().size();
    if(Members[memberIndex]->getFanPages().size() == 0){
        return;
    }

    string page1Name = Members[memberIndex]->getFanPages()[fanPageIndex]->getName();
    bool connected = false;
    for (i = 0; i < size; i++) {

        string page2Name = FanPages[i]->getName();
        if (page1Name == page2Name) {
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
    Members[memberIndex]->unlikeFanPage(FanPages[i]);
    cout << "Page unliked successfully!" << endl;
}



