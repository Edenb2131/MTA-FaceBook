#include <iostream>
using namespace std;
#include "FaceBook.h"

int main(){

    FaceBook fb;

    enterDataToStartWith(fb);

   //printing the start data:
   for(int i = 0; i < fb.getNumOfMembersOverAll(); i++) {
       fb.getMembers()[i]->printMember();
   }

   for (int i = 0; i < fb.getNumOfFanPagesOverAll(); i++) {
       fb.getFanPages()[i]->printAllPosts();
   }

   fb.addNewMember();
   fb.getMembers()[1]->addPost();
   fb.getMembers()[1]->addFriend(fb.getMembers()[0]);
   fb.getMembers()[1]->printFriendsTenLatestPosts(fb.getMembers()[0]);
   fb.getMembers()[1]->printTenLatestPostsOfFriends();


   fb.printAllEntities(); // Prints all entities in the system (members and fan pages)

   cout << endl << endl << endl << endl << endl;

   fb.printAllEntitiesAndTheirData(); // Prints all entities in the system (members and fan pages) and their data

    return 0;
}