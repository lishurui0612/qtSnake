#include <Qtimer>
#include <QColor>
#include <time.h>
#include <random>
#include <vector>
#include <QPainter>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <cstdio>
#include <dialog3.h>

#include "gamepanel.h"
#include "ui_gamepanel.h"


#define random(x) rand()%(x)

int max_fps=1;
int difficulty;
bool difficultyChanged;
bool paused=false;

//int ai_this->board[15][15];

std::vector<std::pair<int,int> > snake;
//std::vector<std::pair<int,int> > ai_snake;
std::vector<int> direction;
int last_direction=0;
std::pair<int,int> food;
int score=0;

void GamePanel::paintEvent(QPaintEvent*)
//paintEvent函数由系统自动调用，用不着我们人为的去调用。
{
    //    paint->setPen(QPen(Qt::blue,4,Qt::DashLine));//设置画笔形式
    QPainter painter(this);
    QColor blue=QColor(130,200,250);
    painter.setBrush(QBrush(blue,Qt::SolidPattern));//设置画刷形式
    painter.drawRect(60*snake[0].first+25,60*snake[0].second+25,50,50);

    QColor black=QColor(0,0,0);
    painter.setBrush(QBrush(black,Qt::SolidPattern));//设置画刷形式
    if (last_direction<=2)
    {
        painter.drawEllipse(QPointF(60*snake[0].first+35,60*snake[0].second+50),5,5);
        painter.drawEllipse(QPointF(60*snake[0].first+65,60*snake[0].second+50),5,5);
    }
    if (last_direction>2)
    {
        painter.drawEllipse(QPointF(60*snake[0].first+50,60*snake[0].second+35),5,5);
        painter.drawEllipse(QPointF(60*snake[0].first+50,60*snake[0].second+65),5,5);
    }

// TODO triangle tail
    painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
      if (snake.size()>1)
          for (unsigned int i=0;i<snake.size()-1;i++)
              if (snake[i].first==snake[i+1].first)
              {
                  painter.drawRect((snake[i].first+snake[i+1].first)/2*60+25,(snake[i].second+snake[i+1].second)/2*60+75,50,10);
              }
              else
              {
                  painter.drawRect((snake[i].first+snake[i+1].first)/2*60+75,(snake[i].second+snake[i+1].second)/2*60+25,10,50);
              }

    QColor darkBlue=QColor(160,220,250);
    painter.setBrush(QBrush(darkBlue,Qt::SolidPattern));//设置画刷形式
    for (unsigned int i=1;i<snake.size();i++)
        painter.drawRect(60*snake[i].first+25,60*snake[i].second+25,50,50);

    painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));//设置画刷形式
    painter.drawRect(60*food.first+25,60*food.second+25,50,50);
    painter.end();
}

void GamePanel::endGame()
{
    this->timer->stop();
    this->close();
    dialog3=new Dialog3(score, this);
    dialog3->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
}

std::pair<int,int> GamePanel::generateFood()
{
    std::vector<std::pair<int,int> > tmp;
    tmp.clear();
    for (int i=0;i<15;i++)
        for (int j=0;j<15;j++)
        {
            if (this->board[i][j]==0)
                tmp.push_back(std::make_pair(i,j));
        }
    int tmpp=random(tmp.size());
    board[tmp[tmpp].first][tmp[tmpp].second]=2;
    return tmp[tmpp];
}


void GamePanel::snake_move()
{
    //printf("%d\n",difficulty);
    if(paused)
        return;
    if(!score) ui->label->setNum(0);
    if (difficultyChanged)
    {
        this->timer->stop();
        this->timer->start(1000/difficulty);
        difficultyChanged=false;
    }
    int choosedWay=0;
    int dx[]={0,0,0,-1,1};
    int dy[]={0,-1,1,0,0};

    if(!direction.empty())
    {
        for (std::vector<int>::iterator it=direction.begin();it!=direction.end();it++)
            if ((*it)*last_direction!=2 && (*it)*last_direction!=12)
                choosedWay=(*it);
        direction.clear();
    }
    if (choosedWay==0)
        choosedWay=last_direction;
    else
        last_direction=choosedWay;
    for (int i=1;i<5;i++)
    {
        if (choosedWay==i)
        {
            if (snake[0].first+dx[i]<0 || snake[0].first+dx[i]>=15 || snake[0].second+dy[i]<0 || snake[0].second+dy[i]>=15)
            {
                //std::cout<<1;
                endGame();
            }
            if (this->board[snake[0].first+dx[i]][snake[0].second+dy[i]]==1)
            {
                //std::cout<<snake[0].first+dx[i]<<snake[0].second+dy[i];
                endGame();
            }
            snake.insert(snake.begin(),std::make_pair(snake[0].first+dx[i],snake[0].second+dy[i]));
            //printf("%d %d\n",dx[i],dy[i]);
            if (snake[0]==food)
            {
                food=generateFood();
                score+=10;
                ui->label->setNum(score);
            }
            else
            {
                this->board[snake.back().first][snake.back().second]=0;
                snake.pop_back();
            }
            this->board[snake[0].first][snake[0].second]=1;
        }
    }
    GamePanel::update();
}



GamePanel::GamePanel(int mode,int difficulty,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GamePanel)
{
    ui->setupUi(this);
    srand(time(NULL));

    //初始化变量
    memset(this->board,0,sizeof(this->board));
    snake.clear();
    direction.clear();
    score=0;
    last_direction=0;
    snake.push_back(std::make_pair(7,7));
    snake.push_back(std::make_pair(7,8));
    this->board[7][7]=1;
    this->board[7][8]=1;
    food=generateFood();
    difficulty=5;
    this->mode=mode;
    if (this->mode==2) this->setFixedSize(1880,930);
    else this->setFixedSize(930,930);

    timer=new QTimer(this);
    connect(this->timer,SIGNAL(timeout()),this,SLOT(snake_move()));
    this->timer->start(1000/difficulty);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
    //    this->mousedown=false;
    //    this->release=false;
    //初始化画布
    //    QPixmap pix;
    QPixmap pixmap(800, 800);
    pixmap.fill(Qt::white);
}

GamePanel::~GamePanel()
{
    delete ui;
}

void GamePanel::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Up)
        direction.push_back(1);
    if(ev->key() == Qt::Key_Down)
        direction.push_back(2);
    if(ev->key() == Qt::Key_Left)
        direction.push_back(3);
    if(ev->key() == Qt::Key_Right)
        direction.push_back(4);
    if(ev->key() == Qt::Key_F1)
    {
        difficulty++;
        difficultyChanged=true;
    }
    if(ev->key() == Qt::Key_F2)
        if (difficulty>1)
        {
            difficulty--;
            difficultyChanged=true;
        }
    if(ev->key() == Qt::Key_Space)
        paused=!paused;
    QWidget::keyPressEvent(ev);
}

void GamePanel::keyReleaseEvent(QKeyEvent *ev)
{

    QWidget::keyReleaseEvent(ev);
}
