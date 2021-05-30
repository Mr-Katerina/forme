#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MyGraph; }
QT_END_NAMESPACE

class MyGraph : public QMainWindow
{
    Q_OBJECT

public:
    MyGraph(QWidget *parent = nullptr);
    ~MyGraph();

private:
    Ui::MyGraph *ui;
};
#endif // MYGRAPH_H
