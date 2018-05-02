#include "test.h"

Test::Test(QObject* obj):
    m_obj(obj)
{

}

void Test::output()
{
    QString strTemp="invoke from Test";
    QMetaObject::invokeMethod(m_obj,"print_on_log",Qt::QueuedConnection, Q_ARG(QString,strTemp));
}
