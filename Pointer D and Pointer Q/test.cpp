#include "test.h"
#include "test_p.h"

Test::Test():
    d_ptr(new TestPrivate(this))
{
    Q_D(Test);
    d->q_ptr = this;
    qDebug()<<"construct";
}

Test::~Test()
{
    qDebug()<<"destruct";
}

void Test::foo()
{
    qDebug()<<"foo";
}

void Test::setNum(int num)
{
    Q_D(Test);
    d->m_num = num;
}

int Test::getNum()
{
    Q_D(Test);
    return d->m_num;
}

TestPrivate::TestPrivate(Test *parent)
{
    Q_Q(TestPrivate);
    q_ptr = parent;
}
