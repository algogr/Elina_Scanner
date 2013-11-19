/********************************************************************************
** Form generated from reading UI file 'return_roll.ui'
**
** Created: Sat Jul 14 21:17:27 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETURN_ROLL_H
#define UI_RETURN_ROLL_H

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

class Ui_return_roll
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QLineEdit *lineScan;
    QLabel *label;

    void setupUi(QDialog *return_roll)
    {
        if (return_roll->objectName().isEmpty())
            return_roll->setObjectName(QString::fromUtf8("return_roll"));
        return_roll->resize(320, 300);
        pushButton = new QPushButton(return_roll);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 30, 101, 27));
        tableWidget = new QTableWidget(return_roll);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 70, 301, 201));
        lineScan = new QLineEdit(return_roll);
        lineScan->setObjectName(QString::fromUtf8("lineScan"));
        lineScan->setGeometry(QRect(10, 30, 151, 23));
        label = new QLabel(return_roll);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 150, 221, 31));

        retranslateUi(return_roll);

        QMetaObject::connectSlotsByName(return_roll);
    } // setupUi

    void retranslateUi(QDialog *return_roll)
    {
        return_roll->setWindowTitle(QApplication::translate("return_roll", "\316\225\317\200\316\271\317\203\317\204\317\201\316\277\317\206\316\255\317\202 \317\201\316\277\316\273\317\216\316\275", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("return_roll", "\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("return_roll", "\316\223\316\257\316\275\316\265\317\204\316\261\316\271 \316\265\316\275\316\267\316\274\316\255\317\201\317\211\317\203\316\267. \316\240\316\261\317\201\316\261\316\272\316\261\316\273\317\216 \317\200\316\265\317\201\316\271\316\274\316\255\316\275\316\265\317\204\316\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class return_roll: public Ui_return_roll {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETURN_ROLL_H
