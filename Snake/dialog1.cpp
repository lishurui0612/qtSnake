#include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_clicked()//开始游戏
{
    int a=on_spinBox_valueChanged();
    gamepanel=new GamePanel(this);//缺少传值
    gamepanel->show();
    this->hide();
}

void Dialog1::on_pushButton_2_clicked()//返回主窗口
{
    this->hide();
}



int Dialog1::on_spinBox_valueChanged()
{
    return(box->value());
}

