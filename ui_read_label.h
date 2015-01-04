/********************************************************************************
** Form generated from reading UI file 'read_label.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READ_LABEL_H
#define UI_READ_LABEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_read_labelClass
{
public:
    QLineEdit *lineEdit;
    QLabel *labelcode;
    QLabel *labelper;
    QLabel *labelxrisi;
    QLabel *labelgrm;
    QLabel *labelepimikinsi;
    QLabel *labelfylla;
    QLabel *labelmd;
    QLabel *labelcd;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *read_labelClass)
    {
        if (read_labelClass->objectName().isEmpty())
            read_labelClass->setObjectName(QString::fromUtf8("read_labelClass"));
        read_labelClass->resize(320, 300);
        lineEdit = new QLineEdit(read_labelClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 151, 31));
        labelcode = new QLabel(read_labelClass);
        labelcode->setObjectName(QString::fromUtf8("labelcode"));
        labelcode->setGeometry(QRect(200, 10, 111, 21));
        QFont font;
        font.setPointSize(11);
        labelcode->setFont(font);
        labelper = new QLabel(read_labelClass);
        labelper->setObjectName(QString::fromUtf8("labelper"));
        labelper->setGeometry(QRect(10, 50, 301, 21));
        QFont font1;
        font1.setPointSize(12);
        labelper->setFont(font1);
        labelxrisi = new QLabel(read_labelClass);
        labelxrisi->setObjectName(QString::fromUtf8("labelxrisi"));
        labelxrisi->setGeometry(QRect(10, 75, 301, 21));
        labelxrisi->setFont(font1);
        labelgrm = new QLabel(read_labelClass);
        labelgrm->setObjectName(QString::fromUtf8("labelgrm"));
        labelgrm->setGeometry(QRect(100, 100, 91, 31));
        labelgrm->setFont(font1);
        labelepimikinsi = new QLabel(read_labelClass);
        labelepimikinsi->setObjectName(QString::fromUtf8("labelepimikinsi"));
        labelepimikinsi->setGeometry(QRect(100, 140, 39, 31));
        labelepimikinsi->setFont(font1);
        labelfylla = new QLabel(read_labelClass);
        labelfylla->setObjectName(QString::fromUtf8("labelfylla"));
        labelfylla->setGeometry(QRect(100, 180, 71, 31));
        labelfylla->setFont(font1);
        labelmd = new QLabel(read_labelClass);
        labelmd->setObjectName(QString::fromUtf8("labelmd"));
        labelmd->setGeometry(QRect(20, 230, 81, 31));
        labelmd->setFont(font1);
        labelcd = new QLabel(read_labelClass);
        labelcd->setObjectName(QString::fromUtf8("labelcd"));
        labelcd->setGeometry(QRect(160, 230, 81, 31));
        labelcd->setFont(font1);
        label = new QLabel(read_labelClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 100, 71, 31));
        label->setFont(font1);
        label_2 = new QLabel(read_labelClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 140, 81, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(read_labelClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 180, 71, 31));
        label_3->setFont(font1);
        label_4 = new QLabel(read_labelClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 230, 21, 31));
        label_4->setFont(font1);
        pushButton = new QPushButton(read_labelClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 10, 31, 27));
        pushButton_2 = new QPushButton(read_labelClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 230, 51, 51));

        retranslateUi(read_labelClass);

        QMetaObject::connectSlotsByName(read_labelClass);
    } // setupUi

    void retranslateUi(QDialog *read_labelClass)
    {
        read_labelClass->setWindowTitle(QApplication::translate("read_labelClass", "\316\221\316\275\316\254\316\263\316\275\317\211\317\203\316\267 \316\225\317\204\316\271\316\272\316\255\317\204\316\261\317\202", 0, QApplication::UnicodeUTF8));
        labelcode->setText(QString());
        labelper->setText(QString());
        labelxrisi->setText(QString());
        labelgrm->setText(QString());
        labelepimikinsi->setText(QString());
        labelfylla->setText(QString());
        labelmd->setText(QString());
        labelcd->setText(QString());
        label->setText(QApplication::translate("read_labelClass", "\316\223\317\201\316\261\316\274\316\274\316\254\317\201\316\271\316\261", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("read_labelClass", "\316\225\317\200\316\271\316\274\316\256\316\272\317\205\316\275\317\203\316\267", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("read_labelClass", "\316\246\317\215\316\273\316\273\316\261", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("read_labelClass", "/", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class read_labelClass: public Ui_read_labelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READ_LABEL_H
