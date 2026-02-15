#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextDocument>
#include <QTextFrame>
#include <QTextFrameFormat>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextDocument *doc= ui->textEdit->document();//文本内容
    QTextFrame* root_frame = doc->rootFrame();//通过 rootFrame 获取根框架
    QTextFrameFormat format;
    /*文本框样式 设置这个框架的边框样式为蓝色，边框为3 */
    format.setBorderBrush(Qt::blue);
    format.setBorder(3);
    root_frame->setFrameFormat(format);

    /* 插入的纯文本 */
    ui->textEdit->insertPlainText("hello world!\n");
    ui->textEdit->insertPlainText("Hello Qt\n");

    /*再设置一个文本样式*/
    QTextFrameFormat  frameFormat;//
    frameFormat.setBackground(Qt::lightGray);
    frameFormat.setMargin(10);
    frameFormat.setPadding(5);
    frameFormat.setBorder(2);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dashed);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertFrame(frameFormat);//生成一个新的文本框架
    ui->textEdit->insertPlainText("inner text!\n");
    ui->textEdit->insertPlainText("Hello inner Text!\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}

