/********************************************************************************
** Form generated from reading UI file 'profortosi_new_1_1.ui'
**
** Created: Mon Jan 9 18:28:40 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFORTOSI_NEW_1_1_H
#define UI_PROFORTOSI_NEW_1_1_H

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

class Ui_profortosi_new_1_1Class
{
public:
    QLineEdit *lineEdit;
    QLabel *labelWeight;
    QTableWidget *tableWidget;
    QPushButton *pushdelrow;
    QPushButton *finalPush;
    QPushButton *back;
    QPushButton *devPush;
    QPushButton *pushCheck;
    QLabel *labelPieces;

    void setupUi(QDialog *profortosi_new_1_1Class)
    {
        if (profortosi_new_1_1Class->objectName().isEmpty())
            profortosi_new_1_1Class->setObjectName(QString::fromUtf8("profortosi_new_1_1Class"));
        profortosi_new_1_1Class->resize(320, 300);
        lineEdit = new QLineEdit(profortosi_new_1_1Class);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 22, 131, 31));
        labelWeight = new QLabel(profortosi_new_1_1Class);
        labelWeight->setObjectName(QString::fromUtf8("labelWeight"));
        labelWeight->setGeometry(QRect(220, 10, 91, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        labelWeight->setFont(font);
        tableWidget = new QTableWidget(profortosi_new_1_1Class);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 70, 201, 192));
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(true);
        pushdelrow = new QPushButton(profortosi_new_1_1Class);
        pushdelrow->setObjectName(QString::fromUtf8("pushdelrow"));
        pushdelrow->setEnabled(false);
        pushdelrow->setGeometry(QRect(220, 70, 91, 41));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        pushdelrow->setFont(font1);
        finalPush = new QPushButton(profortosi_new_1_1Class);
        finalPush->setObjectName(QString::fromUtf8("finalPush"));
        finalPush->setGeometry(QRect(220, 120, 91, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        finalPush->setFont(font2);
        back = new QPushButton(profortosi_new_1_1Class);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(220, 240, 91, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(30);
        font3.setBold(true);
        font3.setWeight(75);
        back->setFont(font3);
        devPush = new QPushButton(profortosi_new_1_1Class);
        devPush->setObjectName(QString::fromUtf8("devPush"));
        devPush->setGeometry(QRect(220, 180, 91, 51));
        devPush->setFont(font2);
        pushCheck = new QPushButton(profortosi_new_1_1Class);
        pushCheck->setObjectName(QString::fromUtf8("pushCheck"));
        pushCheck->setGeometry(QRect(10, 270, 85, 27));
        labelPieces = new QLabel(profortosi_new_1_1Class);
        labelPieces->setObjectName(QString::fromUtf8("labelPieces"));
        labelPieces->setGeometry(QRect(150, 10, 61, 51));
        QFont font4;
        font4.setPointSize(20);
        labelPieces->setFont(font4);

        retranslateUi(profortosi_new_1_1Class);

        QMetaObject::connectSlotsByName(profortosi_new_1_1Class);
    } // setupUi

    void retranslateUi(QDialog *profortosi_new_1_1Class)
    {
        profortosi_new_1_1Class->setWindowTitle(QApplication::translate("profortosi_new_1_1Class", "\316\235\316\255\316\261 \316\240\317\201\316\277\317\206\317\214\317\201\317\204\317\211\317\203\316\267 \316\272\316\261\317\204\316\254 \317\203\317\205\317\201\317\201\316\277\316\256", 0, QApplication::UnicodeUTF8));
        labelWeight->setText(QString());
        pushdelrow->setText(QApplication::translate("profortosi_new_1_1Class", "\316\224\316\271\316\261\316\263\317\201\316\261\317\206\316\256 \n"
" \316\232\317\211\316\264\316\271\316\272\316\277\317\215", 0, QApplication::UnicodeUTF8));
        finalPush->setText(QApplication::translate("profortosi_new_1_1Class", "\316\237\317\201\316\271\317\203\317\204\316\271\316\272\316\256\n"
"\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        back->setText(QApplication::translate("profortosi_new_1_1Class", "X", 0, QApplication::UnicodeUTF8));
        devPush->setText(QApplication::translate("profortosi_new_1_1Class", "\316\240\317\201\316\277\317\203\317\211\317\201\316\271\316\275\316\256\n"
"\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushCheck->setText(QApplication::translate("profortosi_new_1_1Class", "\316\210\316\273\316\265\316\263\317\207\316\277\317\202", 0, QApplication::UnicodeUTF8));
        labelPieces->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class profortosi_new_1_1Class: public Ui_profortosi_new_1_1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFORTOSI_NEW_1_1_H
