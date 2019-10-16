#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include<windows.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
dialog=new Dialog(this);
dialog->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    dialog1=new Dialog1(this);
    dialog1->show();
}

void MainWindow::on_pushButton_3_clicked()
{

    exit(1);
}
