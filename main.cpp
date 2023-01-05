#define _CRT_SECURE_NO_WARNINGS
#include "FaceBook.h"
#include "Common.h"
#include "UI.h"

int main(){
    FaceBook fb;
    enterDataToStartWith(fb);
    UI ui(&fb);
    ui.process();
    return 0;
}