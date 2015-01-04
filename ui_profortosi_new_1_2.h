/********************************************************************************
** Form generated from reading UI file 'profortosi_new_1_2.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFORTOSI_NEW_1_2_H
#define UI_PROFORTOSI_NEW_1_2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profortosi_new_1_2Class
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit_2;
    QTableWidget *tableWidget_2;
    QWidget *tab_3;
    QWidget *tab_2;
    QLineEdit *lineEdit;
    QPushButton *deleteButton;
    QTableWidget *tableWidget;
    QPushButton *finalButton;
    QPushButton *pushTemp;
    QPushButton *pushExit;
    QLabel *labelWeight;

    void setupUi(QDialog *profortosi_new_1_2Class)
    {
        if (profortosi_new_1_2Class->objectName().isEmpty())
            profortosi_new_1_2Class->setObjectName(QString::fromUtf8("profortosi_new_1_2Class"));
        profortosi_new_1_2Class->resize(320, 300);
        tabWidget = new QTabWidget(profortosi_new_1_2Class);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 301, 281));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 10, 211, 31));
        tableWidget_2 = new QTableWidget(tab);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 50, 211, 192));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, 10, 191, 31));
        deleteButton = new QPushButton(tab_2);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(false);
        deleteButton->setGeometry(QRect(210, 50, 81, 41));
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 50, 201, 192));
        finalButton = new QPushButton(tab_2);
        finalButton->setObjectName(QString::fromUtf8("finalButton"));
        finalButton->setEnabled(true);
        finalButton->setGeometry(QRect(210, 100, 81, 41));
        pushTemp = new QPushButton(tab_2);
        pushTemp->setObjectName(QString::fromUtf8("pushTemp"));
        pushTemp->setEnabled(true);
        pushTemp->setGeometry(QRect(210, 150, 81, 41));
        pushExit = new QPushButton(tab_2);
        pushExit->setObjectName(QString::fromUtf8("pushExit"));
        pushExit->setEnabled(true);
        pushExit->setGeometry(QRect(210, 200, 81, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        pushExit->setFont(font);
        labelWeight = new QLabel(tab_2);
        labelWeight->setObjectName(QString::fromUtf8("labelWeight"));
        labelWeight->setGeometry(QRect(210, 14, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AlArabiya"));
        font1.setPointSize(20);
        labelWeight->setFont(font1);
        tabWidget->addTab(tab_2, QString());

        retranslateUi(profortosi_new_1_2Class);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(profortosi_new_1_2Class);
    } // setupUi

    void retranslateUi(QDialog *profortosi_new_1_2Class)
    {
        profortosi_new_1_2Class->setWindowTitle(QApplication::translate("profortosi_new_1_2Class", "\316\235\316\255\316\261 \317\200\317\201\316\277\317\206\317\214\317\201\317\204\317\211\317\203\316\267 \316\272\316\261\317\204\316\254 \316\272\317\211\316\264\316\271\316\272\317\214", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("profortosi_new_1_2Class", "\316\232\317\211\316\264\316\271\316\272\316\277\317\202 \316\221", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("profortosi_new_1_2Class", "\316\240\317\201\316\277\316\264\316\271\316\261\316\263\317\201\316\261\317\206\316\255\317\202", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("profortosi_new_1_2Class", "\316\224\316\271\316\261\316\263\317\201\316\261\317\206\316\256 \n"
" \316\232\317\211\316\264\316\271\316\272\316\277\317\215", 0, QApplication::UnicodeUTF8));
        finalButton->setText(QApplication::translate("profortosi_new_1_2Class", "\316\237\317\201\316\271\317\203\317\204\316\271\316\272\316\256\n"
"\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushTemp->setText(QApplication::translate("profortosi_new_1_2Class", "\316\240\317\201\316\277\317\203\317\211\317\201\316\271\316\275\316\256\n"
"\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushExit->setText(QApplication::translate("profortosi_new_1_2Class", "\316\247", 0, QApplication::UnicodeUTF8));
        labelWeight->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("profortosi_new_1_2Class", "Scan", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class profortosi_new_1_2Class: public Ui_profortosi_new_1_2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFORTOSI_NEW_1_2_H
