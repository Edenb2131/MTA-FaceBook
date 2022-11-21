
#include "FaceBook.h"

//constructor
FaceBook::FaceBook() {
    Members = nullptr;
    NumOfMembersOverAll = 0;
    FanPages = nullptr;
    NumOfFanPagesOverAll = 0;
}


Member *FaceBook::getMembers() const {
    return Members;
}

int FaceBook::getNumOfMembersOverAll() const {
    return NumOfMembersOverAll;
}

FanPage *FaceBook::getFanPages() const {
    return FanPages;
}

int FaceBook::getNumOfFanPagesOverAll() const {
    return NumOfFanPagesOverAll;
}

//void FaceBook::setMembers(Member *members) {
//    FaceBook::Members = members;
//}

void FaceBook::setNumOfMembersOverAll(int numOfMembersOverAll) {
    FaceBook::NumOfMembersOverAll = numOfMembersOverAll;
}

void FaceBook::setFanPages(FanPage *fanPages) {
    FaceBook::FanPages = fanPages;
}

void FaceBook::setNumOfFanPagesOverAll(int numOfFanPagesOverAll) {
    FaceBook::NumOfFanPagesOverAll = numOfFanPagesOverAll;
}


void FaceBook::addNewMember() {

    if(NumOfMembersOverAll != 0){
        Member* newMembers = (Member*) malloc(sizeof(Member) * (NumOfMembersOverAll + 1));
        for (int i = 0; i < NumOfMembersOverAll; i++){
            newMembers[i] = Members[i];
        }
        newMembers[NumOfMembersOverAll] = Member();
        delete [] Members;
        Members = newMembers;
    }
    else{
        Members = new Member[1];
    }

    NumOfMembersOverAll++;
    cout << endl;
}