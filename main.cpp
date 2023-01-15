#define _CRT_SECURE_NO_WARNINGS
#include "FaceBook.h"
#include "Common.h"
#include "UI.h"
#include "FileHandler.h"

int main(){

    FaceBook fb;
    FileHandler fh(&fb);
    fh.loadDataFromFileToFacebook("/Users/edenbar/CLionProjects/Year2/MTA-FaceBook/Data.bin");
    UI ui(&fb);
    ui.process();
    fh.saveDataToFile("/Users/edenbar/CLionProjects/Year2/MTA-FaceBook/Data.bin");
    return 0;
}