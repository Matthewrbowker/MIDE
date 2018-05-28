#include "mainwindow.h"
#include "fileinterface.h"
#include <string>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    FileInterface fi();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
