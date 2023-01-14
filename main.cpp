#define _CRT_SECURE_NO_WARNINGS
#include "FaceBook.h"
#include "Common.h"
#include "UI.h"
#include "FileHandler.h"

int main(){

    FaceBook fb;
    FileHandler fh(&fb);
    //fh.loadDataFromFileToFacebook("/Users/uder/Downloads/cs/שנה ב/MTA-FaceBook/Data.bin");
    enterDataToStartWith(fb);
    UI ui(&fb);
    ui.process();
    fh.saveDataToFile("/Users/uder/Downloads/cs/שנה ב/MTA-FaceBook/Data.bin");
    return 0;
}