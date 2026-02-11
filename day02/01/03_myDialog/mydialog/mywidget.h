#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT
public slots:
    //void ShowChildDialog();//右击 Refactor菜单项, 在XX.cpp添加定义
    void on_ShowChild_clicked();
public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    Ui::MyWidget *ui;
};
#endif // MYWIDGET_H
