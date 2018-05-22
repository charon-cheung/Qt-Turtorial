#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString hostName = QHostInfo::localHostName();      // 获得主机名
    QHostInfo info = QHostInfo::fromName(hostName);
    // QHostAddress::LocalHost是127.0.0.1, 不是本机IP
    foreach(QHostAddress addr, info.addresses())     // 相当于 ipconfig /all
    {
        if(addr.protocol()==QAbstractSocket::IPv4Protocol)
        {
            qDebug()<<"IPV4 addr: "<<addr.toString();
            qDebug()<<"quint32 IPV4 addr: "<<addr.toIPv4Address();
        }
        else if(addr.protocol()==QAbstractSocket::IPv6Protocol)
        {
            qDebug()<<"IPV6 addr: "<<addr.toString();
        }
    }
    qDebug()<<"---------------------------";
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface interface, list)
    {
        // 例如“以太网”，“蓝牙网络连接 4”
        qDebug()<<"readable name:  "<<interface.humanReadableName();
        qDebug()<<"Name: "<<interface.name();
        qDebug()<<"Hardware Addr: "<<interface.hardwareAddress();   // MAC地址
        // 遍历所有网络接口，如果只需要IP，可用allAddresses
        foreach (QNetworkAddressEntry entry, interface.addressEntries())
        {
            qDebug()<<QStringLiteral("广播地址: ")<<entry.broadcast().toString();
            qDebug()<<"netmask: "<<entry.netmask().toString();
            qDebug()<<"ip: "<<entry.ip().toString();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
