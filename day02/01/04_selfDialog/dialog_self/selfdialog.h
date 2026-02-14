#ifndef SELFDIALOG_H
#define SELFDIALOG_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class selfDialog; }
QT_END_NAMESPACE

class selfDialog : public QMainWindow
{
    Q_OBJECT

public:
    selfDialog(QWidget *parent = nullptr);
    ~selfDialog();

private:
    Ui::selfDialog *ui;
};
#endif // SELFDIALOG_H
