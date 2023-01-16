#include "UI.h"
#include <exception>
using namespace std;

UI::UI(FaceBook* fb) {
    if (fb != nullptr)
        FB = fb;
    else
        throw FaceBookException("Pointer to faceBook cannot be NULL! ");
}

MenuOptions UI::menu() const {
    cout << endl;
    int choice = -1;
    while(choice < 1 || choice > 20) {
        try {
            cout << "Please choose an action from the list below: " << endl;
            cout << "Enter 1 to register to FaceBook as a member" << endl;
            cout << "Enter 2 to register to FaceBook as a fan page" << endl;
            cout << "Enter 3 to write a post as a member" << endl;
            cout << "Enter 4 to write a post as a fan page" << endl;
            cout << "Enter 5 to see all posts of a member in Facebook" << endl;
            cout << "Enter 6 to see all posts of a fan pages you liked" << endl;
            cout << "Enter 7 to see ten latest posts of your friends" << endl;
            cout << "Enter 8 to add a friend" << endl;
            cout << "Enter 9 to delete a friend" << endl;
            cout << "Enter 10 to like a fan page" << endl;
            cout << "Enter 11 to unlike a fan page" << endl;
            cout << "Enter 12 to see all entities on FaceBook" << endl;
            cout << "Enter 13 to see all your friends" << endl;
            cout << "Enter 14 to see all your liked fan pages" << endl;
            cout << "Enter 15 to see all fans of a fan page" << endl;
            cout << "Enter 16 to compare between two members" << endl;
            cout << "Enter 17 to compare between two fan pages" << endl;
            cout << "Enter 18 to compare between two posts" << endl;
            cout << "Enter 19 to exit" << endl;
        
            cin >> choice;
        
            if (choice < 1 || choice > 19)
                throw FaceBookException("Invalid choice! ");
        }
        catch (FaceBookException &e) {
            cout << e.what() << endl;
            cout << "Exiting the program...." << endl;
            return MenuOptions::Exit;
        }
    }
    return (MenuOptions)choice;
}

void UI::process() {
    bool finish = false;
    MenuOptions choice = menu();

    while (!finish) {
        try {
            switch (choice) {
                case MenuOptions::RegisterToFaceBookAsMember: {
                    FB->addNewMember(getMemberInfoFromUser());
                    break;
                }
                case MenuOptions::RegisterToFaceBookAsFanPage: {
                    FB->addNewPage(getFanPageNameFromUser());
                    break;
                }
                case MenuOptions::WritePostAsMember: {
                    int choiceOfMember = 1;
                    int memberIndex = chooseMember();
                    string s = getStatusFromUser(choiceOfMember);
                    switch (choiceOfMember){
                        case 1: {
                            FB->writePostAsMember(memberIndex, s);
                            break;
                        }
                        case 2: {
                            FB->writePostWithImageAsMember(memberIndex, s, "image");
                            break;
                        }
                        case 3: {
                            FB->writePostWithVideoAsMember(memberIndex, s, "video");
                            break;
                        }
                    }
                    break;
                }
                case MenuOptions::WritePostAsFanPage: {
                    int choiceOfFanPage = 1;
                    int fanPageIndex = chooseFanPage();
                    string s = getStatusFromUser(choiceOfFanPage);
                    switch (choiceOfFanPage){
                        case 1: {
                            FB->writePostAsFanPage(fanPageIndex, s);
                            break;
                        }
                        case 2: {
                            FB->writePostWithImageAsFanPage(fanPageIndex, s, "image");
                            break;
                        }
                        case 3: {
                            FB->writePostWithVideoAsFanPage(fanPageIndex, s, "video");
                            break;
                        }
                    }
                    break;
                }
                case MenuOptions::PrintAllPostOfAMember: {
                    int memberIndex = chooseMember();
                    FB->printAllPostOfAMember(memberIndex);
                    break;
                }
                case MenuOptions::PrintAllPostOfAFanPage: {
                    int memberIndex = chooseMember();
                    FB->printAllPostOfAFanPage(memberIndex);
                    break;
                }
                case MenuOptions::PrintTenLastPostOfAMember: {
                    int memberIndex = chooseMember();
                    FB->printTenLastPostOfAMember(memberIndex);
                    break;
                }
                case MenuOptions::AddAFriend: {
                    cout << "Please choose the first member: " << endl;
                    int firstMemberIndex = chooseMember();
                    cout << "Please choose the second member: " << endl;
                    int secondMemberIndex = chooseMember();
                    FB->connectTwoMembers(firstMemberIndex, secondMemberIndex);
                    break;
                }
                case MenuOptions::DeleteAFriend: {
                    cout << "Please choose the first member: " << endl;
                    int firstMemberIndex = chooseMember();
                    cout << "Please choose the second member: " << endl;
                    int secondMemberIndex = chooseFriendOfMember(*FB->getMembers()[firstMemberIndex]);
                    FB->disconnectTwoMembers(firstMemberIndex, secondMemberIndex);
                    break;
                }
                case MenuOptions::LikeAFanPage: {
                    int memberIndex = chooseMember();
                    int fanPageIndex = chooseFanPage();
                    FB->connectMemberAndFanPage(memberIndex, fanPageIndex);
                    break;
                }
                case MenuOptions::UnLikeAFanPage: {
                    int memberIndex = chooseMember();
                    int fanPageIndex = chooseFanPageOfMember(*FB->getMembers()[memberIndex]);
                    FB->disconnectMemberAndFanPage(memberIndex, fanPageIndex);
                    break;
                }
                case MenuOptions::PrintAllEntitiesAndTheirData: {
                    FB->printAllEntities();
                    FB->printAllEntitiesAndTheirData();
                    break;
                }
                case MenuOptions::PrintAllMembersFriends: {
                    int memberIndex = chooseMember();
                    FB->printAllMembersFriends(memberIndex);
                    break;
                }
                case MenuOptions::PrintAllFanPagesOfMember: {
                    int memberIndex = chooseMember();
                    FB->printAllFanPagesOfMember(memberIndex);
                    break;
                }
                case MenuOptions::PrintAllFansOfAFanPage: {
                    int fanPageIndex = chooseFanPage();
                    FB->printAllFansOfAFanPage(fanPageIndex);
                    break;
                }
                case MenuOptions::CompareTwoMembers: {
                    handleComparingBetweenMembers();
                    break;
                }
                case MenuOptions::CompareTwoFanPages: {
                    handleComparingBetweenFanPages();
                    break;
                }
                case MenuOptions::CompareBetweenPosts: {
                    handleComparingBetweenEntities();
                    break;
                }
                case MenuOptions::Exit: {
                    cout << "Thank you for using FaceBook, hope to see you again soon!" << endl;
                    finish = true;
                    break;
                }
            }
        }

        catch (const MemberException& exp) {
            cout << exp.what() << endl;
        }
        catch (const FanPageException& exp) {
            cout << exp.what() << endl;
        }
        catch (const InvalidInputException& exp) {
            cout << "Invalid input: " << exp.what() << endl;
        }
        
        // This one is for everything else that inherits from exception
        catch (const exception& msg) {
            cout << msg.what() << endl;
        }
        
        //This one is for any error that did not catch by the previous catches
        catch (...) {
            cout << "Unknown error" << endl;
        }
        if (!finish)
            choice = menu();
    }
}

MemberInfo UI::getMemberInfoFromUser() const {
    int day, month, year;
    cin.ignore(); // This is to flush the buffer
    string name;
    cout << "Enter member's name: " << endl;

    // Check if the name is already in the system or name is valid
    getline(cin, name);
    
    checkIfNameIsValid(name);
    checkIfMemberExists(name);
    
    // if name is legal we continue to get the date until its right
    cout << "Enter member's birthday: (Day Month Year)" << endl;

    
    // Here we are not looking for throwing an error, we conclude that the name was OK, so we continue
    cin >> day ;
    cin >> month;
    cin >> year;

    while (day < 1 || day > 31) {
        cout << "Invalid day! Please enter a valid day: " << endl;
        cin >> day;
    }

    while (month < 1 || month > 12) {
        cout << "Invalid month! Please enter a valid month: " << endl;
        cin >> month;
    }

    while (year < 1900 || year > 2022) {
        cout << "Invalid year! Please enter a valid year: " << endl;
        cin >> year;
    }

    cin.ignore(); // This is to flush the buffer

    return MemberInfo(name, Date(day, month, year));
}

bool UI::checkIfMemberExists(const string &name) const {
    for(auto i : FB->getMembers()) {
        //Check to see if there is another member with the same name ( not case-sensitive )
        if (i->getName() == name)
            throw InvalidInputException("Name already exists. Exiting to main menu...");
    }
    return true;
}

bool UI::checkIfNameIsValid(const std::string& name) const{
    if (name.empty())
        throw InvalidInputException("Name is empty. Exiting to main menu...");
    if(name.length() > 30)
        throw InvalidInputException("Name is too long. Exiting to main menu...");
    return true;
}


string UI::getFanPageNameFromUser() const {
    cin.ignore();
    string name;
    cout << "Please enter page's name:" << endl;
    getline(cin, name);
    if (name.empty())
        throw InvalidInputException("Name is empty. Exiting to main menu...");
    if(name.length() > 30)
        throw InvalidInputException("Name is too long. Exiting to main menu...");

    for(int i = 0; i < FB->getFanPages().size(); i++) {
        //Check to see if there is another fan page with the same name ( not case-sensitive )
        if (FB->getFanPages()[i]->getName() == name)
            throw InvalidInputException("Name already exists. Exiting to main menu...");
    }
    return name;
}

int UI::chooseMember() const {
    int index = -1;
    int numOfMembersOverAll = (int)FB->getMembers().size();

    if (numOfMembersOverAll == 0) {
        throw FaceBookException("There are no members using FaceBook! Exiting to main menu...");
    }

    cout << "Please choose a member from the list below:" << endl;
    while (index < 0 || index > numOfMembersOverAll) {
        for (int i = 0; i < numOfMembersOverAll; i++) {
            cout << "Enter " << i + 1 << " for " << FB->getMembers()[i]->getName() << endl;
        }
        cin >> index;
        if(index < 0 || index > numOfMembersOverAll)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

int UI::chooseFriendOfMember(const Member &member) const {
    int index = -1;
    int numOfFriends = (int)member.getFriends().size();
    if (numOfFriends == 0){
        throw MemberException("This member has no friends. Exiting to main menu...");
    }

    cout << "Please choose a member from the list below:" << endl;
    while(index < 0 || index > numOfFriends) {
        for (int i = 0; i < numOfFriends; i++) {
            cout << "Enter " << i + 1 << " for " << member.getFriends()[i]->getName() << endl;
        }
        cin >> index;
        if(index < 0 || index > numOfFriends)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

int UI::chooseStatusOfMember(const Member &member) const {
    int index = -1;
    int numOfStatuses = (int)member.getPosts().size();
    if(numOfStatuses == 0){
        throw MemberException("This member has no statuses. Exiting to main menu...");
    }
    
    cout << "Please choose a status from the list below:" << endl;
    while(index < 0 || index > numOfStatuses) {
        for (int i = 0; i < numOfStatuses; i++) {
            cout << "Enter " << i + 1 << " for " << member.getPosts()[i]->getContent() << endl;
        }
        cin >> index;
        if(index < 0 || index > numOfStatuses)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

int UI::chooseFanPage() const {
    int index = -1;
    int numOfFanPagesOverAll = (int)FB->getFanPages().size();

    if (numOfFanPagesOverAll == 0) {
        throw FanPageException("There are no fan pages using FaceBook! Exiting to main menu...");
    }
    cout << "Please choose a fan page from the list below:" << endl;
    while(index < 0 || index > numOfFanPagesOverAll) {
        for (int i = 0; i < numOfFanPagesOverAll; i++) {
            cout << "Enter " << i + 1 << " for " << FB->getFanPages()[i]->getName() << endl;
        }
        cin >> index;
        if(index < 0 || index > numOfFanPagesOverAll)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

int UI::chooseFanPageOfMember(const Member &member) const {
    int index = -1;
    int numOfFanPages = (int)member.getFanPages().size();
    if(numOfFanPages == 0){
        throw MemberException("This member has no liked fan pages. Exiting to main menu...");
    }

    cout << "Please choose a fan page from the list below:" << endl;
    while(index < 0 || index > numOfFanPages) {
        for (int i = 0; i < numOfFanPages; i++) {
            cout << "Enter " << i + 1 << " for " << member.getFanPages()[i]->getName() << endl;
        }
        cin >> index;
        if(index < 0 || index > numOfFanPages)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

int UI::chooseStatusOfFanPage(const FanPage &fanPage) const {
    int index = -1;
    int numOfStatuses = (int)fanPage.getPosts().size();
    if(numOfStatuses == 0){
        throw FaceBookException("This fan page has no statuses. Exiting to main menu...");
    }
    
    cout << "Please choose a status from the list below:" << endl;
    while(index < 0 || index > numOfStatuses) {
        for (int i = 0; i < numOfStatuses; i++) {
            cout << "Enter " << i + 1 << " for " << fanPage.getPosts()[i]->getContent() << endl;
        }
        cin >> index;
        
        // We want to make sure that the user enters a valid input and no throw to main menu
        if(index < 0 || index > numOfStatuses)
            cout << "Invalid input. Enter again." << endl;
    }
    return index - 1;
}

string UI::getStatusFromUser(int& choice) const {
    
    string post;
    
    cout << "Please chose between a regular post, a post with photo or a post with video" << endl;
    cout << "1. Post" << endl;
    cout << "2. Post with photo" << endl;
    cout << "3. Post with video" << endl;
    cin >> choice;
    
    if( choice < 1 || choice > 3)
        throw InvalidInputException("Invalid input. Exiting to main menu...");
    
    cin.ignore();
    
    cout << "Please enter your status:" << endl;
    getline(cin, post);
    
    if (post.empty())
        throw InvalidInputException("Post is empty. Exiting to main menu...");

    return post;
}

bool UI::handleComparingBetweenEntities() const {
    int firstMemberIndex, secondMemberIndex, firstFanPageIndex, secondFanPageIndex;
    int statusIndexOfFirstMember, statusIndexOfFirstFanPage, statusIndexOfSecondMember, statusIndexOfSecondFanPage;
    Member *firstMember = nullptr, *secondMember = nullptr;
    FanPage *firstFanPage = nullptr, *secondFanPage = nullptr;
    cout << "Do you wish to choose a post from a member or fan page? Enter 1 for member, 2 for fan page." << endl;
    int res1 = 0;
    cin >> res1;
    try {
        if (res1 == 1) {
            cout << "Please choose the first member: " << endl;
            firstMemberIndex = chooseMember();
            statusIndexOfFirstMember = chooseStatusOfMember(*FB->getMembers()[firstMemberIndex]);
            firstMember = FB->getMembers()[firstMemberIndex];
        }
        else if (res1 == 2) {
            cout << "Please choose the first fan page: " << endl;
            firstFanPageIndex = chooseFanPage();
            statusIndexOfFirstFanPage = chooseStatusOfFanPage(*FB->getFanPages()[firstFanPageIndex]);
            firstFanPage = FB->getFanPages()[firstFanPageIndex];
        }
        else
            throw InvalidInputException("selected invalid type.");

        cout << "For the second entity, " ;
        cout << "Do you wish to choose a post from a member or fan page? Enter 1 for member, 2 for fan page." << endl;
        int res2 = 0;
        cin >> res2;
        if (res2 == 1) {
            cout << "Please choose the second member: " << endl;
            secondMemberIndex = chooseMember();
            statusIndexOfSecondMember = chooseStatusOfMember(*FB->getMembers()[secondMemberIndex]);
            secondMember = FB->getMembers()[secondMemberIndex];
        }
        else if (res2 == 2) {
            cout << "Please choose the second fan page: " << endl;
            secondFanPageIndex = chooseFanPage();
            statusIndexOfSecondFanPage = chooseStatusOfFanPage(*FB->getFanPages()[secondFanPageIndex]);
            secondFanPage = FB->getFanPages()[secondFanPageIndex];
        }
        else
            throw InvalidInputException("selected invalid type.");
            
       if(firstMember == nullptr && secondMember == nullptr && firstFanPage == nullptr && secondFanPage == nullptr)
            throw InvalidInputException("nothing was selected for comparison.");
            
            
        if (res1 == 1 && res2 == 1) {
            if (firstMember->getPosts()[statusIndexOfFirstMember]->getContent() == (secondMember->getPosts()[statusIndexOfSecondMember])->getContent())
                cout << "These posts are Identical!" << endl;
            else
                cout << "These post are different..." << endl;
        }
        else if (res1 == 1 && res2 == 2) {
            if (firstMember->getPosts()[statusIndexOfFirstMember]->getContent() == (secondFanPage->getPosts()[statusIndexOfSecondFanPage])->getContent())
                cout << "These posts are Identical!" << endl;
            else
                cout << "These post are different..." << endl;
        }
        else if (res1 == 2 && res2 == 1) {
            if (firstFanPage->getPosts()[statusIndexOfFirstFanPage]->getContent() == (secondMember->getPosts()[statusIndexOfSecondMember])->getContent())
                cout << "These posts are Identical!" << endl;
            else
                cout << "These post are different..." << endl;
        }
        else if (res1 == 2 && res2 == 2) {
            if (firstFanPage->getPosts()[statusIndexOfFirstFanPage]->getContent() == (secondFanPage->getPosts()[statusIndexOfSecondFanPage])->getContent())
                cout << "These posts are Identical!" << endl;
            else
                cout << "These post are different..." << endl;
        }
       
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    return true;
}

bool UI::handleComparingBetweenMembers() const {
    cout << "Please choose the first member: " << endl;
    int firstMemberIndex = chooseMember();
    cout << "Please choose the second member: " << endl;
    int secondMemberIndex = chooseMember();
    
    if (firstMemberIndex == secondMemberIndex) {
        throw InvalidInputException("member indices should be different for comparison. Received " + std::to_string(firstMemberIndex+1) + " twice.");
    }
    
    if (FB->getMembers()[firstMemberIndex]->getFriends().size() > FB->getMembers()[secondMemberIndex]->getFriends().size())
        cout << "The  member: "<<FB->getMembers()[firstMemberIndex]->getName() << " is more popular than " << FB->getMembers()[secondMemberIndex]->getName() << endl;
    else {
        if (FB->getMembers()[firstMemberIndex]->getFriends().size() < FB->getMembers()[secondMemberIndex]->getFriends().size())
            cout << "The  member: "<<FB->getMembers()[secondMemberIndex]->getName() << " is more popular than " << FB->getMembers()[firstMemberIndex]->getName() << endl;
        else
            cout << "Both members have the same number of friends." << endl;
    }
    return true;
}

bool UI::handleComparingBetweenFanPages() const {
    cout << "Please choose the first fan page: " << endl;
    int firstFanPageIndex = chooseFanPage();
    cout << "Please choose the second fan page: " << endl;
    int secondFanPageIndex = chooseFanPage();
    
    if (firstFanPageIndex == secondFanPageIndex)
        throw InvalidInputException("fan page indices should be different for comparison. Received " +
                                    std::to_string(firstFanPageIndex + 1) + " twice.");
    
    if (FB->getFanPages()[firstFanPageIndex]->getFans().size() > FB->getFanPages()[secondFanPageIndex]->getFans().size())
        cout << "The fan page: " << FB->getFanPages()[firstFanPageIndex]->getName() << " is more popular than: "
             << FB->getFanPages()[secondFanPageIndex]->getName() << endl;
    else {
        if (FB->getFanPages()[firstFanPageIndex]->getFans().size() == FB->getFanPages()[secondFanPageIndex]->getFans().size())
            cout << "The fan pages are equally popular." << endl;
        else {
            cout << "The fan page: " << FB->getFanPages()[secondFanPageIndex]->getName() << " is more popular than: "
            << FB->getFanPages()[firstFanPageIndex]->getName() << endl;
        }
    }
    return true;
}









