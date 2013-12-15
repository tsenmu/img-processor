/********************************************************************************
** Form generated from reading UI file 'commentedimage.ui'
**
** Created: Mon May 28 21:31:31 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTEDIMAGE_H
#define UI_COMMENTEDIMAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommentedImage
{
public:
    QLabel *label_image;
    QLabel *label_comment;

    void setupUi(QWidget *CommentedImage)
    {
        if (CommentedImage->objectName().isEmpty())
            CommentedImage->setObjectName(QString::fromUtf8("CommentedImage"));
        CommentedImage->resize(400, 300);
        CommentedImage->setWindowOpacity(0);
        CommentedImage->setStyleSheet(QString::fromUtf8(""));
        label_image = new QLabel(CommentedImage);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setGeometry(QRect(160, 70, 54, 12));
        label_comment = new QLabel(CommentedImage);
        label_comment->setObjectName(QString::fromUtf8("label_comment"));
        label_comment->setGeometry(QRect(160, 120, 54, 12));
        label_comment->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 127, 210);\n"
""));
        label_comment->setScaledContents(true);
        label_comment->setWordWrap(true);

        retranslateUi(CommentedImage);

        QMetaObject::connectSlotsByName(CommentedImage);
    } // setupUi

    void retranslateUi(QWidget *CommentedImage)
    {
        CommentedImage->setWindowTitle(QApplication::translate("CommentedImage", "Form", 0, QApplication::UnicodeUTF8));
        label_image->setText(QString());
        label_comment->setText(QApplication::translate("CommentedImage", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CommentedImage: public Ui_CommentedImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTEDIMAGE_H
