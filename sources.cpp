#include "sources.h"
#include "ui_sources.h"

Sources::Sources(FileInterface *fiTmp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sources)
{
    //ui->setupUi(this);
    fi = fiTmp;
}

Sources::~Sources()
{
    delete ui;
}
