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
  Room* currentRoom = starting;

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

  starting->setExit(1, dough);
  starting->setExit(2, bagel);
  starting->setExit(-1, corridor2);
  starting->setExit(-2, corridor1);

  dough->setExit(-1, starting);

  bagel->setExit(-2, starting);

  corridor2->setExit(1, starting);
  corridor2->setExit(-1, storageDoor);

  corridor1->setExit(2, starting);
  corridor1->setExit(-1, milk);
  corridor1->setExit(-2, bucket);

  milk->setExit(1, corridor1);

  bucket->setExit(2, corridor1);

  storageDoor->setExit(1, corridor2);
  storageDoor->setExit(2, acid);

  acid->setExit(-2, storageDoor);

  storage->setExit(1, storageDoor);
  storage->setExit(2, key);

  key->setExit(-2, storage);

  secret->setExit(2, storage);

  secretSecret->setExit(3, secret);

  exitKey->setExit(2, secretSecret);

  cout << "Welcome to Adventure which is a C++ version of my Zuul game from Java last year!" << endl;
  bool isRunning = true;

  const char get[] = "GET";
  const char drop[] = "DROP";
  const char use[] = "USE";
  const char go[] = "GO";
  const char help[] = "HELP";
  const char inventory[] = "INVENTORY";
  const char quit[] = "QUIT";
  char input[81];
  while (isRunning) {
    cout << "Please enter GET, DROP, USE, GO, HELP, INVENTORY, and QUIT" << endl;
    cin >> input;
    cin.ignore();
    if (strcasecmp(input, get) == 0) {
      
      //mediaList.push_back(addMedia());
      cout << "Getting..." << endl;
    }
    else if (strcasecmp(input, drop) == 0) {
      /*if (mediaList.size() < 1)
	cout << "There isn't anything to delete. Maybe you should \"ADD\" something first?" << endl;
	else
	deleteMedia(listPtr);*/
      cout << "Dropping..." << endl;
    }
    else if (strcasecmp(input, use) == 0) {
      /*if (mediaList.size() < 1)
	cout << "There isn't anything to search for. Maybe you should \"ADD\" something first?" << endl;
      else
      searchMedia(listPtr);*/
    }
    else if (strcasecmp(input, go) == 0) {
      /*cout << "Quitting..." << endl;
	cout << "Program terminated. Thanks for your time." << endl;
	isRunning = false;*/
    }
    else if (strcasecmp(input, help) == 0) {
      
    }
    else if (strcasecmp(input, inventory) == 0) {
      
    }
    else if (strcasecmp(input, quit) == 0) {

    }

    else {
      cout << "That command does not seem to be valid. Please check your spelling." << endl;
    }
  }
  
  return 0;
}
