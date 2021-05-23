#ifndef TWOTERM_H
#define TWOTERM_H
#include <QDialog>
namespace Ui {
class twoterm;
}
class twoterm : public QDialog
{
    Q_OBJECT
public:
    explicit twoterm(QWidget *parent = nullptr);
    ~twoterm();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::twoterm *ui;
};
#endif // TWOTERM_H
