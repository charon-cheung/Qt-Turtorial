#ifndef MYEVENT_H
#define MYEVENT_H
#include <QEvent>
#include <QString>
class MyEvent : public QEvent
{

public:
    explicit MyEvent(int m);
    static QEvent::Type t;
};

#endif // MYEVENT_H
