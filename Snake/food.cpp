#include "food.h"
#include <cstdlib>
#include <ctime>

Food::Food(int maxX, int maxY) : maxX(maxX), maxY(maxY) //构造函数，传入地图大小，限制 food 的位置，不会生成到界外去
{
  //std::srand(static_cast<unsigned>(std::time(nullptr)));
  generate();
}

void Food::generate() //随机生成 food 在地图上
{
  int x = QRandomGenerator::global()->bounded(maxX);
  int y = QRandomGenerator::global()->bounded(maxY);
  position.setX(x);
  position.setY(y);
}

void Food::generate(const QList<QPoint>& SnakeBody)
{
  bool vaild = false;
  QPoint temp;
  while(!vaild)
  {
    int x = QRandomGenerator::global()->bounded(maxX);
    int y = QRandomGenerator::global()->bounded(maxY);
    temp.setX(x);
    temp.setY(y);
    vaild = true;

    for(const QPoint& p : SnakeBody)
    {
      if(p == temp || position == temp)
      {
        vaild = false;
        break;
      }
    }
    position = temp;
  }
}

QPoint Food::getPosition() const //获取 food 的坐标
{
  return position;
}
