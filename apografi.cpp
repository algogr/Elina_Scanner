/*
    Elina Scanner Inventory Management
    Copyright (C) 2012 Dimitris Paraschou

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */
#include <QSound>
#include "apografi.h"
#include "stdio.h"
#include <iostream>

apografi::apografi(QWidget *parent, int mode) :
	QDialog(parent) {

	ui.setupUi(this);
	QString ipath=(QString)APATH+"/img/app.png";
	QIcon *icon=new QIcon(ipath);
    comment="";
	this->setWindowIcon(*icon);
	ui.label->setVisible(FALSE);
	QHostAddress addr((QString) SVR_HOST);
	//client = new QTcpSocket;
	//client->connectToHost(addr, 8889);

	this->r = 0;
	this->mode = mode;
	lastscanned = "A";

	if (mode == 0) {
		ui.tableWidget->setColumnCount(2);
		ui.tableWidget->setHorizontalHeaderLabels(QStringList()
				<< trUtf8("K/T") << trUtf8("K/A"));
		ui.tableWidget->setColumnWidth(0, 200);
		ui.tableWidget->setColumnWidth(1, 200);

	} else {
		ui.tableWidget->setColumnCount(1);
		ui.tableWidget->setHorizontalHeaderLabels(QStringList()
				<< trUtf8("K/T"));
		ui.tableWidget->setColumnWidth(0, 200);
	}
	ui.pushButton->setFocusPolicy(Qt::NoFocus);
    ui.pushButton_2->setFocusPolicy(Qt::NoFocus);
	ui.tableWidget->setFocusPolicy(Qt::NoFocus);


	connect(ui.lineScan, SIGNAL(returnPressed()), this, SLOT(scan()));
	connect(ui.lineScan, SIGNAL(lostFocus()), this, SLOT(lock()));

    connect(ui.pushButton, SIGNAL(released()), this, SLOT(comments()));
    connect(ui.pushButton_2,SIGNAL(released()),this,SLOT(info()));


}

apografi::~apografi() {


}



void apografi::scan() {
    qDebug()<<"0";
	if (lastscanned.left(1)=="A" || lastscanned.left(1)=="E")
		iska=TRUE;
	else
		iska=FALSE;
    qDebug()<<"4";
	ui.pushButton->setFocusPolicy(Qt::NoFocus);
    qDebug()<<"5";
	if (mode == 1) {
        qDebug()<<"6";
		QString scanned = ui.lineScan->text();
		for (int i = 0; i < ui.tableWidget->rowCount(); ++i) {
			if (ui.tableWidget->item(i, 0)->text() == scanned) {
				QMessageBox m;
				QSound::play("bell.wav");
				m.setText(trUtf8("O K/T έχει ήδη διαβαστεί"));
				m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
				m.setStandardButtons(QMessageBox::NoButton);
				m.move(0, 100);
				QFont serifFont("Times", 18, QFont::Bold);
				m.setFont(serifFont);

				m.exec();
				ui.lineScan->setText("");
				ui.lineScan->setFocus();

				return;
			}

		}

		ui.tableWidget->setRowCount(r + 1);
		QTableWidgetItem *code = new QTableWidgetItem;

		if (r > 0)
			code->setText(ui.tableWidget->item(r - 1, 0)->text());

		ui.tableWidget->setItem(r, 0, code);

		for (int i = r - 1; i > 0; --i) {

			ui.tableWidget->item(i, 0)->setText(
					ui.tableWidget->item(i - 1, 0)->text());

		}
		ui.tableWidget->item(0, 0)->setText(scanned);

		ui.lineScan->setText("");
		ui.lineScan->setFocus();

		++r;
	}

	else {
        qDebug()<<"7";
		QString scanned = ui.lineScan->text();

        qDebug()<<"8"<<"iska:"<<iska<<"left"<<scanned.left(1);
		if (iska==TRUE && (scanned.left(1) != "A" && scanned.left(1) != "E")) {
            qDebug()<<"1";

			QRegExp kt("\\d{12,12}[X-Z]\\d{2,2}");
			if (kt.exactMatch(scanned)==FALSE)
			{
                qDebug()<<"2";
				QMessageBox m;

				m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
				m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
				m.setStandardButtons(QMessageBox::Ok);
				m.move(0, 100);
				QFont serifFont("Times", 18, QFont::Bold);
				m.setFont(serifFont);
				m.exec();
				ui.lineScan->setText("");
				ui.lineScan->setFocus();
				return;


			}

		}

		if (iska==FALSE && (scanned.left(1) == "A" || scanned.left(1) == "E")) {

					QRegExp ka("\[AE]\\d{14,14}");

					if (ka.exactMatch(scanned)==FALSE)
					{
						QMessageBox m;

						m.setText(trUtf8("Λάθος μορφή  Κ/A"));
						m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
						m.setStandardButtons(QMessageBox::Ok);
						m.move(0, 100);
						QFont serifFont("Times", 18, QFont::Bold);
						m.setFont(serifFont);
						m.exec();
						ui.lineScan->setText("");
						ui.lineScan->setFocus();
						return;


					}

				}






        if (iska==TRUE &&(scanned.left(1) == "A" || scanned.left(1) == "E")) {
            qDebug()<<"11";
			for (int i = 0; i < 15; ++i) {
                qDebug()<<"12";
				QApplication::beep();
                qDebug()<<"13";
			}
            qDebug()<<"12";
			QMessageBox m;

			m.setText(trUtf8("Πρέπει να διαβαστεί Κ/Τ"));
			m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
			m.setStandardButtons(QMessageBox::Ok);
			m.move(0, 100);
			QFont serifFont("Times", 18, QFont::Bold);
			m.setFont(serifFont);

			m.exec();

			ui.lineScan->setText("");
			ui.lineScan->setFocus();
			return;

		}

		if (iska==FALSE && ((scanned.left(1) != "A") && (scanned.left(1) != "E"))) {
			qDebug()<<"ISKA:"<<iska<<"LEFT"<<scanned.left(1);
			for (int i = 0; i < 15; ++i) {
				QApplication::beep();
			}

			QMessageBox m;
			m.setText(trUtf8("Πρέπει να διαβαστεί Κ/A"));
			m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
			m.setStandardButtons(QMessageBox::Ok);
			QFont serifFont("Times", 18, QFont::Bold);
			m.setFont(serifFont);

			m.move(0, 100);
			m.exec();
			ui.lineScan->setText("");
			ui.lineScan->setFocus();
			return;

		}

		for (int i = 0; i < ui.tableWidget->rowCount(); ++i) {
			if (ui.tableWidget->item(i, 0)->text() == scanned) {
				for (int i = 0; i < 15; ++i) {
					QApplication::beep();
				}
				QMessageBox m;
				m.setText(trUtf8("O K/T έχει ήδη διαβαστεί"));
				m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
				m.setStandardButtons(QMessageBox::Ok);
				m.move(0, 100);
				QFont serifFont("Times", 18, QFont::Bold);
				m.setFont(serifFont);

				m.exec();
				ui.lineScan->setText("");
				ui.lineScan->setFocus();
				return;
			}

		}
		if ((scanned.left(1) != "A") && (scanned.left(1) != "E")) {
			ui.tableWidget->setRowCount(r + 1);
			QTableWidgetItem *code = new QTableWidgetItem;
			QTableWidgetItem *code_a = new QTableWidgetItem;
			if (r > 0) {
				code->setText(ui.tableWidget->item(r - 1, 0)->text());
				code_a->setText(ui.tableWidget->item(r - 1, 1)->text());
			}
			ui.tableWidget->setItem(r, 0, code);
			ui.tableWidget->setItem(r, 1, code_a);

			for (int i = r - 1; i > 0; --i) {

				ui.tableWidget->item(i, 0)->setText(ui.tableWidget->item(i - 1,
						0)->text());
				ui.tableWidget->item(i, 1)->setText(ui.tableWidget->item(i - 1,
						1)->text());

			}
			ui.tableWidget->item(0, 0)->setText(scanned);
			ui.tableWidget->item(0, 1)->setText("");

			ui.lineScan->setText("");
			ui.lineScan->setFocus();

		} else {
			ui.tableWidget->item(0, 1)->setText(scanned);
			ui.lineScan->setText("");
			ui.lineScan->setFocus();

			++r;

		}
		lastscanned = scanned;
	}
	ui.pushButton->setFocusPolicy(Qt::NoFocus);

}

void apografi::insert_db() {
	ui.pushButton->setEnabled(FALSE);
	ui.lineScan->setEnabled(FALSE);
	ui.label->setVisible(TRUE);
	QFile file("apografi.txt");
	QMap<QString, QString> records;
	if (!file.exists()) {
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			qDebug() << "Cannot open file for writing: "
					<< qPrintable(file.errorString()) << endl;

		}
	} else
		file.open(QIODevice::Append | QIODevice::Text);
	QTextStream out(&file);
	//out.setVersion(QDataStream::Qt_4_1);

	for (int i = 0; i < ui.tableWidget->rowCount(); ++i) {

		QString code_t = ui.tableWidget->item(i, 0)->text();
		QString code_a = ui.tableWidget->item(i, 1)->text();
        QString code=code_t+code_a+comment+"\n";
		//out << code_t << code_a;
        out<<code;
		//if (code_t != "")
			//create_row(code_t, code_a);

	}
	file.close();
	//this->hide();
	delete (this);
}


void apografi::lock() {
	ui.lineScan->setFocus();
}

bool apografi::eventFilter(QObject *object, QEvent *event) {
	if (event->type() == QEvent::FocusOut)
		ui.lineScan->setFocus();
	return FALSE;
}

void apografi::comments()
{
    apografi_comment *w=new apografi_comment(this);
    w->show();
}

void apografi::info()
{
    QFile file("apografi.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QVariant line_count=0;
    QString line=in.readLine();
    int no=0;
    while (!in.atEnd())
    {
        line_count=no++;
        line=in.readLine();
    }
    file.close();
    QVariant current_scan=ui.tableWidget->rowCount();
    QMessageBox m;
    m.setText(trUtf8("Κωδικοί στο αρχείο:")+line_count.toString());
    m.setInformativeText(trUtf8("Τρέχουσα σάρωση:")+current_scan.toString());
    m.setStandardButtons(QMessageBox::Ok);
    m.move(0, 100);
    QFont serifFont("Times", 18, QFont::Bold);
    m.setFont(serifFont);

    m.exec();

}
