
#include "Member.h"

Member::Member(Info infoFromUser): // Using here c'tor init line
    Name(infoFromUser.Name),
    Birthday(infoFromUser.birthDate)
{
    Friends = nullptr;
    NumOfFriends = 0,
    Posts = nullptr;
    NumOfPosts = 0;
    fanPages =nullptr;
}

Member::Member(const char* name, int day, int month, int year ) :
    Name(strdup(name)),
    Birthday(),
    Friends(nullptr),
    NumOfFriends(0),
    Posts(nullptr),
    NumOfPosts(0),
    fanPages(nullptr)
{
    Birthday.day = day;
    Birthday.month = month;
    Birthday.year = year;
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


void Member::addFriend(Member *friendToAdd, int a) {
    Member **temp = new Member *[NumOfFriends + 1];
    for (int i = 0; i < NumOfFriends; i++) {
        temp[i] = Friends[i];
    }

    //// Need to add the friend to the friend's friend list as well ////
    if(a == 0) {
        friendToAdd->addFriend(this, 1);
    }

    temp[NumOfFriends] = friendToAdd;
    delete[] Friends;
    Friends = temp;
    NumOfFriends++;
}

//void Member::removeFriend(Member *friendToRemove) {
//    Member **temp = new Member*[NumOfFriends - 1];
//    int j = 0;
//    for (int i = 0; i < NumOfFriends; i++) {
//        if (Friends[i] != friendToRemove) {
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

void Member::addPost(const char* content) {
    Status* newPost = new Status(content);

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
        cout << "Friends of " << "'" << Name << "'" << " are: " ;
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
            cout <<" "<< i+1 << ". " ;
            Posts[i]->printStatus();
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
// Getting a friend's name and printing his 10 latest posts
void Member::printFriendsTenLatestPosts(Member *friendToPrintLatestPosts){
    cout << "These are the latest posts of : '" << friendToPrintLatestPosts->getName() << "' "<< endl;
    friendToPrintLatestPosts->printTenLatestPosts();
    cout << endl;
}


// Printing all the posts of all the friends
void Member::printTenLatestPostsOfFriends() {
    cout << "These are your 10 latest posts of your friends: " << endl;
    if(NumOfFriends == 0){
        cout << "You have no friends ! " << endl;
    }
    else {
        for (int i = 0; i < NumOfFriends; i++) {
            if (Friends[i]->getNumOfPosts() < 10) {
                Friends[i]->printAllPosts();
            }
            else {
                for (int j = Friends[i]->getNumOfPosts() - 10; j < Friends[i]->getNumOfPosts(); j++) {
                    cout << Friends[i]->getPosts()[j]->getContent() << endl;
                }
            }
        }
    }
    cout << endl;
}




