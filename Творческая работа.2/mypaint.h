#ifndef MYPAINT_H
#define MYPAINT_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
class MyPaint
{
public:
    MyPaint();
public:
    void paint(QPainter *painter, QPaintEvent *event);
    QBrush front;
private:
    QBrush back;
    QFont Font;
    QPen Pen;
};

#endif // MYPAINT_H
