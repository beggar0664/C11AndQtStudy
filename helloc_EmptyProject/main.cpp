#include<QApplication>
#include<QDialog>
#include<QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);//QApplication 类对象 用于管理 应用程序的资源，任何一个QT widgets程序都需要一个 QApplication对象
    QDialog w;//对话框
    QLabel label(&w);// 对话框是它的父窗口，标签 放在对话框 窗口里
    label.setText("hello");//显示的内容
    w.show();//显示对话框
    return app.exec();//进入事件循环，运行时接收产生的 事件
}
