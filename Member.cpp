
#include "Member.h"
#include "FanPage.h"

//constructor
Member::Member(Info infoFromUser): // Using here c'tor init line
    Name(infoFromUser.Name),
    Birthday(infoFromUser.birthDate)
{
    Friends = nullptr;
    NumOfFriends = 0,
    Posts = nullptr;
    NumOfPosts = 0;
    FanPages =nullptr;
    NumOfFanPages = 0;
}

//constructor
Member::Member(const char* name, int day, int month, int year) :
    Name(strdup(name)),
    Birthday(),
    Friends(nullptr),
    NumOfFriends(0),
    Posts(nullptr),
    NumOfPosts(0),
    FanPages(nullptr),
    NumOfFanPages(0)
{
    Birthday.day = day;
    Birthday.month = month;
    Birthday.year = year;
}

//destructor
Member::~Member() {
    int i;
    for (i = 0; i < NumOfFriends; i++) {
        delete Friends[i];
    }
    delete [] Friends;

    for (i = 0; i < NumOfPosts; i++) {
        delete Posts[i];
    }
    delete [] Posts;

    for (i = 0; i < NumOfFanPages; i++) {
        delete FanPages[i];
    }
    delete FanPages;

    delete [] Name;
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

FanPage** Member::getFanPages() const {
    return FanPages;
}

int Member::getNumOfFanPages() const {
    return NumOfFanPages;
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

void Member::setFanPages(FanPage** fanPages) {
    FanPages = fanPages;
}

void Member::setNumOfFanPages(int numOfFanPages) {
    NumOfFanPages = numOfFanPages;
}

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
    for (i = 0; i < this->NumOfFriends; i++) {
        if (strcmp (this->Friends[i]->Name, friendToAdd->Name) == 0) {
            cout << "Already friends !" << endl;
            return;
        }
    }

    Member **temp = new Member *[NumOfFriends + 1];
    for (i = 0; i < NumOfFriends; i++) {
        temp[i] = Friends[i];
    }

    temp[NumOfFriends] = friendToAdd;
    delete[] Friends;
    Friends = temp;
    NumOfFriends++;



}

void Member::removeFriend(Member *friendToRemove) {
    int friendsIndex;
    bool found = false;
    // Check if possible in Theta(1)
    for (friendsIndex = 0; friendsIndex < this->NumOfFriends; friendsIndex++) {
        if (strcmp (this->Friends[friendsIndex]->Name, friendToRemove->Name) != 0) {
            found = false;
        }
        else {
            found = true;
            break;
        }
    }

    if (!found)
        return;

    Member **temp = new Member *[NumOfFriends - 1];
    int tempIndex = 0;
    for (friendsIndex = 0; friendsIndex < NumOfFriends; friendsIndex++) {
        if (strcmp (this->Friends[friendsIndex]->Name, friendToRemove->Name) != 0){
            temp[tempIndex] = Friends[friendsIndex];
            tempIndex++;
        }
    }
    delete[] Friends;
    Friends = temp;
    NumOfFriends--;

    //// Need to remove the friend from the friend's friend list as well ////
    friendToRemove->removeFriend(this);
}

void Member::likeFanPage(FanPage *fanPageToLike) {
    int i;

    // Checking to see if needed to add that fan-page or not
    for (i = 0; i < NumOfFanPages; i++) {
        if (strcmp (FanPages[i]->getName(), fanPageToLike->getName()) == 0) {
            return;
        }
    }

    FanPage** temp = new FanPage * [NumOfFanPages + 1];
    for (i = 0; i < NumOfFanPages; i++) {
        temp[i] = FanPages[i];
    }
    temp[NumOfFanPages] = fanPageToLike;
    delete [] FanPages;
    FanPages = temp;
    NumOfFanPages++;

    // Need to add the member to the page's fans as well
    fanPageToLike->addFan(this);
}

void Member::unlikeFanPage(FanPage *fanPageToUnlike) {
    int pagesIndex;
    bool found = false;
    for (pagesIndex = 0; pagesIndex < NumOfFanPages; pagesIndex++) {
        if (strcmp (FanPages[pagesIndex]->getName(), fanPageToUnlike->getName()) != 0) {
            found = false;
        }
        else {
            found = true;
            break;
        }
    }

    if (!found)
        return;

    FanPage** temp = new FanPage * [NumOfFanPages - 1];
    int tempIndex = 0;
    for (pagesIndex = 0; pagesIndex < NumOfFanPages; pagesIndex++) {
        if (strcmp (FanPages[pagesIndex]->getName(), fanPageToUnlike->getName()) != 0) {
            temp[pagesIndex] = FanPages[pagesIndex];
            tempIndex++;
        }
    }

    delete [] FanPages;
    FanPages = temp;
    NumOfFanPages--;

    //// Need to remove the member from the page's fans list as well ////
    fanPageToUnlike->removeFan(this);
}

void Member::addPost() {
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

void Member::printLikedPages() {
    if (NumOfFanPages == 0) {
        cout << "You have no liked pages !" << endl;
    }
    else {
        cout << "Liked pages of " << "'" << Name << "'" << " are: " ;
        int i;
        for (i = 0; i < NumOfFanPages - 1; i++)
            cout << FanPages[i]->getName() << ", " ;

        cout << FanPages[i]->getName() << endl ;
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
    printLikedPages();
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




