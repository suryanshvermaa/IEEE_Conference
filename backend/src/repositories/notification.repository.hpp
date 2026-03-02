#include <iostream>
#include <vector>
#include<unordered_map>
using std::string;
using std::vector;
using std::unordered_map;

enum class NotificationType {
    HIGHLIGHTS,
    RECENT_UPDATES,
};


static const unordered_map<NotificationType, std::string> notificationMap = {
    {NotificationType::HIGHLIGHTS, "HIGHLIGHTS"},
    {NotificationType::RECENT_UPDATES, "RECENT_UPDATES"},
};

struct notification
{
    int id;
    string title;
    string description;
    string type;
    string link;
    int priority;
    string createdAt;
};

namespace NotificationRepository{
    int createNotification(const notification &n);
    bool updateNotification(int id,const notification &n);
    bool deleteNotification(int id);
    vector<notification> getNotifications(int page,int limit,const string &type);
    notification getNotification(int id);
}