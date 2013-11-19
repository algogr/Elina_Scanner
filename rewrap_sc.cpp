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



    ui->label_new1->setVisible(FALSE);
    ui->label_new2->setVisible(FALSE);
    ui->label_new3->setVisible(FALSE);
    ui->label_new4->setVisible(FALSE);
    ui->label_new5->setVisible(FALSE);
    ui->lineNew1->setVisible(FALSE);
    ui->lineNew2->setVisible(FALSE);
    ui->lineNew3->setVisible(FALSE);
    ui->lineNew4->setVisible(FALSE);
    ui->lineNew5->setVisible(FALSE);
    ui->pushCancel->setEnabled(FALSE);
    ui->pushInsert->setEnabled(FALSE);
    ui->pushCancel->setFocusPolicy(Qt::NoFocus);
    ui->pushInsert->setFocusPolicy(Qt::NoFocus);
    connect(ui->lineOld, SIGNAL(returnPressed()), this, SLOT(scanned_old()));
    connect(ui->lineNew1, SIGNAL(returnPressed()), this, SLOT(scanned_new1()));
    connect(ui->lineNew2, SIGNAL(returnPressed()), this, SLOT(scanned_new2()));
    connect(ui->lineNew3, SIGNAL(returnPressed()), this, SLOT(scanned_new3()));
    connect(ui->lineNew4, SIGNAL(returnPressed()), this, SLOT(scanned_new4()));
    connect(ui->lineNew5, SIGNAL(returnPressed()), this, SLOT(scanned_new5()));
    connect(ui->pushCancel, SIGNAL(clicked()), this, SLOT(cancelClicked()));
    connect(ui->pushInsert, SIGNAL(clicked()), this, SLOT(insertClicked()));
    connect(this->client,SIGNAL(readyRead()),this,SLOT(startread()));
}

rewrap_sc::~rewrap_sc()
{
    delete client;
    delete client1;
    delete ui;
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
    ui->label_new1->setVisible(TRUE);
    ui->lineNew1->setVisible(TRUE);
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
    ui->label_new2->setVisible(TRUE);
    ui->lineNew2->setVisible(TRUE);
    ui->lineNew2->setFocus();
    ui->pushCancel->setEnabled(TRUE);
    ui->pushInsert->setEnabled(TRUE);
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
    ui->label_new3->setVisible(TRUE);
    ui->lineNew3->setVisible(TRUE);
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
    ui->label_new4->setVisible(TRUE);
    ui->lineNew4->setVisible(TRUE);
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
    ui->label_new5->setVisible(TRUE);
    ui->lineNew5->setVisible(TRUE);
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
            << ui->lineNew4->text() << ui->lineNew5->text());
    QString old_code = ui->lineOld->text();
    insert_production(old_code, new_codes);
    //delete(this);
}

void rewrap_sc::cancelClicked() {
    delete (this);
}

void rewrap_sc::insert_production(QString old_code, QStringList new_codes) {

            QString code1,code2,code3,code4,code5;
            code1=new_codes.value(0);
            if(new_codes.value(1)!="")
                code2=new_codes.value(1);
            if(new_codes.value(2)!="")
                code3=new_codes.value(2);
            if(new_codes.value(3)!="")
                code4=new_codes.value(3);
            if(new_codes.value(4)!="")
                code5=new_codes.value(4);


            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_4_1);
            QString req_type = "PRREWRAP";
            qDebug() << req_type << old_code << code1 << code2<< code3<< code4<< code5;;
            out << quint16(0) << req_type << old_code << code1 << code2<< code3<< code4<< code5;
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

        int last_record=0;
        if (pid2=="")
            last_record=1;
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_1);
        QString req_type = "KFREWRAP";
        out << quint16(0) << req_type << ui->lineOld->text() << ui->lineNew1->text() << f_code << pid1<< vardia <<last_record ;
        out.device()->seek(0);
        out << quint16(block.size() - sizeof(quint16));
        client->write(block);
        QByteArray block1;
        QDataStream out1(&block, QIODevice::WriteOnly);
        out1.setVersion(QDataStream::Qt_4_1);
        out1 << quint16(0xFFFF);
        client->write(block1);


        if (pid2!="")
        {
            QByteArray block;
            qDebug()<<"MPIKA2";
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_4_1);
            if (pid3=="")
                last_record=1;
            QString req_type = "KFREWRAP";
            out << quint16(0) << req_type << ui->lineOld->text() << ui->lineNew2->text() << f_code << pid2<< vardia <<last_record ;
            out.device()->seek(0);
            out << quint16(block.size() - sizeof(quint16));
            client->write(block);
            QByteArray block1;
            QDataStream out1(&block, QIODevice::WriteOnly);
            out1.setVersion(QDataStream::Qt_4_1);
            out1 << quint16(0xFFFF);
            client->write(block1);

        }

        if (pid3!="")
        {
            QByteArray block;
            qDebug()<<"MPIKA3";
            if (pid4=="")
                last_record=1;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_4_1);
            QString req_type = "KFREWRAP";
            out << quint16(0) << req_type << ui->lineOld->text() << ui->lineNew3->text() << f_code << pid3<< vardia <<last_record ;
            out.device()->seek(0);
            out << quint16(block.size() - sizeof(quint16));
            client->write(block);
            QByteArray block1;
            QDataStream out1(&block, QIODevice::WriteOnly);
            out1.setVersion(QDataStream::Qt_4_1);
            out1 << quint16(0xFFFF);
            client->write(block1);

        }

        if (pid4!="")
        {
            QByteArray block;
            qDebug()<<"MPIKA4";
            if (pid5=="")
                last_record=1;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_4_1);
            QString req_type = "KFREWRAP";
            out << quint16(0) << req_type << ui->lineOld->text() << ui->lineNew4->text() << f_code << pid4<< vardia <<last_record ;
            out.device()->seek(0);
            out << quint16(block.size() - sizeof(quint16));
            client->write(block);
            QByteArray block1;
            QDataStream out1(&block, QIODevice::WriteOnly);
            out1.setVersion(QDataStream::Qt_4_1);
            out1 << quint16(0xFFFF);
            client->write(block1);

        }

        if (pid5!="")
        {
            QByteArray block;
            qDebug()<<"MPIKA5";
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_4_1);
            QString req_type = "KFREWRAP";
            out << quint16(0) << req_type << ui->lineOld->text() << ui->lineNew5->text() << f_code << pid5<< vardia <<1 ;
            out.device()->seek(0);
            out << quint16(block.size() - sizeof(quint16));
            client->write(block);
            QByteArray block1;
            QDataStream out1(&block, QIODevice::WriteOnly);
            out1.setVersion(QDataStream::Qt_4_1);
            out1 << quint16(0xFFFF);
            client->write(block1);

        }

        QMessageBox m;
        QString mtext;
        m.setText(trUtf8("Η ανατύλιξη στάλθηκε επιτυχώς!"));
        //QSound::play("bell.wav");


        m.setStandardButtons(QMessageBox::Ok);
        m.move(80,120);
        //QFont serifFont("Times", 18, QFont::Bold);
        //m.setFont(serifFont);
        m.exec();

        ui->label_new1->setVisible(FALSE);
        ui->label_new2->setVisible(FALSE);
        ui->label_new3->setVisible(FALSE);
        ui->label_new4->setVisible(FALSE);
        ui->label_new5->setVisible(FALSE);
        ui->lineNew1->setVisible(FALSE);
        ui->lineNew2->setVisible(FALSE);
        ui->lineNew3->setVisible(FALSE);
        ui->lineNew4->setVisible(FALSE);
        ui->lineNew5->setVisible(FALSE);
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
