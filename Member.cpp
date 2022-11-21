//
// Created by Eden Bar on 16/11/2022.
//

#include "Member.h"


Member::Member() {
    cout << "Enter your name: " << endl;
    Functions::getString(this->Name);
    cout << "Enter your birthday: (Day/Month/Year" << endl;
    cin << Birthday.day << Birthday.month << Birthday.year;
    Friends = nullptr;
    NumOfFriends = 0;
    Posts = nullptr;
    NumOfPosts = 0;

}

char *Member::getName() const {
    return Name;
}

Date Member::getBirthday() const {
    return Birthday;
}

Member *Member::getFriends() const {
    return Friends;
}

int Member::getNumOfFriends() const {
    return NumOfFriends;
}

Status *Member::getPosts() const {
    return Posts;
}

int Member::getNumOfPosts() const {
    return NumOfPosts;
}

void Member::setName(const char *name) {
    Member::Name = name;
}

void Member::setBirthday(Date birthday) {
    Member::Birthday = birthday;
}

void Member::setFriends(Member *friends) {
    Member::Friends = friends;
}

void Member::setNumOfFriends(int numOfFriends) {
    Member::NumOfFriends = numOfFriends;
}

void Member::setPosts(Status* *posts) {
    Member::Posts = posts;
}

void Member::setNumOfPosts(int numOfPosts) {
    Member::NumOfPosts = numOfPosts;
}

void Member::addFriend(Member *friendToAdd) {
    Member *temp = new Member[NumOfFriends + 1];
    for (int i = 0; i < NumOfFriends; ++i) {
        temp[i] = Friends[i];
    }
    temp[NumOfFriends] = *friendToAdd;

    //// Need to add the friend to the friend's friend list as well ////
    friendToAdd->addFriend(this);

    delete[] Friends;
    Friends = temp;
    NumOfFriends++;
}

//void Member::removeFriend(Member *friendToRemove) {
//    Member *temp = new Member[NumOfFriends-1];
//    int j = 0;
//    for (int i = 0; i < NumOfFriends; ++i) {
//        if(friends[i].getName() != friendToRemove->getName()){
//            temp[j] = Friends[i];
//            j++;
//        }
//    }
//    delete[] friends;
//    friends = temp;
//    numOfFriends--;
//}

void Member::addPost(Status* postToAdd){
    Status* temp = new Status[NumOfPosts + 1];
    for(int i = 0; i < NumOfPosts ; i++){
        temp[i] = Posts[i];
    }

    temp[NumOfPosts] = postToAdd;
    delete [] Posts;
    Posts = temp;
    NumOfPosts++;
}

//void Member::removePost(char *postToRemove) {
//    char **temp = new char*[NumOfPosts-1];
//    int j = 0;
//    for (int i = 0; i < NumOfPosts; ++i) {
//        if(Posts[i] != postToRemove){
//            temp[j] = posts[i];
//            j++;
//        }
//    }
//    delete[] Posts;
//    Posts = temp;
//    NumOfPosts--;
//}


////
//void Member::printPosts() {
//    for (int i = 0; i < NumOfPosts; ++i) {
//        cout << Posts[i] << endl;
//    }
//}

void Member::printFriends() {
    for (int i = 0; i < NumOfFriends; ++i) {
        cout << Friends[i].getName() << endl;
    }
}

void Member::printMember() {
    cout << "Name: " << Name << endl;
    cout << "Birthday: " << Birthday.day << "/" << Birthday.month << "/" << Birthday.year << endl;
    cout << "Friends: " << endl;
    printFriends();
    cout << "Posts: " << endl;
    printPosts();
}

