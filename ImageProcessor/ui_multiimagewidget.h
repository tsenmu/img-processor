/********************************************************************************
** Form generated from reading UI file 'multiimagewidget.ui'
**
** Created: Mon May 28 21:31:31 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIIMAGEWIDGET_H
#define UI_MULTIIMAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiImageWidget
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *MultiImageWidget)
    {
        if (MultiImageWidget->objectName().isEmpty())
            MultiImageWidget->setObjectName(QString::fromUtf8("MultiImageWidget"));
        MultiImageWidget->resize(392, 251);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MultiImageWidget->sizePolicy().hasHeightForWidth());
        MultiImageWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(MultiImageWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        retranslateUi(MultiImageWidget);

        QMetaObject::connectSlotsByName(MultiImageWidget);
    } // setupUi

    void retranslateUi(QWidget *MultiImageWidget)
    {
        MultiImageWidget->setWindowTitle(QApplication::translate("MultiImageWidget", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MultiImageWidget: public Ui_MultiImageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIIMAGEWIDGET_H
