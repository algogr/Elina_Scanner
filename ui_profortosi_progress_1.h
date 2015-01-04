/********************************************************************************
** Form generated from reading UI file 'profortosi_progress_1.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFORTOSI_PROGRESS_1_H
#define UI_PROFORTOSI_PROGRESS_1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_profortosi_progress_1Class
{
public:
    QPushButton *pushReview;
    QPushButton *pushContinue;
    QTableWidget *tableWidget;
    QPushButton *pushBack;
    QPushButton *pushDelete;

    void setupUi(QDialog *profortosi_progress_1Class)
    {
        if (profortosi_progress_1Class->objectName().isEmpty())
            profortosi_progress_1Class->setObjectName(QString::fromUtf8("profortosi_progress_1Class"));
        profortosi_progress_1Class->resize(320, 300);
        pushReview = new QPushButton(profortosi_progress_1Class);
        pushReview->setObjectName(QString::fromUtf8("pushReview"));
        pushReview->setGeometry(QRect(110, 10, 91, 41));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        pushReview->setFont(font);
        pushContinue = new QPushButton(profortosi_progress_1Class);
        pushContinue->setObjectName(QString::fromUtf8("pushContinue"));
        pushContinue->setGeometry(QRect(220, 10, 91, 41));
        pushContinue->setFont(font);
        tableWidget = new QTableWidget(profortosi_progress_1Class);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 70, 311, 181));
        tableWidget->verticalHeader()->setVisible(false);
        pushBack = new QPushButton(profortosi_progress_1Class);
        pushBack->setObjectName(QString::fromUtf8("pushBack"));
        pushBack->setGeometry(QRect(10, 10, 81, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        pushBack->setFont(font1);
        pushDelete = new QPushButton(profortosi_progress_1Class);
        pushDelete->setObjectName(QString::fromUtf8("pushDelete"));
        pushDelete->setGeometry(QRect(110, 256, 85, 41));
        QFont font2;
        font2.setPointSize(10);
        pushDelete->setFont(font2);

        retranslateUi(profortosi_progress_1Class);

        QMetaObject::connectSlotsByName(profortosi_progress_1Class);
    } // setupUi

    void retranslateUi(QDialog *profortosi_progress_1Class)
    {
        profortosi_progress_1Class->setWindowTitle(QApplication::translate("profortosi_progress_1Class", "\316\240\317\201\316\277\317\206\316\277\317\201\317\204\317\216\317\203\316\265\316\271\317\202 \317\203\316\265 \316\265\316\276\316\255\316\273\316\271\316\276\316\267", 0, QApplication::UnicodeUTF8));
        pushReview->setText(QApplication::translate("profortosi_progress_1Class", "\316\221\316\275\316\261\317\203\316\272\317\214\317\200\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushContinue->setText(QApplication::translate("profortosi_progress_1Class", "\316\243\317\205\316\275\316\255\317\207\316\271\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushBack->setText(QApplication::translate("profortosi_progress_1Class", "<<", 0, QApplication::UnicodeUTF8));
        pushDelete->setText(QApplication::translate("profortosi_progress_1Class", "\316\224\316\271\316\261\316\263\317\201\316\261\317\206\316\256 ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class profortosi_progress_1Class: public Ui_profortosi_progress_1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFORTOSI_PROGRESS_1_H
