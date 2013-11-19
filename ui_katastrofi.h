/********************************************************************************
** Form generated from reading UI file 'katastrofi.ui'
**
** Created: Thu Sep 1 12:33:31 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KATASTROFI_H
#define UI_KATASTROFI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_katastrofiClass
{
public:
    QLineEdit *lineScan;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *katastrofiClass)
    {
        if (katastrofiClass->objectName().isEmpty())
            katastrofiClass->setObjectName(QString::fromUtf8("katastrofiClass"));
        katastrofiClass->resize(320, 300);
        lineScan = new QLineEdit(katastrofiClass);
        lineScan->setObjectName(QString::fromUtf8("lineScan"));
        lineScan->setGeometry(QRect(10, 30, 151, 23));
        label = new QLabel(katastrofiClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 150, 221, 31));
        tableWidget = new QTableWidget(katastrofiClass);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 70, 301, 201));
        pushButton = new QPushButton(katastrofiClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 30, 101, 27));

        retranslateUi(katastrofiClass);

        QMetaObject::connectSlotsByName(katastrofiClass);
    } // setupUi

    void retranslateUi(QDialog *katastrofiClass)
    {
        katastrofiClass->setWindowTitle(QApplication::translate("katastrofiClass", "katastrofi", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("katastrofiClass", "\316\223\316\257\316\275\316\265\317\204\316\261\316\271 \316\265\316\275\316\267\316\274\316\255\317\201\317\211\317\203\316\267. \316\240\316\261\317\201\316\261\316\272\316\261\316\273\317\216 \317\200\316\265\317\201\316\271\316\274\316\255\316\275\316\265\317\204\316\265", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("katastrofiClass", "\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class katastrofiClass: public Ui_katastrofiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KATASTROFI_H
