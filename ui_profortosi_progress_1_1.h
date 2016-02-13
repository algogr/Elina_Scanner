/********************************************************************************
** Form generated from reading UI file 'profortosi_progress_1_1.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFORTOSI_PROGRESS_1_1_H
#define UI_PROFORTOSI_PROGRESS_1_1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_profortosi_progress_1_1Class
{
public:
    QLabel *labelCustomer;
    QLabel *labelCar1;
    QLabel *label_2;
    QPushButton *pushBack;
    QLabel *label;
    QTableWidget *tableWidget;
    QLabel *labelCar2;
    QLabel *labelWeight;
    QLabel *label_3;

    void setupUi(QDialog *profortosi_progress_1_1Class)
    {
        if (profortosi_progress_1_1Class->objectName().isEmpty())
            profortosi_progress_1_1Class->setObjectName(QString::fromUtf8("profortosi_progress_1_1Class"));
        profortosi_progress_1_1Class->resize(320, 300);
        labelCustomer = new QLabel(profortosi_progress_1_1Class);
        labelCustomer->setObjectName(QString::fromUtf8("labelCustomer"));
        labelCustomer->setGeometry(QRect(90, 10, 221, 21));
        labelCar1 = new QLabel(profortosi_progress_1_1Class);
        labelCar1->setObjectName(QString::fromUtf8("labelCar1"));
        labelCar1->setGeometry(QRect(90, 40, 71, 16));
        label_2 = new QLabel(profortosi_progress_1_1Class);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 71, 16));
        pushBack = new QPushButton(profortosi_progress_1_1Class);
        pushBack->setObjectName(QString::fromUtf8("pushBack"));
        pushBack->setGeometry(QRect(220, 60, 81, 31));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        pushBack->setFont(font);
        label = new QLabel(profortosi_progress_1_1Class);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 61, 16));
        tableWidget = new QTableWidget(profortosi_progress_1_1Class);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 100, 311, 192));
        labelCar2 = new QLabel(profortosi_progress_1_1Class);
        labelCar2->setObjectName(QString::fromUtf8("labelCar2"));
        labelCar2->setGeometry(QRect(90, 70, 61, 16));
        labelWeight = new QLabel(profortosi_progress_1_1Class);
        labelWeight->setObjectName(QString::fromUtf8("labelWeight"));
        labelWeight->setGeometry(QRect(230, 40, 61, 16));
        label_3 = new QLabel(profortosi_progress_1_1Class);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 71, 16));

        retranslateUi(profortosi_progress_1_1Class);

        QMetaObject::connectSlotsByName(profortosi_progress_1_1Class);
    } // setupUi

    void retranslateUi(QDialog *profortosi_progress_1_1Class)
    {
        profortosi_progress_1_1Class->setWindowTitle(QApplication::translate("profortosi_progress_1_1Class", "\316\221\316\275\316\261\317\203\316\272\317\214\317\200\316\267\317\203\316\267 \317\200\317\201\316\277\317\206\317\214\317\201\317\204\317\211\317\203\316\267\317\202", 0, QApplication::UnicodeUTF8));
        labelCustomer->setText(QString());
        labelCar1->setText(QString());
        label_2->setText(QApplication::translate("profortosi_progress_1_1Class", "\316\240\316\271\316\275\316\261\316\272\316\257\316\264\316\261 1", 0, QApplication::UnicodeUTF8));
        pushBack->setText(QApplication::translate("profortosi_progress_1_1Class", "<<", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("profortosi_progress_1_1Class", "\316\240\316\265\316\273\316\254\317\204\316\267\317\202", 0, QApplication::UnicodeUTF8));
        labelCar2->setText(QString());
        labelWeight->setText(QString());
        label_3->setText(QApplication::translate("profortosi_progress_1_1Class", "\316\240\316\271\316\275\316\261\316\272\316\257\316\264\316\261 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class profortosi_progress_1_1Class: public Ui_profortosi_progress_1_1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFORTOSI_PROGRESS_1_1_H
