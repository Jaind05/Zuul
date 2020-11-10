#ifndef ROOM_H
#define ROOM_H

#include "item.h"

using namespace std;

class room{
public:
 room(char *, char*, int, int*);
  ~room();
  char* getname();
  char* getdescription();
  int* getexits();
  item* getitem(int);
  int getid();
  //void set_num_items(int);
  void drop_item(item *);
  item *pickup_item(char *);
  
private:
  char name [100];
  char description[200];
  int id; //1 through 15
  int exit[4];  // 0 = North , 1 = EAST, 2= South, 3 = west 
  //int num_items;
  item *items[5];
};


#endif
