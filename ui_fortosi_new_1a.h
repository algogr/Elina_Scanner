/********************************************************************************
** Form generated from reading UI file 'fortosi_new_1a.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORTOSI_NEW_1A_H
#define UI_FORTOSI_NEW_1A_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fortosi_new_1aClass
{
public:
    QPushButton *pushContinue;
    QTableWidget *tableWidget;
    QPushButton *pushBack;
    QPushButton *pushReview;

    void setupUi(QWidget *fortosi_new_1aClass)
    {
        if (fortosi_new_1aClass->objectName().isEmpty())
            fortosi_new_1aClass->setObjectName(QString::fromUtf8("fortosi_new_1aClass"));
        fortosi_new_1aClass->resize(320, 300);
        pushContinue = new QPushButton(fortosi_new_1aClass);
        pushContinue->setObjectName(QString::fromUtf8("pushContinue"));
        pushContinue->setGeometry(QRect(220, 10, 91, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        pushContinue->setFont(font);
        tableWidget = new QTableWidget(fortosi_new_1aClass);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 60, 311, 231));
        tableWidget->verticalHeader()->setVisible(false);
        pushBack = new QPushButton(fortosi_new_1aClass);
        pushBack->setObjectName(QString::fromUtf8("pushBack"));
        pushBack->setGeometry(QRect(10, 10, 81, 41));
        pushBack->setFont(font);
        pushReview = new QPushButton(fortosi_new_1aClass);
        pushReview->setObjectName(QString::fromUtf8("pushReview"));
        pushReview->setGeometry(QRect(110, 10, 91, 41));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        pushReview->setFont(font1);

        retranslateUi(fortosi_new_1aClass);

        QMetaObject::connectSlotsByName(fortosi_new_1aClass);
    } // setupUi

    void retranslateUi(QWidget *fortosi_new_1aClass)
    {
        fortosi_new_1aClass->setWindowTitle(QApplication::translate("fortosi_new_1aClass", "\316\225\317\200\316\271\316\273\316\277\316\263\316\256 \317\200\317\201\316\277\317\206\317\214\317\201\317\204\317\211\317\203\316\267\317\202", 0, QApplication::UnicodeUTF8));
        pushContinue->setText(QApplication::translate("fortosi_new_1aClass", ">>", 0, QApplication::UnicodeUTF8));
        pushBack->setText(QApplication::translate("fortosi_new_1aClass", "<<", 0, QApplication::UnicodeUTF8));
        pushReview->setText(QApplication::translate("fortosi_new_1aClass", "\316\221\316\275\316\261\317\203\316\272\317\214\317\200\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fortosi_new_1aClass: public Ui_fortosi_new_1aClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORTOSI_NEW_1A_H
