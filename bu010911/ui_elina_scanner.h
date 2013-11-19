/********************************************************************************
** Form generated from reading UI file 'elina_scanner.ui'
**
** Created: Tue May 3 18:08:20 2011
**      by: Qt User Interface Compiler version 4.6.3
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
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Elina_ScannerClass
{
public:
    QSplitter *splitter;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *Elina_ScannerClass)
    {
        if (Elina_ScannerClass->objectName().isEmpty())
            Elina_ScannerClass->setObjectName(QString::fromUtf8("Elina_ScannerClass"));
        Elina_ScannerClass->resize(320, 300);
        splitter = new QSplitter(Elina_ScannerClass);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(20, 11, 271, 281));
        splitter->setOrientation(Qt::Vertical);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        splitter->addWidget(pushButton);
        pushButton_7 = new QPushButton(splitter);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        splitter->addWidget(pushButton_7);
        pushButton_2 = new QPushButton(splitter);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        splitter->addWidget(pushButton_2);
        pushButton_3 = new QPushButton(splitter);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        splitter->addWidget(pushButton_3);
        pushButton_4 = new QPushButton(splitter);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        splitter->addWidget(pushButton_4);
        pushButton_5 = new QPushButton(splitter);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        splitter->addWidget(pushButton_5);
        pushButton_6 = new QPushButton(splitter);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        splitter->addWidget(pushButton_6);

        retranslateUi(Elina_ScannerClass);

        QMetaObject::connectSlotsByName(Elina_ScannerClass);
    } // setupUi

    void retranslateUi(QWidget *Elina_ScannerClass)
    {
        Elina_ScannerClass->setWindowTitle(QApplication::translate("Elina_ScannerClass", "Scanner", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Elina_ScannerClass", "1.\316\246\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton->setShortcut(QApplication::translate("Elina_ScannerClass", "1", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Elina_ScannerClass", "2.\316\240\317\201\316\277\317\206\317\214\317\201\317\204\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton_7->setShortcut(QApplication::translate("Elina_ScannerClass", "2", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Elina_ScannerClass", "3.\316\221\317\200\316\277\316\263\317\201\316\261\317\206\316\256", 0, QApplication::UnicodeUTF8));
        pushButton_2->setShortcut(QApplication::translate("Elina_ScannerClass", "3", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Elina_ScannerClass", "4.\316\225\317\200\316\271\317\203\317\204\317\201\316\277\317\206\316\255\317\202", 0, QApplication::UnicodeUTF8));
        pushButton_3->setShortcut(QApplication::translate("Elina_ScannerClass", "4", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Elina_ScannerClass", "5.\316\221\316\273\316\273\316\261\316\263\316\256 \316\225\317\204\316\271\316\272\316\255\317\204\316\261\317\202", 0, QApplication::UnicodeUTF8));
        pushButton_4->setShortcut(QApplication::translate("Elina_ScannerClass", "5", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Elina_ScannerClass", "6.\316\221\316\275\316\254\316\263\316\275\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushButton_5->setShortcut(QApplication::translate("Elina_ScannerClass", "6", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Elina_ScannerClass", "7.\316\232\316\261\317\204\316\261\317\203\317\204\317\201\316\277\317\206\316\256", 0, QApplication::UnicodeUTF8));
        pushButton_6->setShortcut(QApplication::translate("Elina_ScannerClass", "7", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Elina_ScannerClass: public Ui_Elina_ScannerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELINA_SCANNER_H
