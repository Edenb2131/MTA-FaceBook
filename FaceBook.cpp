
#include "FaceBook.h"

//constructor
FaceBook::FaceBook() {
    Members = nullptr;
    NumOfMembersOverAll = 0;
    FanPages = nullptr;
    NumOfFanPagesOverAll = 0;
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

