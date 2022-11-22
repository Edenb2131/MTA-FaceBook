
#include <iostream>
using namespace std;
#include "FaceBook.h"

int main(){

    FaceBook fb;
    fb.addNewMember();
    fb.getMembers()[0]->addPost();
    fb.getMembers()[0]->addPost();
    fb.getMembers()[0]->addPost();
    fb.addNewPage();
    fb.getFanPages()[0]->addPost();

   for(int i = 0; i < fb.getNumOfMembersOverAll(); i++) {
       fb.getMembers()[i]->printMember();
   }

   for (int i = 0; i < fb.getNumOfFanPagesOverAll(); i++) {
       fb.getFanPages()[i]->printAllPosts();
   }
    return 0;
}