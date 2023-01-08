#include "FanPage.h"
#include "Member.h"
#include <string>
using namespace std;

//constructor
FanPage::FanPage(string name) :
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

const FanPage& FanPage::operator+=(Member* fanToAdd) { // Add fan operator - required

  this ->addFan(fanToAdd);
  return *this;
}

const FanPage& FanPage::operator-=(Member* fanToRemove){ // Remove fan operator - required

  this -> removeFan(fanToRemove);
  return *this;
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

void FanPage::addPostWithImage(std::string content, std::string image) {
    StatusWithImage* newPost = new StatusWithImage(content, image);
    Posts.push_back(newPost);
}

void FanPage::addPostWithVideo(std::string content, std::string video) {
    StatusWithVideo* newPost = new StatusWithVideo(content, video);
    Posts.push_back(newPost);
}

void FanPage::printAllPosts() const {
    if (Posts.empty()) {
        cout << "No posts for page!" << endl;
        return;
    }
    cout << "Posts for page " << "'" << Name << "'" << " are:" << endl;
    int size = Posts.size();
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
            throw FanPageException("Already likes that fan page!");
        }
    }
    Fans.push_back(fanToAdd);

    // Need to add the page to the member's likes pages list as well
    fanToAdd->likeFanPage(this);
}

void FanPage::removeFan(Member* fanToRemove, bool isConnection) {
    int fansIndex;
    bool found = false;
    int numOfFans = Fans.size();

    
    for (fansIndex = 0; fansIndex < numOfFans; fansIndex++) {
        if (Fans[fansIndex]->getName() == fanToRemove->getName()) {
            found = true;
            break;
        }
    }
    
    if(isConnection){
        Fans.erase(Fans.begin() + fansIndex);
        return;
    }
    
    if (!found)
        throw FanPageException("Fan was not found!");

    
    // Need to remove the page from the member's likes pages list as well
    fanToRemove->unlikeFanPage(this);
    
    Fans.erase(Fans.begin() + fansIndex);
}

void FanPage::printFans() const {
    if (Fans.empty()) {
        cout << "No fans for page!" << endl;
        return;
    }
    int numOfFans = Fans.size();
    cout << "Fans of page " << "'" << Name << "'" << " are:" << endl;
    for (int i = 0; i < numOfFans; i++){
        cout <<" "<< i+1 << ". " << Fans[i]->getName() << endl;
    }
    cout << endl;
}



