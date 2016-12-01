#include <iostream>
#include <string.h>

using namespace std;

class Room {
 public:
  char* getName();

 protected:
  char* title;
  map <int, Room> exitMap;
