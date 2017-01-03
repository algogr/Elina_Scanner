/********************************************************************************
** Form generated from reading UI file 'elina_scanner.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELINA_SCANNER_H
#define UI_ELINA_SCANNER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Elina_ScannerClass
{
public:
    QPushButton *bRewrap;
    QPushButton *bReturn;
    QPushButton *bChangeLabel;
    QPushButton *bReadLabel;
    QPushButton *bAnalyser;
    QPushButton *bFortosi;
    QPushButton *bApografi;
    QLabel *statusLabel;
    QLabel *statusLabel_2;
    QPushButton *bTransmitApografi;

    void setupUi(QWidget *Elina_ScannerClass)
    {
        if (Elina_ScannerClass->objectName().isEmpty())
            Elina_ScannerClass->setObjectName(QString::fromUtf8("Elina_ScannerClass"));
        Elina_ScannerClass->resize(320, 300);
        bRewrap = new QPushButton(Elina_ScannerClass);
        bRewrap->setObjectName(QString::fromUtf8("bRewrap"));
        bRewrap->setGeometry(QRect(120, 10, 85, 71));
        bReturn = new QPushButton(Elina_ScannerClass);
        bReturn->setObjectName(QString::fromUtf8("bReturn"));
        bReturn->setGeometry(QRect(220, 10, 85, 71));
        bChangeLabel = new QPushButton(Elina_ScannerClass);
        bChangeLabel->setObjectName(QString::fromUtf8("bChangeLabel"));
        bChangeLabel->setGeometry(QRect(20, 90, 89, 71));
        bReadLabel = new QPushButton(Elina_ScannerClass);
        bReadLabel->setObjectName(QString::fromUtf8("bReadLabel"));
        bReadLabel->setGeometry(QRect(120, 90, 85, 71));
        bAnalyser = new QPushButton(Elina_ScannerClass);
        bAnalyser->setObjectName(QString::fromUtf8("bAnalyser"));
        bAnalyser->setGeometry(QRect(220, 90, 85, 71));
        bFortosi = new QPushButton(Elina_ScannerClass);
        bFortosi->setObjectName(QString::fromUtf8("bFortosi"));
        bFortosi->setGeometry(QRect(20, 10, 85, 71));
        bApografi = new QPushButton(Elina_ScannerClass);
        bApografi->setObjectName(QString::fromUtf8("bApografi"));
        bApografi->setGeometry(QRect(20, 170, 85, 71));
        statusLabel = new QLabel(Elina_ScannerClass);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(20, 250, 121, 20));
        statusLabel_2 = new QLabel(Elina_ScannerClass);
        statusLabel_2->setObjectName(QString::fromUtf8("statusLabel_2"));
        statusLabel_2->setGeometry(QRect(180, 250, 121, 20));
        statusLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bTransmitApografi = new QPushButton(Elina_ScannerClass);
        bTransmitApografi->setObjectName(QString::fromUtf8("bTransmitApografi"));
        bTransmitApografi->setGeometry(QRect(220, 170, 85, 71));

        retranslateUi(Elina_ScannerClass);

        QMetaObject::connectSlotsByName(Elina_ScannerClass);
    } // setupUi

    void retranslateUi(QWidget *Elina_ScannerClass)
    {
        Elina_ScannerClass->setWindowTitle(QApplication::translate("Elina_ScannerClass", "Scanner", 0, QApplication::UnicodeUTF8));
        bRewrap->setText(QApplication::translate("Elina_ScannerClass", "2.\316\221\316\275\316\261\317\204\317\215\316\273\316\271\316\276\316\267", 0, QApplication::UnicodeUTF8));
        bRewrap->setShortcut(QApplication::translate("Elina_ScannerClass", "3", 0, QApplication::UnicodeUTF8));
        bReturn->setText(QApplication::translate("Elina_ScannerClass", "3.\316\225\317\200\316\271\317\203\317\204\317\201\316\277\317\206\316\255\317\202", 0, QApplication::UnicodeUTF8));
        bReturn->setShortcut(QApplication::translate("Elina_ScannerClass", "4", 0, QApplication::UnicodeUTF8));
        bChangeLabel->setText(QApplication::translate("Elina_ScannerClass", "4.\316\221\316\273\316\273.\316\265\317\204\316\271\316\272\316\265\317\204.", 0, QApplication::UnicodeUTF8));
        bChangeLabel->setShortcut(QApplication::translate("Elina_ScannerClass", "5", 0, QApplication::UnicodeUTF8));
        bReadLabel->setText(QApplication::translate("Elina_ScannerClass", "5.\316\221\316\275\316\254\316\263\316\275\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        bReadLabel->setShortcut(QApplication::translate("Elina_ScannerClass", "6", 0, QApplication::UnicodeUTF8));
        bAnalyser->setText(QApplication::translate("Elina_ScannerClass", "6.\316\221\316\275\316\261\316\273\317\205\317\204\316\256\317\202", 0, QApplication::UnicodeUTF8));
        bAnalyser->setShortcut(QApplication::translate("Elina_ScannerClass", "7", 0, QApplication::UnicodeUTF8));
        bFortosi->setText(QApplication::translate("Elina_ScannerClass", "1.\316\246\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        bFortosi->setShortcut(QApplication::translate("Elina_ScannerClass", "1", 0, QApplication::UnicodeUTF8));
        bApografi->setText(QApplication::translate("Elina_ScannerClass", "7.\316\221\317\200\316\277\316\263\317\201\316\261\317\206\316\256", 0, QApplication::UnicodeUTF8));
        bApografi->setShortcut(QApplication::translate("Elina_ScannerClass", "8", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QString());
        statusLabel_2->setText(QString());
        bTransmitApografi->setText(QApplication::translate("Elina_ScannerClass", "8.\316\221\317\200\316\277\317\203\317\204o\316\273\316\256", 0, QApplication::UnicodeUTF8));
        bTransmitApografi->setShortcut(QApplication::translate("Elina_ScannerClass", "8", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Elina_ScannerClass: public Ui_Elina_ScannerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELINA_SCANNER_H
