/********************************************************************************
** Form generated from reading UI file 'change_label.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_LABEL_H
#define UI_CHANGE_LABEL_H

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

class Ui_change_labelClass
{
public:
    QLineEdit *lineOld;
    QLineEdit *lineNew;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushBack;

    void setupUi(QDialog *change_labelClass)
    {
        if (change_labelClass->objectName().isEmpty())
            change_labelClass->setObjectName(QString::fromUtf8("change_labelClass"));
        change_labelClass->resize(320, 300);
        lineOld = new QLineEdit(change_labelClass);
        lineOld->setObjectName(QString::fromUtf8("lineOld"));
        lineOld->setGeometry(QRect(70, 60, 191, 41));
        lineNew = new QLineEdit(change_labelClass);
        lineNew->setObjectName(QString::fromUtf8("lineNew"));
        lineNew->setGeometry(QRect(70, 150, 191, 41));
        pushButton = new QPushButton(change_labelClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 230, 85, 27));
        label = new QLabel(change_labelClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 15, 131, 31));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label_2 = new QLabel(change_labelClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 120, 131, 21));
        label_2->setFont(font);
        pushBack = new QPushButton(change_labelClass);
        pushBack->setObjectName(QString::fromUtf8("pushBack"));
        pushBack->setGeometry(QRect(70, 230, 85, 27));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        pushBack->setFont(font1);

        retranslateUi(change_labelClass);

        QMetaObject::connectSlotsByName(change_labelClass);
    } // setupUi

    void retranslateUi(QDialog *change_labelClass)
    {
        change_labelClass->setWindowTitle(QApplication::translate("change_labelClass", "change_label", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("change_labelClass", "\316\221\316\273\316\273\316\261\316\263\316\256", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("change_labelClass", "\316\240\316\261\316\273\316\271\317\214\317\202 \316\232/\316\244", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("change_labelClass", "\316\235\316\255\316\277\317\202 \316\232/\316\244", 0, QApplication::UnicodeUTF8));
        pushBack->setText(QApplication::translate("change_labelClass", "<<", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class change_labelClass: public Ui_change_labelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_LABEL_H
