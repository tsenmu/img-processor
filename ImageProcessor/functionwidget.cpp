#include "functionwidget.h"
#include "functionpool.h"
#include "ui_functionwidget.h"
#include <QListWidgetItem>
#include <QList>
#include <QDebug>
#include "functionitem.h"

FunctionWidget::FunctionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FunctionWidget)
{
    ui->setupUi(this);
    ui->listWidget_currentFunctions->setSelectionMode(QListWidget::SingleSelection);
    ui->listWidget_installedFunctions->setSelectionMode(QListWidget::SingleSelection);
    ui->listWidget_installedFunctions->setSortingEnabled(true);


    updateButtons();
    connect(ui->button_add, SIGNAL(clicked()), this, SLOT(add()));
    connect(ui->button_moveDown, SIGNAL(clicked()), this, SLOT(moveDown()));
    connect(ui->button_moveUp, SIGNAL(clicked()), this, SLOT(moveUp()));
    connect(ui->button_process, SIGNAL(clicked()), this, SLOT(process()));
    connect(ui->button_properties, SIGNAL(clicked()), this, SLOT(properties()));
    connect(ui->button_remove, SIGNAL(clicked()), this, SLOT(remove()));
    connect(ui->button_removeAll, SIGNAL(clicked()), this, SLOT(removeAll()));
    connect(ui->listWidget_currentFunctions, SIGNAL(currentRowChanged(int)), this, SLOT(updateButtons(int)));
    connect(ui->listWidget_installedFunctions, SIGNAL(currentRowChanged(int)), this, SLOT(updateButtons(int)));
}

FunctionWidget::~FunctionWidget()
{
    delete ui;
}


void FunctionWidget::add()
{
    QListWidgetItem* it = ui->listWidget_installedFunctions->currentItem();
    if(it != NULL)
    {
        FunctionItem* fi = this->functionItemOf(it);
        if(fi != NULL)
        {
            fi->setListed(true);
            ui->listWidget_installedFunctions->takeItem(ui->listWidget_installedFunctions->currentRow());
            ui->listWidget_currentFunctions->addItem(it);
        }
    }
    ui->listWidget_installedFunctions->sortItems();
    updateButtons();
}

void FunctionWidget::remove()
{
    QListWidgetItem* it = ui->listWidget_currentFunctions->currentItem();
    if(it != NULL)
    {
        FunctionItem* fi = this->functionItemOf(it);
        if(fi != NULL)
        {
            fi->setListed(false);
            ui->listWidget_currentFunctions->takeItem(ui->listWidget_currentFunctions->currentRow());
            ui->listWidget_installedFunctions->addItem(it);
        }
    }
    ui->listWidget_installedFunctions->sortItems();
    updateButtons();
}

void FunctionWidget::removeAll()
{
    QList<QListWidgetItem*> items;
    for(int i = 0; i < ui->listWidget_currentFunctions->count(); ++i)
    {
        items.append(ui->listWidget_currentFunctions->item(i));
    }

    foreach(QListWidgetItem*  it, items)
    {
        if(it != NULL)
        {
            FunctionItem* fi = this->functionItemOf(it);
            if(fi != NULL)
            {
                fi->setListed(false);
                ui->listWidget_currentFunctions->takeItem(ui->listWidget_currentFunctions->row(it));
                ui->listWidget_installedFunctions->addItem(it);
            }
        }
    }
    ui->listWidget_installedFunctions->sortItems();
    updateButtons();
}

void FunctionWidget::moveUp()
{
    QListWidgetItem* it = ui->listWidget_currentFunctions->currentItem();
    if(it != NULL)
    {
        int r = ui->listWidget_currentFunctions->currentRow();
        if(r != 0)
        {
            ui->listWidget_currentFunctions->takeItem(r);
            ui->listWidget_currentFunctions->insertItem(r-1, it);
            ui->listWidget_currentFunctions->setCurrentRow(r-1);
        }
    }

}

void FunctionWidget::moveDown()
{
    QListWidgetItem* it = ui->listWidget_currentFunctions->currentItem();
    if(it != NULL)
    {
        int r = ui->listWidget_currentFunctions->currentRow();
        if(r != ui->listWidget_currentFunctions->count() -1)
        {
            ui->listWidget_currentFunctions->takeItem(r);
            ui->listWidget_currentFunctions->insertItem(r+1, it);
            ui->listWidget_currentFunctions->setCurrentRow(r+1);
        }
    }

}

void FunctionWidget::properties()
{
    if(ui->listWidget_currentFunctions->currentItem() != NULL)
    {
        functionItemOf(ui->listWidget_currentFunctions->currentItem())->properties();

    }
}

void FunctionWidget::process()
{
    emit processStarted();
    emit processRefreshed(0);

    int currentPercentage = 0;
    int step = ui->listWidget_currentFunctions->count() == 0 ? 100 : 100 / ui->listWidget_currentFunctions->count();
    for(int i = 0; i < ui->listWidget_currentFunctions->count(); ++i)
    {
        FunctionItem* fi = functionItemOf(ui->listWidget_currentFunctions->item(i));
        fi->process();
        currentPercentage += step;
        emit processRefreshed(currentPercentage);
    }
    emit processFinished();
}

void FunctionWidget::updateItems()
{
    for(int i = 0; i < ui->listWidget_currentFunctions->count(); ++i)
    {
        ui->listWidget_currentFunctions->takeItem(0);
    }
    for(int i = 0; i < ui->listWidget_installedFunctions->count(); ++i)
    {
        ui->listWidget_installedFunctions->takeItem(0);
    }
    for(int i = 0; i < m_items.size(); ++i)
    {
        if(m_items.at(i)->listed())
        {
            ui->listWidget_currentFunctions->addItem(m_items.at(i)->item());
        }
        else
        {
            ui->listWidget_installedFunctions->addItem(m_items.at(i)->item());
        }
    }
}

FunctionItem* FunctionWidget::functionItemOf(QListWidgetItem* it)
{
    for(int i = 0; i < m_items.size(); ++i)
    {
        if(m_items.at(i)->item() == it)
        {
            return m_items.at(i);
        }
    }
    return NULL;
}

void FunctionWidget::updateButtons(int row)
{
    updateButtons();
}

void FunctionWidget::updateButtons()
{
    ui->button_moveUp->setEnabled(ui->listWidget_currentFunctions->count() != 0 && ui->listWidget_currentFunctions->currentItem()!= NULL && ui->listWidget_currentFunctions->currentRow()!= 0);
    ui->button_moveDown->setEnabled(ui->listWidget_currentFunctions->count() != 0 && ui->listWidget_currentFunctions->currentItem()!= NULL && ui->listWidget_currentFunctions->currentRow()!= ui->listWidget_currentFunctions->count()-1);
    ui->button_remove->setEnabled(ui->listWidget_currentFunctions->count()!= 0 && ui->listWidget_currentFunctions->currentItem()!= NULL);
    ui->button_add->setEnabled(ui->listWidget_installedFunctions->count() != 0 && ui->listWidget_installedFunctions->currentItem() != NULL);
    ui->button_removeAll->setEnabled(ui->listWidget_currentFunctions->count()!= 0);
    ui->button_process->setEnabled(ui->listWidget_currentFunctions->count()!=0);
    ui->button_properties->setEnabled(ui->listWidget_currentFunctions->currentItem()!= NULL);
}

void FunctionWidget::setFunctionPool(FunctionPool *fp)
{
    m_functionPool = fp;
    if(fp != NULL)
    {
        foreach(QString str, fp->functionNameList())
        {
            FunctionItem* fi = new FunctionItem(str, this);
            fi->setFunctionPool(fp);
            m_items.append(fi);
            connect(fi, SIGNAL(called(QString)), fp, SLOT(call(QString)));
        }


    }
    updateItems();
}
