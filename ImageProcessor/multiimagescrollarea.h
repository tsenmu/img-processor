#ifndef MULTIIMAGESCROLLAREA_H
#define MULTIIMAGESCROLLAREA_H

#include <QScrollArea>

class MultiImageScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit MultiImageScrollArea(QWidget *parent = 0);

signals:

public slots:

protected:
    void resizeEvent(QResizeEvent * e);

};

#endif // MULTIIMAGESCROLLAREA_H
