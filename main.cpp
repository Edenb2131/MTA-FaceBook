
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
    fb.getFanPages()[0]->addPost();

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

   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;

   fb.printAllEntitiesAndTheirData(); // Prints all entities in the system (members and fan pages) and their data

    return 0;
}