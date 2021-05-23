#include "mycalculator.h"
#include "ui_mycalculator.h"
#include "oneterm.h"
#include "twoterm.h"
#include "threeterm.h"
#include "fourterm.h"
mycalculator::mycalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mycalculator)
{
    ui->setupUi(this);
    QPalette palette;
    QPixmap pan("C:/MyGRAPPH/green.jpg");
    pan = pan.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, pan);
    this->setPalette(palette);

}

mycalculator::~mycalculator()
{
    delete ui;
}


void mycalculator::on_pushButton_clicked()
{

     win1=new oneterm(this);
     win1->show();
}

void mycalculator::on_pushButton_3_clicked()
{

    win2=new twoterm(this);
    win2->show();

}
void mycalculator::on_pushButton_2_clicked()
{

    win3=new threeterm(this);
    win3->show();
}

void mycalculator::on_pushButton_4_clicked()
{

    win4=new fourterm(this);
    win4->show();

}
