/********************************************************************************
** Form generated from reading UI file 'apografi.ui'
**
** Created: Tue Jan 6 13:18:02 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APOGRAFI_H
#define UI_APOGRAFI_H

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

class Ui_apografiClass
{
public:
    QLineEdit *lineScan;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QDialog *apografiClass)
    {
        if (apografiClass->objectName().isEmpty())
            apografiClass->setObjectName(QString::fromUtf8("apografiClass"));
        apografiClass->resize(320, 300);
        lineScan = new QLineEdit(apografiClass);
        lineScan->setObjectName(QString::fromUtf8("lineScan"));
        lineScan->setGeometry(QRect(10, 20, 151, 23));
        tableWidget = new QTableWidget(apografiClass);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 60, 301, 221));
        pushButton = new QPushButton(apografiClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 6, 81, 51));
        QFont font;
        font.setPointSize(9);
        pushButton->setFont(font);
        label = new QLabel(apografiClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 150, 221, 31));
        pushButton_2 = new QPushButton(apografiClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 10, 51, 41));
        pushButton_2->setFont(font);

        retranslateUi(apografiClass);

        QMetaObject::connectSlotsByName(apografiClass);
    } // setupUi

    void retranslateUi(QDialog *apografiClass)
    {
        apografiClass->setWindowTitle(QApplication::translate("apografiClass", "\316\221\317\200\316\277\316\263\317\201\316\261\317\206\316\256", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("apografiClass", "\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("apografiClass", "\316\223\316\257\316\275\316\265\317\204\316\261\316\271 \316\265\316\275\316\267\316\274\316\255\317\201\317\211\317\203\316\267. \316\240\316\261\317\201\316\261\316\272\316\261\316\273\317\216 \317\200\316\265\317\201\316\271\316\274\316\255\316\275\316\265\317\204\316\265", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("apografiClass", "INFO", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class apografiClass: public Ui_apografiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APOGRAFI_H
