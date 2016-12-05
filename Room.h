#include <iostream>
#include <string.h>
#include <map>
#include <vector>

using namespace std;

class Room {
 public:
  Room(char* newName);
  char* getName();
  Room* getExit(int exit);
  void setExit(int direction, Room* nextRoom);
  void addItem(Item* newItem);
  Item* removeItem(char* itemName);
  
 protected:
  char* name;
  map<int, Room*> exitMap;
  vector<Item*> itemList;
};
