#include "assetspage.h"
#include "ui_assetspage.h"


AssetsPage::AssetsPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::AssetsPage)
{
    ui->setupUi(this);
    
    // title
    decoration = new QFrame(this);
    decoration->setFixedWidth(310);
    decoration->setFixedHeight(1);
    decoration->move(10,0);
    decoration->setStyleSheet("border: 1px solid #ff1a00;");
    title = new QLabel(this);
    title->setText("Asset Creation and Management");
    title->move(10, 2);
    title->setFixedWidth(310);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("color: white; background-color: #232323; font: 12pt;");
    spacer = new QLabel(this);
    spacer->move(10, 17);
    spacer->setFixedHeight(15);
}


AssetsPage::~AssetsPage()
{
    delete ui;
}
