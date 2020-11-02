#ifndef ITEM_H
#define ITEM_H

class item
{
  
 public:
  item(char *, int);
  ~item();
  char* getname();
  int getlocation();
  void setlocation(int);
 

 private:
  char name [100];
   int location; //room_id
};


#endif

