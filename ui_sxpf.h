/********************************************************************************
** Form generated from reading UI file 'sxpf.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SXPF_H
#define UI_SXPF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_sxpfClass
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QDialog *sxpfClass)
    {
        if (sxpfClass->objectName().isEmpty())
            sxpfClass->setObjectName(QString::fromUtf8("sxpfClass"));
        sxpfClass->resize(320, 300);
        pushButton = new QPushButton(sxpfClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 250, 85, 27));
        tableWidget = new QTableWidget(sxpfClass);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(15, 11, 291, 231));

        retranslateUi(sxpfClass);

        QMetaObject::connectSlotsByName(sxpfClass);
    } // setupUi

    void retranslateUi(QDialog *sxpfClass)
    {
        sxpfClass->setWindowTitle(QApplication::translate("sxpfClass", "\316\240\317\201\316\277\317\206\316\277\317\201\317\204\317\216\317\203\316\265\316\271\317\202", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("sxpfClass", "\316\225\317\200\316\271\316\273\316\277\316\263\316\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sxpfClass: public Ui_sxpfClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SXPF_H
