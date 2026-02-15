#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMimeData>
#include<QDebug>
#include<QList>
#include<QUrl>
#include<QTextCodec>
#include<QTextStream>
#include<QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);//
    ui->textEdit->setAcceptDrops(false); //接受   拖拽 事件
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls()){
        qDebug() << "event url is " << event->mimeData()->urls()[0]<< endl;
        event->acceptProposedAction();//接收动作 拖拽进入动作
     }
    else {
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent * event)
{
    const QMimeData * mimeData = event->mimeData();
    //判断是否包含url
    if(mimeData->hasUrls()){
        QList<QUrl> urlList = mimeData->urls();
        //将第一个匹配为本地文件路径
        QString filename = urlList[0].toLocalFile();
        if(!filename.isEmpty()){
            QTextCodec *codec=QTextCodec::codecForName("UTF-8");// uft8格式
            QFile file(filename);
            //打开文件失败
            if(!file.open(QIODevice::ReadOnly)){
                return;
            }
            QTextCodec::setCodecForLocale(codec);
            //打开成功
            QTextStream in(&file);
            //qDebug()<< "in readall is " << in.readAll() << endl;
            ui->textEdit->setText(in.readAll());
        }

    }else{
        event->ignore();
    }
}



