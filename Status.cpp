#include "Status.h"
using namespace std;

//constructor
Status::Status(string content) : Content(content)
{
    pTime = time(nullptr);
}

// Operator overloading
// Operator ==
bool Status::operator==(const Status &other) const {
    return (Content == other.Content);
}

// Operator !=
bool Status::operator!=(const Status &other) const {
    return (Content != other.Content);
}

const string Status::getContent() const {
    return Content;
}

string Status::getTimePostPosted(){
    return ctime(&pTime);
}

void Status::printStatus() {
    cout << this->getContent() << "   At time: " << this->getTimePostPosted() ;
}


// For classes


void StatusWithImage::printStatus() {
    cout << this->getContent() << "   Image: " << this->getImage() << "   At time: " << this->getTimePostPosted();
//    system("start Mountain.jpeg");
    
}

void StatusWithVideo::printStatus() {
    cout << this->getContent() << "   Video: " << this->getVideo() << "   At time: " << this->getTimePostPosted();
//    system("start CatReuniteWithOwner.mp4");
}