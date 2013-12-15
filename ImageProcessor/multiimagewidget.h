#ifndef MULTIIMAGEWIDGET_H
#define MULTIIMAGEWIDGET_H

#include <QWidget>

class QPixmap;
class QLabel;
class CommentedImage;
class FunctionPool;

namespace Ui {
    class MultiImageWidget;
}

class QPixmap;
class MultiImageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MultiImageWidget(QWidget *parent = 0);
    ~MultiImageWidget();
    const CommentedImage* appendImage();
    const QList<CommentedImage*> commentedImages();
    void setFunctionPool(FunctionPool* fp);


public slots:
    /** Appends a pixmap */
    void append(const QPixmap& pixmap, const QString comment = "", const QString fileName="");
    //void update();
    void reference(CommentedImage* ci);
    void dereference(CommentedImage* ci);
    /** Clears pixmaps */
    void clear();
    void updateImages();
    void updatePixmaps(QList<QPixmap> pixmaps);

private slots:


    void remove(CommentedImage* ci);
    void display(QPixmap pixmap, QString comment);

signals:
    void displayPixmap(QPixmap pixmap, QString comment);

protected:
    void contextMenuEvent(QContextMenuEvent * e);

private:
    Ui::MultiImageWidget *ui;

    /** Maintains a list of commented images */
    QList<CommentedImage*> m_commentedImages;
    CommentedImage* m_appendImage;
    CommentedImage* m_reference;
    void position();
    FunctionPool* m_functionPool;


};

#endif // MULTIIMAGEWIDGET_H
