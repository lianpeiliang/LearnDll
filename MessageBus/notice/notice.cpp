#include "notice.h"
#include "messagebus.h"
#include <QDebug>

void SubscribeLogin(MessageBus *bus)
{
    // 订阅总线消息：每次收到消息，都会执行这个 lambda。
    // 这里把 bus 作为连接的上下文，bus 销毁时连接会自动断开。
    QObject::connect(bus, &MessageBus::message, bus,
                     [](const QString &event, const QString &text) {
        if (event == "login_success") {
            qDebug().noquote() << "[Notice] welcome" << text;
        }
    });
}
