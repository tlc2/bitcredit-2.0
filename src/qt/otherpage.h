#ifndef OTHERPAGE_H
#define OTHERPAGE_H

#include "clientmodel.h"

#include <QWidget>
#include <QFrame>
#include <QLabel>

namespace Ui
{
    class OtherPage;
}

class OtherPage: public QWidget
{
    Q_OBJECT

public:
    OtherPage(QWidget *parent = 0);
    ~OtherPage();

    void setClientModel(ClientModel *model);

private:
    Ui::OtherPage *ui;
    ClientModel *clientModel;


};

#endif // OTHERPAGE_H
