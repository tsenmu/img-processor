#include "homomorphicfilterdialog.h"
#include "ui_homomorphicfilterdialog.h"

HomomorphicFilterDialog::HomomorphicFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomomorphicFilterDialog)
{
    ui->setupUi(this);
}

HomomorphicFilterDialog::~HomomorphicFilterDialog()
{
    delete ui;
}

void HomomorphicFilterDialog::setFLow(double val)
{
    ui->fLow->setValue(val);
}

void HomomorphicFilterDialog::setFHigh(double val)
{
    ui->fHigh->setValue(val);
}

double HomomorphicFilterDialog::fLow()
{
    return ui->fLow->value();
}

double HomomorphicFilterDialog::fHigh()
{
    return ui->fHigh->value();
}
