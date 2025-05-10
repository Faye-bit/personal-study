#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
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

private slots:
  void updateGame(); // 每帧更新
  void on_btnStart_clicked(); //btnStart 的槽函数
  void on_btnPause_clicked(); //btnPause 的槽函数
  void on_btnRestart_clicked(); //btnRestart 的超函数

private:
  const int gridSize = 20; // 每个方格的像素大小
  const int gridWidth = 20; // 格子数
  const int gridHeight = 20;
  QTimer *timer; // 定时器用于控制蛇移动速度
  Snake snake; // 蛇
  Food food; // 食物
  bool gameOver = false;
  bool isPause =false;
  Ui::Menu *ui;

  bool checkCollision(); // 碰撞检测
};

#endif // GAMEWIDGET_H
