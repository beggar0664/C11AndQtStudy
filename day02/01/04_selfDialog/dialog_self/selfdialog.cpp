#include "selfdialog.h"
#include "ui_selfdialog.h"

selfDialog::selfDialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::selfDialog)
{
    ui->setupUi(this);
}

selfDialog::~selfDialog()
{
    delete ui;
}

