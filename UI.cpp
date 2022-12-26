#include "UI.h"
#include "CommonExceptions.h"
#include <exception>
using namespace std;

#define ABNORMAL_NAME_LEN 40

UI::UI(FaceBook* fb) {
    if (fb != nullptr)
        FB = fb;
    else
       // TODO: fix exception;
        throw exception();
}

MenuOptions UI::menu() const {
    cout << endl;
    int choice;
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
                    int memberIndex = chooseMember();
                    FB->writePostAsMember(memberIndex, getStatusFromUser());
                    break;
                }
                case MenuOptions::WritePostAsFanPage: {
                    int fanPageIndex = chooseFanPage();
                    FB->writePostAsFanPage(fanPageIndex, getStatusFromUser());
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
        catch (const UIException& exp) {
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
    getchar();
    string name;
    cout << "Enter member's name: " << endl;

    // Check if the name is already in the system or name is valid
    getline(cin, name);
    if (name.empty())
        throw MemberException("Name is empty. Exiting to main menu...");
    if(name.length() > 30)
        throw MemberException("Name is too long.Exiting to main menu...");

    for(int i = 0; i < FB->getMembers().size(); i++) {
        //Check to see if there is another member with the same name ( not case-sensitive )
        if (FB->getMembers()[i]->getName() == name)
            throw MemberException("Name already exists. Exiting to main menu...");
    }
    // if name is legal we continue to get the date until its right
    cout << "Enter member's birthday: (Day Month Year)" << endl;

    
    // Here we are not looking for throwing an error, we conclude that the name was OK, so we continue
    cin >> day ;
    while (day < 1 || day > 31) {
        cout << "Invalid day! Please enter a valid day: " << endl;
        cin >> day;
    }

    cin >> month ;
    while (month < 1 || month > 12) {
        cout << "Invalid month! Please enter a valid month: " << endl;
        cin >> month;
    }

    cin >> year;
    while (year < 1900 || year > 2022) {
        cout << "Invalid year! Please enter a valid year: " << endl;
        cin >> year;
    }

    cin.ignore(); // This is to flush the buffer

    return MemberInfo(name, Date(day, month, year));
}

string UI::getFanPageNameFromUser() const {
    cin.ignore();
    string name;
    cout << "Please enter page's name:" << endl;
    getline(cin, name);
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
        throw MemberException("This member has no friends.Exiting to main menu...");
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
        throw UIException("This fan page has no statuses. Exiting to main menu...");
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

string UI::getStatusFromUser() const {
    cin.ignore();
    string name;
    cout << "Please enter your status:" << endl;
    getline(cin, name);
    return name;
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
            throw UIException("Invalid input in comparing between entities.");
        
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
            throw UIException("Invalid input in comparing between entities.");
            
       if(firstMember == nullptr && secondMember == nullptr && firstFanPage == nullptr && secondFanPage == nullptr)
            throw UIException("Invalid input in comparing between entities.");
            
            
        if (res1 == 1 && res2 == 1) {
            if (firstMember->getPosts()[statusIndexOfFirstMember] == (secondMember->getPosts()[statusIndexOfSecondMember]))
                cout << "These posts are Identical!" << endl;
            else
                cout << "These post are different..." << endl;
        }
        else if (res1 == 1 && res2 == 2) {
            if (firstMember->getPosts()[statusIndexOfFirstMember] == (secondFanPage->getPosts()[statusIndexOfSecondFanPage]))
                cout << "These posts are Identical!" << endl;
            else
                cout << "These post are different..." << endl;
        }
        else if (res1 == 2 && res2 == 1) {
            if (firstFanPage->getPosts()[statusIndexOfFirstFanPage] == (secondMember->getPosts()[statusIndexOfSecondMember]))
                cout << "These posts are Identical!" << endl;
            else
                cout << "These post are different..." << endl;
        }
        else if (res1 == 2 && res2 == 2) {
            if (firstFanPage->getPosts()[statusIndexOfFirstFanPage] == (secondFanPage->getPosts()[statusIndexOfSecondFanPage]))
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
        throw UIException("member indices should be different for comparison. Received " + std::to_string(firstMemberIndex+1) + " twice.");
    }
    
    if (*FB->getMembers()[firstMemberIndex] > *FB->getMembers()[secondMemberIndex])
        cout << "The first member is more popular than the second member" << endl;
    else
        cout << "The second member is more popular than the first member" << endl;
    
    return true;
}

bool UI::handleComparingBetweenFanPages() const {
    cout << "Please choose the first fan page: " << endl;
    int firstFanPageIndex = chooseFanPage();
    cout << "Please choose the second fan page: " << endl;
    int secondFanPageIndex = chooseFanPage();
    
    if (firstFanPageIndex == secondFanPageIndex)
        throw UIException("fan page indices should be different for comparison. Received "  +  std::to_string(firstFanPageIndex+1) + " twice.");
    
    if (*FB->getFanPages()[firstFanPageIndex] > *FB->getFanPages()[secondFanPageIndex])
        cout << "The first fan page is more popular than the second fan page" << endl;
    else
        cout << "The second fan page is more popular than the first fan page" << endl;
    return true;
}






