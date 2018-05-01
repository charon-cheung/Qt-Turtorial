#include "myevent.h"
#include <QDebug>

QEvent::Type MyEvent::t = static_cast<QEvent::Type> (QEvent::registerEventType(QEvent::User+1));
MyEvent::MyEvent(int m)
    :QEvent(t)
{
    qDebug()<<"myevent constructor: "<<m;
}
