#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "money.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_set_clicked();

    void on_set2_clicked();

    void on_sum_clicked();

    void on_sub_clicked();

    void on_multi_clicked();

    void on_div_clicked();


private:
    Ui::MainWindow *ui;
    Money m1;
    Money m2;
    Money res;

};
#endif // MAINWINDOW_H
