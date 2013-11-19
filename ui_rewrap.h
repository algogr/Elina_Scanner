/********************************************************************************
** Form generated from reading UI file 'rewrap.ui'
**
** Created: Tue Jul 10 12:30:59 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REWRAP_H
#define UI_REWRAP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rewrap
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *rewrap)
    {
        if (rewrap->objectName().isEmpty())
            rewrap->setObjectName(QString::fromUtf8("rewrap"));
        rewrap->resize(320, 300);
        lineEdit = new QLineEdit(rewrap);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 113, 31));
        lineEdit_2 = new QLineEdit(rewrap);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(180, 20, 113, 31));
        lineEdit_3 = new QLineEdit(rewrap);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(180, 80, 113, 31));
        lineEdit_4 = new QLineEdit(rewrap);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(180, 140, 113, 31));
        lineEdit_5 = new QLineEdit(rewrap);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(180, 200, 113, 31));
        lineEdit_6 = new QLineEdit(rewrap);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(180, 260, 113, 31));
        label = new QLabel(rewrap);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 5, 121, 21));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(rewrap);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 0, 121, 21));
        label_2->setFont(font);
        label_3 = new QLabel(rewrap);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 60, 121, 21));
        label_3->setFont(font);
        label_4 = new QLabel(rewrap);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 120, 121, 21));
        label_4->setFont(font);
        label_5 = new QLabel(rewrap);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 180, 121, 21));
        label_5->setFont(font);
        label_6 = new QLabel(rewrap);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(180, 240, 121, 21));
        label_6->setFont(font);
        pushButton = new QPushButton(rewrap);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 110, 85, 61));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(rewrap);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 190, 85, 61));
        pushButton_2->setFont(font);

        retranslateUi(rewrap);

        QMetaObject::connectSlotsByName(rewrap);
    } // setupUi

    void retranslateUi(QWidget *rewrap)
    {
        rewrap->setWindowTitle(QApplication::translate("rewrap", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("rewrap", "\316\232\317\211\316\264\316\271\316\272\317\214\317\202 \317\200\317\201\316\277\317\202 \316\261\316\275\316\261\317\204\317\215\316\273\316\271\316\276\316\267", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("rewrap", "1\316\277\317\202 \316\232\317\211\316\264\316\271\316\272\317\214\317\202", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("rewrap", "2\316\277\317\202 \316\232\317\211\316\264\316\271\316\272\317\214\317\202", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("rewrap", "3\316\277\317\202 \316\232\317\211\316\264\316\271\316\272\317\214\317\202", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("rewrap", "4\316\277\317\202 \316\232\317\211\316\264\316\271\316\272\317\214\317\202", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("rewrap", "5\316\277\317\202 \316\232\317\211\316\264\316\271\316\272\317\214\317\202", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("rewrap", "\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("rewrap", "\316\221\316\272\317\215\317\201\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class rewrap: public Ui_rewrap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REWRAP_H
