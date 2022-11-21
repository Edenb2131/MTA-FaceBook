
#include <iostream>
using namespace std;
#include "FaceBook.h"

int main(){

    FaceBook fb = FaceBook();
    fb.addNewMember();
    fb.addNewMember();
    fb.addNewMember();

   for(int i = 0; i < fb.getNumOfMembersOverAll(); i++) {
       fb.getMembers()[i].printMember();
   }

    fb.getMembers()[0].addFriend(&fb.getMembers()[1]);
    fb.getMembers()[0].addFriend(&fb.getMembers()[2]);
    fb.getMembers()[1].addFriend(&fb.getMembers()[2]);

    for(int i = 0; i < fb.getNumOfMembersOverAll(); i++) {
        fb.getMembers()[i].printMember();
    }

    fb.getMembers()[0].addPost();
    fb.getMembers()[0].addPost();
    fb.getMembers()[0].printMember();

    fb.getMembers()[0].printTenLatestPosts();
    return 0;
}