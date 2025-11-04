#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Item {
private:
  string name;
  string desc;
public:
  Item(string n, string d);
  Item(){name = "", desc = "";}
  string getName(void){return name;}
  string getDesc(void){return desc;}
};
Item::Item(string n, string d) : name(n), desc(d){}


class Enemy {
private:
  string name;
  int health;
  int attackPower;
public:
  Enemy(string n, int h, int a);
  Enemy(){name = "", health = 0, attackPower = 0;}
};


class Place {
  /*TODO: write your code*/
};


class Player {
  /*TODO: write your code*/
};
