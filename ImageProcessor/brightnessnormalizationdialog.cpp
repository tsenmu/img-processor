#include "brightnessnormalizationdialog.h"
#include "ui_brightnessnormalizationdialog.h"

BrightnessNormalizationDialog::BrightnessNormalizationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessNormalizationDialog)
{
    ui->setupUi(this);
}

BrightnessNormalizationDialog::~BrightnessNormalizationDialog()
{
    delete ui;
}


void BrightnessNormalizationDialog::setK(double k)
{
    this->ui->k->setValue(k);
}

double BrightnessNormalizationDialog::k()
{
    return this->ui->k->value();
}
