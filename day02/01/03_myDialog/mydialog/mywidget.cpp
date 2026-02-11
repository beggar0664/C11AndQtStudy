#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
//#define Shade 1
//#define Modal 1//模态对话框:关闭该对话框前，不能与同一个程序的其他窗口 交互
//#define NoModal 1//非模态对话框：可以与同一程序中的其他窗口 进行交互
#if 0
void MyWidget::ShowChildDialog()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}
#endif
void MyWidget::on_ShowChild_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent) //1、先显示调用 父类有参构造，对象树机制,为了 传递 parent父对象参数，如果不写，会调用默认构造（无参构造）
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);//2、再执行 这里(派生类构造)

#if Shade
    QDialog dialog(this);//一闪而过， dialog只存在 MyWidget构造函数的范围
    dialog.show();
#elif Modal
    QDialog dialog(this);//模态对话框
    dialog.exec();//exec函数,只有对话框关闭才会返回
#elif NoModal
    QDialog *dialog = new QDialog(this);//非模态对话框
    dialog->show();//dialog 调用完show 后会立即将控制权 交给调用者，程序可以继续往下执行
#endif

    //connect(ui->ShowChild, &QPushButton::clicked, this, &MyWidget::ShowChildDialog);//手动关联
    on_ShowChild_clicked();//自动关联
}

MyWidget::~MyWidget()
{
    delete ui;
}

