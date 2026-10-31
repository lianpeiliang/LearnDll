#include "messagebus.h"

MessageBus::MessageBus(QObject *parent) : QObject(parent)
{
}

void MessageBus::publish(const QString &event, const QString &text)
{
    emit message(event, text); // 把消息转发给订阅者。
}
