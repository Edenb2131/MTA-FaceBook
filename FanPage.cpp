#include "FanPage.h"
#include "Member.h"

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
   for (i = 0; i < NumOfFans; i++) {
      delete Fans[i];
   }
   delete [] Fans;

   for (i = 0; i < NumOfPosts; i++) {
       delete Posts[i];
   }
   delete [] Posts;

   delete [] Name;
}

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
    for (i = 0; i < NumOfFans; i++) {
        if (strcmp(Fans[i]->getName(), fanToAdd->getName()) == 0) {
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

    //// Need to add the page to the member's likes pages list as well ////
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



