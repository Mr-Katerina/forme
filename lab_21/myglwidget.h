#include "myglwidget.h"
#include "mypainter.h"
#include <QPainter>
myglwidget::myglwidget(QWidget*parent)

    :QOpenGLWidget(parent)
 {
     mypainter=new myPainter;
 }
 void myglwidget::redraw()
 {
     //mypainter->front.setColor((QColor(255,0,0)));
     this->update();
 }
 void myglwidget::paintEvent(QPaintEvent *event)
 {
     QPainter painter;
     painter.begin(this);
     mypainter->draw(&painter,event);
     painter.end();
}
