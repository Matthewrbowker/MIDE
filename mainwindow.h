#include <fileinterface.h>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionPaste_without_Formatting_triggered();

    void on_actionRemotes_triggered();

    void on_actionView_Sources_triggered();

private:
    Ui::MainWindow *ui;
    FileInterface * fi;
};

#endif // MAINWINDOW_H
