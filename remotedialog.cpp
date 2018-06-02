#include "remotedialog.h"
#include "ui_remotedialog.h"

RemoteDialog::RemoteDialog(FileInterface *fiTmp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoteDialog)
{
    ui->setupUi(this);
    fi = fiTmp;
}

RemoteDialog::~RemoteDialog()
{
    delete ui;
}
