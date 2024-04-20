#ifndef CARDS1_H
#define CARDS1_H

#include <QMainWindow>
#include <QPushButton>
#include<QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class CARDS1; }
QT_END_NAMESPACE

class CARDS1 : public QMainWindow
{
    Q_OBJECT

public:
    CARDS1(QWidget *parent = nullptr);
    ~CARDS1();




private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_EVEN_clicked();

    void on_pushButton_ODD_clicked();

    void on_pushButton_PLAY_clicked();

   void switchCards();

   void on_pushButton_STOP_clicked();

   void on_pushButton_SUM_clicked();

   void on_pushButton_RESET_clicked();


private:
    Ui::CARDS1 *ui;
    QPushButton *playButton;

    bool check1=false;
    bool check2=false;
    bool check3=false;
    bool check4=false;

    bool visible1=false; int one=1;
    bool visible2=false;int two=2;
    bool visible3=false;int three=3;
    bool visible4=false;int four=4;

    bool flag=false;
    QTimer *timer;

     QStringList cardPaths;

     int currentCardIndex = 0;
     int nextCardIndex = (currentCardIndex + 1) % 4;
};

#endif // CARDS1_H

