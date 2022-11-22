
#include "Status.h"

Status::Status() {
    cout << "Enter your status: " << endl;
    cin >> Content;
    //Content = getDynamicString();
}

char *Status::getContent() const {
    return Content;
}

void Status::setContent(char *content) {
    Status::Content = content;
}

void Status::printStatus() {
    cout << "Status: " << Content << endl;
}


