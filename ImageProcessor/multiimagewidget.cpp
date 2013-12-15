#include "multiimagewidget.h"
#include "ui_multiimagewidget.h"
#include "commentedimage.h"
#include "functionpool.h"
#include <QMessageBox>
#include <QDebug>

MultiImageWidget::MultiImageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiImageWidget)
{
    ui->setupUi(this);
    //this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Ignored);

    m_appendImage = new CommentedImage(this);
    m_appendImage->setAppendImage(true);
    m_commentedImages.append(m_appendImage);
    ui->horizontalLayout->setEnabled(false);
    this->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    position();
    m_reference = NULL;
}

MultiImageWidget::~MultiImageWidget()
{
    delete ui;
}

void MultiImageWidget::append(const QPixmap &pixmap, const QString comment, const QString fileName)
{
    CommentedImage* ci = new CommentedImage(this);

    ci->setPixmap(pixmap);
    ci->setComment(comment);
    ci->setFileName(fileName);
    this->m_commentedImages.insert(m_commentedImages.size()-1,ci);
    this->ui->horizontalLayout->addWidget(ci);
    connect(ci, SIGNAL(displayPixmap(QPixmap, QString)), this, SLOT(display(QPixmap, QString)));
    connect(ci, SIGNAL(removeCommentedImage(CommentedImage*)), this, SLOT(remove(CommentedImage*)));
    connect(ci, SIGNAL(referenced(CommentedImage*)), this, SLOT(reference(CommentedImage*)));
    connect(ci, SIGNAL(dereferenced(CommentedImage*)), this, SLOT(dereference(CommentedImage*)));
    connect(ci, SIGNAL(cleared()), this, SLOT(clear()));
    position();
}

void MultiImageWidget::clear()
{
    int size = m_commentedImages.size();
    for(int i = 0; i < size -1; ++i) {
        CommentedImage* ci = m_commentedImages.at(0);
        if(ci == this->m_reference)
        {
            m_reference = NULL;
        }
        this->layout()->removeWidget(ci);
        m_commentedImages.removeAt(0);
        delete ci;
    }
    position();
}



void MultiImageWidget::remove(CommentedImage* ci)
{
    int index = m_commentedImages.indexOf(ci);
    ui->horizontalLayout->removeWidget(ci);
    if(index != -1)
    {
        CommentedImage* ci = m_commentedImages.at(index);
        if(ci == this->m_reference)
        {
            m_reference = NULL;
        }
        delete ci;
        m_commentedImages.removeAt(index);
    }

    position();
}

void MultiImageWidget::display(QPixmap pixmap, QString comment)
{
    emit displayPixmap(pixmap, comment);
}

void MultiImageWidget::position()
{
    int x = 5;
    int y = 5;
    foreach(CommentedImage* ci, m_commentedImages)
    {
        ci->move(x, y);
        x += 5 + ci->width();
    }
    setFixedWidth(x);
    move(0, 0);
}

const CommentedImage* MultiImageWidget::appendImage()
{
    return m_appendImage;
}


const QList<CommentedImage*> MultiImageWidget::commentedImages()
{
    return m_commentedImages;
}

void MultiImageWidget::contextMenuEvent(QContextMenuEvent * e)
{

}

void MultiImageWidget::reference(CommentedImage* ci)
{
    if(m_reference != NULL)
    {
        m_reference->setAsReference(false);
    }
    this->m_reference =  ci;
}

void MultiImageWidget::dereference(CommentedImage* ci)
{
    if(m_reference == ci) {
        m_reference = NULL;
    }
}

void MultiImageWidget::setFunctionPool(FunctionPool *fp)
{
    m_functionPool = fp;
}

void MultiImageWidget::updateImages()
{
    if(m_functionPool != NULL)
    {
        QList<QPixmap> pixmaps;
        QList<QString> filenames;
        foreach(CommentedImage* ci, this->commentedImages())
        {
            if(ci != NULL && !ci->isAppendImage())
            {
                QPixmap* p = ci->pixmap();
                pixmaps.append(*p);
                delete p;
                QString fn = ci->comment();
                filenames.append(fn);
            }
        }
        QPixmap* pixmap = NULL;
        if(m_reference != NULL)
        {
            pixmap = new QPixmap(*m_reference->pixmap());
        }
        m_functionPool->setData(pixmaps, filenames, pixmap);
    }
}


void MultiImageWidget::updatePixmaps(QList<QPixmap> pixmaps)
{
    for(int i = 0; i < this->commentedImages().size() - 1; ++i)
    {
        commentedImages().at(i)->setPixmap(pixmaps.at(i));
        QString cmt = commentedImages().at(i)->comment();
        if(!cmt.endsWith('*'))
        {
            cmt.append('*');
        }
        commentedImages().at(i)->setComment(cmt, false);
    }
}
