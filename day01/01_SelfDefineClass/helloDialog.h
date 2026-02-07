#ifndef HELLODIALOG_CLASS_H
#define HELLODIALOG_CLASS_H

#include<QDialog>// 需要手动添加 头文件

namespace Ui {//命名空间 Ui
class helloDialog;//声明 helloDialog 类, ui_hello.h中的那个
}// 前置声明 为了加快编译速度。只使用了类对象 指针，不需要该类的完整定义，所以可使用 前置声明
class helloDialog : public QDialog
{
    Q_OBJECT;//拓展 类的功能,比如 信号和槽
public:
    explicit helloDialog(QWidget *parent = nullptr);//显示构造，参数用来指定 父窗口
    ~helloDialog();
private:
    Ui::helloDialog *ui;
};

#endif // HELLODIALOG_CLASS_H
