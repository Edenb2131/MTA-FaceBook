
#include "Status.h"

Status::Status(char *content) {
    Content = content;
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

