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
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Elina_ScannerClass
{
public:
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QLabel *statusLabel;
    QLabel *statusLabel_2;
    QPushButton *pushButton_9;
    QProgressBar *progressBar;

    void setupUi(QWidget *Elina_ScannerClass)
    {
        if (Elina_ScannerClass->objectName().isEmpty())
            Elina_ScannerClass->setObjectName(QString::fromUtf8("Elina_ScannerClass"));
        Elina_ScannerClass->resize(320, 300);
        pushButton_8 = new QPushButton(Elina_ScannerClass);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(220, 10, 85, 71));
        pushButton_3 = new QPushButton(Elina_ScannerClass);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 100, 85, 61));
        pushButton_4 = new QPushButton(Elina_ScannerClass);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(120, 100, 89, 61));
        pushButton_5 = new QPushButton(Elina_ScannerClass);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(220, 100, 85, 61));
        pushButton_6 = new QPushButton(Elina_ScannerClass);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 180, 85, 61));
        pushButton = new QPushButton(Elina_ScannerClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 11, 85, 71));
        pushButton_7 = new QPushButton(Elina_ScannerClass);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(120, 10, 85, 71));
        pushButton_2 = new QPushButton(Elina_ScannerClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 180, 85, 61));
        statusLabel = new QLabel(Elina_ScannerClass);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(10, 250, 91, 20));
        statusLabel_2 = new QLabel(Elina_ScannerClass);
        statusLabel_2->setObjectName(QString::fromUtf8("statusLabel_2"));
        statusLabel_2->setGeometry(QRect(220, 250, 91, 20));
        pushButton_9 = new QPushButton(Elina_ScannerClass);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(220, 180, 85, 61));
        progressBar = new QProgressBar(Elina_ScannerClass);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(110, 250, 101, 23));
        progressBar->setValue(0);

        retranslateUi(Elina_ScannerClass);

        QMetaObject::connectSlotsByName(Elina_ScannerClass);
    } // setupUi

    void retranslateUi(QWidget *Elina_ScannerClass)
    {
        Elina_ScannerClass->setWindowTitle(QApplication::translate("Elina_ScannerClass", "Scanner", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Elina_ScannerClass", "3.\316\221\316\275\316\261\317\204\317\215\316\273\316\271\316\276\316\267", 0, QApplication::UnicodeUTF8));
        pushButton_8->setShortcut(QApplication::translate("Elina_ScannerClass", "3", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Elina_ScannerClass", "4.\316\225\317\200\316\271\317\203\317\204\317\201\316\277\317\206\316\255\317\202", 0, QApplication::UnicodeUTF8));
        pushButton_3->setShortcut(QApplication::translate("Elina_ScannerClass", "4", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Elina_ScannerClass", "5.\316\221\316\273\316\273.\316\265\317\204\316\271\316\272\316\265\317\204.", 0, QApplication::UnicodeUTF8));
        pushButton_4->setShortcut(QApplication::translate("Elina_ScannerClass", "5", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Elina_ScannerClass", "6.\316\221\316\275\316\254\316\263\316\275\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton_5->setShortcut(QApplication::translate("Elina_ScannerClass", "6", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Elina_ScannerClass", "7.\316\221\316\275\316\261\316\273\317\205\317\204\316\256\317\202", 0, QApplication::UnicodeUTF8));
        pushButton_6->setShortcut(QApplication::translate("Elina_ScannerClass", "7", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Elina_ScannerClass", "1.\316\246\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton->setShortcut(QApplication::translate("Elina_ScannerClass", "1", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Elina_ScannerClass", "2.\316\240\317\201\316\277\317\206\317\214\317\201\317\204.", 0, QApplication::UnicodeUTF8));
        pushButton_7->setShortcut(QApplication::translate("Elina_ScannerClass", "2", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Elina_ScannerClass", "8.\316\221\317\200\316\277\316\263\317\201\316\261\317\206\316\256", 0, QApplication::UnicodeUTF8));
        pushButton_2->setShortcut(QApplication::translate("Elina_ScannerClass", "8", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QString());
        statusLabel_2->setText(QString());
        pushButton_9->setText(QApplication::translate("Elina_ScannerClass", "9.\316\221\317\200\316\277\317\203\317\204o\316\273\316\256", 0, QApplication::UnicodeUTF8));
        pushButton_9->setShortcut(QApplication::translate("Elina_ScannerClass", "8", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Elina_ScannerClass: public Ui_Elina_ScannerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELINA_SCANNER_H
