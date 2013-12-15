#include "multiimagescrollarea.h"
#include "multiimagewidget.h"

MultiImageScrollArea::MultiImageScrollArea(QWidget *parent) :
    QScrollArea(parent)
{
    this->setFixedHeight(196);
}

void MultiImageScrollArea::resizeEvent(QResizeEvent *e)
{
    //((MultiImageWidget*)this->widget())->update();
}
