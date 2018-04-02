##Qt使用QWaitCondition实现多线程和线程间通信

Thread_1生产数据，放到缓冲区供Thread_2消费，Thread_2与主线程通信，将每次接收的最后一个数据显示在界面

当生产者生成一些数据时，bufferNotEmpty条件被发射，告诉消费者可以读取它了；当消费者读取一些数据时，bufferNotFull 条件被发射，告诉生产者生成更多的数据。

[Qt多线程同步（生产者-消费者模式 - QWaitCondition实现）](https://yq.aliyun.com/articles/62060)