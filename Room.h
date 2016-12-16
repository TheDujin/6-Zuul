#include <iostream>
#include <string.h>
#include <map>
#include <vector>

using namespace std;
//Struct item which holds only its name and nothing else.
struct Item {
  char* name;
};
//Define Room's members and functions.
class Room {
 public:
  Room(char* newName);
  char* getName();
  Room* getExit(int exit);
  void setExit(int direction, Room* nextRoom);
  void addItem(Item* newItem);
  Item* removeItem(char* itemName);
  bool hasItems();
  void printRoom();
  void setName(char* newName);
  
 protected:
  char* name;
  map<int, Room*> exitMap;
  vector<Item*> itemList;
};
