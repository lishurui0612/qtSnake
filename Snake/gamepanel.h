#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <QMainWindow>
#include <QKeyEvent>



namespace Ui {
class GamePanel;
}

class GamePanel : public QMainWindow
{
    Q_OBJECT
    int speed;
public:
    explicit GamePanel(QWidget *parent = 0);
    ~GamePanel();


protected:
    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void keyReleaseEvent(QKeyEvent *ev);

private slots:
    void snake_move();
private:
    Ui::GamePanel *ui;
    void paintEvent(QPaintEvent*);
       QPainter *paintBlue;
       QPainter *paintRed;
       std::pair<int,int> generateFood();
};

#endif // GAMEPANEL_H
