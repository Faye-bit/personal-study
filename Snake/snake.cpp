#include "snake.h"

Snake::Snake()
{
  body.append(QPoint(5, 5));
  direction = Right;
}

void Snake::move()
{
  QPoint head = body.first(); //获取蛇头的坐标
  switch (direction) //操控蛇的移动
  {
  case Up:    head.ry() -= 1; break;
  case Down:  head.ry() += 1; break;
  case Left:  head.rx() -= 1; break;
  case Right: head.rx() += 1; break;
  }
  body.prepend(head); //在 body 的最前面插入移动后的蛇头
  body.removeLast(); //删除尾部（除非吃到食物）
}

void Snake::grow()
{
  body.append(body.last()); //增加尾巴
}

bool Snake::checkCollision() const //检测是否蛇头碰撞到蛇身
{
  QPoint head = body.first();
  for (int i = 1; i < body.size(); ++i) //遍历蛇身
  {
    if (body[i] == head) return true; //如果蛇身的坐标和蛇头相等，返回true
  }
  return false;
}

void Snake::setDirection(Direction dir) // 防止反向
{
  if ((direction == Up && dir != Down) ||
      (direction == Down && dir != Up) ||
      (direction == Left && dir != Right) ||
      (direction == Right && dir != Left)) {
    direction = dir;
  }
}

const QList<QPoint>& Snake::getBody() const
{
  return body;
}
