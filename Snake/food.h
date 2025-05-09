#ifndef FOOD_H
#define FOOD_H

#include <QPoint>
#include <QRandomGenerator>

class Food
{
public:
  Food(int maxX, int maxY);
  void generate();
  QPoint getPosition() const;

private:
  int maxX, maxY;
  QPoint position;
};

#endif // FOOD_H
