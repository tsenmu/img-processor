#include "commentedimage.h"
#include "ui_commentedimage.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <QDebug>
#include <QMenu>

CommentedImage::CommentedImage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommentedImage)
{
    ui->setupUi(this);
    ui->label_image->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label_image->setScaledContents(true);
    ui->label_image->move(0, 0);
    ui->label_image->setBackgroundRole(QPalette::Base);
    ui->label_comment->setVisible(false);
    ui->label_comment->setTextFormat(Qt::RichText);
    ui->label_comment->setAlignment(Qt::AlignCenter);
    m_isAppendImage = false;

    m_actionDisplay = new QAction(tr("Display"), this);
    QFont font; font.setBold(true);
    m_actionDisplay->setFont(font);
    m_actionDelete = new QAction(tr("Delete"), this);
    m_actionClear = new QAction(tr("Clear"), this);
    m_actionSelectAsReference = new QAction(tr("Reference"), this);
    m_actionSelectAsReference->setCheckable(true);
    m_actionProperty = new QAction(tr("Properties"), this);

    m_contextMenu = new QMenu();
    m_contextMenu->addAction(m_actionDisplay);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(m_actionDelete);
    m_contextMenu->addAction(m_actionClear);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(m_actionSelectAsReference);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(m_actionProperty);
    connect(m_actionDisplay, SIGNAL(triggered()), this, SLOT(display()));
    connect(m_actionDelete, SIGNAL(triggered()), this, SLOT(remove()));
    connect(m_actionClear, SIGNAL(triggered()), this, SIGNAL(cleared()));
    connect(m_actionSelectAsReference, SIGNAL(triggered()), this, SLOT(selectAsReference()));
    connect(m_actionProperty, SIGNAL(triggered()), this, SLOT(showProperty()));
}

CommentedImage::~CommentedImage()
{
    delete ui;
}

void CommentedImage::setPixmap(const QPixmap &pixmap)
{
    this->ui->label_image->setPixmap(pixmap);

    double parentHeight = 196 - 30;
    double pixmapHeight = (double)this->ui->label_image->pixmap()->height();
    QSize pixmapSize = this->ui->label_image->pixmap()->size();
    QSize newSize=pixmapSize * (1.0 * parentHeight / pixmapHeight);
    ui->label_image->setFixedSize(newSize);
    ui->label_image->move(0, 0);
    setFixedSize(newSize);
    ui->label_comment->setFixedWidth(newSize.width() - 10);
    ui->label_comment->move((newSize.width() - ui->label_comment->width()) * 0.5,
                            (newSize.height() - ui->label_comment->height()) * 0.5);

}

QPixmap* CommentedImage::pixmap()
{
    QPixmap* pixmap = new QPixmap(*this->ui->label_image->pixmap());
    return pixmap;
}

void CommentedImage::setComment(const QString str, bool asFileName)
{
    QString strColored = "<font color = 'black'> " + str+"</font>";
    this->ui->label_comment->setText(strColored);
    //this->ui->label_comment->set
    ui->label_comment->adjustSize();
    if(asFileName)
    {
        m_comment = str;
    }
}

const QString CommentedImage::comment()
{
    return m_comment;
}

void CommentedImage::setFileName(const QString fileName)
{
    m_fileName = fileName;
}

const QString CommentedImage::fileName()
{
    return m_fileName;
}

void CommentedImage::enterEvent(QEvent *e)
{
    if(!m_isAppendImage)
    {
        ui->label_comment->setVisible(true);
    }
    else
    {
        ui->label_image->setPixmap(QPixmap::fromImage(QImage(":/images/append_image_hovered.png")));
        ui->label_image->setCursor(Qt::PointingHandCursor);
    }
}

void CommentedImage::leaveEvent(QEvent *e)
{
    if(!m_isAppendImage)
    {
        ui->label_comment->setVisible(false);
    }
    else
    {
        ui->label_image->setPixmap(QPixmap::fromImage(QImage(":/images/append_image.png")));
        ui->label_image->setCursor(Qt::ArrowCursor);
    }
}



void CommentedImage::setAppendImage(bool is)
{
    m_isAppendImage = is;
    if(m_isAppendImage)
    {
        QImage image(":/images/append_image.png");
        setPixmap(QPixmap::fromImage(image));
    }
}

bool CommentedImage::isAppendImage()
{
    return m_isAppendImage;
}

void CommentedImage::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_mousePressed = true;
    }
}

void CommentedImage::mouseReleaseEvent(QMouseEvent *e)
{
    if(m_mousePressed && e->button() == Qt::LeftButton)
    {
        m_mousePressed = false;
        if(m_isAppendImage)
        {
            emit clicked();
        }
        else
        {
            emit display();
        }
    }
}

void CommentedImage::contextMenuEvent(QContextMenuEvent *e)
{
    if(!m_isAppendImage)
    {
        m_contextMenu->move(e->globalPos());
        m_contextMenu->show();
    }
}

void CommentedImage::display()
{
    emit displayPixmap(*ui->label_image->pixmap(), ui->label_comment->text());
}

void CommentedImage::selectAsReference()
{
    if(m_actionSelectAsReference->isChecked())
    {
        ui->label_image->setStyleSheet("border: 3px solid  rgb(85, 170, 255);");
        emit referenced(this);
    }
    else
    {
        ui->label_image->setStyleSheet("");
        emit dereferenced(this);
    }
}

void CommentedImage::remove()
{
    emit removeCommentedImage(this);
}

void CommentedImage::showProperty()
{

}

void CommentedImage::setAsReference(bool is)
{
    m_actionSelectAsReference->setChecked(is);
    selectAsReference();
}
