#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widgetop.h"
#include <QPainter>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <mypaint.h>
#include<QButtonGroup>
#include<QFile>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette palette;
    QPixmap pan("C:/mywork/soul.jpg");
    pan = pan.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, pan);
    this->setPalette(palette);
    ui->setupUi(this);
    ui->setupUi(this);
    widgetOP *openGLW=new widgetOP(this);
    QGridLayout *grid=new QGridLayout();
    QButtonGroup *G=new QButtonGroup;

    for(int i=0;i<3;i++)
    {
        QPushButton *btn=new QPushButton;
        btn->setFixedSize(200,100);
        grid->addWidget(btn,i,1,1,2);
        G->addButton(btn,i);
    }
    G->button(0)->setText("обновить");
    G->button(1)->setText("Отобразить граф");
    G->button(2)->setText("Внести элементы матрицы ");
    G->button(0)->setFixedSize(300,100);
    G->button(1)->setFixedSize(300,100);
    G->button(2)->setFixedSize(300,100);
    grid->addWidget(openGLW,0,0,9,2);
    grid->addWidget(G->button(0), 3, 2);
    grid->addWidget(G->button(1), 2, 2);
    grid->addWidget(G->button(2), 1, 2);
    for (int i=0;i<3;i++)
    {
        G->button(i)->setStyleSheet("QPushButton { background-color: rgb(0,255,255); }\n");
    }

  ui->centralwidget->setLayout(grid);
    connect(G->button(0),&QPushButton::clicked,openGLW,&widgetOP::redraw);
    connect(G->button(1), &QPushButton::clicked, openGLW,&widgetOP::read_from_file);
    connect(G->button(2), &QPushButton::clicked, openGLW, &widgetOP::make_file);
    QFile inputFileTrack("C:/mywork/Track.txt");
    inputFileTrack.open(QFile::ReadOnly | QFile::Text);
    int s2;
    QString s1;
    s1 = inputFileTrack.readLine();
    qDebug() << s1 << endl;
    s2 = inputFileTrack.readLine().toInt();
    qDebug() << s2 << endl;
    inputFileTrack.flush();
    inputFileTrack.close();

}


MainWindow::~MainWindow()
{
    delete ui;
}
