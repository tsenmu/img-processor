#ifndef HOMOMORPHICFILTERDIALOG_H
#define HOMOMORPHICFILTERDIALOG_H

#include <QDialog>

namespace Ui {
    class HomomorphicFilterDialog;
}

class HomomorphicFilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HomomorphicFilterDialog(QWidget *parent = 0);
    ~HomomorphicFilterDialog();
    void setFLow(double val);
    void setFHigh(double val);
    double fLow();
    double fHigh();

private:
    Ui::HomomorphicFilterDialog *ui;
};

#endif // HOMOMORPHICFILTERDIALOG_H
