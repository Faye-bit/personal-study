#include "gamewidget.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

GameWidget::GameWidget(QWidget *parent): QWidget(parent), food(gridWidth, gridHeight)
{
  setFixedSize(gridWidth * gridSize, gridHeight * gridSize);//设置窗口大小

  timer = new QTimer(this); //初始化定时器

   //关联信号与槽，让timer每次发出信号时游戏画面更新一次
  connect(timer, &QTimer::timeout, this, &GameWidget::updateGame);
  timer->start(150);  //每150ms移动一次
}

void GameWidget::paintEvent(QPaintEvent *) //重写 paintEvent() 函数，进行游戏的绘制
{
  QPainter painter(this);

   // 画蛇
  painter.setBrush(Qt::green);
  for (const QPoint &p : snake.getBody())
  {
    painter.drawRect(p.x() * gridSize, p.y() * gridSize, gridSize, gridSize);
  }

   // 画食物
  painter.setBrush(Qt::red);
  QPoint foodPos = food.getPosition();
  painter.drawEllipse(foodPos.x() * gridSize, foodPos.y() * gridSize, gridSize, gridSize);
  qDebug() << "Food at:" << foodPos;


   // 游戏结束提示
  if (gameOver) {
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(rect(), Qt::AlignCenter, "Game Over\nPress R to Restart");
  }
}

void GameWidget::keyPressEvent(QKeyEvent *event) //重写 keyPressEvent() 函数，用于检测键盘输入
{
  if (gameOver && event->key() == Qt::Key_R) //当游戏结束且键盘'R'键被按下时，重置游戏
  {
    snake = Snake();
    food.generate();
    gameOver = false;
    timer->start(150);
    update();
    return;
  }

  switch (event->key()) //检测键盘输入，并设置为蛇新的行进方向
  {
  case Qt::Key_Up:    snake.setDirection(Up); break;
  case Qt::Key_Down:  snake.setDirection(Down); break;
  case Qt::Key_Left:  snake.setDirection(Left); break;
  case Qt::Key_Right: snake.setDirection(Right); break;
  }
}

void GameWidget::updateGame()
{
  snake.move();

   // 先获取新头部位置
  QPoint head = snake.getBody().first();

   // 判断是否撞墙
  /*if (head.x() < 0 || head.x() >= gridWidth || head.y() < 0 || head.y() >= gridHeight) {
    gameOver = true;
    timer->stop();
    update();
    return;
  }*/

   // 判断是否撞到自己（从第二节开始判断）
  /*for (int i = 1; i < snake.getBody().size(); ++i) {
    if (snake.getBody()[i] == head) {
      gameOver = true;
      timer->stop();
      update();
      return;
    }
  }*/
  if(this->checkCollision())
  {
    gameOver = true;
    timer->stop();
    update();
    return;
  }

  // 判断是否吃到食物
  if (head == food.getPosition())
  {
    snake.grow();
    food.generate();
  }

  update();
}


bool GameWidget::checkCollision()
{
  bool gameover = false;
  QPoint head = snake.getBody().first();

         // 撞墙
  if (head.x() < 0 || head.y() < 0 || head.x() >= gridWidth || head.y() >= gridHeight)
  {
    gameover = true;
    gameOver = true;
    timer->stop();
  }

         // 撞自己
  if (snake.checkCollision())
  {
    gameover = true;
    gameOver = true;
    timer->stop();
  }

  return gameover;
}
