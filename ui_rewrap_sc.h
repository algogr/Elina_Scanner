/********************************************************************************
** Form generated from reading UI file 'rewrap_sc.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
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
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_rewrap_sc
{
public:
    QLineEdit *lineNew1;
    QLineEdit *lineNew4;
    QPushButton *pushCancel;
    QPushButton *pushInsert;
    QLineEdit *lineNew3;
    QLineEdit *lineOld;
    QLineEdit *lineNew2;
    QLineEdit *lineNew5;
    QFrame *line;
    QLineEdit *lineOldA;
    QLineEdit *lineNew1A;
    QLineEdit *lineNew2A;
    QLineEdit *lineNew3A;
    QLineEdit *lineNew4A;
    QLineEdit *lineNew5A;

    void setupUi(QDialog *rewrap_sc)
    {
        if (rewrap_sc->objectName().isEmpty())
            rewrap_sc->setObjectName(QString::fromUtf8("rewrap_sc"));
        rewrap_sc->resize(320, 300);
        lineNew1 = new QLineEdit(rewrap_sc);
        lineNew1->setObjectName(QString::fromUtf8("lineNew1"));
        lineNew1->setGeometry(QRect(180, 60, 113, 25));
        QFont font;
        font.setPointSize(8);
        lineNew1->setFont(font);
        lineNew4 = new QLineEdit(rewrap_sc);
        lineNew4->setObjectName(QString::fromUtf8("lineNew4"));
        lineNew4->setGeometry(QRect(180, 150, 113, 25));
        lineNew4->setFont(font);
        pushCancel = new QPushButton(rewrap_sc);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));
        pushCancel->setGeometry(QRect(180, 210, 85, 61));
        QFont font1;
        font1.setPointSize(10);
        pushCancel->setFont(font1);
        pushInsert = new QPushButton(rewrap_sc);
        pushInsert->setObjectName(QString::fromUtf8("pushInsert"));
        pushInsert->setGeometry(QRect(50, 210, 85, 61));
        pushInsert->setFont(font1);
        lineNew3 = new QLineEdit(rewrap_sc);
        lineNew3->setObjectName(QString::fromUtf8("lineNew3"));
        lineNew3->setGeometry(QRect(180, 120, 113, 25));
        lineNew3->setFont(font);
        lineOld = new QLineEdit(rewrap_sc);
        lineOld->setObjectName(QString::fromUtf8("lineOld"));
        lineOld->setGeometry(QRect(180, 10, 113, 25));
        lineOld->setFont(font);
        lineNew2 = new QLineEdit(rewrap_sc);
        lineNew2->setObjectName(QString::fromUtf8("lineNew2"));
        lineNew2->setGeometry(QRect(180, 90, 113, 25));
        lineNew2->setFont(font);
        lineNew5 = new QLineEdit(rewrap_sc);
        lineNew5->setObjectName(QString::fromUtf8("lineNew5"));
        lineNew5->setGeometry(QRect(180, 180, 113, 25));
        lineNew5->setFont(font);
        line = new QFrame(rewrap_sc);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 321, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lineOldA = new QLineEdit(rewrap_sc);
        lineOldA->setObjectName(QString::fromUtf8("lineOldA"));
        lineOldA->setGeometry(QRect(20, 10, 113, 25));
        lineOldA->setFont(font);
        lineNew1A = new QLineEdit(rewrap_sc);
        lineNew1A->setObjectName(QString::fromUtf8("lineNew1A"));
        lineNew1A->setGeometry(QRect(20, 60, 113, 25));
        lineNew1A->setFont(font);
        lineNew2A = new QLineEdit(rewrap_sc);
        lineNew2A->setObjectName(QString::fromUtf8("lineNew2A"));
        lineNew2A->setGeometry(QRect(20, 90, 113, 25));
        lineNew2A->setFont(font);
        lineNew3A = new QLineEdit(rewrap_sc);
        lineNew3A->setObjectName(QString::fromUtf8("lineNew3A"));
        lineNew3A->setGeometry(QRect(20, 120, 113, 25));
        lineNew3A->setFont(font);
        lineNew4A = new QLineEdit(rewrap_sc);
        lineNew4A->setObjectName(QString::fromUtf8("lineNew4A"));
        lineNew4A->setGeometry(QRect(20, 150, 113, 25));
        lineNew4A->setFont(font);
        lineNew5A = new QLineEdit(rewrap_sc);
        lineNew5A->setObjectName(QString::fromUtf8("lineNew5A"));
        lineNew5A->setGeometry(QRect(20, 180, 113, 25));
        lineNew5A->setFont(font);

        retranslateUi(rewrap_sc);

        QMetaObject::connectSlotsByName(rewrap_sc);
    } // setupUi

    void retranslateUi(QDialog *rewrap_sc)
    {
        rewrap_sc->setWindowTitle(QApplication::translate("rewrap_sc", "\316\221\316\275\316\261\317\204\317\215\316\273\316\271\316\276\316\267", 0, QApplication::UnicodeUTF8));
        pushCancel->setText(QApplication::translate("rewrap_sc", "\316\221\316\272\317\215\317\201\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushInsert->setText(QApplication::translate("rewrap_sc", "\316\232\316\261\317\204\316\261\317\207\317\216\317\201\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class rewrap_sc: public Ui_rewrap_sc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REWRAP_SC_H
