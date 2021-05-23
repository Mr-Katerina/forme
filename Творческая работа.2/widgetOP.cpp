#include "widgetop.h"
#include "mypaint.h"
#include <QPainter>
#include <QFile>
#include <QTextStream>

widgetOP::widgetOP(QWidget *parent)
    :QOpenGLWidget(parent)
{
    mypainter=new MyPaint;
}

void widgetOP::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    mypainter->paint(&painter,event);
    painter.end();
}
void widgetOP::obnovlenie()
{
    this->update();
}
