bool QTime::isValid() const

&emsp;&emsp;Returns true if the time is valid; otherwise returns false. For example, the time 23:30:55.746 is valid, but 24:12:30 is invalid.

bool QTime::setHMS(int h, int m, int s, int ms = 0)

&emsp;&emsp;Sets the time to hour h, minute m, seconds s and milliseconds ms.
h must be in the range 0 to 23, m and s must be in the range 0 to 59, and ms must be in the range 0 to 999. Returns true if the set time is valid; otherwise returns false.

void QTime::start()

&emsp;&emsp;Sets this time to the current time. This is practical for timing:
```
QTime t;
t.start();
some_lengthy_task();
qDebug("Time elapsed: %d ms", t.elapsed());
```
