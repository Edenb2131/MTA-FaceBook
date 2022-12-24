
#include "Member.h"
#include "FanPage.h"
#include <string>
#include <vector>
using namespace std;

//constructor
Member::Member(MemberInfo infoFromUser): // Using here c'tor init line
    Name(infoFromUser.Name),
    Birthday(infoFromUser.birthDate) {}

//constructor
Member::Member(string name, int day, int month, int year) :
    Name(name),
    Birthday(day, month, year)
{
    Birthday.day = day;
    Birthday.month = month;
    Birthday.year = year;
}

//getters :
string Member::getName() const {
    return Name;
}

Date Member::getBirthday() const {
    return Birthday;
}

vector<Member*> Member::getFriends() const {
    return Friends;
}

vector<Status*> Member::getPosts() const {
    return Posts;
}

vector<FanPage*> Member::getFanPages() const {
    return FanPages;
}

//operators :

void Member::operator+=(Member* friendToAdd) { // Add friend operator - required

    this ->addFriend(friendToAdd, false); // false = need to be added to the other friend as well
}

void Member::operator-=(Member* friendToRemove) { // Remove friend operator - required

    this ->removeFriend(friendToRemove);
}

bool Member::operator<(const Member& other) const { // Less than operator - required

    return (this->Friends.size() < other.Friends.size());
}

bool Member::operator>(const Member& other) const { // Greater than operator - required

    return (this->Friends.size() > other.Friends.size());
}

bool Member::operator<=(const Member &other) const {
    return (this->Friends.size() <= other.Friends.size());
}

bool Member::operator>=(const Member &other) const {
    return (this->Friends.size() >= other.Friends.size());
}


// Functions :

void Member::addFriend(Member *friendToAdd, int neededToBeAdded) {
    int i;

    // Checking to see if not trying to add yourself
    if(this == friendToAdd){
        cout << "You cannot add yourself !" << endl;
        return;
    }

    // Need to add the friend to the friend's friend list as well
    if(neededToBeAdded == false ){
        friendToAdd->addFriend(this, true);
    }

    //Checking to see if already friends
    int size = this->Friends.size();
    for (i = 0; i < size; i++) {
        if (this->Friends[i]->Name == friendToAdd->Name) {
            cout << "Already friends !" << endl;
            return;
        }
    }

    Friends.push_back(friendToAdd);
}

void Member::removeFriend(Member *friendToRemove) {
    int friendsIndex;
    bool found = false;
    int size = this->Friends.size();
    // Check if possible in Theta(1)
    for (friendsIndex = 0; friendsIndex < size; friendsIndex++) {
        if (this->Friends[friendsIndex]->Name != friendToRemove->Name) {
            found = false;
        }
        else {
            found = true;
            break;
        }
    }

    if (!found)
        return;

    Friends.erase(Friends.begin() + friendsIndex);

    //// Need to remove the friend from the friend's friend list as well ////
    friendToRemove->removeFriend(this);
}

void Member::likeFanPage(FanPage *fanPageToLike) {
    int i;
    int size = this->FanPages.size();
    // Checking to see if needed to add that fan-page or not
    for (i = 0; i < size; i++) {
        if (FanPages[i]->getName() == fanPageToLike->getName()) {
            return;
        }
    }

    FanPages.push_back(fanPageToLike);

    // Need to add the member to the page's fans as well
    fanPageToLike->addFan(this);
}

void Member::unlikeFanPage(FanPage *fanPageToUnlike) {
    int pagesIndex;
    bool found = false;
    int size = this->FanPages.size();
    for (pagesIndex = 0; pagesIndex < size; pagesIndex++) {
        if (FanPages[pagesIndex]->getName() == fanPageToUnlike->getName()) {
            found = false;
        }
        else {
            found = true;
            break;
        }
    }

    if (!found)
        return;

    FanPages.erase(FanPages.begin() + pagesIndex);

    //// Need to remove the member from the page's fans list as well ////
    fanPageToUnlike->removeFan(this);
}

void Member::addPost() {
    //getchar();
    Status* newPost = new Status;
    Posts.push_back(newPost);
}

void Member::addPost(string content) {
    Status* newPost = new Status(content);
    Posts.push_back(newPost);
}

void Member::printFriends() const{
    int size = Friends.size();
    if(size == 0){
        cout << "You have no friends ! " << endl;
    }
    else {
        cout << "Friends of " << "'" << Name << "'" << " are: " ;
        int i;
        for (i = 0; i < size - 1; i++)
            cout << Friends[i]->getName() << ", " ;

        cout << Friends[i]->getName() << endl ;
    }
    cout << endl;
}

void Member::printLikedPages() const{
    int size = FanPages.size();
    if (size == 0) {
        cout << "You have no liked pages !" << endl;
    }
    else {
        cout << "Liked pages of " << "'" << Name << "'" << " are: " ;
        int i;
        for (i = 0; i < size - 1; i++)
            cout << FanPages[i]->getName() << ", " ;

        cout << FanPages[i]->getName() << endl ;
    }
    cout << endl;
}

void Member::printAllPosts() const{
    int size = Posts.size();
    if(size == 0){
        cout << "You have no posts ! " << endl;
    }
    else {
        cout << "Posts of " << "'" << Name << "'" << " are:" << endl;
        for (int i = 0; i < size; i++) {
            cout <<" "<< i+1 << ". " ;
            Posts[i]->printStatus();
        }
    }
    cout << endl;
}

void Member::printMember() const {
    cout << "Name: " << Name << endl;
    cout << "Birthday: " << Birthday.day << "/" << Birthday.month << "/" << Birthday.year << endl;
    printFriends();
    printAllPosts();
    printLikedPages();
}

void Member::printTenLatestPosts() const {
    int size = Posts.size();
    cout << "These are your 10 latest posts: " << endl;
    if(size < 10){
        printAllPosts();
    }
    else {
        for (int i = size - 10; i < size; i++) {
            cout << Posts[i]->getContent() << endl;
        }
    }
}

// Getting a friend's name and printing his 10 latest posts
void Member::printFriendsTenLatestPosts(Member *friendToPrintLatestPosts) const{
    cout << "These are the latest posts of : '" << friendToPrintLatestPosts->getName() << "' "<< endl;
    friendToPrintLatestPosts->printTenLatestPosts();
    cout << endl;
}

// Printing all the posts of all the friends
void Member::printTenLatestPostsOfFriends() const{
    int size = Friends.size();
    cout << "These are your 10 latest posts of your friends: " << endl;
    if(size == 0){
        cout << "You have no friends ! " << endl;
    }
    else {
        for (int i = 0; i < size; i++) {
            if (Friends[i]->Posts.size() < 10) {
                Friends[i]->printAllPosts();
            }
            else {
                for (int j = Friends[i]->Posts.size()  - 10; j < Friends[i]->Posts.size() ; j++) {
                    cout << Friends[i]->getPosts()[j]->getContent() << endl;
                }
            }
        }
    }
    cout << endl;
}




