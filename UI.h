#ifndef MTA_FACEBOOK_UI_H
#define MTA_FACEBOOK_UI_H
#include "FaceBook.h"
#include "Common.h"

class UI {
private:
  FaceBook* FB;

public:
    UI(FaceBook* fb);

    int menu() const;
    void process();
    MemberInfo getMemberInfoFromUser();




};


#endif //MTA_FACEBOOK_UI_H
