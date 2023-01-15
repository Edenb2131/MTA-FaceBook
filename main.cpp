#define _CRT_SECURE_NO_WARNINGS
#include "FaceBook.h"
#include "Common.h"
#include "UI.h"
#include "FileHandler.h"

int main(){

    FaceBook fb;
    FileHandler fh(&fb);
    fh.loadDataFromFileToFacebook("Data.bin");
    UI ui(&fb);
    ui.process();
    fh.saveDataToFile("Data.bin");
    return 0;
}