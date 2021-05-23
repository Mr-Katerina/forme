#ifndef ONETERM_H
#define ONETERM_H

#include <QDialog>

namespace Ui {
class oneterm;
}

class oneterm : public QDialog
{
    Q_OBJECT

public:
    explicit oneterm(QWidget *parent = nullptr);
    ~oneterm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::oneterm *ui;
};

#endif // ONETERM_H
