#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include<QSpinBox>
#include"gamepanel.h"
namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();

private slots:
    void on_pushButton_clicked();//开始游戏

    void on_pushButton_2_clicked();//返回主界面

    int on_spinBox_valueChanged();
public:
    QSpinBox* box;

private:
    Ui::Dialog1 *ui;
    GamePanel* gamepanel;

};

#endif // DIALOG1_H