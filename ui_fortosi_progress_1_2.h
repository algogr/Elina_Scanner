/********************************************************************************
** Form generated from reading UI file 'fortosi_progress_1_2.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORTOSI_PROGRESS_1_2_H
#define UI_FORTOSI_PROGRESS_1_2_H

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

class Ui_fortosi_progress_1_2Class
{
public:
    QLineEdit *lineScan;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *labelCustomer;
    QPushButton *pushDelete;
    QPushButton *finalPush;
    QPushButton *tempPush;
    QPushButton *pushCancel;
    QLabel *labelWeight;
    QPushButton *pushProf;
    QPushButton *pushCheck;
    QLabel *labelPieces;

    void setupUi(QDialog *fortosi_progress_1_2Class)
    {
        if (fortosi_progress_1_2Class->objectName().isEmpty())
            fortosi_progress_1_2Class->setObjectName(QString::fromUtf8("fortosi_progress_1_2Class"));
        fortosi_progress_1_2Class->resize(320, 300);
        lineScan = new QLineEdit(fortosi_progress_1_2Class);
        lineScan->setObjectName(QString::fromUtf8("lineScan"));
        lineScan->setGeometry(QRect(10, 40, 141, 31));
        tableWidget = new QTableWidget(fortosi_progress_1_2Class);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 80, 201, 171));
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);
        label = new QLabel(fortosi_progress_1_2Class);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 61, 16));
        labelCustomer = new QLabel(fortosi_progress_1_2Class);
        labelCustomer->setObjectName(QString::fromUtf8("labelCustomer"));
        labelCustomer->setGeometry(QRect(60, 10, 151, 20));
        pushDelete = new QPushButton(fortosi_progress_1_2Class);
        pushDelete->setObjectName(QString::fromUtf8("pushDelete"));
        pushDelete->setGeometry(QRect(230, 80, 81, 41));
        finalPush = new QPushButton(fortosi_progress_1_2Class);
        finalPush->setObjectName(QString::fromUtf8("finalPush"));
        finalPush->setGeometry(QRect(230, 130, 81, 41));
        tempPush = new QPushButton(fortosi_progress_1_2Class);
        tempPush->setObjectName(QString::fromUtf8("tempPush"));
        tempPush->setGeometry(QRect(230, 180, 81, 41));
        pushCancel = new QPushButton(fortosi_progress_1_2Class);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));
        pushCancel->setGeometry(QRect(230, 230, 81, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        pushCancel->setFont(font);
        labelWeight = new QLabel(fortosi_progress_1_2Class);
        labelWeight->setObjectName(QString::fromUtf8("labelWeight"));
        labelWeight->setGeometry(QRect(230, 10, 81, 51));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        labelWeight->setFont(font1);
        pushProf = new QPushButton(fortosi_progress_1_2Class);
        pushProf->setObjectName(QString::fromUtf8("pushProf"));
        pushProf->setGeometry(QRect(120, 260, 85, 27));
        pushCheck = new QPushButton(fortosi_progress_1_2Class);
        pushCheck->setObjectName(QString::fromUtf8("pushCheck"));
        pushCheck->setGeometry(QRect(20, 260, 85, 27));
        labelPieces = new QLabel(fortosi_progress_1_2Class);
        labelPieces->setObjectName(QString::fromUtf8("labelPieces"));
        labelPieces->setGeometry(QRect(160, 40, 61, 31));
        QFont font2;
        font2.setPointSize(15);
        labelPieces->setFont(font2);

        retranslateUi(fortosi_progress_1_2Class);

        QMetaObject::connectSlotsByName(fortosi_progress_1_2Class);
    } // setupUi

    void retranslateUi(QDialog *fortosi_progress_1_2Class)
    {
        fortosi_progress_1_2Class->setWindowTitle(QApplication::translate("fortosi_progress_1_2Class", "\316\243\317\205\316\275\316\255\317\207\316\271\317\203\316\267 \316\246\317\214\317\201\317\204\317\211\317\203\316\267\317\202", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("fortosi_progress_1_2Class", "\316\240\316\265\316\273\316\254\317\204\316\267\317\202", 0, QApplication::UnicodeUTF8));
        labelCustomer->setText(QString());
        pushDelete->setText(QApplication::translate("fortosi_progress_1_2Class", "\316\224\316\271\316\261\316\263\317\201\316\261\317\206\316\256\n"
"\316\232\317\211\316\264\316\271\316\272\316\277\317\215", 0, QApplication::UnicodeUTF8));
        finalPush->setText(QApplication::translate("fortosi_progress_1_2Class", "\316\237\317\201\316\271\317\203\317\204\316\271\316\272\316\256\n"
"\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        tempPush->setText(QApplication::translate("fortosi_progress_1_2Class", "\316\240\317\201\316\277\317\203\317\211\317\201\316\271\316\275\316\256\n"
"\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushCancel->setText(QApplication::translate("fortosi_progress_1_2Class", "\316\247", 0, QApplication::UnicodeUTF8));
        labelWeight->setText(QString());
        pushProf->setText(QApplication::translate("fortosi_progress_1_2Class", "\316\243\317\215\316\263\316\272\317\201\316\271\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushCheck->setText(QApplication::translate("fortosi_progress_1_2Class", "\316\210\316\273\316\265\316\263\317\207\316\277\317\202", 0, QApplication::UnicodeUTF8));
        labelPieces->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fortosi_progress_1_2Class: public Ui_fortosi_progress_1_2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORTOSI_PROGRESS_1_2_H
