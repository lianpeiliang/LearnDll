#pragma once
#include <QObject>
#include <QString>

#ifdef MESSAGEBUS_LIBRARY
#  define MESSAGEBUS_API Q_DECL_EXPORT
#else
#  define MESSAGEBUS_API Q_DECL_IMPORT
#endif

// 消息总线只负责转发消息，不关心谁发送、谁接收。
class MESSAGEBUS_API MessageBus : public QObject
{
    Q_OBJECT

public:
    explicit MessageBus(QObject *parent = nullptr);
    void publish(const QString &event, const QString &text);

signals:
    void message(const QString &event, const QString &text);
};
