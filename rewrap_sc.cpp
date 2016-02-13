#include "rewrap_sc.h"
#include "ui_rewrap_sc.h"

rewrap_sc::rewrap_sc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rewrap_sc)
{
    ui->setupUi(this);
    QHostAddress addr((QString)SVR_HOST);
    client = new QTcpSocket;
    client->connectToHost(addr, 8889);
    client1 = new QTcpSocket;
    client1->connectToHost(addr, 8889);

    nextblocksize=0;
    ui->pushInsert->setFocusPolicy(Qt::NoFocus);
    ui->pushCancel->setFocusPolicy(Qt::NoFocus);



    ui->lineNew1->setVisible(FALSE);
    ui->lineNew2->setVisible(FALSE);
    ui->lineNew3->setVisible(FALSE);
    ui->lineNew4->setVisible(FALSE);
    ui->lineNew5->setVisible(FALSE);
    ui->lineNew1A->setVisible(FALSE);
    ui->lineNew2A->setVisible(FALSE);
    ui->lineNew3A->setVisible(FALSE);
    ui->lineNew4A->setVisible(FALSE);
    ui->lineNew5A->setVisible(FALSE);
    ui->pushCancel->setEnabled(FALSE);
    ui->pushInsert->setEnabled(FALSE);
    ui->pushCancel->setFocusPolicy(Qt::NoFocus);
    ui->pushInsert->setFocusPolicy(Qt::NoFocus);
    connect(ui->lineOldA, SIGNAL(returnPressed()), this, SLOT(scanned_oldA()));
    connect(ui->lineNew1A, SIGNAL(returnPressed()), this, SLOT(scanned_new1A()));
    connect(ui->lineNew2A, SIGNAL(returnPressed()), this, SLOT(scanned_new2A()));
    connect(ui->lineNew3A, SIGNAL(returnPressed()), this, SLOT(scanned_new3A()));
    connect(ui->lineNew4A, SIGNAL(returnPressed()), this, SLOT(scanned_new4A()));
    connect(ui->lineNew5A, SIGNAL(returnPressed()), this, SLOT(scanned_new5A()));

    connect(ui->lineOld, SIGNAL(returnPressed()), this, SLOT(scanned_old()));
    connect(ui->lineNew1, SIGNAL(returnPressed()), this, SLOT(scanned_new1()));
    connect(ui->lineNew2, SIGNAL(returnPressed()), this, SLOT(scanned_new2()));
    connect(ui->lineNew3, SIGNAL(returnPressed()), this, SLOT(scanned_new3()));
    connect(ui->lineNew4, SIGNAL(returnPressed()), this, SLOT(scanned_new4()));
    connect(ui->lineNew5, SIGNAL(returnPressed()), this, SLOT(scanned_new5()));
    connect(ui->pushCancel, SIGNAL(clicked()), this, SLOT(cancelClicked()));
    connect(ui->pushInsert, SIGNAL(clicked()), this, SLOT(insertClicked()));
    connect(this->client,SIGNAL(readyRead()),this,SLOT(startread()));
    ui->lineOldA->setFocus();
}

rewrap_sc::~rewrap_sc()
{
    delete client;
    delete client1;
    delete ui;
}

void rewrap_sc::scanned_oldA() {
    QString scanned = ui->lineOldA->text();

    QRegExp ka("\[AE]\\d{14,14}");

    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineOldA->setText("");
        ui->lineOldA->setFocus();
        return;
    }
    ui->lineOld->setFocus();
}


void rewrap_sc::scanned_old() {
    QString scanned = ui->lineOld->text();

    QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
    if (kt.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineOld->setText("");
        ui->lineOld->setFocus();
        return;
    }
    ui->lineNew1A->setVisible(TRUE);
    ui->lineNew1->setVisible(TRUE);
    ui->lineNew1A->setFocus();
}

void rewrap_sc::scanned_new1A() {
    QString scanned = ui->lineNew1A->text();

    QRegExp ka("\[AE]\\d{14,14}");
    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineNew1A->setText("");
        ui->lineNew1A->setFocus();
        return;
    }

    ui->lineNew1->setFocus();



}

void rewrap_sc::scanned_new1() {
    QString scanned = ui->lineNew1->text();

    QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
    if (kt.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineNew1->setText("");
        ui->lineNew1->setFocus();
        return;
    }

    ui->lineNew2A->setVisible(TRUE);
    ui->lineNew2A->setFocus();
    ui->lineNew2->setVisible(TRUE);
    ui->pushCancel->setEnabled(TRUE);
    ui->pushInsert->setEnabled(TRUE);
}

void rewrap_sc::scanned_new2A() {
    QString scanned = ui->lineNew2A->text();

    QRegExp ka("\[AE]\\d{14,14}");
    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineNew2A->setText("");
        ui->lineNew2A->setFocus();
        return;
    }

    ui->lineNew2->setFocus();



}


void rewrap_sc::scanned_new2() {
    QString scanned = ui->lineNew2->text();

    QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
    if (kt.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineNew2->setText("");
        ui->lineNew2->setFocus();
        return;
    }

    ui->lineNew3A->setVisible(TRUE);
    ui->lineNew3A->setFocus();
    ui->lineNew3->setVisible(TRUE);
}

void rewrap_sc::scanned_new3A() {
    QString scanned = ui->lineNew3A->text();

    QRegExp ka("\[AE]\\d{14,14}");
    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineNew3A->setText("");
        ui->lineNew3A->setFocus();
        return;
    }

    ui->lineNew3->setFocus();



}


void rewrap_sc::scanned_new3() {
    QString scanned = ui->lineNew3->text();

    QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
    if (kt.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineNew3->setText("");
        ui->lineNew3->setFocus();
        return;
    }

    ui->lineNew4A->setVisible(TRUE);
    ui->lineNew4A->setFocus();
    ui->lineNew4->setVisible(TRUE);
}

void rewrap_sc::scanned_new4A() {
    QString scanned = ui->lineNew4A->text();

    QRegExp ka("\[AE]\\d{14,14}");
    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineNew4A->setText("");
        ui->lineNew4A->setFocus();
        return;
    }

    ui->lineNew4->setFocus();



}



void rewrap_sc::scanned_new4() {
    QString scanned = ui->lineNew4->text();

    QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
    if (kt.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineNew4->setText("");
        ui->lineNew4->setFocus();
        return;
    }

    ui->lineNew5A->setVisible(TRUE);
    ui->lineNew5A->setFocus();
    ui->lineNew5->setVisible(TRUE);
}


void rewrap_sc::scanned_new5A() {
    QString scanned = ui->lineNew5A->text();

    QRegExp ka("\[AE]\\d{14,14}");
    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineNew5A->setText("");
        ui->lineNew5A->setFocus();
        return;
    }

    ui->lineNew5->setFocus();



}


void rewrap_sc::scanned_new5() {
    QString scanned = ui->lineNew5->text();

    QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
    if (kt.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui->lineNew5->setText("");
        ui->lineNew5->setFocus();
        return;
    }

}

void rewrap_sc::insertClicked() {
    ui->pushInsert->setEnabled(FALSE);
    ui->pushCancel->setEnabled(FALSE);

    int newWeight = 0;
    int oldWeight = 0;

    newWeight += ui->lineNew1->text().left(3).toInt();
    qDebug() << "WEIGHT1:" << newWeight;
    if (ui->lineNew2->text() != "")
        newWeight += ui->lineNew2->text().left(3).toInt();
    qDebug() << "WEIGHT2:" << newWeight;
    if (ui->lineNew3->text() != "")
        newWeight += ui->lineNew3->text().left(3).toInt();
    qDebug() << "WEIGHT3:" << newWeight;
    if (ui->lineNew4->text() != "")
        newWeight += ui->lineNew4->text().left(3).toInt();
    qDebug() << "WEIGHT4:" << newWeight;
    if (ui->lineNew5->text() != "")
        newWeight += ui->lineNew5->text().left(3).toInt();
    qDebug() << "WEIGHT5:" << newWeight;
    oldWeight = ui->lineOld->text().left(3).toInt();
    qDebug() << "OLDWEIGHT:" << oldWeight;
    if (oldWeight <newWeight)  {
        QMessageBox m;

        m.setText(trUtf8("ΔΕΝ ΓΙΝΕΤΑΙ Η ΑΝΑΤΥΛΙΞΗ ΝΑ ΕΧΕΙ ΠΕΡΙΣΣΟΤΕΡΑ ΚΙΛΑ ΑΠΟ ΤΟ ΑΡΧΙΚΟ ΠΡΟΪΟΝ. ΚΑΛΕΣΤΕ ΕΝΑΝ ΥΠΕΥΘΥΝΟ."));
        m.setWindowTitle(trUtf8("ΛΑΘΟΣ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.move(200,200);
        m.exec();
        ui->pushInsert->setEnabled(TRUE);
        ui->pushCancel->setEnabled(TRUE);
        return;
    }

    if (oldWeight >newWeight) {
        QMessageBox m;

        m.setText(trUtf8("ΤΑ ΚΙΛΑ ΔΕΝ ΣΥΜΦΩΝΟΥΝ!ΝΑ ΠΕΡΑΣΩ ΤΑ ΚΙΛΑ ΠΟΥ ΠΕΡΙΣΣΕΥΟΥΝ ΩΣ ΦΥΡΑ;"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        QAbstractButton *acc1 = m.addButton(trUtf8("Ναί"),
                QMessageBox::ActionRole);
        QAbstractButton *rej1 = m.addButton(trUtf8("Όχι"),
                QMessageBox::ActionRole);
        m.move(0, 100);

        m.setDefaultButton((QPushButton*)rej1);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);

        m.exec();
        if (m.clickedButton() == rej1) {
            ui->pushInsert->setEnabled(TRUE);
            ui->pushCancel->setEnabled(TRUE);

            return;

        }





    }


    QStringList new_codes = (QStringList() << ui->lineNew1->text()
            << ui->lineNew2->text() << ui->lineNew3->text()
            << ui->lineNew4->text() << ui->lineNew5->text()
            << ui->lineNew1A->text() << ui->lineNew2A->text()
            << ui->lineNew3A->text() << ui->lineNew4A->text()
            << ui->lineNew5A->text());

    QStringList old_codes = (QStringList() << ui->lineOld->text() << ui->lineOldA->text());
    insert_production(old_codes, new_codes);
    //delete(this);
}

void rewrap_sc::cancelClicked() {
    delete (this);
}

void rewrap_sc::insert_production(QStringList old_codes, QStringList new_codes) {

            QString code1,code2,code3,code4,code5,code1A,code2A,code3A,code4A,code5A,oldcode,oldcodeA;
            code1=new_codes.value(0);
            if(new_codes.value(1)!="")
                code2=new_codes.value(1);
            if(new_codes.value(2)!="")
                code3=new_codes.value(2);
            if(new_codes.value(3)!="")
                code4=new_codes.value(3);
            if(new_codes.value(4)!="")
                code5=new_codes.value(4);
            code1A=new_codes.value(5);
            if(new_codes.value(6)!="")
                code2A=new_codes.value(6);
            if(new_codes.value(7)!="")
                code3A=new_codes.value(7);
            if(new_codes.value(8)!="")
                code4A=new_codes.value(8);
            if(new_codes.value(9)!="")
                code5A=new_codes.value(9);

            oldcode=old_codes.value(0);
            oldcodeA=old_codes.value(1);


            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_4_1);
            QString req_type = "PRREWRAP";
            qDebug() << req_type << oldcode << code1 << code2<< code3<< code4<< code5;
            out << quint16(0) << req_type << oldcode << code1 << code2 << code3 << code4 << code5
                << oldcodeA << code1A << code2A << code3A << code4A << code5A;
            out.device()->seek(0);
            out << quint16(block.size() - sizeof(quint16));
            client->write(block);
            QByteArray block1;
            QDataStream out1(&block, QIODevice::WriteOnly);
            out1.setVersion(QDataStream::Qt_4_1);
            out1 << quint16(0xFFFF);
            client->write(block1);



        }


void rewrap_sc::startread()
{
    QDataStream in(client);
    qDebug() << "MIKA";

    in.setVersion(QDataStream::Qt_4_1);


    forever {

        if (nextblocksize == 0) {

            if (client->bytesAvailable() < sizeof(quint16))
                break;
            //	qDebug()<<"MPIKA1";
            in >> nextblocksize;

        }

        if (nextblocksize == 0xFFFF) {
            //client->close();
            break;
        }

        if (client->bytesAvailable() < nextblocksize)
            break;
        QString f_code,vardia,pid1,pid2,pid3,pid4,pid5;


        in >>f_code>>vardia>>pid1>>pid2>>pid3>>pid4>>pid5;


        QMessageBox m;
        QString mtext;
        m.setText(trUtf8("Η ανατύλιξη στάλθηκε επιτυχώς!"));
        //QSound::play("bell.wav");


        m.setStandardButtons(QMessageBox::Ok);
        m.move(80,120);
        //QFont serifFont("Times", 18, QFont::Bold);
        //m.setFont(serifFont);
        m.exec();

        ui->lineNew1A->setVisible(FALSE);
        ui->lineNew2A->setVisible(FALSE);
        ui->lineNew3A->setVisible(FALSE);
        ui->lineNew4A->setVisible(FALSE);
        ui->lineNew5A->setVisible(FALSE);
        ui->lineNew1->setVisible(FALSE);
        ui->lineNew2->setVisible(FALSE);
        ui->lineNew3->setVisible(FALSE);
        ui->lineNew4->setVisible(FALSE);
        ui->lineNew5->setVisible(FALSE);

        ui->lineNew1A->setText("");
        ui->lineNew2A->setText("");
        ui->lineNew3A->setText("");
        ui->lineNew4A->setText("");
        ui->lineNew5A->setText("");
        ui->lineNew1->setText("");
        ui->lineNew2->setText("");
        ui->lineNew3->setText("");
        ui->lineNew4->setText("");
        ui->lineNew5->setText("");
        ui->lineOld->setText("");
        ui->lineOldA->setText("");

        ui->pushCancel->setEnabled(FALSE);
        ui->pushInsert->setEnabled(FALSE);
        ui->pushCancel->setFocusPolicy(Qt::NoFocus);
        ui->pushInsert->setFocusPolicy(Qt::NoFocus);


        //delete(this);






        //qDebug() << req_type;
        nextblocksize = 0;

    }
    nextblocksize = 0;
}
