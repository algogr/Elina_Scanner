/********************************************************************************
** Form generated from reading UI file 'profortosi_progress_1_2.ui'
**
** Created: Mon Jan 9 18:28:40 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFORTOSI_PROGRESS_1_2_H
#define UI_PROFORTOSI_PROGRESS_1_2_H

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

class Ui_profortosi_progress_1_2Class
{
public:
    QPushButton *pushCancel;
    QPushButton *finalPush;
    QPushButton *tempPush;
    QLabel *labelWeight;
    QLabel *label;
    QLabel *labelCustomer;
    QPushButton *pushDelete;
    QTableWidget *tableWidget;
    QLineEdit *lineScan;
    QPushButton *pushCheck;
    QLabel *labelPieces;

    void setupUi(QDialog *profortosi_progress_1_2Class)
    {
        if (profortosi_progress_1_2Class->objectName().isEmpty())
            profortosi_progress_1_2Class->setObjectName(QString::fromUtf8("profortosi_progress_1_2Class"));
        profortosi_progress_1_2Class->resize(320, 300);
        pushCancel = new QPushButton(profortosi_progress_1_2Class);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));
        pushCancel->setGeometry(QRect(230, 230, 81, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        pushCancel->setFont(font);
        finalPush = new QPushButton(profortosi_progress_1_2Class);
        finalPush->setObjectName(QString::fromUtf8("finalPush"));
        finalPush->setGeometry(QRect(230, 130, 81, 41));
        tempPush = new QPushButton(profortosi_progress_1_2Class);
        tempPush->setObjectName(QString::fromUtf8("tempPush"));
        tempPush->setGeometry(QRect(230, 180, 81, 41));
        labelWeight = new QLabel(profortosi_progress_1_2Class);
        labelWeight->setObjectName(QString::fromUtf8("labelWeight"));
        labelWeight->setGeometry(QRect(230, 10, 81, 51));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        labelWeight->setFont(font1);
        label = new QLabel(profortosi_progress_1_2Class);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 61, 16));
        labelCustomer = new QLabel(profortosi_progress_1_2Class);
        labelCustomer->setObjectName(QString::fromUtf8("labelCustomer"));
        labelCustomer->setGeometry(QRect(50, 10, 161, 16));
        pushDelete = new QPushButton(profortosi_progress_1_2Class);
        pushDelete->setObjectName(QString::fromUtf8("pushDelete"));
        pushDelete->setGeometry(QRect(230, 80, 81, 41));
        tableWidget = new QTableWidget(profortosi_progress_1_2Class);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 80, 201, 181));
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);
        lineScan = new QLineEdit(profortosi_progress_1_2Class);
        lineScan->setObjectName(QString::fromUtf8("lineScan"));
        lineScan->setGeometry(QRect(10, 40, 141, 31));
        pushCheck = new QPushButton(profortosi_progress_1_2Class);
        pushCheck->setObjectName(QString::fromUtf8("pushCheck"));
        pushCheck->setGeometry(QRect(10, 270, 85, 27));
        labelPieces = new QLabel(profortosi_progress_1_2Class);
        labelPieces->setObjectName(QString::fromUtf8("labelPieces"));
        labelPieces->setGeometry(QRect(160, 30, 61, 41));
        QFont font2;
        font2.setPointSize(15);
        labelPieces->setFont(font2);

        retranslateUi(profortosi_progress_1_2Class);

        QMetaObject::connectSlotsByName(profortosi_progress_1_2Class);
    } // setupUi

    void retranslateUi(QDialog *profortosi_progress_1_2Class)
    {
        profortosi_progress_1_2Class->setWindowTitle(QApplication::translate("profortosi_progress_1_2Class", "\316\243\317\205\316\275\316\255\317\207\316\271\317\203\316\267 \316\240\317\201\316\277\317\206\317\214\317\201\317\204\317\211\317\203\316\267\317\202", 0, QApplication::UnicodeUTF8));
        pushCancel->setText(QApplication::translate("profortosi_progress_1_2Class", "\316\247", 0, QApplication::UnicodeUTF8));
        finalPush->setText(QApplication::translate("profortosi_progress_1_2Class", "\316\237\317\201\316\271\317\203\317\204\316\271\316\272\316\256\n"
"\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        tempPush->setText(QApplication::translate("profortosi_progress_1_2Class", "\316\240\317\201\316\277\317\203\317\211\317\201\316\271\316\275\316\256\n"
"\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        labelWeight->setText(QString());
        label->setText(QApplication::translate("profortosi_progress_1_2Class", "\316\240\316\265\316\273\316\254\317\204\316\267\317\202", 0, QApplication::UnicodeUTF8));
        labelCustomer->setText(QString());
        pushDelete->setText(QApplication::translate("profortosi_progress_1_2Class", "\316\224\316\271\316\261\316\263\317\201\316\261\317\206\316\256\n"
"\316\232\317\211\316\264\316\271\316\272\316\277\317\215", 0, QApplication::UnicodeUTF8));
        pushCheck->setText(QApplication::translate("profortosi_progress_1_2Class", "\316\210\316\273\316\265\316\263\317\207\316\277\317\202", 0, QApplication::UnicodeUTF8));
        labelPieces->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class profortosi_progress_1_2Class: public Ui_profortosi_progress_1_2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFORTOSI_PROGRESS_1_2_H
