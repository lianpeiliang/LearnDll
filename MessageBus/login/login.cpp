#include "login.h"
#include "messagebus.h"
#include <QDebug>

void Login(MessageBus *bus)
{
    qDebug().noquote() << "[Login] login succeeded";

    // 假设登录成功，发布事件，并附带用户名。
    // 登录模块不知道谁会接收这个消息。
    bus->publish("login_success", "Alice");
}
