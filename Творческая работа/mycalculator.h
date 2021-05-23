#ifndef MYCALCULATOR_H
#define MYCALCULATOR_H

#include <QMainWindow>
#include "oneterm.h"
#include "twoterm.h"
#include "threeterm.h"
#include "fourterm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mycalculator; }
QT_END_NAMESPACE

class mycalculator : public QMainWindow
{
    Q_OBJECT

public:
    mycalculator(QWidget *parent = nullptr);
    ~mycalculator();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::mycalculator *ui;
    oneterm *win1;
    twoterm *win2;
    threeterm *win3;
    fourterm *win4;
};
#endif // MYCALCULATOR_H
