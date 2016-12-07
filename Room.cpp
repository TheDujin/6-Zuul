#include "Room.h"
#include <iostream>
#include <string.h>
#include <map>
#include <vector>

using namespace std;
const int NORTH = 1;
const int SOUTH = -1;
const int EAST = 2;
const int WEST = -2;
const int UP = 3;
const int DOWN = -3;

Room::Room(char* newName) {
  name = newName;
}

char* Room::getName() {
  return name;
}

Room* Room::getExit(int exit) {
  map<int, Room*>::iterator it = exitMap.find(exit);
  if (it != exitMap.end())
    return exitMap.find(exit)->second;
  return NULL;
}

void Room::setExit(int direction, Room* nextRoom) {
  exitMap[direction] = nextRoom;
}

void Room::addItem(Item* newItem) {
  itemList.push_back(newItem);
}

Item* Room::removeItem(char* itemName) {
  for (int i = 0; i < itemList.size(); i++)
    if (strcasecmp(itemName, itemList[i]->name)) {
      Item* returnedItem = itemList[i];
      itemList.erase(itemList.begin() + i);
      return returnedItem;
    }
  cout << "You can't pick up something that doesn't exist." << endl;
  return NULL;
}
