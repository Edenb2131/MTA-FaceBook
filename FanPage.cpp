#include "FanPage.h"
#include "Member.h"
#include <string>
using namespace std;

//constructor
FanPage::FanPage(string name) :  // Using here c'tor init line
    Name(name) {}

// Getters :

string FanPage::getName() const {
    return Name;
}

vector<Member*> FanPage::getFans() const {
    return Fans;
}

vector<Status*> FanPage::getPosts() const {
    return Posts;
}


// Operators :

void FanPage::operator+=(Member* fanToAdd) { // Add fan operator - required

  this ->addFan(fanToAdd);
}

void FanPage::operator-=(Member* fanToRemove){ // Remove fan operator - required

  this -> removeFan(fanToRemove);
}

bool FanPage::operator>(const FanPage& other) const{ // Greater than operator - required

  return (this-> Fans.size() > other.Fans.size());
}

bool FanPage::operator<(const FanPage& other) const{ // Less than operator - required

    return (this-> Fans.size() < other.Fans.size());
}

bool FanPage::operator>=(const FanPage& other) const{

    return (this-> Fans.size() >= other.Fans.size());
}

bool FanPage::operator<=(const FanPage& other) const{

    return (this-> Fans.size() <= other.Fans.size());
}


// Functions :

void FanPage::addPost(string content) {
    Status* newPost = new Status(content);
    Posts.push_back(newPost);
}

void FanPage::printAllPosts() const {
    int size = Posts.size();
    cout << "Posts for page " << "'" << Name << "'" << " are:" << endl;
    for (int i = 0; i < size; i++){
        cout <<" "<< i+1 << ". " ;
        Posts[i]->printStatus();
    }
    cout << endl;
}

void FanPage::printFanPage() const {
    int numOfPosts = Posts.size();
    int numOfFans = Fans.size();
    cout << "FanPage name is: " << Name << endl;
    cout << "Number of fans: " << numOfFans << endl;
    cout << "Number of posts: " << numOfPosts << endl;
    cout << endl;
}

void FanPage::addFan(Member* fanToAdd) {
    int i;
    int numOfFans = Fans.size();

    // Checking to see if needed to add that friend or not
    for (i = 0; i < numOfFans; i++) {
        if (Fans[i]->getName() == fanToAdd->getName()) {
            cout << "Already likes that fan page!" << endl;
            return;
        }
    }
    Fans.push_back(fanToAdd);

    // Need to add the page to the member's likes pages list as well
    fanToAdd->likeFanPage(this);
}

void FanPage::removeFan(Member* fanToRemove) {
    int fansIndex;
    bool found = false;
    int numOfFans = Fans.size();

    for (fansIndex = 0; fansIndex < numOfFans; fansIndex++) {
        if (Fans[fansIndex]->getName() != fanToRemove->getName()) {
            found = false;
        }
        else {
            found = true;
            break;
        }
    }

    if (!found)
        return;

    Fans.erase(Fans.begin() + fansIndex);

    //// Need to remove the page from the member's likes pages list as well ////
    fanToRemove->unlikeFanPage(this);
}

void FanPage::printFans() const {
    int numOfFans = Fans.size();
    cout << "Fans of page " << "'" << Name << "'" << " are:" << endl;
    for (int i = 0; i < numOfFans; i++){
        cout <<" "<< i+1 << ". " << Fans[i]->getName() << endl;
    }
    cout << endl;
}

