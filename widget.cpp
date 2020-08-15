#include <QMessageBox>
#include <string>
#include "widget.h"
#include "ui_widget.h"

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeData(int diff){
    money += diff;
    if(money >= 200){
        ui->btn_coffee->setEnabled(true);
        ui->btn_tea->setEnabled(true);
        ui->btn_milk->setEnabled(true);
    } else if(money >= 150) {
        ui->btn_coffee->setEnabled(true);
        ui->btn_tea->setEnabled(true);
        ui->btn_milk->setEnabled(false);
    } else if(money >= 100) {
        ui->btn_coffee->setEnabled(true);
        ui->btn_tea->setEnabled(false);
        ui->btn_milk->setEnabled(false);
    } else {
        ui->btn_coffee->setEnabled(false);
        ui->btn_tea->setEnabled(false);
        ui->btn_milk->setEnabled(false);
    }
    ui->lcdNumber->display(money);
}

void Widget::on_btn_10_clicked()
{
    changeData(10);
}

void Widget::on_btn_50_clicked()
{
    changeData(50);
}

void Widget::on_btn_100_clicked()
{
    changeData(100);
}

void Widget::on_btn_500_clicked()
{
    changeData(500);
}

void Widget::on_btn_coffee_clicked()
{
    changeData(-100);
}

void Widget::on_btn_tea_clicked()
{
    changeData(-150);
}

void Widget::on_btn_milk_clicked()
{
    changeData(-200);
}

void Widget::on_btn_reset_clicked()
{
    QMessageBox box;

    int coinNum_500 = money/500;
    money %= 500;
    string coin_500 = to_string(coinNum_500);

    int coinNum_100 = money/100;
    money %= 100;
    string coin_100 = to_string(coinNum_100);

    int coinNum_50 = money/50;
    money %= 50;
    string coin_50 = to_string(coinNum_50);

    int coinNum_10 = money/10;
    money %= 10;
    string coin_10 = to_string(coinNum_10);

    string info = "Coin 500 Num: " + coin_500 + "\n" +
                "Coin 100 Num: " + coin_100 + "\n" +
                "Coin 50 Num: " + coin_50 + "\n" +
                "Coin 10 Num: " + coin_10;
    const char* tmp = info.c_str();

     box.information(nullptr, "notice", tmp);

     money = 0;
     ui->lcdNumber->display(money);
     changeData(money);

}
