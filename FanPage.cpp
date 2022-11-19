#include "FanPage.h"
#include "Member.h"

FanPage::FanPage(char *Name){
    this->Name = Name;
    this->Fans = nullptr;
    this->NumOfFans = 0;
    this->Posts = nullptr;
    this->NumOfPosts = 0;
}

char *FanPage::getName() const {
    return Name;
}

Member *FanPage::getFans() const {
    return Fans;
}

int FanPage::getNumOfFans() const {
    return NumOfFans;
}

Status* FanPage::getPosts() const {
    return Posts;
}

int FanPage::getNumOfPosts() const {
    return NumOfPosts;
}

void FanPage::setName(const char *name) {
    this->Name = name;
}

void FanPage::setFans(Member *fans) {
    this->Fans = fans;
}

void FanPage::setNumOfFans(int numOfFans){
    this->NumOfFans = numOfFans;
}

void FanPage::setPosts(Status *posts) {
    this->Posts = posts;
}

void FanPage::setNumOfPosts(int numOfPosts) {
    this->NumOfPosts = numOfPosts;
}

void FanPage::addPost(Status *postToAdd) {
    Status* newPosts = new Status[NumOfPosts + 1];
    for (int i = 0; i < NumOfPosts; i++){
        newPosts[i] = Posts[i];
    }
    newPosts[NumOfPosts] = *postToAdd;
    delete [] Posts;
    Posts = newPosts;
    NumOfPosts++;
}

void FanPage::printAllPosts() const {
    cout << "Posts are:" << endl;
    for (int i = 0; i < NumOfPosts; i++){
        cout << i+1 << ". " << Posts[i] << endl;
    }
}




