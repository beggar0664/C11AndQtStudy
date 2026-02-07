/********************************************************************************
** Form generated from reading UI file 'hello.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_H
#define UI_HELLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_helloDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *helloDialog)
    {
        if (helloDialog->objectName().isEmpty())
            helloDialog->setObjectName(QString::fromUtf8("helloDialog"));
        helloDialog->resize(400, 300);
        label = new QLabel(helloDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 150, 54, 12));

        retranslateUi(helloDialog);

        QMetaObject::connectSlotsByName(helloDialog);
    } // setupUi

    void retranslateUi(QDialog *helloDialog)
    {
        helloDialog->setWindowTitle(QCoreApplication::translate("helloDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("helloDialog", "hello\344\275\240\345\245\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helloDialog: public Ui_helloDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_H
