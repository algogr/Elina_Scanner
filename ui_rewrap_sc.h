/********************************************************************************
** Form generated from reading UI file 'rewrap_sc.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REWRAP_SC_H
#define UI_REWRAP_SC_H

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

class Ui_rewrap_sc
{
public:
    QLabel *label_new3;
    QLineEdit *lineNew1;
    QLineEdit *lineNew4;
    QLabel *label;
    QLabel *label_new4;
    QPushButton *pushCancel;
    QLabel *label_new1;
    QLabel *label_new2;
    QLabel *label_new5;
    QPushButton *pushInsert;
    QLineEdit *lineNew3;
    QLineEdit *lineOld;
    QLineEdit *lineNew2;
    QLineEdit *lineNew5;

    void setupUi(QDialog *rewrap_sc)
    {
        if (rewrap_sc->objectName().isEmpty())
            rewrap_sc->setObjectName(QString::fromUtf8("rewrap_sc"));
        rewrap_sc->resize(320, 300);
        label_new3 = new QLabel(rewrap_sc);
        label_new3->setObjectName(QString::fromUtf8("label_new3"));
        label_new3->setGeometry(QRect(180, 120, 121, 21));
        QFont font;
        font.setPointSize(10);
        label_new3->setFont(font);
        lineNew1 = new QLineEdit(rewrap_sc);
        lineNew1->setObjectName(QString::fromUtf8("lineNew1"));
        lineNew1->setGeometry(QRect(180, 20, 113, 31));
        lineNew4 = new QLineEdit(rewrap_sc);
        lineNew4->setObjectName(QString::fromUtf8("lineNew4"));
        lineNew4->setGeometry(QRect(180, 200, 113, 31));
        label = new QLabel(rewrap_sc);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 5, 121, 21));
        label->setFont(font);
        label_new4 = new QLabel(rewrap_sc);
        label_new4->setObjectName(QString::fromUtf8("label_new4"));
        label_new4->setGeometry(QRect(180, 180, 121, 21));
        label_new4->setFont(font);
        pushCancel = new QPushButton(rewrap_sc);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));
        pushCancel->setGeometry(QRect(20, 190, 85, 61));
        pushCancel->setFont(font);
        label_new1 = new QLabel(rewrap_sc);
        label_new1->setObjectName(QString::fromUtf8("label_new1"));
        label_new1->setGeometry(QRect(180, 0, 121, 21));
        label_new1->setFont(font);
        label_new2 = new QLabel(rewrap_sc);
        label_new2->setObjectName(QString::fromUtf8("label_new2"));
        label_new2->setGeometry(QRect(180, 60, 121, 21));
        label_new2->setFont(font);
        label_new5 = new QLabel(rewrap_sc);
        label_new5->setObjectName(QString::fromUtf8("label_new5"));
        label_new5->setGeometry(QRect(180, 240, 121, 21));
        label_new5->setFont(font);
        pushInsert = new QPushButton(rewrap_sc);
        pushInsert->setObjectName(QString::fromUtf8("pushInsert"));
        pushInsert->setGeometry(QRect(20, 110, 85, 61));
        pushInsert->setFont(font);
        lineNew3 = new QLineEdit(rewrap_sc);
        lineNew3->setObjectName(QString::fromUtf8("lineNew3"));
        lineNew3->setGeometry(QRect(180, 140, 113, 31));
        lineOld = new QLineEdit(rewrap_sc);
        lineOld->setObjectName(QString::fromUtf8("lineOld"));
        lineOld->setGeometry(QRect(10, 30, 113, 31));
        lineNew2 = new QLineEdit(rewrap_sc);
        lineNew2->setObjectName(QString::fromUtf8("lineNew2"));
        lineNew2->setGeometry(QRect(180, 80, 113, 31));
        lineNew5 = new QLineEdit(rewrap_sc);
        lineNew5->setObjectName(QString::fromUtf8("lineNew5"));
        lineNew5->setGeometry(QRect(180, 260, 113, 31));

        retranslateUi(rewrap_sc);

        QMetaObject::connectSlotsByName(rewrap_sc);
    } // setupUi

    void retranslateUi(QDialog *rewrap_sc)
    {
        rewrap_sc->setWindowTitle(QApplication::translate("rewrap_sc", "\316\221\316\275\316\261\317\204\317\215\316\273\316\271\316\276\316\267", 0, QApplication::UnicodeUTF8));
        label_new3->setText(QApplication::translate("rewrap_sc", "3\316\277\317\202 \316\232\317\211\316\264\316\271\316\272\317\214\317\202", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("rewrap_sc", "\316\232\317\211\316\264\316\271\316\272\317\214\317\202 \317\200\317\201\316\277\317\202 \316\261\316\275\316\261\317\204\317\215\316\273\316\271\316\276\316\267", 0, QApplication::UnicodeUTF8));
        label_new4->setText(QApplication::translate("rewrap_sc", "4\316\277\317\202 \316\232\317\211\316\264\316\271\316\272\317\214\317\202", 0, QApplication::UnicodeUTF8));
        pushCancel->setText(QApplication::translate("rewrap_sc", "\316\221\316\272\317\215\317\201\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        label_new1->setText(QApplication::translate("rewrap_sc", "1\316\277\317\202 \316\232\317\211\316\264\316\271\316\272\317\214\317\202", 0, QApplication::UnicodeUTF8));
        label_new2->setText(QApplication::translate("rewrap_sc", "2\316\277\317\202 \316\232\317\211\316\264\316\271\316\272\317\214\317\202", 0, QApplication::UnicodeUTF8));
        label_new5->setText(QApplication::translate("rewrap_sc", "5\316\277\317\202 \316\232\317\211\316\264\316\271\316\272\317\214\317\202", 0, QApplication::UnicodeUTF8));
        pushInsert->setText(QApplication::translate("rewrap_sc", "\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class rewrap_sc: public Ui_rewrap_sc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REWRAP_SC_H
