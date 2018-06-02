#include <QFileDialog>
#include <stdio.h>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "remotedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fi = new FileInterface();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{

}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                "Open File",
                //QDir::home(),
                ".",
                "MediaWiki IDE File (*.mide);MediaWiki IDE Template (*.midt)"
            );
    if (!filename.isNull()) {
        cout << filename.toStdString() << endl;
        fi->loadFile(filename.toStdString());
    }

    return;
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit(0);
}

void MainWindow::on_actionPaste_without_Formatting_triggered()
{
    // TODO
}

void MainWindow::on_actionRemotes_triggered()
{

    RemoteDialog r(fi);
    r.show();
}
