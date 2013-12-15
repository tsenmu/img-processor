#ifndef FUNCTIONWIDGET_H
#define FUNCTIONWIDGET_H

#include <QWidget>

namespace Ui {
    class FunctionWidget;
}


class FunctionItem;
class QListWidgetItem;
class FunctionPool;

class FunctionWidget : public QWidget
{
    Q_OBJECT

signals:
    void processStarted();
    void processRefreshed(int);
    void processFinished();
public:
    explicit FunctionWidget(QWidget *parent = 0);
    ~FunctionWidget();
    void setFunctionPool(FunctionPool* fp);
private slots:
    void add();
    void remove();
    void removeAll();
    void moveUp();
    void moveDown();
    void properties();
    void process();
    void updateButtons(int row);

private:
    Ui::FunctionWidget *ui;
    QList<FunctionItem*> m_items;
    void updateItems();
    FunctionItem* functionItemOf(QListWidgetItem* it);
    void updateButtons();
    FunctionPool* m_functionPool;
};

#endif // FUNCTIONWIDGET_H
