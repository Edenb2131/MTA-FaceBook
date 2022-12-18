#include "FanPage.h"
#include "Member.h"
#include <string>

using namespace std;

//constructor
FanPage::FanPage(char *name) :  // Using here c'tor init line
    Name(strdup(name))
{
    Fans = nullptr;
    NumOfFans = 0,
    Posts = nullptr,
    NumOfPosts = 0;
}

//destructor
FanPage::~FanPage() {
  int i;

  delete[] Fans;   //No need to delete every one because thats happning in the FaceBook d'tor

  for (i = 0; i < NumOfPosts; i++) {
    delete Posts[i];
  }
  delete[] Posts;

  delete[] Name;
}

// Getters :

char *FanPage::getName() const {
    return Name;
}

Member **FanPage::getFans() const {
    return Fans;
}

int FanPage::getNumOfFans() const {
    return NumOfFans;
}

Status** FanPage::getPosts() const {
    return Posts;
}

int FanPage::getNumOfPosts() const {
    return NumOfPosts;
}

// Setters :

void FanPage::setName( char *name) {
    Name = name;
}

void FanPage::setFans(Member **fans) {
    Fans = fans;
}

void FanPage::setNumOfFans(int numOfFans){
    NumOfFans = numOfFans;
}

void FanPage::setPosts(Status **posts) {
    Posts = posts;
}

void FanPage::setNumOfPosts(int numOfPosts) {
    NumOfPosts = numOfPosts;
}


// Operators :

void FanPage::operator+=(Member* fanToAdd) { // Add fan operator - required

  this ->addFan(fanToAdd);
}

void FanPage::operator-=(Member* fanToRemove){ // Remove fan operator - required

  this -> removeFan(fanToRemove);
}

bool FanPage::operator>(const FanPage& other) const{ // Greater than operator - required

  return (this-> getNumOfFans() > other.getNumOfFans());
}

bool FanPage::operator<(const FanPage& other) const{ // Less than operator - required

  return (this-> getNumOfFans() < other.getNumOfFans());
}

bool FanPage::operator>=(const FanPage& other) const{

  return (this-> getNumOfFans() >= other.getNumOfFans());
}

bool FanPage::operator<=(const FanPage& other) const{

  return (this-> getNumOfFans() <= other.getNumOfFans());
}


// Functions :

void FanPage::addPost() {
    getchar();
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

void FanPage::addPost(const char* content) {
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

void FanPage::printAllPosts() const {
    cout << "Posts for page " << "'" << Name << "'" << " are:" << endl;
    for (int i = 0; i < NumOfPosts; i++){
        cout <<" "<< i+1 << ". " ;
        Posts[i]->printStatus();
    }
    cout << endl;
}

void FanPage::printFanPage() const {
    cout << "FanPage name is: " << Name << endl;
    cout << "Number of fans: " << NumOfFans << endl;
    cout << "Number of posts: " << NumOfPosts << endl;
    cout << endl;
}

void FanPage::addFan(Member* fanToAdd) {
    int i;

    // Checking to see if needed to add that friend or not
    for (i = 0; i < NumOfFans; i++) {
        if (strcmp(Fans[i]->getName(), fanToAdd->getName()) == 0) {
            cout << "Already likes that fan page!" << endl;
            return;
        }
    }

    Member** temp = new Member * [NumOfFans + 1];
    for (i = 0; i < NumOfFans; i++) {
        temp[i] = Fans[i];
    }

    temp[NumOfFans] = fanToAdd;
    delete [] Fans;
    Fans = temp;
    NumOfFans++;

    // Need to add the page to the member's likes pages list as well
    fanToAdd->likeFanPage(this);
}

void FanPage::removeFan(Member* fanToRemove) {
    int fansIndex;
    bool found = false;

    for (fansIndex = 0; fansIndex < NumOfFans; fansIndex++) {
        if (strcmp(Fans[fansIndex]->getName(), fanToRemove->getName()) != 0) {
            found = false;
        }
        else {
            found = true;
            break;
        }
    }

    if (!found)
        return;

    Member** temp = new Member * [NumOfFans - 1];
    int tempIndex = 0;
    for (fansIndex = 0; fansIndex < NumOfFans; fansIndex++) {
        if (strcmp(Fans[fansIndex]->getName(), fanToRemove->getName()) != 0) {
            temp[tempIndex] = Fans[fansIndex];
            tempIndex++;
        }
    }

    delete [] Fans;
    Fans = temp;
    NumOfFans--;

    //// Need to remove the page from the member's likes pages list as well ////
    fanToRemove->unlikeFanPage(this);
}

void FanPage::printFans() const {

    cout << "Fans of page " << "'" << Name << "'" << " are:" << endl;
    for (int i = 0; i < NumOfFans; i++){
        cout <<" "<< i+1 << ". " ;
        Fans[i]->printMember();
    }
    cout << endl;
}

