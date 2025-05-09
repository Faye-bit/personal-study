#ifndef SNAKE_H
#define SNAKE_H

#include <QList>
#include <QPoint>

enum Direction { Up, Down, Left, Right }; //枚举类型

class Snake
{
public:
  Snake();
  void move();
  void grow();
  bool checkCollision() const;
  void setDirection(Direction dir);
  const QList<QPoint>& getBody() const;

private:
  QList<QPoint> body;
  Direction direction; //蛇当前的行进方向
};

#endif // SNAKE_H
