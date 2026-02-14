/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *color;
    QPushButton *files;
    QPushButton *intData;
    QPushButton *floatData;
    QPushButton *item;
    QPushButton *message;
    QPushButton *progress;
    QPushButton *Wizrd;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        color = new QPushButton(centralwidget);
        color->setObjectName(QString::fromUtf8("color"));
        color->setGeometry(QRect(60, 50, 75, 23));
        files = new QPushButton(centralwidget);
        files->setObjectName(QString::fromUtf8("files"));
        files->setGeometry(QRect(200, 50, 75, 23));
        intData = new QPushButton(centralwidget);
        intData->setObjectName(QString::fromUtf8("intData"));
        intData->setGeometry(QRect(340, 50, 91, 23));
        floatData = new QPushButton(centralwidget);
        floatData->setObjectName(QString::fromUtf8("floatData"));
        floatData->setGeometry(QRect(490, 50, 121, 23));
        item = new QPushButton(centralwidget);
        item->setObjectName(QString::fromUtf8("item"));
        item->setGeometry(QRect(60, 130, 75, 23));
        message = new QPushButton(centralwidget);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(190, 140, 75, 23));
        progress = new QPushButton(centralwidget);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setGeometry(QRect(320, 130, 75, 23));
        Wizrd = new QPushButton(centralwidget);
        Wizrd->setObjectName(QString::fromUtf8("Wizrd"));
        Wizrd->setGeometry(QRect(510, 130, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        color->setText(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262", nullptr));
        files->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        intData->setText(QCoreApplication::translate("MainWindow", "\346\225\264\345\275\242\346\225\260\345\255\227int", nullptr));
        floatData->setText(QCoreApplication::translate("MainWindow", "\346\265\256\347\202\271\346\225\260\345\255\227float", nullptr));
        item->setText(QCoreApplication::translate("MainWindow", "\346\235\241\347\233\256", nullptr));
        message->setText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272", nullptr));
        progress->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\272\246", nullptr));
        Wizrd->setText(QCoreApplication::translate("MainWindow", "\345\220\221\345\257\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
