/********************************************************************************
** Form generated from reading UI file 'elina_scanner.ui'
**
** Created: Wed Mar 9 10:57:47 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELINA_SCANNER_H
#define UI_ELINA_SCANNER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Elina_ScannerClass
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *Elina_ScannerClass)
    {
        if (Elina_ScannerClass->objectName().isEmpty())
            Elina_ScannerClass->setObjectName(QString::fromUtf8("Elina_ScannerClass"));
        Elina_ScannerClass->resize(320, 300);
        pushButton = new QPushButton(Elina_ScannerClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 10, 131, 27));
        pushButton_2 = new QPushButton(Elina_ScannerClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 50, 131, 27));
        pushButton_3 = new QPushButton(Elina_ScannerClass);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(80, 90, 131, 27));
        pushButton_4 = new QPushButton(Elina_ScannerClass);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(80, 130, 131, 27));
        pushButton_5 = new QPushButton(Elina_ScannerClass);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(80, 170, 131, 27));
        pushButton_6 = new QPushButton(Elina_ScannerClass);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(80, 210, 131, 27));

        retranslateUi(Elina_ScannerClass);

        QMetaObject::connectSlotsByName(Elina_ScannerClass);
    } // setupUi

    void retranslateUi(QWidget *Elina_ScannerClass)
    {
        Elina_ScannerClass->setWindowTitle(QApplication::translate("Elina_ScannerClass", "Scanner", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Elina_ScannerClass", "\316\246\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Elina_ScannerClass", "\316\221\317\200\316\277\316\263\317\201\316\261\317\206\316\256", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Elina_ScannerClass", "\316\225\317\200\316\271\317\203\317\204\317\201\316\277\317\206\316\255\317\202", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Elina_ScannerClass", "\316\221\316\273\316\273\316\261\316\263\316\256 \316\225\317\204\316\271\316\272\316\255\317\204\316\261\317\202", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Elina_ScannerClass", "\316\221\316\275\316\254\316\263\316\275\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Elina_ScannerClass", "\316\232\316\261\317\204\316\261\317\203\317\204\317\201\316\277\317\206\316\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Elina_ScannerClass: public Ui_Elina_ScannerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELINA_SCANNER_H
