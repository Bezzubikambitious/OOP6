#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_set_clicked()
{
    this->m1.SetDolar(ui->set_dollars1->text().toInt());
    int tmp = ui->set_cents1->text().toInt();
    while (tmp>=100)
    {// це якщо центів введуть багато
        this->m1.SetDolar(this->m1.GetDolar()+1);
        tmp -= 100;
    }
    this->m1.SetCent(tmp);
}

void MainWindow::on_set2_clicked()
{
    this->m2.SetDolar(ui->set_dollars2->text().toInt());
    int tmp = ui->set_cents2->text().toInt();
    while (tmp>=100)
    {
        this->m2.SetDolar(this->m2.GetDolar()+1);
        tmp -= 100;
    }
    this->m2.SetCent(tmp);
}

void MainWindow::on_sum_clicked()
{
    this->res = this->m1.operator+(this->m2);
    ui->show_sum->setText(QString::fromStdString(this->res.get_res()));
}

void MainWindow::on_sub_clicked()
{
    this->res = this->m1.operator-(this->m2);
    ui->show_sub->setText(QString::fromStdString(this->res.get_res()));
}


void MainWindow::on_multi_clicked()
{
    this->res = this->m1.operator*(this->m2);
    ui->show_mul->setText(QString::fromStdString(this->res.get_res()));
}

void MainWindow::on_div_clicked()
{
    this->res = this->m1.operator*(this->m2);
    ui->show_div->setText(QString::fromStdString(this->res.get_res()));
}

void MainWindow::on_right_clicked()
{
    this->res = this->m1.operator>>(this->m2);
    ui->show_right->setText(QString::fromStdString(this->res.get_res()));
}

void MainWindow::on_left_clicked()
{
    this->res = this->m1.operator<<(this->m2);
    ui->show_left->setText(QString::fromStdString(this->res.get_res()));
}
