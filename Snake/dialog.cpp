#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()//人机
{
    gamepanel=new GamePanel(this);//此处记得区分难度
    gamepanel->show();
    this->hide();
}

void Dialog::on_pushButton_2_clicked()
{
    gamepanel=new GamePanel(this);
    gamepanel->show();
    this->hide();
}
