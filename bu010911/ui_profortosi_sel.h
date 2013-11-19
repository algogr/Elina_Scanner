/********************************************************************************
** Form generated from reading UI file 'profortosi_sel.ui'
**
** Created: Wed May 4 16:31:06 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFORTOSI_SEL_H
#define UI_PROFORTOSI_SEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_profortosi_selClass
{
public:
    QSplitter *splitter;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *profortosi_selClass)
    {
        if (profortosi_selClass->objectName().isEmpty())
            profortosi_selClass->setObjectName(QString::fromUtf8("profortosi_selClass"));
        profortosi_selClass->resize(320, 300);
        splitter = new QSplitter(profortosi_selClass);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(30, 9, 261, 281));
        splitter->setOrientation(Qt::Vertical);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        splitter->addWidget(pushButton);
        pushButton_2 = new QPushButton(splitter);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        splitter->addWidget(pushButton_2);

        retranslateUi(profortosi_selClass);

        QMetaObject::connectSlotsByName(profortosi_selClass);
    } // setupUi

    void retranslateUi(QDialog *profortosi_selClass)
    {
        profortosi_selClass->setWindowTitle(QApplication::translate("profortosi_selClass", "\316\240\317\201\316\277\317\206\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("profortosi_selClass", "1.\316\235\316\255\316\261 \316\240\317\201\316\277\317\206\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton->setShortcut(QApplication::translate("profortosi_selClass", "1", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("profortosi_selClass", "2.\316\240\317\201\316\277\317\206\317\214\317\201\317\204\317\211\317\203\316\267 \317\203\316\265 \316\265\316\276\316\255\316\273\316\271\316\276\316\267", 0, QApplication::UnicodeUTF8));
        pushButton_2->setShortcut(QApplication::translate("profortosi_selClass", "2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class profortosi_selClass: public Ui_profortosi_selClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFORTOSI_SEL_H
