#include <iostream>
#include <string>
using namespace std;

class Fan
{
public:
  Fan()
  {
    speed = 1;
    on = false;
    radius = 5;
    color = string("white");
  }

  int getSpeed()
  {
    return speed;
  }

  void setSpeed(int speed)
  {
    this->speed = speed;
  }

  bool isOn()
  {
    return on;
  }

  void setOn(bool trueOrFalse)
  {
    this->on = trueOrFalse;
  }

  double getRadius()
  {
    return radius;
  }

  void setRadius(double radius)
  {
    this->radius = radius;
  }

  string getColor()
  {
    return color;
  }

  void setColor(string color)
  {
    this->color = color;
  }

private:
  int speed;
  bool on;
  double radius;
  string color;
};


int main()
{
  cout << "First fan properties: " << endl;
  Fan fan;
  fan.setSpeed(3);
  fan.setRadius(10);
  fan.setOn(true);
  fan.setColor("yellow");

  cout << "Fan speed: " << fan.getSpeed() << endl;
  cout << "Fan radius: " << fan.getRadius() << endl;
  cout << "Fan on? " << fan.isOn() << endl;
  cout << "Fan color: " << fan.getColor() << endl;

  Fan fan1;
  fan1.setSpeed(2);
  fan1.setRadius(5);
  fan1.setOn(false);

  cout << "\nSecond fan properties: " << endl;
  cout << "Fan speed: " << fan1.getSpeed() << endl;
  cout << "Fan radius: " << fan1.getRadius() << endl;
  cout << "Fan on? " << fan1.isOn() << endl;
  cout << "Fan color: " << fan1.getColor() << endl;


  return 0;
}
