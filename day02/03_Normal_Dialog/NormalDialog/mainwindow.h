#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>//定时器
#include <QProgressDialog>//进度对话框
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_cancelProgressDialog();
    void on_updateProgressDialog();
private slots:
    void on_color_clicked();

    void on_files_clicked();

    void on_item_clicked();

    void on_intData_clicked();

    void on_floatData_clicked();

    void on_message_clicked();

    void on_progress_clicked();

    void on_Wizrd_clicked();

private:
    Ui::MainWindow *ui;
    QProgressDialog *_progressDialog;
    QTimer *_timer;
    int _count;
};
#endif // MAINWINDOW_H
