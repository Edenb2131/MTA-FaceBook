#include "Status.h"
using namespace std;

//constructor
Status::Status(string content) : Content(content)
{
    pTime = time(nullptr);
}

Status::Status(std::string content, time_t time) : Content(content), pTime(time){}

// Operator overloading
// Operator ==
bool Status::operator==(const Status &other) const {
    return (Content == other.Content);
}

// Operator !=
bool Status::operator!=(const Status &other) const {
    return (Content != other.Content);
}

const string& Status::getContent() const {
    return Content;
}

string Status::getTimeAsString() const{
    return ctime(&pTime);
}

time_t Status::getTime() const{
    return pTime;
}

void Status::setTime(time_t time) {
    pTime = time;
}

void Status::printStatus() {
    cout << this->getContent() << "   At time: " << this->getTimeAsString() ;
}


// For classes

void StatusWithImage::printStatus() {
    cout << this->getContent() << "   Image: " << this->getImage() << "   At time: " << this->getTimeAsString();
//    system("start Mountain.jpeg");
    
}

void StatusWithVideo::printStatus() {
    cout << this->getContent() << "   Video: " << this->getVideo() << "   At time: " << this->getTimeAsString();
//    system("start CatReuniteWithOwner.mp4");
}