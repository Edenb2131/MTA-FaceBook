
#ifndef MTA_FACEBOOK_STATUS_H
#define MTA_FACEBOOK_STATUS_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <utility>

class Status {
    std::string Content;
    time_t pTime;
public:

    //constructor
    Status(std::string content);
    Status(std::string content, time_t time);

    // Operator overloading
    bool operator==(const Status& other) const; // Equality operator - required
    bool operator!=(const Status& other) const; // Inequality operator - required

    //Functions :
    const std::string& getContent() const;
    virtual void printStatus();
    std::string getTimeAsString() const;
    time_t getTime() const;
    void setTime(time_t time);
};


class StatusWithImage : public Status {
    std::string Image;
public:

    StatusWithImage(std::string content, std::string image) : Status(std::move(content)), Image(std::move(image)) {}

    const std::string& getImage() const {
        return Image;
    }
    
    void printStatus() override;
};




class StatusWithVideo : public Status {
    std::string Video;
public:
    StatusWithVideo(std::string content, std::string video) : Status(std::move(content)), Video(std::move(video)) {}

    const std::string& getVideo() const {
        return Video;
    }
    
    void printStatus() override;
};





#endif //MTA_FACEBOOK_STATUS_H