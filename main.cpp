
#include <iostream>
using namespace std;
#include "FaceBook.h"

int main(){
    cout << "Hello, World!!" << endl;
    FaceBook fb = FaceBook();
    fb.addNewMember();

    fb.getMembers()[0].printMember();

    fb.addNewMember();

    fb.getMembers()[1].printMember();

    return 0;
}