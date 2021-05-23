#include "mypaint.h"
#include "mypaint.h"
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <QVector>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QtCore/qmath.h>
#include <widgetop.h>
#include <QDebug>
#include <QProcess>
#include<QLineEdit>
int kol;
int R=225;
int r=40;
double pi=3.1415;
int Text=20;
int xa=370;
int ya=450;
double angle=pi/8;
int str=30;
int strasp=60;
int LenghtWay;
QString Way;
bool find;
QVector<QVector<int>> matrix;




MyPaint::MyPaint()
{
    Pen=QPen(QColor(150,33,250));
    front=QBrush(QColor(0,255,180));
    back=QBrush(QColor(255,255,255));
    Font.setPixelSize(Text);
}

void widgetOP::writefile() {
    QProcess::startDetached("C:/mywork/run.bat");
}



void widgetOP::readfile() {
    this->repaint();
    QFile myWay("C:/mywork/Track.txt");
    myWay.open(QFile::ReadOnly | QFile::Text);
    Way = myWay.readLine();
    qDebug() << Way << endl;
    LenghtWay = myWay.readLine().toInt();
    qDebug() << LenghtWay << endl;
    kol = myWay.readLine().toInt();
    qDebug() << kol << endl;
    myWay.flush();
    myWay.close();
    QFile myMatrix("C:/mywork/Matrix.txt");
    myMatrix.open(QFile::ReadOnly | QFile::Text);
    QString line, a= "";
    QVector<int> tmp;
    QVector<QVector<int>> tmp2;
    for(int i = 0; i < kol; i++) {
        line = myMatrix.readLine();
        for(int j = 0; j < line.size(); j++) {
            if(line[j] != " ") {
                a += line[j];
            }
            else {
                tmp.push_back(a.toInt());
                a= "";
            }
        }
        tmp2.push_back(tmp);
        tmp.clear();
        a = "";
    }
    matrix = tmp2;
    myMatrix.flush();
    myMatrix.close();
}

void MyPaint::paint(QPainter *painter, QPaintEvent *event)
{
    painter->fillRect(event->rect(),back);
    painter->setBrush(front);
    painter->setPen(Pen);
    painter->setFont(Font);
    Pen.setWidth(4);
    for (int i=0;i<kol;i++)
    {
        double a=pi*3/2+pi*2/kol*i;
        int xc=cos(a)*R+xa;
        int yc=sin(a)*R+ya;
        int c1=xc-20;
        int c2=yc-Text/2;
        int c3=40;
        int c4=Text;
        QString text; text.setNum(i+1);
        painter->drawEllipse(QRectF(xc-r,yc-r,2*r,2*r));
        painter->drawText(QRect(c1,c2,c3,c4),Qt::AlignCenter,text);
        for (int k=0;k<kol;k++)
        {
            if (matrix[i][k]!=-1 && matrix[i][k] != 10000&& matrix[i][k]!=0)
            {


                double a2=pi*3/2+pi*2/kol*k;
                double xc2=cos(a2)*R+xa;
                double yc2=sin(a2)*R+ya;
                double l=sqrt((xc2-xc)*(xc2-xc)+(yc2-yc)*(yc2-yc));
                int xl1=(xc2-xc)/l*r+xc;
                int yl1=(yc2-yc)/l*r+yc;
                int xl2=xc2-(xc2-xc)/l*r;
                int yl2=yc2-(yc2-yc)/l*r;
                painter->drawLine(xl1,yl1,xl2,yl2);

                double b;
                if      (xc2==xl2 && yl2<yc2) b=pi*3/2;
                else if (yc2==yl2 && xl2<xc2) b=pi;
                else if (xc2==xl2 && yl2>yc2) b=pi/2;
                else if (yc2==yl2 && xl2>xc2) b=0;
                else if (xl2>xc2 && yl2<yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi*2;
                else if (xl2<xc2 && yl2<yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi;
                else if (xl2<xc2 && yl2>yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi;
                else if (xl2>xc2 && yl2>yc2)  b=atan((yc2-yl2)/(xc2-xl2));
                int xs1=cos(b+angle)*str+xl2;
                int ys1=sin(b+angle)*str+yl2;
                int xs2=cos(b-angle)*str+xl2;
                int ys2=sin(b-angle)*str+yl2;
                painter->drawLine(xl2,yl2,xs1,ys1);
                painter->drawLine(xl2,yl2,xs2,ys2);

                c1=(xl2+xl1)/2-20+qrand()%strasp-strasp/2;
                c2=(yl2+yl1)/2-Text/2+qrand()%strasp-strasp/2;
                c3=40;
                c4=Text;
                text.setNum(matrix[i][k]);
                painter->drawText(QRect(c1,c2,c3,c4),Qt::AlignCenter,text);
                QString s,s2;
                s="Путь: " +Way;
                s2="Длина пути: " +QString::number(LenghtWay);
                painter->drawText(QRect(20,40,1000,40),Qt::AlignCenter,s);
                painter->drawText(QRect(55,60,1000,40),Qt::AlignCenter,s2);

            }
        }
    }

}
