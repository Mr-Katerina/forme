#ifndef FOURTERM_H
#define FOURTERM_H
#include <QDialog>
namespace Ui {
class fourterm;
}
class fourterm : public QDialog
{
    Q_OBJECT
public:
    explicit fourterm(QWidget *parent = nullptr);
    ~fourterm();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::fourterm *ui;
};
#endif // FOURTERM_H
