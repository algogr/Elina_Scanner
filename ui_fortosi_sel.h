/********************************************************************************
** Form generated from reading UI file 'fortosi_sel.ui'
**
** Created: Tue Mar 12 16:39:30 2013
**      by: Qt User Interface Compiler version 4.8.2
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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fortosi_selClass
{
public:
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *fortosi_selClass)
    {
        if (fortosi_selClass->objectName().isEmpty())
            fortosi_selClass->setObjectName(QString::fromUtf8("fortosi_selClass"));
        fortosi_selClass->resize(320, 300);
        pushButton_3 = new QPushButton(fortosi_selClass);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 200, 281, 91));
        pushButton = new QPushButton(fortosi_selClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 281, 91));
        pushButton->setMaximumSize(QSize(291, 16777215));
        pushButton_2 = new QPushButton(fortosi_selClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 110, 281, 91));
        pushButton_2->setMaximumSize(QSize(281, 16777215));

        retranslateUi(fortosi_selClass);

        QMetaObject::connectSlotsByName(fortosi_selClass);
    } // setupUi

    void retranslateUi(QWidget *fortosi_selClass)
    {
        fortosi_selClass->setWindowTitle(QApplication::translate("fortosi_selClass", "\316\246\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("fortosi_selClass", "3.\316\221\317\200\316\277\317\203\317\204\316\277\316\273\316\256 \316\244\316\265\316\273\316\265\317\205\317\204\316\261\316\257\316\261\317\202 \316\246\317\214\317\201\317\204\317\211\317\203\316\267\317\202", 0, QApplication::UnicodeUTF8));
        pushButton_3->setShortcut(QApplication::translate("fortosi_selClass", "3", 0, QApplication::UnicodeUTF8));
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
