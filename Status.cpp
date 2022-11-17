//
// Created by Eden Bar on 17/11/2022.
//

#include "Status.h"

Status::Status(char *content) {
    this->content = content;
}

char *Status::getContent() const {
    return content;
}

void Status::setContent(char *content) {
    Status::content = content;
}

void Status::printStatus() {
    cout << "Status: " << content << endl;
}

