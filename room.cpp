#include <cstring>
#include "room.h"

using namespace std;


room::room(char *name1, char* description1, int id1, int* exit1){
  strcpy(name, name1);
  strcpy(description, description1);
  id = id1;
  for(int i = 0; i<4; i++)
  {
    exit[i] = exit1[i];
  }
}
room::~room(){
  *name = NULL;
  *description = NULL;
  id = 0;
  for(int i = 0; i<4; i++)
  {
    exit[i] = 0;
  }
}

char* room::getname(){
  return name;
}

char* room::getdescription(){
  return description;
}

int *room::getexits(){
  return exit;
}

/*
void room::set_num_items(int y){
  num_items = y;
}
*/
int room::getid(){
  return id;
}

item *room::getitem(int i){
  return items[i];
}

void room::drop_item(item * item1){
  for(int i = 0; i < 5; i++){
    if(items[i] == NULL){
      items[i] = item1;
    }
  }

}

item *room::pickup_item(char *item_name){
  item *temp_item;
  for(int i = 0; i < 5; i++){
    if(strcmp(items[i]->getname(), item_name)== 0){
      temp_item = items[i];
      items[i] = NULL;
    }
  }
  return temp_item;
}



