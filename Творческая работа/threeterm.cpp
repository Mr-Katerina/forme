#include "threeterm.h"
#include "ui_threeterm.h"
threeterm::threeterm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::threeterm)
{
    ui->setupUi(this);
    QPalette palette;
    QPixmap pan("C:/MyGRAPPH/green.jpg");
    pan = pan.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, pan);
    this->setPalette(palette);
}
threeterm::~threeterm()
{
    delete ui;
}
void threeterm::on_pushButton_clicked()
{
    float result=1.0;
        QString sum1=ui->lineEdit_2->text();
      QStringList elem1=sum1.split("*");
      if(ui->checkBox->isChecked())
      {
        float cons=75.5;
    for(int i=0;i<elem1.length();i++)
    {
       result*=elem1[i].toFloat()*cons;
    }
    QString res=QString::number(result);
    ui->lineEdit_2->setText(res);
      }
      if(ui->checkBox_2->isChecked())
      {
          float cons=0.75;
       for(int i=0;i<elem1.length();i++)
       {
           result*=elem1[i].toFloat()*cons;
       }
       QString res=QString::number(result);
       ui->lineEdit_2->setText(res);
      }
      if(ui->checkBox_3->isChecked())
      {
      }
}
void threeterm::on_pushButton_2_clicked()
{
    float result1=0.0;
    float result2=0.0;
   QString srok1=ui->srokone->text();
   QString sum1=ui->lineEdit_2->text();
   QStringList elem1=sum1.split("+");
   QStringList elem2=srok1.split("+");
   QString result=ui->lineEdit->text();
for(int i=0;i<elem1.length();i++)
{
    result1+=elem1[i].toFloat();
}
for(int i=0;i<elem2.length();i++)
{
    result2+=elem2[i].toFloat();
}
float n=0.0;
for(int i=0;i<result2;i++)
 {
n=result1/1000;
result1+=n*5;
}
QString res2=QString::number(result1);
ui->lineEdit->setText(res2);
}
