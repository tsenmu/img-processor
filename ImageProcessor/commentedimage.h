#ifndef COMMENTEDIMAGE_H
#define COMMENTEDIMAGE_H

#include <QWidget>

namespace Ui {
    class CommentedImage;
}

class QMenu;

class CommentedImage : public QWidget
{
    Q_OBJECT

public:
    explicit CommentedImage(QWidget *parent = 0);
    ~CommentedImage();

    void setPixmap(const QPixmap& pixmap);
    void setComment(const QString str, bool asFileName = true);
    void setFileName(const QString fileName);
    QPixmap* pixmap();
    const QString comment();
    const QString fileName();
    bool isAppendImage();
    void setAppendImage(bool is);
    void setAsReference(bool is);
public slots:

private slots:
    void display();
    void selectAsReference();
    void remove();
    void showProperty();
signals:
    void clicked();
    void cleared();
    void referenced(CommentedImage* ci);
    void dereferenced(CommentedImage* ci);
    void removeCommentedImage(CommentedImage* ci);
    void displayPixmap(QPixmap pixmap, QString comment);
protected:
    void enterEvent(QEvent* e);
    void leaveEvent(QEvent * e);
    void mousePressEvent(QMouseEvent * e);
    void mouseReleaseEvent(QMouseEvent * e);
    void contextMenuEvent(QContextMenuEvent * e);
private:
    QAction* m_actionDisplay;
    QAction* m_actionDelete;
    QAction* m_actionClear;
    QAction* m_actionSelectAsReference;
    QAction* m_actionProperty;

    QMenu* m_contextMenu;
    Ui::CommentedImage *ui;
    bool m_isAppendImage;
    bool m_mousePressed;
    QString m_fileName;
    QString m_comment;
};

#endif // COMMENTEDIMAGE_H
