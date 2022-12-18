#include "Status.h"
using namespace std;

//constructor
Status::Status() {
    cout << "Enter your status: " << endl;
    getline(cin, Content);
    pTime = time(nullptr);
    cout << endl;
}

//constructor
Status::Status(const string content) : Content(content)
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

string Status::getContent() const {
    return Content;
}

void Status::setContent(string content) {
    Content = content;
}

string Status::getTimePostPosted(){
    return ctime(&pTime);
}

void Status::printStatus() {
    cout << this->getContent() << "   At time: " << this->getTimePostPosted() ;
}


