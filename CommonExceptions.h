#ifndef MTA_FACEBOOK_COMMONEXCEPTIONS_H
#define MTA_FACEBOOK_COMMONEXCEPTIONS_H

#include <exception>
#include <string>

class InvalidInputException : public std::exception {
private:
    std::string data;
public:
    InvalidInputException(const std::string& str){
        data = str;
    }
    
    InvalidInputException(const char* str){
        data = str;
    }
    const char* what() const noexcept override {
        return data.c_str();
    }
};

#endif //MTA_FACEBOOK_COMMONEXCEPTIONS_H
