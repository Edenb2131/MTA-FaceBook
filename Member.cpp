
#include "Member.h"
#include "FanPage.h"
#include <string>
#include <vector>
using namespace std;

//constructor
Member::Member(const MemberInfo& infoFromUser): Name(infoFromUser.Name), Birthday(infoFromUser.birthDate) {}

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

const Member& Member::operator+=(Member* friendToAdd) { // Add friend operator - required

    this ->addFriend(friendToAdd, false); // false = need to be added to the other friend as well
    return *this;
}

const Member& Member::operator-=(Member* friendToRemove) { // Remove friend operator - required

    this ->removeFriend(friendToRemove);
    return *this;
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

bool Member::operator>(const FanPage &other) const {
    return (this->FanPages.size() > other.getFans().size());
}


// Functions :

void Member::addFriend(Member *friendToAdd, int connected) {
    int i;
    // Checking to see if not trying to add yourself
    if (this == friendToAdd){
        throw MemberException("You cannot friend yourself!");
        
    }
    // Need to add the friend to the friend's friend list as well
    if(!connected){
        friendToAdd->addFriend(this, true);
    }

    //Checking to see if already friends
    int size = this->Friends.size();
    for (i = 0; i < size; i++) {
        if (this->Friends[i]->Name == friendToAdd->Name) {
            throw MemberException("Members are already friends!");
        }
    }
    Friends.push_back(friendToAdd);
}

void Member::removeFriend(Member *friendToRemove, int connected) {

    // Checking to see if not trying to add yourself
    if (this == friendToRemove){
        throw MemberException("You cannot unfriend yourself!");
    }
    int friendsIndex;
    bool found = false;
    int size = this->Friends.size();
    for (friendsIndex = 0; friendsIndex < size; friendsIndex++) {
        if (this->Friends[friendsIndex]->Name == friendToRemove->Name) {
            found = true;
            break;
        }
    }
    if (!found)
        throw MemberException("Friend was not found!");

    Friends.erase(Friends.begin() + friendsIndex);

    if (connected) { // Need to delete the friend to the friend's friend list as well
        friendToRemove->removeFriend(this, false);
    }
}

void Member::likeFanPage(FanPage *fanPageToLike, int connected) {
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

void Member::unlikeFanPage(FanPage *fanPageToUnlike, int connected) {
    int pagesIndex;
    bool found = false;
    int size = this->FanPages.size();
    for (pagesIndex = 0; pagesIndex < size && !found; pagesIndex++) {
        if (FanPages[pagesIndex]->getName() == fanPageToUnlike->getName()) {
            found = true;
            break;
        }
    }
    if (!found) {
        throw MemberException("Fan page was not found!");
    }
   

//  Need to remove the member from the page's fans list as well.
    fanPageToUnlike->removeFan(this, true);
    
    FanPages.erase(FanPages.begin() + pagesIndex);
}

void Member::addPost(string content) {
    Status* newPost = new Status(content);
    Posts.push_back(newPost);
}

void Member::printFriends() const{
    int size = Friends.size();
    if(size == 0){
        cout << "You have no friends! " << endl;
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
        cout << "You have no liked pages!" << endl;
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
        cout << "You have no posts! " << endl;
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

// Printing all the posts of all the friends
void Member::printTenLatestPostsOfFriends() const{
    int size = Friends.size();
    if(size == 0){
        cout << "You have no friends! " << endl;
        return;
    }
    cout << "These are your 10 latest posts of your friends: " << endl;
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
    cout << endl;
}

std::ostream &operator<<(ostream &os, const Member &member) {
    member.printMember();
    return os;
}





