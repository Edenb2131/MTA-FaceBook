//
// Created by Eden Bar on 05/01/2023.
//

#ifndef MTA_FACEBOOK_HANDLEFILES_H
#define MTA_FACEBOOK_HANDLEFILES_H

#include "iostream"
#include "fstream"
#include "string"
#include "Common.h"

class FaceBook; // forward declaration

class HandleFiles {
    std::string fileName;
    std::fstream file;
    
public:
    
    HandleFiles(std::string& fileName, FaceBook& fb); // Opens the file and uploading the data to the file
    ~HandleFiles(); // Writing to the file all the content and closes the file
    
//    static void writeToFile(std::string fileName, std::string content);
//    static std::string readFromFile(std::string fileName);

};



class FileException : public std::exception {
    std::string message;
public:
    
    explicit FileException(const char* message) : message(message) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
    
    
};



#endif //MTA_FACEBOOK_HANDLEFILES_H
