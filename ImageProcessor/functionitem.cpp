#include "functionitem.h"
#include "functionpool.h"
#include <QListWidgetItem>
#include <QDebug>


FunctionItem::FunctionItem(const QString text, QObject *parent) :
    QObject(parent)
{
    m_item = new QListWidgetItem(text);
    m_listed = false;
}

void FunctionItem::setListed(bool on)
{
    m_listed = on;
}

bool FunctionItem::listed()
{
    return m_listed;
}

QListWidgetItem* FunctionItem::item()
{
    return m_item;
}

void FunctionItem::process()
{
     emit called(m_item->text());
}

void FunctionItem::properties()
{
    m_functionPool->properties(m_item->text());
}


void FunctionItem::setFunctionPool(FunctionPool* fp)
{
    this->m_functionPool = fp;
}
