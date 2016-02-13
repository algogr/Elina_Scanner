/********************************************************************************
** Form generated from reading UI file 'fortosi_progress_1.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORTOSI_PROGRESS_1_H
#define UI_FORTOSI_PROGRESS_1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_fortosi_progress_1Class
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushReview;
    QPushButton *pushBack;
    QPushButton *pushContinue;
    QPushButton *pushDelete;

    void setupUi(QDialog *fortosi_progress_1Class)
    {
        if (fortosi_progress_1Class->objectName().isEmpty())
            fortosi_progress_1Class->setObjectName(QString::fromUtf8("fortosi_progress_1Class"));
        fortosi_progress_1Class->resize(320, 300);
        tableWidget = new QTableWidget(fortosi_progress_1Class);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 60, 311, 161));
        tableWidget->verticalHeader()->setVisible(false);
        pushReview = new QPushButton(fortosi_progress_1Class);
        pushReview->setObjectName(QString::fromUtf8("pushReview"));
        pushReview->setGeometry(QRect(100, 10, 91, 41));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        pushReview->setFont(font);
        pushBack = new QPushButton(fortosi_progress_1Class);
        pushBack->setObjectName(QString::fromUtf8("pushBack"));
        pushBack->setGeometry(QRect(0, 10, 81, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        pushBack->setFont(font1);
        pushContinue = new QPushButton(fortosi_progress_1Class);
        pushContinue->setObjectName(QString::fromUtf8("pushContinue"));
        pushContinue->setGeometry(QRect(210, 10, 91, 41));
        pushContinue->setFont(font);
        pushDelete = new QPushButton(fortosi_progress_1Class);
        pushDelete->setObjectName(QString::fromUtf8("pushDelete"));
        pushDelete->setGeometry(QRect(110, 230, 85, 41));
        QFont font2;
        font2.setPointSize(10);
        pushDelete->setFont(font2);

        retranslateUi(fortosi_progress_1Class);

        QMetaObject::connectSlotsByName(fortosi_progress_1Class);
    } // setupUi

    void retranslateUi(QDialog *fortosi_progress_1Class)
    {
        fortosi_progress_1Class->setWindowTitle(QApplication::translate("fortosi_progress_1Class", "\316\246\316\277\317\201\317\204\317\216\317\203\316\265\316\271\317\202 \317\203\316\265 \316\265\316\276\316\255\316\273\316\271\316\276\316\267", 0, QApplication::UnicodeUTF8));
        pushReview->setText(QApplication::translate("fortosi_progress_1Class", "\316\221\316\275\316\261\317\203\316\272\317\214\317\200\316\267\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushBack->setText(QApplication::translate("fortosi_progress_1Class", "<<", 0, QApplication::UnicodeUTF8));
        pushContinue->setText(QApplication::translate("fortosi_progress_1Class", "\316\243\317\205\316\275\316\255\317\207\316\271\317\203\316\267", 0, QApplication::UnicodeUTF8));
        pushDelete->setText(QApplication::translate("fortosi_progress_1Class", "\316\224\316\271\316\261\316\263\317\201\316\261\317\206\316\256 ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fortosi_progress_1Class: public Ui_fortosi_progress_1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORTOSI_PROGRESS_1_H
