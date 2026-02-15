#ifndef MY_ACTION_H
#define MY_ACTION_H

#include<QLineEdit>
#include<QObject>
#include <QWidgetAction>
/*
 *
 * 动态多态: 基类 指针 调用 虚函数
 * 重写 override  QWidgetAction -> createWidget
*/
class my_action : public QWidgetAction
{
    Q_OBJECT
signals:/*信号和槽 本质都是 槽函数*/
    void SIGNALS_GetTextInfo(const QString &string);
public:
    my_action(QObject *parent = nullptr);//无参构造 默认值,有参构造
protected:// createWidget 可写为别的权限
    virtual QWidget* createWidget(QWidget* parent);
private:
    QLineEdit *PLineEdit_;

private slots://槽函数
    void SendText();

};

#endif // MY_ACTION_H
