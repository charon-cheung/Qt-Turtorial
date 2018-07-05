#ifndef TEST_H
#define TEST_H
#include <QDebug>

class TestPrivate;
class Test : public QObject
{
    Q_OBJECT
public:
    Test();
    virtual ~Test();
    void foo();
    void setNum(int num);
    int getNum();
private:
    Q_DECLARE_PRIVATE(Test)
    Q_DISABLE_COPY(Test)
    QScopedPointer<TestPrivate> d_ptr;
};

#endif // TEST_H
