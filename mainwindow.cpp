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


void MainWindow::on_pushButton_clicked()
{

}




void MainWindow::on_set_clicked()
{
    this->m1.SetDolar(ui->set_dollars1->text().toInt());
    this->m1.SetCent(ui->set_cents1->text().toInt());
}

void MainWindow::on_set2_clicked()
{
    this->m2.SetDolar(ui->set_dollars2->text().toInt());
    this->m2.SetCent(ui->set_cents2->text().toInt());
}
