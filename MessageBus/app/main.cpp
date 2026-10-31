#include <QCoreApplication>
#include "messagebus.h"
#include "login.h"
#include "notice.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    MessageBus bus;        // 整个程序共用这一个消息总线。
    SubscribeLogin(&bus); // 通知库：先订阅。
    Login(&bus);          // 登录库：再发布。

    // 本例全部在同一个线程，槽函数会立即执行，无需 app.exec()。
    return 0;
}
