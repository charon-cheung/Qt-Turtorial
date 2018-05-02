#ifndef TEST_H
#define TEST_H
#include <QDebug>
#include <QObject>
class Test
{

public:
    Test(QObject* obj);
    void output();
private:
    int m_num;
    QObject* m_obj;
};

#endif // TEST_H
