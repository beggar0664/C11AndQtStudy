#include<QApplication>
#include"helloDialog.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);//QApplication 类对象 用于管理 应用程序的资源，任何一个QT widgets程序都需要一个 QApplication对象
    helloDialog w;
    w.show();
    return app.exec();//进入事件循环，运行时接收产生的 事件
}
