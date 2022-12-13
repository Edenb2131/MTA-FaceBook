
#include "Status.h"
using namespace std;

//constructor
Status::Status() {
    cout << "Enter your status: " << endl;
    Content = new char[100];
    cin.getline(Content, 100);
    pTime = time(nullptr);
    cout << endl;
}

//constructor
Status::Status(const char* content) : Content(strdup(content))
{
    pTime = time(nullptr);
}

//destructor
Status::~Status() {
    delete [] Content;
}

// Operator overloading
// Operator ==
bool Status::operator==(const Status &other) const {
    return (strcmp(Content, other.Content) == 0);
}

// Operator !=
bool Status::operator!=(const Status &other) const {
    return (strcmp(Content, other.Content) != 0);
}



char *Status::getContent() const {
    return Content;
}

void Status::setContent(char *content) {
    Content = content;
}

char* Status::getTimePostPosted(){
    return ctime(&pTime);
}

void Status::printStatus() {
    cout << this->getContent() << "   At time: " << this->getTimePostPosted() ;
}


