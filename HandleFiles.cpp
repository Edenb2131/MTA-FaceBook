//
// Created by Eden Bar on 05/01/2023.
//

#include "HandleFiles.h"
using namespace std;

HandleFiles::HandleFiles(string& fileName, FaceBook& fb) : fileName(fileName) {
    file.open(fileName, ios::in | ios::out | ios::app);
    if (!file.is_open()) {
        throw FileException("Error opening file. Couldn't upload data from the file");
    }
    
    // Upload the data from the file to the FaceBook
    // TODO - upload the data from the file to the FaceBook
 

    file.close();
}


HandleFiles::~HandleFiles() {
    
    file.open(fileName, ios::in);
    if (!file.is_open()) {
        throw FileException("Error opening file. Couldn't write data to the file");
    }
    
    // Write to the file all the data from the FaceBook
    // TODO - write to the file all the data from the FaceBook
    
}