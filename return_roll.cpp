#include "return_roll.h"
#include "ui_return_roll.h"

return_roll::return_roll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::return_roll)
{
    ui->setupUi(this);
    QString ipath=(QString)APATH+"/img/app.png";
    QIcon *icon=new QIcon(ipath);

    this->setWindowIcon(*icon);
    ui->label->setVisible(FALSE);
    QHostAddress addr((QString) SVR_HOST);
    client = new QTcpSocket;
    client->connectToHost(addr, 8889);

    this->r = 0;
    lastscanned = "A";


    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
            << trUtf8("K/T") << trUtf8("K/A"));
    ui->tableWidget->setColumnWidth(0, 200);
    ui->tableWidget->setColumnWidth(1, 200);


    ui->pushButton->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);

    connect(ui->lineScan, SIGNAL(returnPressed()), this, SLOT(scan()));
    connect(ui->lineScan, SIGNAL(lostFocus()), this, SLOT(lock()));

    connect(ui->pushButton, SIGNAL(released()), this, SLOT(insert_db()));
    connect(this,SIGNAL(rejected()),this,SLOT(close_now()));
}

return_roll::~return_roll()
{
    delete ui;
    client->close();
}


void return_roll::close_now()
{


    delete(this);
}

void return_roll::scan() {
    ui->pushButton->setFocusPolicy(Qt::NoFocus);


        QString scanned = ui->lineScan->text();
        if (lastscanned.left(1) == "A" && scanned.left(1) == "A") {

            for (int i = 0; i < 15; ++i) {
                QApplication::beep();
            }
            QMessageBox m;

            m.setText(trUtf8("Πρέπει να διαβαστεί Κ/Τ"));
            m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
            m.setStandardButtons(QMessageBox::Ok);
            m.move(0, 100);
            QFont serifFont("Times", 18, QFont::Bold);
            m.setFont(serifFont);

            m.exec();

            ui->lineScan->setText("");
            ui->lineScan->setFocus();
            return;

        }

        if (lastscanned.left(1) != "A" && scanned.left(1) != "A") {
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
            ui->lineScan->setText("");
            ui->lineScan->setFocus();
            return;

        }

        for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
            if (ui->tableWidget->item(i, 0)->text() == scanned) {
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
                ui->lineScan->setText("");
                ui->lineScan->setFocus();
                return;
            }

        }
        if (scanned.left(1) != "A") {
            ui->tableWidget->setRowCount(r + 1);
            QTableWidgetItem *code = new QTableWidgetItem;
            QTableWidgetItem *code_a = new QTableWidgetItem;
            if (r > 0) {
                code->setText(ui->tableWidget->item(r - 1, 0)->text());
                code_a->setText(ui->tableWidget->item(r - 1, 1)->text());
            }
            ui->tableWidget->setItem(r, 0, code);
            ui->tableWidget->setItem(r, 1, code_a);

            for (int i = r - 1; i > 0; --i) {

                ui->tableWidget->item(i, 0)->setText(ui->tableWidget->item(i - 1,
                        0)->text());
                ui->tableWidget->item(i, 1)->setText(ui->tableWidget->item(i - 1,
                        1)->text());

            }
            ui->tableWidget->item(0, 0)->setText(scanned);
            ui->tableWidget->item(0, 1)->setText("");

            ui->lineScan->setText("");
            ui->lineScan->setFocus();

        } else {
            ui->tableWidget->item(0, 1)->setText(scanned);
            ui->lineScan->setText("");
            ui->lineScan->setFocus();

            ++r;

        }
        lastscanned = scanned;

    ui->pushButton->setFocusPolicy(Qt::NoFocus);

}

void return_roll::insert_db() {
    ui->pushButton->setEnabled(FALSE);
    ui->lineScan->setEnabled(FALSE);
    ui->label->setVisible(TRUE);
    QFile file("epistrofi.dat");
    QMap<QString, QString> records;
    if (!file.exists()) {
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "Cannot open file for writing: "
                    << qPrintable(file.errorString()) << endl;

        }
    } else
        file.open(QIODevice::Append);
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_1);

    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {

        QString code_t = ui->tableWidget->item(i, 0)->text();
        QString code_a = ui->tableWidget->item(i, 1)->text();

        out << code_t << code_a;
        if (code_t != "")
            create_row(code_t, code_a);

    }
    file.close();

    delete (this);
}

void return_roll::create_row(QString code_t, QString code_a) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);
    QString req_type = "RETURN_ROLL";
    out << quint16(0) << req_type << code_t << code_a;
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    client->write(block);
    QByteArray block1;
    QDataStream out1(&block, QIODevice::WriteOnly);
    out1.setVersion(QDataStream::Qt_4_1);
    out1 << quint16(0xFFFF);
    client->write(block1);

    return;
}

void return_roll::lock() {
    ui->lineScan->setFocus();
}

bool return_roll::eventFilter(QObject *object, QEvent *event) {
    if (event->type() == QEvent::FocusOut)
        ui->lineScan->setFocus();
    return FALSE;
}


