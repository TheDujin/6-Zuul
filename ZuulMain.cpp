#include <iostream>
#include <vector>
#include <string.h>
#include "Room.h"
#include <map>
//Adventure by Kevin Jin. Walkthrough is at the bottom of the program (line 400).
using namespace std;
//Since it's annoyingly difficult to check for strings as keys, I have constant ints that represent different directions.
const int NORTH = 1;
const int SOUTH = -1;
const int EAST = 2;
const int WEST = -2;
const int UP = 3;
const int DOWN = -3;

//Main class. This time I didn't make any functions for the main class (much more cluttered but also more simple).
int main() {
  //Define everything and set initial exits and item locations.
  vector<Room*> roomList;
  vector<Item*> inventory;
  //Item test;
  //test.name = "testicles";
  //Item* testPtr = &test;
  //inventory.push_back(testPtr);
  
  Room* starting = new Room("in a large, open room. It looks like some sort of old commons. Above you hangs a dusty flag with a strange red, blue, and white pattern.");
  Room* dough = new Room("in a small, stuffy room. The walls are painted white, and there are broken cooking utensils scattered all around.");
  Room* bagel = new Room("in a room. Aside from a bagel machine set in the corner, it is quite unremarkable.");
  Room* corridor1 = new Room("in a corridor. Through the reinforced windows, you can see the ocean.");
  Room* corridor2 = new Room("in a corridor. The lights above you flicker ominously.");
  Room* milk = new Room("in a clean, refrigerated room. It must have once been the food storage, but is now mostly empty.");
  Room* bucket = new Room("in what was once a workshop. There is little equipment here anymore.");
  Room* storageDoor = new Room("at the end of the hallway. South of you is a locked door with an odd bagel-shaped indentation where a keyhole would be. A sign above the door reads, \"US government property. No trespassing.\" What is a US?");
  Room* acid = new Room("in what might have once been a lab room. Acid is all over the place, slowly eating into the walls and floor. Was this why the facility was abandoned?");
  Room* storage = new Room("in the lab storage. South of you, you see a large metal door with the word EXIT over it. Sadly, it is locked.");
  Room* secret = new Room("in a dusty, unlit room. It must have been a secret room, used to store the most valuable equipment and materials.");
  Room* secretSecret = new Room("in a well-lit underground room. There is survival equipment neatly ordered on shelves near the walls.  West of you, there is a locked door that looks remarkably modern.");
  Room* key = new Room("in an extension of the storage room.");
  Room* exitKey = new Room("in a metal-plated bunker of sorts. How odd. A sign near the door reads, \"Welcome to the Congressional Fallout Bunker!\"");
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

  starting->setExit(NORTH, dough);
  starting->setExit(EAST, bagel);
  starting->setExit(SOUTH, corridor2);
  starting->setExit(WEST, corridor1);

  dough->setExit(SOUTH, starting);

  bagel->setExit(WEST, starting);

  corridor2->setExit(NORTH, starting);
  corridor2->setExit(SOUTH, storageDoor);

  corridor1->setExit(EAST, starting);
  corridor1->setExit(SOUTH, milk);
  corridor1->setExit(WEST, bucket);

  milk->setExit(NORTH, corridor1);

  bucket->setExit(EAST, corridor1);

  storageDoor->setExit(NORTH, corridor2);
  storageDoor->setExit(EAST, acid);

  acid->setExit(WEST, storageDoor);

  storage->setExit(NORTH, storageDoor);
  storage->setExit(EAST, key);

  key->setExit(WEST, storage);

  secret->setExit(EAST, storage);

  secretSecret->setExit(UP, secret);

  exitKey->setExit(EAST, secretSecret);

  Item* temp;
  temp = new Item;
  temp->name = "wad_of_dough";
  dough->addItem(temp);
  temp = new Item;
  temp->name = "bucket";
  bucket->addItem(temp);
  temp = new Item;
  temp->name = "milk_carton";
  milk->addItem(temp);
  temp = new Item;
  temp->name = "key";
  key->addItem(temp);
  temp = new Item;
  temp->name = "yardstick";
  storage->addItem(temp);
  temp = new Item;
  temp->name = "another_key";
  exitKey->addItem(temp);

  //Introduction and set constant cstrings for commands.
  cout << "Welcome to Adventure!" << endl;
  cout <<"This is a C++ version of my Zuul game from Java last year!" << endl;
  bool isRunning = true;

  const char get[] = "GET";
  const char drop[] = "DROP";
  const char use[] = "USE";
  const char go[] = "GO";
  const char help[] = "HELP";
  const char inv[] = "INVENTORY";
  const char quit[] = "QUIT";
  char input[81];
  //While player has not won/lost/quit, prompt them for an action.
  while (isRunning) {
    //Print out info about the current room.
    cout << "You are ";
    currentRoom->printRoom();
    cout << "Please enter GET, DROP, USE, GO, HELP, INVENTORY, and QUIT" << endl << "?: ";
    cin >> input;
    cin.ignore();
    //Check which command was called and take appropriate actions.
    if (strcasecmp(input, get) == 0) {
      //Figure out what item player wants to get and get it if possible. Otherwise tell them why they can't get it.
      if (currentRoom->hasItems()) {
	cout << "What item would you like to pick up?" << endl << "?: ";
	cin >> input;
	Item* targetItem = currentRoom->removeItem(input);
	if (targetItem) {
	  inventory.push_back(targetItem);
	  cout << "You have acquired: " << targetItem->name << endl << endl;
	}
	else
	  cout << "You can't get " << input << " because it's not in this room." << endl << endl;
      }
      else
	cout << "There is nothing to pick up in this room." << endl << endl;
    }
    else if (strcasecmp(input, drop) == 0) {
      //Figure out what item player wants to drop and drop it if possible. Otherwise tell them why they can't drop it.
      if (!inventory.empty()) {
	cout << "What item would you like to drop?" << endl << "?: ";
	cin >> input;
	bool foundItem = false;
	for (int i = 0; i < inventory.size(); i++) {
	  if (strcasecmp(inventory.at(i)->name, input) == 0) {
	    foundItem = true;
	    Item* droppedItem = inventory.at(i);
	    currentRoom->addItem(droppedItem);
	    inventory.erase(inventory.begin() + i);
	    cout << "You have dropped: " << droppedItem->name << endl << endl;
	  }
	}
	if (!foundItem)
	  cout << "You can't drop " << input << " because you don't have it." << endl << endl;
      }
	  else
	    cout << "You don't have anything to drop." << endl << endl;
	}
    else if (strcasecmp(input, use) == 0) {
      //Use an item, if they have it.
      if (!inventory.empty()) {
	cout << "What item would you like to use?" << endl << "?: ";
	cin >> input;
	//Check whether they have the item they claim to have and record the index of the item.
	bool hasItem = false;
	int index = 9000;
	for (int i = 0; i < inventory.size(); i++) {
	  if (strcasecmp(inventory.at(i)->name, input) == 0) {
	    hasItem = true;
	    index = i;
	  }
	}
	if (hasItem) {
	  //Run a certain routine based off which item is being used.
	  Item* temp = new Item;
	  if (strcasecmp("milk_carton", input) == 0){
	    cout << "You shake the milk carton and prepare to drink it. As you lift the carton to drink it, a glob of cream cheese tumbles out." << endl;
	    inventory.erase(inventory.begin() + index);
	    temp->name = "glob_of_cream_cheese";
	    inventory.push_back(temp);
            cout << "\nYou lose:\nmilk_carton\n\nYou obtain:\nglob_of_cream_cheese" << endl << endl;
	  }
	  else if (strcasecmp("wad_of_dough", input) == 0 && currentRoom == bagel){
	    cout << "You place the wad of dough into the bagel machine and push the button." << endl;
	    cout << "The machine takes a while to boot, but after turning on, it quickly spits out a bagel." << endl;
	    inventory.erase(inventory.begin() + index);
	    temp->name = "bagel"; 
	    inventory.push_back(temp);
	    cout << "\nYou lose:\nwad_of_dough\n\nYou obtain:\nbagel" << endl << endl;
	  }
	  else if (strcasecmp("bagel", input) == 0){
	    bool ccBagelMade = false;
	    for (int i = 0; i < inventory.size(); i++) {
	      if (strcasecmp(inventory.at(i)->name, "glob_of_cream_cheese") == 0){
		inventory.erase(inventory.begin() + i);
		cout << "You break open the bagel carefully and spread the cream cheese over it." << endl;
		for (int j = 0; j < inventory.size(); j++)
		  if (strcasecmp(inventory.at(j)->name, "bagel") == 0)
		    inventory.erase(inventory.begin() + j);
		temp->name = "cream_cheese_bagel";
		inventory.push_back(temp);
		cout << "\nYou lose:\nbagel\nglob_of_cream_cheese\n\nYou obtain:\ncream_cheese_bagel" << endl << endl;
		ccBagelMade = true;
	      }
	    }
	    if (!ccBagelMade)
	      cout << "You can't use that item right now. Try using it under different circumstances." << endl << endl;
	  }
	  else if (strcasecmp("glob_of_cream_cheese", input) == 0){
	    bool ccBagelMade = false;
	    for (int i = 0; i < inventory.size(); i++) {
	      if (strcasecmp(inventory.at(i)->name, "bagel") == 0){
		inventory.erase(inventory.begin() + i);
		cout << "You break open the bagel carefully and spread the cream cheese over it." << endl;
		for (int j = 0; j < inventory.size(); j++)
		  if (strcasecmp(inventory.at(j)->name, "glob_of_cream_cheese") == 0)
		    inventory.erase(inventory.begin() + j);
		temp->name = "cream_cheese_bagel";
		inventory.push_back(temp);
		cout << "\nYou lose:\nbagel\nglob_of_cream_cheese\n\nYou obtain:\ncream_cheese_bagel" << endl << endl;
		ccBagelMade = true;
	      }
	    }
	    if (!ccBagelMade)
	      cout << "You can't use that item right now. Try using it under different circumstances." << endl << endl;
	  }
	  else if (strcasecmp("bagel", input) == 0 && currentRoom == storageDoor){
	    cout << "You place the bagel into the hole. Inside, machinery whirls for a moment, before it abruptly spits the bagel back out." << endl;
	    cout << "Hmm. It seems that the machine will only accept a higher-quality bagel." << endl << endl;
	  }
	  else if (strcasecmp("bucket", input) == 0 && currentRoom == acid){
	    cout << "Using your bucket, you scoop up some acid." << endl;
	    cout << "Some of it sloshes onto your hand, but you wipe it off on the wall before it can do any real damage." << endl;
	    cout << "You notice that the bucket is slowly dissolving from the inside." << endl;
	    inventory.erase(inventory.begin() + index);
	    temp->name = "bucket_of_acid";
	    inventory.push_back(temp);
	    cout << "\nYou lose:\nbucket\n\nYou obtain:\nbucket_of_acid" << endl << endl;
	  }
	  else if (strcasecmp("cream_cheese_bagel", input) == 0 && currentRoom == storageDoor){
	    cout << "You place the bagel into the hole. After scanning the cheesy bagel, the door unlocks itself." << endl;
	    storageDoor->setExit(SOUTH, storage);
	    inventory.erase(inventory.begin() + index);
	    cout << "\nYou lose:\ncream_cheese_bagel\n\nExits:\nnorth\neast\nsouth" << endl << endl;
	    storageDoor->setName("at the end of the hallway. The door in the south is now unlocked.");
	  }
	  else if (strcasecmp("key", input) == 0 && currentRoom == storage){
	    cout << "You try to insert the key into the lock, but it won't fit." << endl;
	    cout << "Filled with despair, you realize that this must be a key to a different door." << endl << endl;
	  }
	  else if (strcasecmp("bucket_of_acid", input) == 0 && currentRoom == secret){
	    cout << "What's that smell? It's the smell of your shoes dissolving. The acid has eaten a hole in the bucket, and the stuff is now slowly but steadily dropping onto your feet!" << endl;
	    cout << "You fling the bucket away from you. When it hits the wooden floor, the bucket breaks open." << endl;
	    cout << "The acid spills out and dissolves a large hole in the floor. You peer down and see an old room below the floorboards." << endl;
	    secret->setExit(DOWN, secretSecret);
	    inventory.erase(inventory.begin() + index);
	    cout << "\nYou lose:\nbucket_of_acid\n\nExits:\neast\ndown" << endl << endl;
	    secret->setName("in a dusty, unlit room. It must have been a secret room, used to store the most valuable equipment and materials. There is a hole in the floorboards.");
	  }
	  else if (strcasecmp("yardstick", input) == 0 && currentRoom == storage){
	    cout << "You notice an inconspicuous button on the ceiling of the room." << endl;
	    cout << "Using the yardstick, you push the button. There is a grinding noise as a section of the west wall slides back." << endl;
	    cout << "Then, you snap the yardstick for the heck of it." << endl;
	    storage->setExit(WEST, secret);
	    inventory.erase(inventory.begin() + index);
	    cout << "\nYou lose:\nyardstick\n\nExits:\nnorth\neast\nwest" << endl << endl;
	    storage->setName("in the lab storage. South of you is the locked exit, while west of you, a panel of the wall has slid away, opening up a new room.");
	  }
	  else if (strcasecmp("key", input) == 0 && currentRoom == secretSecret){
	    cout << "You approach the locked door and insert the key in the lock." << endl;
	    cout << "After a moment's struggle against the rust, you manage to turn the key in the lock, and the door opens with the expected creepy 'creeeeeeaak' noise," << endl;
	    cout << "followed by a somewhat less expected 'snap' noise as the key breaks off in the lock." << endl;
	    cout << "Wow. It's as if you're inside a game where every item conveniently (or inconveniently, depending on how you think about it) breaks after use." << endl;
	    cout << "But this isn't a game, it's your reality..." << endl;
	    cout << "...right?" << endl;
	    inventory.erase(inventory.begin() + index);
	    secretSecret->setExit(WEST, exitKey);
	    cout << "\nYou lose:\nkey\n\nExits:\nup\nwest" << endl << endl;
	    secretSecret->setName("in a well-lit underground room. West of you, the door is unlocked.");
	  }
	  else if (strcasecmp("another_key", input) == 0 && currentRoom == storage){
	    cout << "Your heart pounding, you try unlocking the exit with the other key." << endl;
	    cout << "The key fits perfectly, and you turn it smoothly, unlocking the door!" << endl;
	    cout << "You leave the key in the lock." << endl;
	    inventory.erase(inventory.begin() + index);
	    storage->setExit(SOUTH, exit);
	    cout << "\nYou lose:\nanother_key\n\nExits:\nnorth\neast\nsouth\nwest" << endl << endl;
	    storage->setName("in the lab storage. South of you is the unlocked exit(!!!), while west of you, a panel of the wall has slid away, opening up a new room.");
	  }
	  //The case where an item can't be used in those conditions.
	  else {
	    cout << "You can't use that item right now. Try using it under different circumstances." << endl << endl;
	  }
	}
	else
	  cout << "You can't use " << input << " because you don't have it." << endl << endl;
      }
	else
	  cout << "You don't have any items to use." << endl << endl;
    }
    else if (strcasecmp(input, go) == 0) {
      //Go somewhere, if possible. Going to the Room exit wins the game, while going in an invalid direction loses you the game.
      cout << "Which way would you like to go?" << endl << "?: ";
      cin >> input;
      int processedInput = 0;
      if (strcasecmp(input, "north") == 0)
	processedInput = NORTH;
      else if (strcasecmp(input, "south") == 0)
	processedInput = SOUTH;
      else if (strcasecmp(input, "east") == 0)
	processedInput = EAST;
      else if (strcasecmp(input, "west") == 0)
	processedInput = WEST;
      else if (strcasecmp(input, "up") == 0)
	processedInput = UP;
      else if (strcasecmp(input, "down") == 0)
	processedInput = DOWN;
      Room* nextRoom = currentRoom->getExit(processedInput);
      if (nextRoom) {
	currentRoom = nextRoom;
	cout << "You go " << input << ": " << endl << endl;
	if (currentRoom == exit) {
	  cout << "You scramble outside. You feel the breeze on your face and pump your fists exuberantly. You’ve survived!" << endl;
	  cout << "Congrats! You win!" << endl << "Thanks for playing!" << endl;
	  isRunning = false;
	}
      }
      else {
	cout << "You walk " << input << " into a wall and die." << endl << endl;
	cout << "You lose! Thanks for playing." << endl;
	isRunning = false;
      }
    }
    else if (strcasecmp(input, help) == 0) {
      //Print help.
      cout << "Help:" << endl << "You're stuck in an abandoned facility. You have no memory of how you get here, but you know you need to get out." << endl;
      cout << "Note: Commands can either be typed in one line or by following the game's prompts. For example, both \"go west\" RET and \"go\" RET \"west\" RET make the player move west." << endl << endl;
    }
    else if (strcasecmp(input, inv) == 0) {
      //Walk through the inventory and print the items.
      cout << "Your inventory:" << endl;
      if (!inventory.empty()) {
	for (int i = 0; i < inventory.size(); i++)
	  cout << inventory.at(i)->name << endl;
	cout << endl;
      }
      else
	cout << "Your inventory is empty." << endl << endl;
    }
    else if (strcasecmp(input, quit) == 0) {
      //Quit the program.
      isRunning = false;
      cout << "Quitting..." << endl << "Game over. Thanks for playing!";
    }
    
    else {
      cout << "That command does not seem to be valid. Please check your spelling." << endl << endl;
    }
  }
  
  return 0;
}
