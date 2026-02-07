#include "helloDialog.h"//helloDialog 类 声明
#include "ui_hello.h"//helloDialog 类 定义
#if 0
helloDialog::helloDialog(QWidget *parent):
    QDialog(parent)
{
    ui = new Ui::helloDialog;// 创建对象
    ui->setupUi(this);//为现在这个类 代表的对话框 创建界面
}
#else
helloDialog::helloDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::helloDialog)// 创建 自定义类-- [ helloDialog ]对象
{
    ui->setupUi(this);//为现在这个类 代表的对话框 创建界面
}
#endif
helloDialog::~helloDialog()
{
    delete ui;
}
