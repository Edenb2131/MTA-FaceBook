
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

Member **Member::getFriends() const {
    return Friends;
}

int Member::getNumOfFriends() const {
    return NumOfFriends;
}

Status **Member::getPosts() const {
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

void Member::setFriends(Member **friends) {
    Friends = friends;
}

void Member::setNumOfFriends(int numOfFriends) {
    NumOfFriends = numOfFriends;
}

void Member::setPosts(Status** posts) {
    Posts = posts;
}

void Member::setNumOfPosts(int numOfPosts) {
    NumOfPosts = numOfPosts;
}

//void Member::addFriend(Member *friendToAdd, int a ) {
//    Member *temp = (Member*)malloc(sizeof(Member) * (NumOfFriends + 1));
//    //Member *temp = new Member[NumOfFriends + 1]; // Dont know why this doesn't work - opening constructor
//    for (int i = 0; i < NumOfFriends; i++) {
//        temp[i] = Friends[i];
//    }
//    temp[NumOfFriends] = *friendToAdd;
//
//    //// Need to add the friend to the friend's friend list as well ////
//    if (a == 0) {
//        friendToAdd->addFriend(this, 1);
//    }
//
//    delete[] Friends;
//    Friends = temp;
//    NumOfFriends++;
//}

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


void Member::addPost() {
    Status* newPost = new Status;

    if (NumOfPosts) {
        Status** newPosts = new Status*[NumOfPosts + 1];
        for (int i = 0; i < NumOfPosts; i++) {
            newPosts[i] = Posts[i];
        }
        newPosts[NumOfPosts] = newPost;
        delete [] Posts;
        Posts = newPosts;
    }
    else {
        Posts = new Status*;
        Posts[0] = newPost;
    }
    NumOfPosts++;
}

void Member::printLatestPost() {
    cout << Posts[NumOfPosts - 1]->getContent() << endl;
}

void Member::printFriends() {
    if(NumOfFriends == 0){
        cout << "You have no friends ! " << endl;
    }
    else {
        cout << "Friends of " << "'" << Name << "'" << " are:" << endl;
        int i;
        for (i = 0; i < NumOfFriends - 1; i++)
            cout << Friends[i]->getName() << ", " ;

        cout << Friends[i]->getName() << endl ;
    }
    cout << endl;
}

void Member::printAllPosts() {
    if(NumOfPosts == 0){
        cout << "You have no posts ! " << endl;
    }
    else {
        cout << "Posts of " << "'" << Name << "'" << " are:" << endl;
        for (int i = 0; i < NumOfPosts; i++) {
            cout << i+1 << ". " << Posts[i]->getContent() << endl;
        }
    }
    cout << endl;
}

void Member::printMember() {
    cout << "Name: " << Name << endl;
    cout << "Birthday: " << Birthday.day << "/" << Birthday.month << "/" << Birthday.year << endl;
    printFriends();
    printAllPosts();
}

void Member::printTenLatestPosts() {
    cout << "These are your 10 latest posts: " << endl;
    if(NumOfPosts < 10){
        printAllPosts();
    }
    else {
        for (int i = NumOfPosts - 10; i < NumOfPosts; i++) {
            cout << Posts[i]->getContent() << endl;
        }
    }
}

Info getInfoFromUser() {
    Info infoFromUser;
    cout << "Enter member's name: " << endl;
    infoFromUser.Name = getDynamicString();
    cout << "Enter member's birthday: (Day Month Year)" << endl;
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
