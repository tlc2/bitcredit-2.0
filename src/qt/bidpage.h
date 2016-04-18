#ifndef BIDPAGE_H
#define BIDPAGE_H

#include "clientmodel.h"

#include <QWidget>
#include <QFrame>
#include <QLabel>

class PlatformStyle;

namespace Ui
{
    class BidPage;
}

class BidPage: public QWidget
{
    Q_OBJECT

public:
    BidPage(const PlatformStyle *platformStyle, QWidget *parent = 0);
    ~BidPage();

    QString str;
    QString btctotal;
    double btctot;

    void setClientModel(ClientModel *model);

private:
    void SummonBTCWallet();   
    void SummonBTCExplorer(); 
    void GetBids();
    void setNumBlocks(int count);
    int getNumBlocks();
    void Estimate();
    
    QFrame *decoration;
    QLabel *title;
    QLabel *spacer;

    QString getDefaultDataDirectory();
    QString pathAppend(const QString& path1, const QString& path2);

private:
    Ui::BidPage *ui;
    ClientModel *clientModel;

};

#endif // BIDPAGE_H
