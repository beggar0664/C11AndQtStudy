#include "selfdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    selfDialog w;
    w.show();
    return a.exec();
}
