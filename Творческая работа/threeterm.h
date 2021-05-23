#ifndef THREETERM_H
#define THREETERM_H

#include <QDialog>

namespace Ui {
class threeterm;
}

class threeterm : public QDialog
{
    Q_OBJECT

public:
    explicit threeterm(QWidget *parent = nullptr);
    ~threeterm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::threeterm *ui;
};

#endif // THREETERM_H
