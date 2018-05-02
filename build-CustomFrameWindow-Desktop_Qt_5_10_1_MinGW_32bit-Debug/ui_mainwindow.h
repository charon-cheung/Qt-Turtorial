/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *min;
    QPushButton *max;
    QPushButton *close;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(733, 579);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        min = new QPushButton(centralWidget);
        min->setObjectName(QStringLiteral("min"));
        min->setGeometry(QRect(480, 20, 45, 45));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Min.png"), QSize(), QIcon::Normal, QIcon::Off);
        min->setIcon(icon);
        min->setIconSize(QSize(45, 45));
        min->setFlat(true);
        max = new QPushButton(centralWidget);
        max->setObjectName(QStringLiteral("max"));
        max->setGeometry(QRect(560, 30, 45, 45));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Max.png"), QSize(), QIcon::Normal, QIcon::Off);
        max->setIcon(icon1);
        max->setIconSize(QSize(45, 45));
        max->setAutoRepeatDelay(300);
        max->setFlat(true);
        close = new QPushButton(centralWidget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(650, 10, 45, 45));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Closed.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon2);
        close->setIconSize(QSize(45, 45));
        close->setFlat(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        min->setText(QString());
        max->setText(QString());
        close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
