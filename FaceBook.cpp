#include "FaceBook.h"
using namespace std;

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

void FaceBook::addNewMember(MemberInfo memberInfo) {
    Member* newMember = new Member(memberInfo);
    Members.push_back(newMember);
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



