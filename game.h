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
  //Item(){name = "", desc = "";}
  string getName(void){return name;}
  string getDesc(void){return desc;}
};
//Item::Item(string n, string d) : name(n), desc(d){}


class Enemy {
private:
  string name;
  int health;
  int attackPower;
public:
  Enemy(string n, int h, int a);
  //Enemy(){name = "", health = 0, attackPower = 0;}
  string getName(void){return name;}
  int getHealth(void){return health;}
  int getAttackPower(void){return attackPower;}
  void setHealth(int h){health -= h;}
};
//Enemy::Enemy(string n, int h, int a) : name(n), health(h), attackPower(a){}


class Place {
private:
  string desc;
public:
  vector<Item> itemList;
  vector<Enemy> enemyList;
  vector<Place*> placeList;

  Place(string desc);
  string getDesc(){return desc;}
  void addItem(const Item& i){itemList.push_back(i);}
  void addEnemy(const Enemy& e){enemyList.push_back(e);}
  void addPlace(Place* p){placeList.push_back(p);}
  void printItems(){
    if (itemList.empty()) {
        cout << "- No items." << endl;
    } else {
        cout << "- Items:" << endl;
        for (auto& Item : itemList) {
            cout << "  - " << Item.getName() << ": " << Item.getDesc() << endl;
        }}}
  void printEnemies(){
    if (enemyList.empty()) {
        cout << "- No enemies." << endl;
    } else {
        cout << "- Enemies:" << endl;
        for (auto& Enemy : enemyList) {
            cout << "  - " << Enemy.getName() << " (Health: " << Enemy.getHealth() 
            << ", Attack Power: " << Enemy.getAttackPower() << ")" << endl;
        }}}
};


class Player {
  private: 
  string name; 
  int health; 
  int attackPower; 
  
  vector<Item> inventory;
  
  public: 
  Place* currentPlace; 
  
  //Functions
  Player(const string& n, int h, int a) : name(n), health(h), attackPower(a), currentPlace(nullptr) {}; 
  void pickUpItem(const Item& i) {
	  inventory.push_back(i);
	  cout << name << " picks up " << i.getName() << "." << endl; 
  }
  void attackEnemy( Enemy& e) {
	  cout << name << " attacks " << e.getName() << " with power " <<  attackPower << endl;
	  e.setHealth(attackPower); 
	  int newHp = max(0, e.getHealth());
	  
	  if (newHp <= 0) { 
		cout << e.getName() << " has been defeated!" << endl; 
	  } else { 
		cout << e.getName() << " has " << newHp << " health left." << endl;
	  }	  
  }
  
  void displayInventory() const {
	  cout << "Inventory:" << endl; 
	  if (inventory.empty()) {
		  cout << "Inventory is empty" << endl;
		  return; 
	  }
	  for (const auto& i : inventory) {
			cout << "- " << i.getName() << ": " << i.getDesc() << endl; 
	} 
  }
  
  void moveToPlace(Place* p) {
	  if (!p) return; 
	  currentPlace = p; 
	  cout << name << " moves to " << p->getDesc() << endl; 
  }
 };
