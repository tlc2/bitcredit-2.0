#include "otherpage.h"
#include "ui_otherpage.h"


OtherPage::OtherPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::OtherPage)
{
    ui->setupUi(this);

}


OtherPage::~OtherPage()
{
    delete ui;
}
