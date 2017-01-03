#include "rewrap_sc.h"
#include "ui_rewrap_sc.h"

rewrap_sc::rewrap_sc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rewrap_sc)
{
    ui->setupUi(this);
    this->setWindowFlags( ( (this->windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowCloseButtonHint) );
    QHostAddress addr((QString)SVR_HOST);
    client = new QTcpSocket;
    client->connectToHost(addr, 8889);

    nextblocksize=0;
    ui->pushInsert->setFocusPolicy(Qt::NoFocus);
    ui->pushCancel->setFocusPolicy(Qt::NoFocus);

    resetControls();

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
    connect(client,SIGNAL(readyRead()),this,SLOT(startread()));
    ui->lineOldA->setFocus();
}

rewrap_sc::~rewrap_sc()
{
    delete client;
    delete ui;
}

void rewrap_sc::scanned_oldA() {
    QString scanned = ui->lineOldA->text();

    if (!check_ka(scanned))
    {
        ui->lineOldA->setText("");
        ui->lineOldA->setFocus();
        return;
    }

    ui->lineOld->setFocus();
}


void rewrap_sc::scanned_old() {
    QString scanned = ui->lineOld->text();

    if (!check_kt(scanned))
    {
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


    if (!check_ka(scanned)) {
        ui->lineNew1A->setText("");
        ui->lineNew1A->setFocus();
        return;
    }

    ui->lineNew1->setFocus();



}

void rewrap_sc::scanned_new1() {
    QString scanned = ui->lineNew1->text();


    if (!check_kt(scanned)) {
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


    if (!check_ka(scanned)) {

        ui->lineNew2A->setText("");
        ui->lineNew2A->setFocus();
        return;
    }

    ui->lineNew2->setFocus();



}


void rewrap_sc::scanned_new2() {
    QString scanned = ui->lineNew2->text();


    if (!check_kt(scanned)) {
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


    if (!check_ka(scanned)) {
        ui->lineNew3A->setText("");
        ui->lineNew3A->setFocus();
        return;
    }

    ui->lineNew3->setFocus();



}


void rewrap_sc::scanned_new3() {
    QString scanned = ui->lineNew3->text();


    if (!check_kt(scanned)) {
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


    if (!check_ka(scanned)) {
        ui->lineNew4A->setText("");
        ui->lineNew4A->setFocus();
        return;
    }

    ui->lineNew4->setFocus();



}



void rewrap_sc::scanned_new4() {
    QString scanned = ui->lineNew4->text();


    if (!check_kt(scanned)) {

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


    if (!check_ka(scanned)) {
        ui->lineNew5A->setText("");
        ui->lineNew5A->setFocus();
        return;
    }

    ui->lineNew5->setFocus();



}


void rewrap_sc::scanned_new5() {
    QString scanned = ui->lineNew5->text();


    if (!check_kt(scanned)) {
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


    QStringList new_codesA = QStringList() <<  ui->lineNew1A->text();
    if (ui->lineNew2A->text()!="")
        new_codesA<< ui->lineNew2A->text();
    if (ui->lineNew3A->text()!="")
        new_codesA<< ui->lineNew3A->text();
    if (ui->lineNew4A->text()!="")
        new_codesA<< ui->lineNew4A->text();
    if (ui->lineNew5A->text()!="")
        new_codesA<< ui->lineNew5A->text();


    QStringList new_codes = QStringList() << ui->lineNew1->text();
    if (ui->lineNew2->text()!="")
        new_codes<< ui->lineNew2->text();
    if (ui->lineNew3->text()!="")
        new_codes<< ui->lineNew3->text();
    if (ui->lineNew4->text()!="")
        new_codes<< ui->lineNew4->text();
    if (ui->lineNew5->text()!="")
        new_codes<< ui->lineNew5->text();



    QStringList old_codes = (QStringList() << ui->lineOld->text() << ui->lineOldA->text());
    insert_production(old_codes, new_codes,new_codesA);

}

void rewrap_sc::cancelClicked() {
    delete (this);
}

void rewrap_sc::resetControls()
{
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
    ui->pushCancel->setEnabled(TRUE);
    ui->pushInsert->setEnabled(FALSE);
    ui->lineOld->setText("");
    ui->lineOldA->setText("");


}

void rewrap_sc::insert_production(QStringList old_codes, QStringList new_codes,QStringList new_codesA) {




            for (int i=0;i<new_codes.size();i++)

            {
                QByteArray block;
                QDataStream out(&block, QIODevice::WriteOnly);
                out.setVersion(QDataStream::Qt_4_1);
                QString req_type = "PRREWRAP";
                out << quint16(0) << req_type << old_codes[0] << old_codes[1] << new_codes[i] << new_codesA[i];
                qDebug() << req_type << old_codes[0] << old_codes[1] << new_codes[i] << new_codesA[i];
                out.device()->seek(0);
                out << quint16(block.size() - sizeof(quint16));
                client->write(block);
                QByteArray block1;
                QDataStream out1(&block, QIODevice::WriteOnly);
                out1.setVersion(QDataStream::Qt_4_1);
                out1 << quint16(0xFFFF);
                client->write(block1);
            }




}

bool rewrap_sc::check_ka(const QString &code)
{
    QRegExp ka("\[AE]\\d{14,14}");

    if (ka.exactMatch(code) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        return false;
    }
    return true;

}

bool rewrap_sc::check_kt(const QString &code)
{
    QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
    if (kt.exactMatch(code) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        return false;
    }
    return true;

}



void rewrap_sc::startread() {
    QDataStream in(client);


    in.setVersion(QDataStream::Qt_4_1);
    forever {

        ff: if (nextblocksize == 0) {

            if (client->bytesAvailable() < sizeof(quint16))
                break;

            in >> nextblocksize;


        }

        if (nextblocksize == 0xFFFF) {
            nextblocksize = 0;

            goto ff;

        }

        if (client->bytesAvailable() < nextblocksize)
            break;
        QString type, code_t, problem;
        in >> type;


        in >> code_t >> problem;




        if (type == "IFI") {

            qDebug()<< "PITA IFI";

            resetControls();


        }


        nextblocksize = 0;

    }
    nextblocksize = 0;

}



