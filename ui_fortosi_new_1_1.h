/********************************************************************************
** Form generated from reading UI file 'fortosi_new_1_1.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORTOSI_NEW_1_1_H
#define UI_FORTOSI_NEW_1_1_H

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

class Ui_fortosi_new_1_1Class
{
public:
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;
    QPushButton *finalPush;
    QPushButton *back;
    QPushButton *pushdelrow;
    QLabel *labelWeight;
    QPushButton *devPush;
    QPushButton *pushCheck;
    QLabel *labelPieces;

    void setupUi(QDialog *fortosi_new_1_1Class)
    {
        if (fortosi_new_1_1Class->objectName().isEmpty())
            fortosi_new_1_1Class->setObjectName(QString::fromUtf8("fortosi_new_1_1Class"));
        fortosi_new_1_1Class->resize(320, 300);
        tableWidget = new QTableWidget(fortosi_new_1_1Class);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 70, 201, 192));
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);
        lineEdit = new QLineEdit(fortosi_new_1_1Class);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 151, 31));
        finalPush = new QPushButton(fortosi_new_1_1Class);
        finalPush->setObjectName(QString::fromUtf8("finalPush"));
        finalPush->setGeometry(QRect(220, 120, 91, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        finalPush->setFont(font);
        back = new QPushButton(fortosi_new_1_1Class);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(220, 240, 91, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        back->setFont(font1);
        pushdelrow = new QPushButton(fortosi_new_1_1Class);
        pushdelrow->setObjectName(QString::fromUtf8("pushdelrow"));
        pushdelrow->setEnabled(false);
        pushdelrow->setGeometry(QRect(220, 70, 91, 41));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        pushdelrow->setFont(font2);
        labelWeight = new QLabel(fortosi_new_1_1Class);
        labelWeight->setObjectName(QString::fromUtf8("labelWeight"));
        labelWeight->setGeometry(QRect(230, 20, 81, 41));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        labelWeight->setFont(font3);
        devPush = new QPushButton(fortosi_new_1_1Class);
        devPush->setObjectName(QString::fromUtf8("devPush"));
        devPush->setGeometry(QRect(220, 180, 91, 51));
        devPush->setFont(font);
        pushCheck = new QPushButton(fortosi_new_1_1Class);
        pushCheck->setObjectName(QString::fromUtf8("pushCheck"));
        pushCheck->setGeometry(QRect(20, 270, 85, 27));
        labelPieces = new QLabel(fortosi_new_1_1Class);
        labelPieces->setObjectName(QString::fromUtf8("labelPieces"));
        labelPieces->setGeometry(QRect(170, 20, 41, 41));
        QFont font4;
        font4.setPointSize(20);
        labelPieces->setFont(font4);

        retranslateUi(fortosi_new_1_1Class);

        QMetaObject::connectSlotsByName(fortosi_new_1_1Class);
    } // setupUi

    void retranslateUi(QDialog *fortosi_new_1_1Class)
    {
        fortosi_new_1_1Class->setWindowTitle(QApplication::translate("fortosi_new_1_1Class", "\316\235\316\255\316\261 \316\246\317\214\317\201\317\204\317\211\317\203\316\267 \316\272\316\261\317\204\316\254 \317\203\317\205\317\201\317\201\316\277\316\256", 0, QApplication::UnicodeUTF8));
        finalPush->setText(QApplication::translate("fortosi_new_1_1Class", "\316\237\317\201\316\271\317\203\317\204\316\271\316\272\316\256\n"
"\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        back->setText(QApplication::translate("fortosi_new_1_1Class", "X", 0, QApplication::UnicodeUTF8));
        pushdelrow->setText(QApplication::translate("fortosi_new_1_1Class", "\316\224\316\271\316\261\316\263\317\201\316\261\317\206\316\256 \n"
" \316\232\317\211\316\264\316\271\316\272\316\277\317\215", 0, QApplication::UnicodeUTF8));
        labelWeight->setText(QString());
        devPush->setText(QApplication::translate("fortosi_new_1_1Class", "\316\240\317\201\316\277\317\203\317\211\317\201\316\271\316\275\316\256\n"
"\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushCheck->setText(QApplication::translate("fortosi_new_1_1Class", "\316\210\316\273\316\265\316\263\317\207\316\277\317\202", 0, QApplication::UnicodeUTF8));
        labelPieces->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fortosi_new_1_1Class: public Ui_fortosi_new_1_1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORTOSI_NEW_1_1_H
