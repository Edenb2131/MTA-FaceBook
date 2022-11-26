#include <iostream>
using namespace std;
#include "FaceBook.h"

int main(){

    FaceBook fb;
    bool finish = false;

    enterDataToStartWith(fb);

    int choice = fb.menu();

    while (!finish) {
        switch (choice) {
            case 1: {
                fb.addNewMember();
                break;
            }
            case 2: {
                fb.addNewPage();
                break;
            }
            case 3: {
                int memberIndex = fb.findMember();
                fb.getMembers()[memberIndex]->addPost();
                break;
            }
            case 15: {
                cout << "Thank you for using FaceBook, hope to see you again soon!" << endl;
                finish = true;
                break;
            }

        }
        if (!finish)
            choice = fb.menu();
    }



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