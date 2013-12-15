/********************************************************************************
** Form generated from reading UI file 'functionwidget.ui'
**
** Created: Mon May 28 21:31:31 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONWIDGET_H
#define UI_FUNCTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FunctionWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_installedFunctions;
    QVBoxLayout *verticalLayout;
    QPushButton *button_add;
    QPushButton *button_remove;
    QSpacerItem *verticalSpacer;
    QPushButton *button_removeAll;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget_currentFunctions;
    QVBoxLayout *verticalLayout_2;
    QPushButton *button_moveUp;
    QPushButton *button_moveDown;
    QPushButton *button_properties;
    QSpacerItem *verticalSpacer_2;
    QPushButton *button_process;

    void setupUi(QWidget *FunctionWidget)
    {
        if (FunctionWidget->objectName().isEmpty())
            FunctionWidget->setObjectName(QString::fromUtf8("FunctionWidget"));
        FunctionWidget->resize(732, 233);
        FunctionWidget->setMinimumSize(QSize(0, 233));
        horizontalLayout_3 = new QHBoxLayout(FunctionWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(FunctionWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listWidget_installedFunctions = new QListWidget(FunctionWidget);
        listWidget_installedFunctions->setObjectName(QString::fromUtf8("listWidget_installedFunctions"));

        horizontalLayout->addWidget(listWidget_installedFunctions);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        button_add = new QPushButton(FunctionWidget);
        button_add->setObjectName(QString::fromUtf8("button_add"));

        verticalLayout->addWidget(button_add);

        button_remove = new QPushButton(FunctionWidget);
        button_remove->setObjectName(QString::fromUtf8("button_remove"));

        verticalLayout->addWidget(button_remove);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        button_removeAll = new QPushButton(FunctionWidget);
        button_removeAll->setObjectName(QString::fromUtf8("button_removeAll"));

        verticalLayout->addWidget(button_removeAll);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(FunctionWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        listWidget_currentFunctions = new QListWidget(FunctionWidget);
        listWidget_currentFunctions->setObjectName(QString::fromUtf8("listWidget_currentFunctions"));

        horizontalLayout_2->addWidget(listWidget_currentFunctions);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        button_moveUp = new QPushButton(FunctionWidget);
        button_moveUp->setObjectName(QString::fromUtf8("button_moveUp"));

        verticalLayout_2->addWidget(button_moveUp);

        button_moveDown = new QPushButton(FunctionWidget);
        button_moveDown->setObjectName(QString::fromUtf8("button_moveDown"));

        verticalLayout_2->addWidget(button_moveDown);

        button_properties = new QPushButton(FunctionWidget);
        button_properties->setObjectName(QString::fromUtf8("button_properties"));

        verticalLayout_2->addWidget(button_properties);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        button_process = new QPushButton(FunctionWidget);
        button_process->setObjectName(QString::fromUtf8("button_process"));

        verticalLayout_2->addWidget(button_process);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);


        retranslateUi(FunctionWidget);

        QMetaObject::connectSlotsByName(FunctionWidget);
    } // setupUi

    void retranslateUi(QWidget *FunctionWidget)
    {
        FunctionWidget->setWindowTitle(QApplication::translate("FunctionWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FunctionWidget", "Installed Functions", 0, QApplication::UnicodeUTF8));
        button_add->setText(QApplication::translate("FunctionWidget", "&Add ->", 0, QApplication::UnicodeUTF8));
        button_remove->setText(QApplication::translate("FunctionWidget", "<- &Remove", 0, QApplication::UnicodeUTF8));
        button_removeAll->setText(QApplication::translate("FunctionWidget", "<< Remove Al&l", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FunctionWidget", "Current Functions", 0, QApplication::UnicodeUTF8));
        button_moveUp->setText(QApplication::translate("FunctionWidget", "Move &Up", 0, QApplication::UnicodeUTF8));
        button_moveDown->setText(QApplication::translate("FunctionWidget", "Move &Down", 0, QApplication::UnicodeUTF8));
        button_properties->setText(QApplication::translate("FunctionWidget", "&Properties...", 0, QApplication::UnicodeUTF8));
        button_process->setText(QApplication::translate("FunctionWidget", "Pr&ocess", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FunctionWidget: public Ui_FunctionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONWIDGET_H
