
#include "Status.h"

Status::Status() {
    cout << "Enter your status: " << endl;
    Content = new char[100];
    cin.getline(Content, 100);
    time_t timeRightNow = time(0);
    pTime = ctime(&timeRightNow); // Making the time a string
    cout << endl;
}

Status::Status(const char* content) : Content(strdup(content))
{
    time_t timeRightNow = time(0);
    pTime = ctime(&timeRightNow); // Making the time a string
}

char *Status::getContent() const {
    return Content;
}

void Status::setContent(char *content) {
    Content = content;
}

char* Status::getTimePostPosted(){
    return pTime;
}

void Status::printStatus() {
    cout << this->getContent() << "   At time: " << this->getTimePostPosted() ;
}


