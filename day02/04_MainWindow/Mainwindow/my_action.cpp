#include "my_action.h"
#include <QSplitter>
#include <QLabel>
#include <QDebug>
my_action::my_action(QObject *parent):QWidgetAction(parent)//显示调用? 实际是 必须实现 基类的 默认构造
{
    /* 创建行编辑器*/
    PLineEdit_ = new QLineEdit(); //init
    connect(PLineEdit_, &QLineEdit::returnPressed, this, &my_action::SendText);
}

QWidget *my_action::createWidget(QWidget *parent)
{
    // 判断    是否 继承 QMenu QToolBar
    if ( (!parent->inherits("QMenu")) &&  (!parent->inherits("QToolBar")) )
    {
        return 0;
    }
    QSplitter *PSplitter = new QSplitter(parent);
    QLabel *PLabel = new QLabel;
    PLabel->setText("插入文本");
    PSplitter->addWidget(PLabel);
    PSplitter->addWidget(PLineEdit_);
    return PSplitter;
}

void my_action::SendText()
{
    qDebug() << "PLabel : " << PLineEdit_->text() << endl;
    emit SIGNALS_GetTextInfo(PLineEdit_->text());
    PLineEdit_->clear();
}
