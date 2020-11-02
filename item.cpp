#include <cstring>

#include "item.h"
item::item(char * name1, int location1){
  strcpy(name, name1);
  location = location1;
}
item::~item(){
  location = 0;
}
char* item::getname(){
  return name;
}
int item::getlocation(){
  return location;
}
void item::setlocation(int x){
  location = x;
}
