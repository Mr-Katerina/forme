#include "mygraph.h"
#include "ui_mygraph.h"
#include "myglwidget.h"
#include <QGridLayout>
#include <QPushButton>
MyGraph::MyGraph(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::MyGraph)
{
    ui->setupUi(this);
    myglwidget *openGLW=new myglwidget(this);
       QGridLayout *grid=new QGridLayout();
       QPushButton *btn=new QPushButton();
       grid->addWidget(openGLW,0,0);
       grid->addWidget(btn,1,0);
       ui->centralwidget->setLayout(grid);
       connect(btn,&QPushButton::clicked,openGLW,&myglwidget::redraw);
}
MyGraph::~MyGraph()
{
    delete ui;
}
