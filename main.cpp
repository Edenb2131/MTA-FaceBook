
#include <iostream>
using namespace std;
#include "FaceBook.h"

void enterDataToStartWith(FaceBook& fb){

    //Member 1:
    fb.addNewMember("Eden Bar" , 22 ,8 , 1997);
    fb.getMembers()[0]->addPost("I like ICE-CREAM !");
    fb.getMembers()[0]->addPost("Let's go to paris  !");

    //Member 2:
    fb.addNewMember("Avivit Cohen" , 10 ,10 , 2000);
    fb.getMembers()[1]->addPost("I love Computer Science !");
    fb.getMembers()[1]->addPost("Who wants to watch FRIENDS with me ?!");
    fb.getMembers()[1]->addPost("Im board.... ?!");

    //Member 3:
    fb.addNewMember("Liri Cohen" , 18 ,8 , 1997);
    fb.getMembers()[2]->addPost("Who wants to play basketball this afternoon?!");
    fb.getMembers()[2]->addPost("With my friends at Victoria's secret (:!");


    // Linking between friends
    fb.getMembers()[0]->addFriend(fb.getMembers()[1]);
    fb.getMembers()[0]->addFriend(fb.getMembers()[2]);


    //FanPage 1:
    fb.addNewPage("Wakanda!");
    fb.getFanPages()[0]->addPost("Wakanda FOREVER!");
    fb.getFanPages()[0]->addPost("Let's go to W-A-R!");
}


int main(){

    FaceBook fb;

    enterDataToStartWith(fb);
//    fb.addNewMember();
//    fb.getMembers()[0]->addPost();
//    fb.getMembers()[0]->addPost();
//    fb.getMembers()[0]->addPost();
//
//    fb.addNewPage();
//    fb.getFanPages()[0]->addPost();
//    fb.getFanPages()[0]->addPost();



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

   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;

   fb.printAllEntitiesAndTheirData(); // Prints all entities in the system (members and fan pages) and their data


    //// NEED TO DELETE ALLOCATIONS !!! ////
    //// NEED TO DELETE ALLOCATIONS !!! ////
    //// NEED TO DELETE ALLOCATIONS !!! ////
    //// NEED TO DELETE ALLOCATIONS !!! ////


    return 0;
}