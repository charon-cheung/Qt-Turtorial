#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>
#include <QLibraryInfo>
#include <QSettings>
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
    qDebug() << "--------------------------------";
    QSettings *reg = new QSettings("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor",
                                   QSettings::NativeFormat);
    qDebug()<<"CPU processor num: "<<reg->childGroups().length();
    reg = new QSettings("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                                       QSettings::NativeFormat);
    qDebug()<<"CPU info: "<<reg->value("ProcessorNameString").toString();
    return a.exec();
}
