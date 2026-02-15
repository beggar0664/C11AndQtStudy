#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_action.h"
#include <QDebug>
#include <QTextEdit>
#include <QMdiSubWindow>//addSubWindow

#include <QKeySequence>

#include <QToolButton> //工具栏
#include <QSpinBox>//数字盒子
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *menu_tool = ui->menubar->addMenu(tr("工具"));
    menu_tool->addSeparator();
    QAction *action_set = menu_tool->addAction(QIcon(":/picture/175.png"), tr("环境配置"));
    action_set->setShortcut(QKeySequence("ctrl+o"));//绑定快捷键,注意大小写
    connect(action_set, &QAction::triggered, this, &MainWindow::on_action_set_triggered);

    QActionGroup *group = new QActionGroup(this);//动作组 组内是互斥的，只能选一个.
    QAction *action_l = group->addAction(tr("左对齐 shift+l"));
    action_l->setShortcut(QKeySequence("shift+l"));
    action_l->setCheckable(true);
    QAction *action_r = group->addAction(tr("右对齐 shift+r"));
    action_r->setShortcut(QKeySequence("shift+r"));
    action_r->setCheckable(true);
    QAction *action_m = group->addAction(tr("居中对齐 shift+m"));
    action_m->setShortcut(QKeySequence("shift+m"));
    action_m->setCheckable(true);
    menu_tool->addSeparator();//添加 分割线
    menu_tool->addAction(action_l);
    menu_tool->addAction(action_r);
    menu_tool->addAction(action_m);

    my_action *action = new my_action(this);//自定义菜单项
    menu_tool->addAction(action);//将 QLabel QLineEdit 加入，返回  QSplitter
    connect(action, &my_action::SIGNALS_GetTextInfo, this, &MainWindow::SLOT_SetText);

    /*工具栏 mainwindow 右击 "添加工具栏", 工具栏 加插件 都按照 widget添加 */
    QToolButton *tool = new QToolButton(this);
    tool->setText(tr("颜色"));
    ui->toolBar->addWidget(tool);//widget 的派生类 QToolButton
    QMenu *ColorMenu = new QMenu(this);//菜单下 有动作
    ColorMenu->addAction(tr("Red"));
    ColorMenu->addAction(tr("Green"));
    ColorMenu->addAction(tr("Blue"));
    tool->setMenu(ColorMenu);
    /*菜单弹出 方式:
     * DelayedPopup 按住toolButton一定时间（超时取决于样式，请参见QStyle.SH_ToolButton_PopupDelay）后，将显示菜单。
     *  MenuButtonPopup 点击 旁边的 三角 可 弹出，点击本身不弹出
     *  InstantPopup 点击本身即可 弹出
    */
    tool->setPopupMode(QToolButton::DelayedPopup);
    ui->toolBar->addSeparator();//添加 分割线
    QSpinBox *spinbox = new QSpinBox(this);
    ui->toolBar->addWidget(spinbox);

    /* statusbar 状态栏*/
    ui->statusbar->showMessage(tr("欢迎使用多文档编辑器"));//临时状态
    QLabel *parm = new QLabel(this);
    parm->setFrameStyle(QFrame::Box | QFrame::Sunken);
    parm->setText("xx.cxx");
    ui->statusbar->addPermanentWidget(parm);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actiondock_triggered()//默认 停靠
{
    qDebug() << "show dock " << endl;
    ui->dockWidget->show();
}

void MainWindow::on_actionNew_File_triggered()
{
    QTextEdit *text = new QTextEdit(this);
    auto childWindow = ui->mdiArea->addSubWindow(text);
    childWindow->setWindowTitle(tr("mdi 编辑 子窗口"));
    childWindow->show();
}

void MainWindow::on_action_set_triggered()
{
    qDebug() << "on_action_set_triggered !!" << endl;
}

void MainWindow::SLOT_SetText(const QString &string)
{
    qDebug() << "slot recv : " << endl;
    ui->textEdit->setText(string);

}
