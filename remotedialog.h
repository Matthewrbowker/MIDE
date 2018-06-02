#ifndef REMOTEDIALOG_H
#define REMOTEDIALOG_H

#include <QDialog>
#include <fileinterface.h>

namespace Ui {
class RemoteDialog;
}

class RemoteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoteDialog(FileInterface *fiTmp, QWidget *parent = 0);
    ~RemoteDialog();

private:
    Ui::RemoteDialog *ui;
    FileInterface *fi;
};

#endif // REMOTEDIALOG_H
