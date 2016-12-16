#include "Room.h"
#include <iostream>
#include <string.h>
#include <map>
#include <vector>

using namespace std;
//The constants represent directions since using char* as key is annoyingly difficult.
const int NORTH = 1;
const int SOUTH = -1;
const int EAST = 2;
const int WEST = -2;
const int UP = 3;
const int DOWN = -3;
//Here I write what each of the functions actually does.
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
  for (int i = 0; i < itemList.size(); i++) {
    if (strcasecmp(itemName, itemList.at(i)->name) == 0) {
      Item* returnedItem = itemList.at(i);
      itemList.erase(itemList.begin() + i);
      return returnedItem;
    }
  }
  return NULL;
}

bool Room::hasItems() {
  if (itemList.empty())
    return false;
  return true;
}

void Room::printRoom() {
  cout << name << endl << endl << "Items: " << endl;
  for (int i = 0; i < itemList.size(); i++)
    cout << itemList.at(i)->name << endl;
  cout << endl << "Exits: " << endl;
  for (map<int, Room*>::iterator it = exitMap.begin(); it != exitMap.end(); it++) {
    int exit = it->first;
    if (exit == NORTH)
      cout << "north" << endl;
    else if (exit == SOUTH)
      cout << "south" << endl;
    else if (exit == EAST)
      cout << "east" << endl;
    else if (exit == WEST)
      cout << "west" << endl;
    else if (exit == UP)
      cout << "up" << endl;
    else if (exit == DOWN)
      cout << "down" << endl;
  }
  cout << endl;
}

void Room::setName(char* newName) {
  name = newName;
}
