#ifndef BRIGHTNESSNORMALIZATIONDIALOG_H
#define BRIGHTNESSNORMALIZATIONDIALOG_H

#include <QDialog>

namespace Ui {
    class BrightnessNormalizationDialog;
}

class BrightnessNormalizationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BrightnessNormalizationDialog(QWidget *parent = 0);
    ~BrightnessNormalizationDialog();
    void setK(double k);
    double k();

private:
    Ui::BrightnessNormalizationDialog *ui;
};

#endif // BRIGHTNESSNORMALIZATIONDIALOG_H
