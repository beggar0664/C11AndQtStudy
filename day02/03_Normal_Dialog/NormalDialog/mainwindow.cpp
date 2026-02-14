#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>//文件 对话框

#include <QStringList>
#include <QInputDialog>//输入对话框

#include <QMessageBox>//提示对话框

#include <QProgressDialog>//进度对话框

#include <QWizard>
#include <QLabel>
#include <QVBoxLayout>
#include <QButtonGroup>//按键组
#include <QRadioButton>//单选 按钮
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_color_clicked()
{
    QColorDialog ColorDlg;
    ColorDlg.exec();
    QColor Color = ColorDlg.currentColor();
    qDebug() << "color is " << Color << endl;
}
//文件对话框
void MainWindow::on_files_clicked()
{
    QString path = QDir::currentPath();
    QString title = tr("文件对话框");
    QString filter = tr("文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)");
    QString aFileName=QFileDialog::getOpenFileName(this,title,path,filter);

    qDebug() << aFileName << endl;
}
/*
 * 输入对话框分几种，
 * 包括文本输入对话框，整数输入对话框，浮点数输入对话框，条目输入对话框,提示对话框。
 *  先看看文本输入对话框
*/

//条目输入对话框
void MainWindow::on_item_clicked()
{
    QStringList items;
    items << tr("条目一") << tr("条目二");
    bool ok = false;
    auto itemdata = QInputDialog::getItem(this, tr("条目对话框"), tr("输入或选择条目") ,items, 0, true, &ok);
    if(ok){
        qDebug() << "item is" << items << endl;
    }
}

//整形数据 输入对话框
void MainWindow::on_intData_clicked()
{
    bool ok = false;
    auto data = QInputDialog::getInt(this, tr("整形数据 输入对话框--InputDialog"), tr("请输入整形的数据:"),
                                     0, -200, 200, 1, &ok);//value为默认值
    if(ok == true){
        qDebug() << "input Int data is " << data << endl;
    }
}
//浮点数输入对话框
void MainWindow::on_floatData_clicked()
{
    bool ok = false;
    auto data = QInputDialog::getDouble(this, tr("浮点形数据 输入对话框--InputDialog"), tr("请输入浮点形的数据:"),
                                     0, -127 , 128, 1, &ok);
    if(ok == true){
        qDebug() << "input Double data is " << data << endl;
    }
}
//提示对话框
void MainWindow::on_message_clicked()
{
    auto ret1 = QMessageBox::question( this, tr("提示对话框"), tr("question:你是单身吗"),
                            QMessageBox::Yes, QMessageBox::No);
    if(ret1 == QMessageBox::Yes || ret1 == QMessageBox::No){
             qDebug() << "ret is " << ret1 << endl;
    }

    auto ret2 = QMessageBox::information( this, tr("通知对话框"), tr("information:你好"),
                            QMessageBox::Ok);
    if(ret2 == QMessageBox::Ok){
             qDebug() << "ret is " << ret1 << endl;
    }

    auto ret3 = QMessageBox::warning(this,tr("警告对话框"),tr("warning：！！！"),QMessageBox::Ok);
    if(ret3 == QMessageBox::Ok){
        qDebug() << "ret3 is " << ret3 << endl;
    }

    auto ret4 = QMessageBox::critical(this,tr("关键提示对话框"), tr("critical:你在追寻什么?"),QMessageBox::Ok);
    if(ret4 == QMessageBox::Ok){
        qDebug() << "ret4 is " << ret4 << endl;
    }
}
/*
* 进度对话框，QProgressDialog
*
*/

void MainWindow::on_progress_clicked()
{
#if 0
    // 进度提示框一闪而逝，不是逻辑问题，是5000量级太小了
        QProgressDialog progressDialog(tr("正在复制"),tr("取消复制"),0,5000,this);
        progressDialog.setWindowTitle(tr("文件复制进度对话框"));
        progressDialog.setWindowModality(Qt::ApplicationModal);
        progressDialog.show();

        for(int i = 0; i < 5000; i++){
            progressDialog.setValue(i);
            QApplication::processEvents();
            if(progressDialog.wasCanceled()){
                break;
            }
        }
        progressDialog.setValue(5000);
#else
    //改用定时器
    _progressDialog = new QProgressDialog(tr("正在复制"),tr("取消复制"),0,5000,this);
    _progressDialog->setWindowTitle(tr("文件复制进度对话框"));
    _progressDialog->setWindowModality(Qt::ApplicationModal);
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &MainWindow::on_updateProgressDialog);
    connect(_progressDialog, &QProgressDialog::canceled, this, &MainWindow::on_cancelProgressDialog);
    _timer->start(2);
    qDebug("复制结束");
#endif
}


void MainWindow::on_updateProgressDialog()
{
    _count++;
    if(_count > 5000){
        _timer->stop();
        delete  _timer;
        _timer = nullptr;
        delete _progressDialog;
        _progressDialog = nullptr;
        _count = 0;
        return;
    }
    _progressDialog->setValue(_count);
}

void MainWindow::on_cancelProgressDialog(){
    _timer->stop();
    delete  _timer;
    _timer = nullptr;
    delete _progressDialog;
    _progressDialog = nullptr;
    _count = 0;
    return;
}

/*
* 引导用户操作时可以采用向导对话框 QWizard
*/

void MainWindow::on_Wizrd_clicked()
{
    QWizard wizard(this);
    QWizardPage* page1 = new QWizardPage();
    page1->setTitle(tr("婚恋介绍引导程序"));
    auto label1 = new QLabel();
    label1->setText(tr("该程序帮助您找到人生伴侣"));
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label1);
    page1->setLayout(layout);
    wizard.addPage(page1);
    QWizardPage* page2 = new QWizardPage();//第二个 页面
    page2->setTitle("选择心动类型");

    QButtonGroup *group = new QButtonGroup(page2);//按键 组
    QRadioButton * btn1 = new QRadioButton();//单选 按钮
    btn1->setText("白富美");
    group->addButton(btn1);//将一个 现有的 按钮添加到 QButtonGroup 中进行管理
    QRadioButton * btn2 = new QRadioButton();
    btn2->setText("萝莉");
    group->addButton(btn2);
    QRadioButton * btn3 = new QRadioButton();
    btn3->setText("御姐");
    group->addButton(btn3);
    QRadioButton * btn4 = new QRadioButton();
    btn4->setText("小家碧玉");
    group->addButton(btn4);
    QRadioButton * btn5 = new QRadioButton();
    btn5->setText("女汉子");
    group->addButton(btn5);

    QRadioButton * btn6 = new QRadioButton();
    btn6->setText("成年人不做选择，全选!");
    group->addButton(btn6);
    QVBoxLayout *vboxLayout2 = new QVBoxLayout();
    for(int i = 0; i < group->buttons().size(); i++){
        vboxLayout2->addWidget(group->buttons()[i]);
    }

    page2->setLayout(vboxLayout2);
    wizard.addPage(page2);

    QWizardPage* page3 = new QWizardPage();
    page3->setTitle(tr("你的缘分即将到来"));
    auto label3 = new QLabel();
    label3->setText(tr("感谢您的参与，接下来的一个月会遇到对的人"));
    QVBoxLayout *layout3 = new QVBoxLayout();
    layout3->addWidget(label3);
    page3->setLayout(layout3);
    wizard.addPage(page3);
    wizard.show();//非模态
    wizard.exec();
}
