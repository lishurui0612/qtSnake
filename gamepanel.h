#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include"dialog3.h"


namespace Ui {
class GamePanel;
}

class GamePanel : public QMainWindow
{
    Q_OBJECT
   // int difficulty;
public:
    explicit GamePanel(int mode,QWidget *parent = 0);
    ~GamePanel();
public:
    int mode;
    int board[20][20];
    int ai_board[20][20];

protected:
    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void keyReleaseEvent(QKeyEvent *ev);

private slots:
    void snake_move();
private:
    Ui::GamePanel *ui;

    void paintEvent(QPaintEvent*);
    QPainter *painter;
    void ai_snake_move();
    std::pair<int,int> generateFood();
    std::pair<int,int> ai_generateFood();
    void endGame();
    int change_aiDirection();
    Dialog3 *dialog3;
    QTimer *timer;
};

#endif // GAMEPANEL_H


