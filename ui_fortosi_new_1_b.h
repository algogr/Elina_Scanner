/********************************************************************************
** Form generated from reading UI file 'fortosi_new_1_b.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORTOSI_NEW_1_B_H
#define UI_FORTOSI_NEW_1_B_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_fortosi_new_1_bClass
{
public:
    QLabel *label;
    QLabel *labelCustomer;
    QLabel *label_3;
    QLabel *labelCar1;
    QLabel *labelCar2;
    QPushButton *pushLoop;
    QLabel *label_4;
    QPushButton *pushCode;
    QPushButton *pushBack;

    void setupUi(QDialog *fortosi_new_1_bClass)
    {
        if (fortosi_new_1_bClass->objectName().isEmpty())
            fortosi_new_1_bClass->setObjectName(QString::fromUtf8("fortosi_new_1_bClass"));
        fortosi_new_1_bClass->resize(320, 300);
        label = new QLabel(fortosi_new_1_bClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 61, 31));
        labelCustomer = new QLabel(fortosi_new_1_bClass);
        labelCustomer->setObjectName(QString::fromUtf8("labelCustomer"));
        labelCustomer->setGeometry(QRect(10, 30, 301, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelCustomer->setFont(font);
        label_3 = new QLabel(fortosi_new_1_bClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 61, 31));
        labelCar1 = new QLabel(fortosi_new_1_bClass);
        labelCar1->setObjectName(QString::fromUtf8("labelCar1"));
        labelCar1->setGeometry(QRect(90, 60, 91, 31));
        labelCar1->setFont(font);
        labelCar2 = new QLabel(fortosi_new_1_bClass);
        labelCar2->setObjectName(QString::fromUtf8("labelCar2"));
        labelCar2->setGeometry(QRect(210, 60, 91, 31));
        labelCar2->setFont(font);
        pushLoop = new QPushButton(fortosi_new_1_bClass);
        pushLoop->setObjectName(QString::fromUtf8("pushLoop"));
        pushLoop->setGeometry(QRect(190, 100, 101, 61));
        label_4 = new QLabel(fortosi_new_1_bClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(190, 60, 21, 31));
        pushCode = new QPushButton(fortosi_new_1_bClass);
        pushCode->setObjectName(QString::fromUtf8("pushCode"));
        pushCode->setGeometry(QRect(190, 180, 101, 61));
        pushBack = new QPushButton(fortosi_new_1_bClass);
        pushBack->setObjectName(QString::fromUtf8("pushBack"));
        pushBack->setGeometry(QRect(30, 140, 91, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        pushBack->setFont(font1);

        retranslateUi(fortosi_new_1_bClass);

        QMetaObject::connectSlotsByName(fortosi_new_1_bClass);
    } // setupUi

    void retranslateUi(QDialog *fortosi_new_1_bClass)
    {
        fortosi_new_1_bClass->setWindowTitle(QApplication::translate("fortosi_new_1_bClass", "\316\235\316\255\316\261 \316\246\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("fortosi_new_1_bClass", "\316\240\316\265\316\273\316\254\317\204\316\267\317\202", 0, QApplication::UnicodeUTF8));
        labelCustomer->setText(QString());
        label_3->setText(QApplication::translate("fortosi_new_1_bClass", "\316\246\316\277\317\201\317\204\316\267\316\263\317\214", 0, QApplication::UnicodeUTF8));
        labelCar1->setText(QString());
        labelCar2->setText(QString());
        pushLoop->setText(QApplication::translate("fortosi_new_1_bClass", "1.\316\232\316\261\317\204\316\254 \317\203\317\205\317\201\317\201\316\277\316\256", 0, QApplication::UnicodeUTF8));
        pushLoop->setShortcut(QApplication::translate("fortosi_new_1_bClass", "1", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("fortosi_new_1_bClass", "/", 0, QApplication::UnicodeUTF8));
        pushCode->setText(QApplication::translate("fortosi_new_1_bClass", "2.\316\232\316\261\317\204\316\254 \316\272\317\211\316\264\316\271\316\272\317\214", 0, QApplication::UnicodeUTF8));
        pushCode->setShortcut(QApplication::translate("fortosi_new_1_bClass", "2", 0, QApplication::UnicodeUTF8));
        pushBack->setText(QApplication::translate("fortosi_new_1_bClass", "<<", 0, QApplication::UnicodeUTF8));
        pushBack->setShortcut(QApplication::translate("fortosi_new_1_bClass", "Esc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fortosi_new_1_bClass: public Ui_fortosi_new_1_bClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORTOSI_NEW_1_B_H
