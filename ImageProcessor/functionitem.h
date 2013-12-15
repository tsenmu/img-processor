#ifndef FUNCTIONITEM_H
#define FUNCTIONITEM_H

#include <QObject>
#include <QList>
class CommentedImage;

class QListWidgetItem;
class FunctionPool;

class FunctionItem : public QObject
{
    Q_OBJECT
public:
    FunctionItem(const QString text, QObject *parent = 0);
    bool listed();
    void setListed(bool on);
    void process();
    void properties();
    QListWidgetItem* item();
    void setFunctionPool(FunctionPool* fp);

signals:
    void called(QString functionName);
public slots:

private:
    bool m_listed;
    QListWidgetItem * m_item;
    FunctionPool* m_functionPool;


};

#endif // FUNCTIONITEM_H
