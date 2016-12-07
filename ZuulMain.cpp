#include <iostream>
#include <vector>
#include <string.h>
#include "Room.h"
#include <map>

using namespace std;
const int NORTH = 1;
const int SOUTH = -1;
const int EAST = 2;
const int WEST = -2;
const int UP = 3;
const int DOWN = -3;


int main() {
  vector<Room*> roomList;
  
  Room* starting = new Room("in a large, open room. It looks like some sort of old commons.");
  Room* dough = new Room("in a small, stuffy room. The walls are painted white, and there are broken cooking utensils scattered all around.");
  Room* bagel = new Room("in a room. Aside from a bagel machine set in the corner, it is quite unremarkable.");
  Room* corridor1 = new Room("in a corridor. Through the reinforced windows, you can see the ocean.");
  Room* corridor2 = new Room("in a corridor. The lights above you flicker ominously.");
  Room* milk = new Room("in a clean, refrigerated room. It must have once been the food storage, but is now mostly empty.");
  Room* bucket = new Room("in what was once a workshop. There is little equipment here anymore.");
  Room* storageDoor = new Room("in a small intersection of hallways. South of you is a locked door with an odd bagel-shaped indentation where a keyhole would be.");
  Room* acid = new Room("in what might have once been a lab room. Acid is all over the place, slowly eating into the walls and floor. Was this why the facility was abandoned?");
  Room* storage = new Room("in the lab storage. South of you, you see a large metal door with the word EXIT over it. Sadly, it is locked.");
  Room* secret = new Room("in a dusty, unlit room. It must have been a secret room, used to store the most valuable equipment and materials.");
  Room* secretSecret = new Room("in an ancient, dirty room. It must have been built hundreds of years ago. West of you, there is a locked door that looks remarkably modern.");
  Room* key = new Room("in an extension of the storage room.");
  Room* exitKey = new Room("in a metal-plated bunker of sorts. How odd.");
  Room* exit = new Room("");

  roomList.push_back(starting);
  roomList.push_back(dough);
  roomList.push_back(bagel);
  roomList.push_back(corridor1);
  roomList.push_back(corridor2);
  roomList.push_back(milk);
  roomList.push_back(bucket);
  roomList.push_back(storageDoor);
  roomList.push_back(acid);
  roomList.push_back(storage);
  roomList.push_back(secret);
  roomList.push_back(secretSecret);
  roomList.push_back(key);
  roomList.push_back(exitKey);
  roomList.push_back(exit);

  cout << "Welcome to Adventure which is a C++ version of my Zuul game from Java last year!" << endl;
  bool isRunning = true;
  while (isRunning) {
    cout << "Please enter GET, GO, " << endl;

  }
  
  return 0;
}
