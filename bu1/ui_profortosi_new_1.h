/********************************************************************************
** Form generated from reading UI file 'profortosi_new_1.ui'
**
** Created: Fri Jun 17 11:39:21 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFORTOSI_NEW_1_H
#define UI_PROFORTOSI_NEW_1_H

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

class Ui_profortosi_new_1Class
{
public:
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QPushButton *pushBack;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QPushButton *pushFront;
    QTableWidget *tableWidget;

    void setupUi(QDialog *profortosi_new_1Class)
    {
        if (profortosi_new_1Class->objectName().isEmpty())
            profortosi_new_1Class->setObjectName(QString::fromUtf8("profortosi_new_1Class"));
        profortosi_new_1Class->resize(320, 300);
        label_2 = new QLabel(profortosi_new_1Class);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 230, 71, 16));
        lineEdit_2 = new QLineEdit(profortosi_new_1Class);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 260, 101, 31));
        lineEdit_3 = new QLineEdit(profortosi_new_1Class);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(90, 10, 221, 23));
        label = new QLabel(profortosi_new_1Class);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 61, 16));
        pushBack = new QPushButton(profortosi_new_1Class);
        pushBack->setObjectName(QString::fromUtf8("pushBack"));
        pushBack->setGeometry(QRect(190, 220, 61, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        pushBack->setFont(font);
        lineEdit = new QLineEdit(profortosi_new_1Class);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 220, 101, 31));
        label_3 = new QLabel(profortosi_new_1Class);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 270, 71, 16));
        pushFront = new QPushButton(profortosi_new_1Class);
        pushFront->setObjectName(QString::fromUtf8("pushFront"));
        pushFront->setGeometry(QRect(250, 220, 61, 71));
        pushFront->setFont(font);
        tableWidget = new QTableWidget(profortosi_new_1Class);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 40, 311, 171));
        tableWidget->verticalHeader()->setVisible(false);

        retranslateUi(profortosi_new_1Class);

        QMetaObject::connectSlotsByName(profortosi_new_1Class);
    } // setupUi

    void retranslateUi(QDialog *profortosi_new_1Class)
    {
        profortosi_new_1Class->setWindowTitle(QApplication::translate("profortosi_new_1Class", "\316\235\316\255\316\261 \316\240\317\201\316\277\317\206\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("profortosi_new_1Class", "\316\240\316\271\316\275\316\261\316\272\316\257\316\264\316\261 1:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("profortosi_new_1Class", "\316\240\316\265\316\273\316\254\317\204\316\267\317\202:", 0, QApplication::UnicodeUTF8));
        pushBack->setText(QApplication::translate("profortosi_new_1Class", "<<", 0, QApplication::UnicodeUTF8));
        pushBack->setShortcut(QApplication::translate("profortosi_new_1Class", "Esc", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("profortosi_new_1Class", "\316\240\316\271\316\275\316\261\316\272\316\257\316\264\316\261 2:", 0, QApplication::UnicodeUTF8));
        pushFront->setText(QApplication::translate("profortosi_new_1Class", ">>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class profortosi_new_1Class: public Ui_profortosi_new_1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFORTOSI_NEW_1_H
