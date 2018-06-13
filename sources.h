#ifndef SOURCES_H
#define SOURCES_H

#include <QDialog>
#include "fileinterface.h"

namespace Ui {
class Sources;
}

class Sources : public QDialog
{
    Q_OBJECT

public:
    explicit Sources(FileInterface*, QWidget *parent = 0);
    ~Sources();

private:
    Ui::Sources *ui;
    FileInterface *fi;
};

#endif // SOURCES_H
