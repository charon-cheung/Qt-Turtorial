#ifndef TEST_P_H
#define TEST_P_H
#include "test.h"
class TestPrivate
{
public:
    TestPrivate(Test *parent);
    Test* q_ptr;
private:
    Q_DECLARE_PUBLIC(Test)
    int m_num;
};
#endif // TEST_P_H
