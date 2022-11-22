
#include "Status.h"

Status::Status() {
    cout << "Enter your status: " << endl;
    Content = new char[100];
    cin.getline(Content, 100);
}

char *Status::getContent() const {
    return Content;
}

void Status::setContent(char *content) {
    Content = content;
}

void Status::printStatus() {
    cout << "Status: " << Content << endl;
}


