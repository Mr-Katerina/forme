#ifndef WIDGETOP_H
#define WIDGETOP_H
#include "mypaint.h"
#include <QOpenGLWidget>

class widgetOP : public QOpenGLWidget
{
public:
    widgetOP(QWidget *parent);
public slots:
    void obnovlenie();
      void writefile();
    void readfile();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    MyPaint *mypainter;
};

#endif // WIDGETOP_H
