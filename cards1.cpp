#include "cards1.h"
#include "ui_cards1.h"
#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QStringList>
#include <QtWidgets>
#include <QObject>

CARDS1::CARDS1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CARDS1)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    cardPaths << "qrc:/1.png"
              << "qrc:/2.png"
              << "qrc:/3.png"
              << "qrc:/4.png";
}

CARDS1::~CARDS1()
{
    delete ui;
}


void CARDS1::on_pushButton_1_clicked()
{
    if (check1==false){
    QPixmap pic1(":/1.png");
    ui->picRED1->setPixmap(pic1);
    check1=true;
    visible1=true;
    }
    else{
        QPixmap picRED1(":/red.png");
        ui->picRED1->setPixmap(picRED1);
        check1=false;
        visible1=false;
    }
}

void CARDS1::on_pushButton_2_clicked()
{
    if (check2==false){
    QPixmap pic2(":/2.png");
    ui->picRED2->setPixmap(pic2);
    check2=true;
    visible2=true;
    }
    else{
        QPixmap picRED2(":/red.png");
        ui->picRED2->setPixmap(picRED2);
        check2=false;
        visible2=false;
    }
}

void CARDS1::on_pushButton_3_clicked()
{
    if (check3==false){
    QPixmap pic3(":/3.png");
    ui->picRED3->setPixmap(pic3);
    check3=true;
    visible3=true;
    }
    else{
        QPixmap picRED3(":/red.png");
        ui->picRED3->setPixmap(picRED3);
        check3=false;
        visible3=false;
    }
}

void CARDS1::on_pushButton_4_clicked()
{
    if (check4==false){
    QPixmap pic4(":/4.png");
    ui->picRED4->setPixmap(pic4);
    check4=true;
    visible4=true;
    }
    else{
        QPixmap picRED4(":/red.png");
        ui->picRED4->setPixmap(picRED4);
        check4=false;
        visible4=false;
    }
}





void CARDS1::on_pushButton_EVEN_clicked()
{
    if (check2==false||check4==false){
        QPixmap pic2(":/2.png");
        ui->picRED2->setPixmap(pic2);

        QPixmap pic4(":/4.png");
        ui->picRED4->setPixmap(pic4);
    check2=true;
    check4=true;
    visible2=true;
    visible4=true;
    }
    else{
        QPixmap picRED2(":/red.png");
        ui->picRED2->setPixmap(picRED2);

        QPixmap picRED4(":/red.png");
        ui->picRED4->setPixmap(picRED4);
        check2=false;
        check4=false;
        visible2=false;
        visible4=false;
    }
}

void CARDS1::on_pushButton_ODD_clicked()
{
    if (check1==false||check3==false){
        QPixmap pic1(":/1.png");
        ui->picRED1->setPixmap(pic1);

        QPixmap pic3(":/3.png");
        ui->picRED3->setPixmap(pic3);

    check1=true;
    check3=true;
    visible1=true;
    visible3=true;
    }
    else{
        QPixmap picRED1(":/red.png");
        ui->picRED1->setPixmap(picRED1);

        QPixmap picRED3(":/red.png");
        ui->picRED3->setPixmap(picRED3);
        check1=false;
        check3=false;
        visible1=false;
        visible3=false;
    }
}


void CARDS1::on_pushButton_SUM_clicked()
{
    if(visible1==false&&visible2==false&&visible3==false&&visible4==false){
        ui->lineEdit->setText(QString::number(0));
        return;
    }

    if(visible1&&visible2&&visible3&&visible4){
        ui->lineEdit->setText(QString::number(one+two+three+four));
        return;
    }
    if(visible1&&visible2&&visible3){
        ui->lineEdit->setText(QString::number(one+two+three));
        return;
    }
    if(visible1&&visible2&&visible4){
        ui->lineEdit->setText(QString::number(one+two+four));
        return;
    }
    if(visible1&&visible3&&visible4){
        ui->lineEdit->setText(QString::number(one+three+four));
        return;
    }
    if(visible2&&visible3&&visible4){
        ui->lineEdit->setText(QString::number(two+three+four));
        return;
    }
    if(visible1&&visible2){
        ui->lineEdit->setText(QString::number(one+two));
        return;
    }
    if(visible3&&visible4){
        ui->lineEdit->setText(QString::number(three+four));
        return;
    }
    if(visible1&&visible3){
        ui->lineEdit->setText(QString::number(one+three));
        return;
    }
    if(visible2&&visible4){
        ui->lineEdit->setText(QString::number(two+four));
        return;
    }
    if(visible1&&visible4){
        ui->lineEdit->setText(QString::number(one+four));
        return;
    }
    if(visible2&&visible3){
        ui->lineEdit->setText(QString::number(two+three));
        return;
    }
    if(visible1&&visible2&&visible3&&visible4){
        ui->lineEdit->setText(QString::number(one+two+three+four));
        return;
    }
    if(visible1){
        ui->lineEdit->setText(QString::number(one));
        return;
    }
    if(visible2){
        ui->lineEdit->setText(QString::number(two));
        return;
    }
    if(visible3){
        ui->lineEdit->setText(QString::number(three));
        return;
    }
    if(visible4){
        ui->lineEdit->setText(QString::number(four));
        return;
    }
}

void CARDS1::on_pushButton_RESET_clicked()
{
    check1=false;
    check2=false;
    check3=false;
    check4=false;

    visible1=false;
    visible2=false;
    visible3=false;
    visible4=false;

    ui->pushButton_STOP->click();

    ui->lineEdit->setText("");

    QPixmap picRED1(":/red.png");
    ui->picRED1->setPixmap(picRED1);

    QPixmap picRED2(":/red.png");
    ui->picRED2->setPixmap(picRED2);

    QPixmap picRED3(":/red.png");
    ui->picRED3->setPixmap(picRED3);

    QPixmap picRED4(":/red.png");
    ui->picRED4->setPixmap(picRED4);

}


void CARDS1::on_pushButton_PLAY_clicked() {

    if(!flag){
    connect(timer, &QTimer::timeout, this, &CARDS1::switchCards);
    flag=true;
    }

    timer->start(1000);
}

void CARDS1::on_pushButton_STOP_clicked() {
  timer->stop();
  currentCardIndex=0;
  nextCardIndex = (currentCardIndex + 1) % 4;
}


void CARDS1::switchCards() {

    if (nextCardIndex >= 4) {
            nextCardIndex = 0;
          }

            currentCardIndex++;
            QPixmap card(cardPaths[nextCardIndex]);
            QLabel* cardLabel = findChild<QLabel*>("pic" + QString::number(currentCardIndex));
            cardLabel->setPixmap(card);

            if(currentCardIndex==1){
                ui->pushButton_1->click();
                ui->pushButton_SUM->click();
                return;
            }
            if(currentCardIndex==2){
                ui->pushButton_2->click();
                ui->pushButton_SUM->click();
                return;
            }
            if(currentCardIndex==3){
                ui->pushButton_3->click();
                ui->pushButton_SUM->click();
                return;
            }
            if(currentCardIndex==4){
                ui->pushButton_4->click();
                ui->pushButton_SUM->click();
                currentCardIndex=0;
                return;
            }
            nextCardIndex++;

 currentCardIndex = nextCardIndex;
}
