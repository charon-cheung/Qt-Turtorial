#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "full architecture:" << QSysInfo::buildAbi();
    qDebug() << "cpu architecture:" << QSysInfo::buildCpuArchitecture();
    qDebug() << "current cpu architecture:" << QSysInfo::currentCpuArchitecture();
    qDebug() << "kernel type:" << QSysInfo::kernelType();
    qDebug() << "kernel version:" << QSysInfo::kernelVersion();
    qDebug() << "host name:" << QSysInfo::machineHostName();
    qDebug() << "product type:" << QSysInfo::productType();
    qDebug() << "product version:" << QSysInfo::productVersion();
    qDebug() << "word size:" << QSysInfo::WordSize;
    qDebug() << "windows version:" << QSysInfo::windowsVersion()<<"\n";
    qDebug() << "--------------------------------";
    qDebug() << "Qt exc path:"<<QLibraryInfo::location(QLibraryInfo::LibraryExecutablesPath);
    qDebug() << "Qt version: "<<QLibraryInfo::version().toString();
    if(QLibraryInfo::isDebugBuild())
        qDebug() << "app is debug build";
    else
        qDebug() << "app is release build";
    qDebug() << "Full build info: "<<QString(QLibraryInfo::build());
    return a.exec();
}
