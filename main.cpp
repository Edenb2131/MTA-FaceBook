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
            case 4: {
                int fanPageIndex = fb.findFanPage();
                fb.getFanPages()[fanPageIndex]->addPost();
                break;
            }
            case 5: {
                int memberIndex = fb.findMember();
                fb.getMembers()[memberIndex]->printAllPosts();
                break;
            }
            case 6: {
                int fanPageIndex = fb.findFanPage();
                fb.getFanPages()[fanPageIndex]->printAllPosts();
                break;
            }
            case 7: {
                for (int i = 0; i < fb.getNumOfMembersOverAll(); i++) {
                    fb.getMembers()[i]->printTenLatestPosts();
                }
                break;
            }
            case 8: {
                cout << "Please choose the first member: " << endl;
                int firstMemberIndex = fb.findMember();
                cout << "Please choose the second member: " << endl;
                int secondMemberIndex = fb.findMember();

                fb.connectTwoMembers(firstMemberIndex, secondMemberIndex);
                break;
            }
            case 9: {
                cout << "Please choose the first member: " << endl;
                int firstMemberIndex = fb.findMember();
                cout << "Please choose the second member: " << endl;
                int secondMemberIndex = fb.findMember();

                fb.disconnectTwoMembers(firstMemberIndex, secondMemberIndex);
                break;
            }
            case 10: {
                break;
            }
            case 11: {
                break;
            }
            case 12: {
                break;
            }
            case 13: {
                break;
            }
            case 14: {
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
    return 0;
}