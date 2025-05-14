#include "gamewidget.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

GameWidget::GameWidget(QWidget *parent): QWidget(parent), food(gridWidth, gridHeight)
{
  setFixedSize(gridWidth * gridSize+150, gridHeight * gridSize);//设置窗口大小

  timer = new QTimer(this); //初始化定时器
  //timer->stop(); //将计时器暂停

   //关联信号与槽，让timer每次发出信号时游戏画面更新一次
  connect(timer, &QTimer::timeout, this, &GameWidget::updateGame);

   //初始化UI
  ui = new Ui::Menu;
  ui->setupUi(this);

   //载入最高得分
  this->loadScore();

   //载入foodImage
  foodImage.load(":/png/pix/food.png");
   //设置初始游戏速度
  GSpeed = 150;

   // 初始化按钮
  isPause = false;
  ui->btnPause->setText("Pause");
  ui->btnPause->setEnabled(false);
  ui->LabelScore->setText("当前得分\n     "+QString::number(score));
  ui->LabelHigh->setText("最高得分\n     "+QString::number(Max_score));
  ui->speed_1x->setChecked(true);

   //设置焦点策略
  setFocusPolicy(Qt::StrongFocus);
  ui->btnStart->setFocusPolicy(Qt::NoFocus);
  ui->btnPause->setFocusPolicy(Qt::NoFocus);
  ui->btnRestart->setFocusPolicy(Qt::NoFocus);
  ui->speed_1x->setFocusPolicy(Qt::NoFocus);
  ui->speed_2x->setFocusPolicy((Qt::NoFocus));
  ui->speed_1point5->setFocusPolicy(Qt::NoFocus);

   //关联信号与槽
  //connect(ui->btnStart,&QPushButton::clicked,this,&GameWidget::on_btnStart_clicked);
  //connect(ui->btnPause,&QPushButton::clicked,this,&GameWidget::on_btnPause_clicked);
  //connect(ui->btnRestart,&QPushButton::clicked,this,&GameWidget::on_btnRestart_clicked);
  connect(ui->speed_1x,&QRadioButton::toggled,this,&GameWidget::do_setSpeed);
  connect(ui->speed_2x,&QRadioButton::toggled,this,&GameWidget::do_setSpeed);
  connect(ui->speed_1point5,&QRadioButton::toggled,this,&GameWidget::do_setSpeed);

  //timer->start(150);  //每150ms移动一次
}

void GameWidget::paintEvent(QPaintEvent *) //重写 paintEvent() 函数，进行游戏的绘制
{

  QPainter painter(this);

   // 画网格
  paintGrid(painter);

   // 画蛇
  painter.setBrush(Qt::green);
  int color=100;
  for (const QPoint &p : snake.getBody())
  {
    //painter.drawRect(p.x() * gridSize, p.y() * gridSize, gridSize, gridSize);
    QRect rect(p.x() * gridSize, p.y() * gridSize, gridSize, gridSize);
    painter.setBrush(QColor(0,color,0));
    painter.setPen(Qt::NoPen);

    painter.drawRoundedRect(rect,6,6);
    color += 5;
  }

   // 画食物
  if(!gameOver)
  {
    /*painter.setBrush(Qt::red);
    QPoint foodPos = food.getPosition();
    painter.drawEllipse(foodPos.x() * gridSize, foodPos.y() * gridSize, gridSize, gridSize);*/
    QPoint foodPixel = food.getPosition()*gridSize;
    painter.drawPixmap(foodPixel.x(),foodPixel.y(),gridSize,gridSize,foodImage);
  }
  //qDebug() << "Food at:" << foodPos;
  //qDebug() << "gameOver:" << gameOver;

   // 游戏结束提示
  if (gameOver)
  {
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(rect(), Qt::AlignCenter, "Game Over\nPress R to Restart");
  }
   // 游戏暂停提示
  if (isPause && !gameOver)
  {
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 15));
    painter.drawText(rect(), Qt::AlignCenter, "Game Pause\nPress Continue to Resume");
  }
}

void GameWidget::keyPressEvent(QKeyEvent *event) //重写 keyPressEvent() 函数，用于检测键盘输入
{
  if (gameOver && event->key() == Qt::Key_R) //当游戏结束且键盘'R'键被按下时，重置游戏
  {
    snake = Snake();
    food.generate(snake.getBody());
    gameOver = false;
    isPause = false;
    ui->btnPause->setText("Pause");
    ui->btnPause->setEnabled(false);
    score = 0;

    timer->start(GSpeed);
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
  ui->LabelScore->setText("当前得分\n     "+QString::number(score));
  ui->LabelHigh->setText("最高得分\n     "+QString::number(Max_score));

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
  if(this->checkCollision())//判断碰撞，检测游戏是否结束
  {
    gameOver = true;
    ui->btnStart->setEnabled(true); //游戏结束后激活 start按钮
    ui->btnPause->setEnabled(false); //禁用 Pause按钮
    timer->stop();
    if(score>Max_score) //判断得分是否超过了历史最高分
    {
      Max_score = score;
      saveScore(); //更新历史最高
    }
    update();
    score = 0;
    return;
  }

   // 判断是否吃到食物
  if (head == food.getPosition())
  {
    score++;
    snake.grow();
    food.generate(snake.getBody());
    /*for (int i = 1; i < snake.getBody().size(); ++i)
    {
      if (snake.getBody()[i] == food.getPosition())
      {
        food.generate();
      }
    }*/
  }

  ui->btnStart->setEnabled(false);
  update();
}

 //碰撞判断函数
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

void GameWidget::on_btnStart_clicked()
{
  qDebug() << "GameOver:" << gameOver;
  if(gameOver)
  {
     // 重置游戏状态
    snake = Snake();
    food.generate(snake.getBody());
    gameOver = false;
    isPause = false;
    ui->btnPause->setText("Pause");
    ui->btnPause->setEnabled(true);
    score = 0;

    timer->start(GSpeed);

    setFocus();
    update();
  }
}

void GameWidget::on_btnPause_clicked()
{
  //qDebug() << "isPause:" <<isPause;
  if(isPause)
  {
    ui->btnPause->setText("Pause"); //切换按钮的文字显示
    timer->start(GSpeed); //计时器开始
    isPause = false;
    setFocus();
    update();
    return;
  }
  else
  {
    ui->btnPause->setText("Continue"); //切换按钮的文字显示
    timer->stop();  //计时器暂停
    isPause = true;
    setFocus();
    update();
    return;
  }


}

void GameWidget::on_btnRestart_clicked()
{
   //重置游戏状态
  snake = Snake();
  food.generate(snake.getBody());
  gameOver = false;
  isPause = false;
  ui->btnPause->setText("Pause");
  score = 0;

  timer->start(150);

  setFocus();
  update();
}

void GameWidget::loadScore()
{
  QFile file("save.txt");
  if(file.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QTextStream in(&file);
    in >> Max_score;
    file.close();
  }
  else
  {
    qDebug()<<"fail to open the file";
  }

}

void GameWidget::saveScore()
{
  QFile file("save.txt");
  if(file.open(QIODevice::WriteOnly | QIODevice::Text))
  {
    QTextStream out(&file);
    out << Max_score;
    file.close();
  }
  else
  {
    qDebug() << "fail to open the file";
  }
}

void GameWidget::do_setSpeed()
{
  if(ui->speed_1x->isChecked()) //一倍速
  {
    GSpeed = 150;
  }
  else if(ui->speed_2x->isChecked()) //二倍速
  {
    GSpeed = 75;
  }
  else if(ui->speed_1point5->isChecked()) //一点五倍速
  {
    GSpeed = 100;
  }
  else //默认一倍速
  {
    GSpeed = 150;
  }
   //刷新计时器
  this->timer->stop();
  if(!gameOver)
  {
    this->timer->start(GSpeed);
  }
}

void GameWidget::paintGrid(QPainter &painter)
{
  QPen pen(Qt::lightGray);
  pen.setWidth(1);
  painter.setPen(pen);

  int rows = height() / gridSize;
  int cols = (width()-150) / gridSize;

   // 画横线
  for (int row = 0; row <= rows; ++row) {
    int y = row * gridSize;
    painter.drawLine(0, y, width()-150, y);
  }

   // 画竖线
  for (int col = 0; col <= cols; ++col) {
    int x = col * gridSize;
    painter.drawLine(x, 0, x, height());
  }
}








