/********************************************************************************
** Form generated from reading UI file 'fortosi_sel.ui'
**
** Created: Wed May 4 16:31:06 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORTOSI_SEL_H
#define UI_FORTOSI_SEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fortosi_selClass
{
public:
    QSplitter *splitter;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *fortosi_selClass)
    {
        if (fortosi_selClass->objectName().isEmpty())
            fortosi_selClass->setObjectName(QString::fromUtf8("fortosi_selClass"));
        fortosi_selClass->resize(320, 300);
        splitter = new QSplitter(fortosi_selClass);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(20, 30, 281, 231));
        splitter->setOrientation(Qt::Vertical);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        splitter->addWidget(pushButton);
        pushButton_2 = new QPushButton(splitter);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        splitter->addWidget(pushButton_2);

        retranslateUi(fortosi_selClass);

        QMetaObject::connectSlotsByName(fortosi_selClass);
    } // setupUi

    void retranslateUi(QWidget *fortosi_selClass)
    {
        fortosi_selClass->setWindowTitle(QApplication::translate("fortosi_selClass", "\316\246\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("fortosi_selClass", "1.\316\235\316\255\316\261 \316\246\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton->setShortcut(QApplication::translate("fortosi_selClass", "1", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("fortosi_selClass", "2.\316\246\317\214\317\201\317\204\317\211\317\203\316\267 \317\203\316\265 \316\265\316\276\316\255\316\273\316\271\316\276\316\267", 0, QApplication::UnicodeUTF8));
        pushButton_2->setShortcut(QApplication::translate("fortosi_selClass", "2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fortosi_selClass: public Ui_fortosi_selClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORTOSI_SEL_H
