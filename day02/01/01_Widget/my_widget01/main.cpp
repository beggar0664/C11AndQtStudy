#include <QDebug>
#include <QApplication>
#include <QWidget>
#include <QLabel>
/*vs 的QT tool 只支持msvc 不支持mingw , 需要*/
//#define windows_default 0
#define windows_type 1
//#define windows_flag 1
int main(int argc , char *argv[])
{
    QApplication a(argc, argv);//  管理 应用程序的   资源
#if windows_default
    /*QWidget 类对象，默认parent参数 为 nullptr, 所以是 窗口*/
    QWidget *widget = new QWidget();
#elif  windows_type
    /*QWidget 类对象，默认parent参数 为 nullptr,所以是窗口, Qt::WindowFlags 窗口样式类型改为dialog*/
    QWidget *widget = new QWidget(nullptr, Qt::Dialog);
#elif windows_flag
    /*QWidget 类对象，默认parent参数 为 nullptr,所以是窗口,窗口样式类型改为 FramelessWindowHint 无边框窗口 */
    QWidget *widget = new QWidget(nullptr, Qt::Dialog | Qt::FramelessWindowHint);
#endif
    int x = widget->x();// widget 是指针
    int y = widget->y();
    QRect geometry = widget->geometry();
    QRect frame = widget->frameGeometry();
    qDebug() << "x:" << x << endl;
    /* Q_UNUSED 参数不使用 避免报错 */
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(geometry);
    Q_UNUSED(frame);
    widget->setWindowTitle(QObject::tr("我是widget"));//设置窗口标题
#if windows_default
    /*QLabel 类对象，默认parent参数 为 nullptr,   所以是  窗口*/
    QLabel *label = new QLabel();
#elif windows_type
    /*QLabel 类对象，默认parent参数 为 nullptr,   所以是  窗口, 窗口样式类型改为 SplassScreen 欢迎窗口类型 */
    QLabel *label = new QLabel(nullptr, Qt::SplashScreen);
#elif windows_flag
    /*QLabel 类对象，默认parent参数 为 nullptr,   所以是  窗口, 窗口样式类型改为 WindowStaysOnTopHint 停留所有其他窗口上面 */
    /*使用 alt+3 快捷键来 打开应用程序输出栏 */
    QLabel *label = new QLabel(nullptr, Qt::SplashScreen | Qt::WindowStaysOnTopHint);
#endif
    label->setWindowTitle(QObject::tr("我是label"));
    label->setText(QObject::tr("我是个窗口"));//显示信息
    label->resize(180, 20);//部件大小 绝对定位

    QLabel *label2 = new QLabel(widget);//QLabel 类对象，指定parent参数 为 widget,   所以是部件
    label2->setText(QObject::tr("label2我不是窗口，是部件"));//显示信息
    label2->resize(250, 20);
    /* 显示*/
    label->show();
    widget->show();
    int ret = a.exec();
    delete label;
    delete widget;//QT中销毁父对象时 会自动销毁子对象
    return ret;
}
