#include "utilitiespage.h"
#include "ui_utilitiespage.h"


UtilitiesPage::UtilitiesPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::UtilitiesPage)
{
    ui->setupUi(this);
    
    // title
    decoration = new QFrame(this);
    decoration->setFixedWidth(310);
    decoration->setFixedHeight(1);
    decoration->move(10,0);
    decoration->setStyleSheet("border: 1px solid #ff1a00;");
    title = new QLabel(this);
    title->setText("Utilities and Settings");
    title->move(10, 2);
    title->setStyleSheet("color: white; background-color: #232323; font: 12pt;");
    spacer = new QLabel(this);
    spacer->move(10, 17);
    spacer->setFixedHeight(15);
}


UtilitiesPage::~UtilitiesPage()
{
    delete ui;
}
