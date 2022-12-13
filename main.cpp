#include <iostream>
using namespace std;
#include "FaceBook.h"
#include "Functions.h"

int main(){
    FaceBook fb;
    enterDataToStartWith(fb);
    fb.process();
    return 0;
}