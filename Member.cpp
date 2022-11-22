//
// Created by Eden Bar on 16/11/2022.
//

#include "Member.h"

Member::Member(Info infoFromUser) {
    Name = infoFromUser.Name;
    Birthday = infoFromUser.birthDate;
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

void Member::setName(char *name) {
  Name = name;
}

void Member::setBirthday(Date birthday) {
    Birthday = birthday;
}

void Member::setFriends(Member *friends) {
    Friends = friends;
}

void Member::setNumOfFriends(int numOfFriends) {
    NumOfFriends = numOfFriends;
}

void Member::setPosts(Status* posts) {
    Posts = posts;
}

void Member::setNumOfPosts(int numOfPosts) {
    NumOfPosts = numOfPosts;
}

void Member::addFriend(Member *friendToAdd, int a ) {
    Member *temp = (Member*)malloc(sizeof(Member) * (NumOfFriends + 1));
    //Member *temp = new Member[NumOfFriends + 1]; // Dont know why this doesn't work - opening constructor
    for (int i = 0; i < NumOfFriends; i++) {
        temp[i] = Friends[i];
    }
    temp[NumOfFriends] = *friendToAdd;

    //// Need to add the friend to the friend's friend list as well ////
    if (a == 0) {
        friendToAdd->addFriend(this, 1);
    }

    delete[] Friends;
    Friends = temp;
    NumOfFriends++;
}

//void Member::removeFriend(Member *friendToRemove) {
//    Member *temp = new Member[NumOfFriends-1];
//    int j = 0;
//    for (int i = 0; i < NumOfFriends; ++i) {
//        if(Friends[i].getName() != friendToRemove->getName()){
//            temp[j] = Friends[i];
//            j++;
//        }
//    }
//    delete[] Friends;
//    Friends = temp;
//    NumOfFriends--;
//}


//void Member::addPost() {
//    if(NumOfPosts != 0) {
//        Status *temp = (Status *) malloc(sizeof(Status) * (NumOfPosts + 1));
//        for (int i = 0; i < NumOfPosts; i++) {
//            temp[i] = Posts[i];
//        }
//
//        cout << "Enter your new status: " << endl;
//        temp[NumOfPosts].setContent(getDynamicString());
//        delete[] Posts;
//        Posts = temp;
//    }
//    else{
//        Posts = (Status *) malloc(sizeof(Status));
//        cout << "Enter your new status: " << endl;
//        Posts[NumOfPosts].setContent(getDynamicString());
//    }
//    cout << endl;
//    NumOfPosts++;
//}

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


void Member::printLatestPosts() {
    cout << Posts[NumOfPosts - 1].getContent() ;
    cout << endl;
}

void Member::printFriends() {
    int i;
    for (i = 0; i < NumOfFriends - 1; i++)
        cout << Friends[i].getName() << ", " ;

    cout << Friends[i].getName() << endl ;
}

void Member::printMember() {
    cout << "Name: " << Name << endl;
    cout << "Birthday: " << Birthday.day << "/" << Birthday.month << "/" << Birthday.year << endl;
    if(NumOfFriends == 0){
        cout << "You have no friends ! " << endl;
    }
    else {
        cout << "Friends: ";
        printFriends();
    }
    if(NumOfPosts == 0){
        cout << "You have no posts ! " << endl;
    }
    else {
        cout << "The latest post : " ;
        printLatestPosts();
    }
    cout << endl;
}

void Member::printAllPosts() {
    for (int i = 0; i < NumOfPosts; i++) {
        cout << Posts[i].getContent() << endl;
    }
}

void Member::printTenLatestPosts() {
    cout << "These are your 10 latest posts: " << endl;
    if(NumOfPosts < 10){
        printAllPosts();
    }
    else {
        for (int i = NumOfPosts - 10; i < NumOfPosts; i++) {
            cout << Posts[i].getContent() << endl;
        }
    }
}

Info getInfoFromUser() {
    Info infoFromUser;
    cout << "Making a new member" << endl;
    cout << "Enter your name: " << endl;
    infoFromUser.Name = getDynamicString();
    cout << "Enter your birthday: (Day Month Year)" << endl;
    cin >> infoFromUser.birthDate.day >> infoFromUser.birthDate.month >> infoFromUser.birthDate.year;
    getchar(); // This is to flush the buffer

    return infoFromUser;
}

//Getting a string with unknown length from the user
char* getDynamicString() {
    char *str = new char[100];
    cin.getline(str, 100);
    return str;
}
