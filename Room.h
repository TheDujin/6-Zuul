#include <iostream>
#include <string.h>
#include <map>

using namespace std;

class Room {
 public:
  Room(char* newName);
  char* getName();
  Room* getExit(int exit);
  void setExit(int direction, Room* nextRoom);
  
 protected:
  char* name;
  map<int, Room*> exitMap;
};
