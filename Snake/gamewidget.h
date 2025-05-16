#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QFile>
#include <QRadioButton>
#include <QPainter>
#include "snake.h"
#include "food.h"
#include "ui_widget.h"

class GameWidget : public QWidget
{
  Q_OBJECT

public:
  explicit GameWidget(QWidget *parent = nullptr);

protected:
  void paintEvent(QPaintEvent *event) override; // 绘图事件
  void keyPressEvent(QKeyEvent *event) override; // 键盘事件
  void loadScore(); //载入最高分数
  void saveScore(); //保存最高分数
  void paintGrid(QPainter &painter); //绘制地图网格

private slots:
  void updateGame(); // 每帧更新
  void on_btnStart_clicked(); //btnStart 的槽函数
  void on_btnPause_clicked(); //btnPause 的槽函数
  void on_btnRestart_clicked(); //btnRestart 的槽函数
  void do_setSpeed(); // spped_1x 和speed_2x 的槽函数

private:
  const int gridSize = 20; // 每个方格的像素大小
  const int gridWidth = 30; // 格子数
  const int gridHeight = 30;
  QTimer *timer; // 定时器用于控制蛇移动速度
  int GSpeed = 150;
  Snake snake; // 蛇
  Food food; // 食物
  QPixmap foodImage;
  int welcome = 0; //打开游戏提示
  bool gameOver = true; //游戏结束
  bool isPause =false; //游戏暂停
  bool directionChange = false; //防止方向再一次 update 中多次改变
  Ui::Menu *ui;
  int score = 0; //得分
  int Max_score = 0; //最高得分

  bool checkCollision(); // 碰撞检测
};

#endif // GAMEWIDGET_H
