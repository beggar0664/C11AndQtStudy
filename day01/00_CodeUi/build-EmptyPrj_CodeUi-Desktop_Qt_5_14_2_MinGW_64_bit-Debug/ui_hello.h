/********************************************************************************
** Form generated from reading UI file 'hello.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_H //预处理命令 防止头文件重复包含
#define UI_HELLO_H //预处理命令
//模版 [ Qt Designer Form ]
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE //QT 命名空间 开始宏

class Ui_helloDialog//定义 类，类名为 对话框类对象的名称前加 "Ui_"字符
{
public:
    QLabel *label;//QLabel 对象指针，对话框窗口 添加的 label 对象

    void setupUi(QDialog *helloDialog)//该函数用来 生成界面, 因为选择的模板 使用的是 对话框，所以函数参数是 QDialog 类型
    {
        if (helloDialog->objectName().isEmpty())
            helloDialog->setObjectName(QString::fromUtf8("helloDialog"));//设置对话框 的对象名称
        helloDialog->resize(400, 300);// 设置 窗口大小
        label = new QLabel(helloDialog);//在对话框上 创建标签对象
        label->setObjectName(QString::fromUtf8("label"));//设置 标签对象 的名称
        label->setGeometry(QRect(120, 120, 54, 12));//设置 标签对象 的大小和位置

        retranslateUi(helloDialog);

        QMetaObject::connectSlotsByName(helloDialog);//使得 窗口中的部件 可以实现 按对象名 进行信号和槽 的关联 
    } // setupUi

    void retranslateUi(QDialog *helloDialog)//对 窗口里的 字符串进行 编码转换 功能
    {
        helloDialog->setWindowTitle(QCoreApplication::translate("helloDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("helloDialog", "hello\344\275\240\345\245\275", nullptr));
    } // retranslateUi

};

namespace Ui {//命名空间
    class helloDialog: public Ui_helloDialog {};//定义 helloDialog 类，继承自 Ui_helloDialog
} // namespace Ui

QT_END_NAMESPACE //QT 命名空间 结束宏

#endif // UI_HELLO_H //预处理命令
