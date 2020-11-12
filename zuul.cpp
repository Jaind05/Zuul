
//Dhruv Jain
//11/10/20
// Zuul C++ program
//White House Choose you own adventure game

#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

int move(room**, int, item**); //makes one action

bool wincheck(item **); //checks if someone has won

int main() { //Main method
  cout << "Welcome to the White House scavengar hunt. There are 5 items hidden across the White House. When you find them all you will win. Good Luck!" << endl; //story print statment
  int num_room = 15;
  int total_items = 5;
  room *room_db[num_room] = {NULL}; //room vector
  item *item_db[total_items] = {NULL}; //item vector
  //ROOM_SETUP
  
  char r_name[num_room][100] ={"Glass room", //room name decleration
    "Roosevelt room",
    "Kitchen",
    "Vice President's room",
    "North Center Hall",
    "Ballroom",
    "Dining Room",
    "President's Secretary's Office",
    "Chief of Staff's Room",
    "South Center Hall",
    "Guest Bedroom",
    "Oval Office",
    "Lobby",
    "Main Entry Hall",
    "Front lawn"};
  char r_description[num_room][200] ={"You are in the glass room, all around you see the lucious green of the white house garden.", //room description decleration
    "You are in the Roosevelt roomm, you see a long wodden table lined with shiny wooden chairs.",
    "You are in the kitchen, there are countless cooks swarming around you making every dish imaginable.",
    "You are in the Vice President's room, you see a study desk surrounded by american flags.",
    "You are in the north center hall, there are many doors on your left and right",
    "You are in the ballroom, it has a super tall celing, with massive speakers.",
    "You are in the Dining room, the table is all set for am extravagent meal.",
    "You are in the President's Secretary's room, you see massive binders that obviously contain important information stacking the tall cabinets on all sides.",
    "You are in the Chief of staffs room",
    "You are in the South Cneter hall, tehre are doors to your left and right",
    "You are in the guest bedroom, there is rumoured to be a ghost in this room",
    "You are in the Oval office, and see the president's desk",
    "You are in the lobby and see pictures of all the past presidents",
    "You are in the Main Entry Hall, ready to greet guests",
    "You are outside on the front lawn"};
  
  int exits[num_room][4] = {{0, 0, 2, 0}, //declares which exits each room has. exit 0 = no exit
			    {0, 0, 5, 0},
			    {0, 0, 7, 0},
			    {0, 5, 9, 0},
			    {2, 6, 10, 4},
			    {0, 7, 11, 5},
			    {3, 0, 0, 6},
			    {0, 9, 12, 0},
			    {4, 10, 0, 8},
			    {5, 11, 13, 9},
			    {6, 0, 0, 10},
			    {8, 0, 0, 0},
			    {10, 0, 14, 0},
			    {13, 0, 15, 0},
			    {14, 0, 0, 0}};
  for (int i = 0; i< num_room; i++){ //creates rooms
    room *room_temp = new room(r_name[i], r_description[i], i+1, &exits[i][0]);
    //		for (int j = 0; j< 4; j++){
    //cout<< exits[i][j] << ' ';
    //		}
    //		cout << endl;
    room_db[i] = room_temp;
  }
  
  char item_name[total_items][10] = { "pen", //initializes item names
    "Spoon",
    "Egg",
    "plant",
    "flag"};
  
  //items initial location
  int init_location[5] = {11, 2, 14, 0, 3};
  
  for (int i = 0; i < total_items; i++) //places items
    {
      int location = init_location[i];
      item *item_temp = new item(item_name[i], location);
      item_db[i] = item_temp;
      
      //put the item in the room
      room_db[location]->drop_item(item_temp);
    }
  
  
  
  //GAME_PLAY
  
  bool stop = false; //boolean to keep track if the user is still playing the game
  int currentlocation = 4; //current location
  char input[30]; //char to track what the user wants to do
  item *picked_db[5] ={NULL, NULL, NULL, NULL, NULL};
  
  while (stop == false){ //main gameplay loop
    
    currentlocation = move(room_db, currentlocation, picked_db);
    if(wincheck(picked_db)){ //if user has won
      stop = true;
    }
    if(currentlocation==100){ //if user wants to quit
      stop = true; //stops while loop
      for (int x = 0;x < total_items; x++){ //for loop to free all items
	delete item_db[x];
      }
      for (int x = 0;x < num_room; x++){ //for loop to free all rooms
	delete room_db[x];
      }
    }
  }//while
  
}//main

int move(room **roomdb, int currentlocation, item **picked){ //function to make a user action
  int curr = currentlocation;
  room *temp = roomdb[curr];
  cout << temp->getdescription()<<endl;
  cout << "The possible exits are "<<endl;
  int *tempexits = temp->getexits();
  for(int i = 0; i<4; i++){ //prints exit titles
    if(tempexits[i]!=0){
      if(i==0){
	cout<< "NORTH: ";
      }
      if(i==1){
	cout<< "EAST: ";
      }
      if(i==2){
	cout<< "SOUTH: ";
      }
      if(i==3){
	cout<< "WEST: ";
      }
      room *temptwo = roomdb[tempexits[i]-1];
      cout << temptwo->getname() << endl; //prints out exit names
    }
    
  }
  cout << "Items:" << endl; //prints items title
  for (int k = 0; k < 5; k++)
    {
      item *t_item = NULL;
      t_item = temp->getitem(k);
      if(t_item != NULL) {
	cout << t_item->getname() << endl; //prints item names
      }
    }
  cout<<"Please input the direction you would like to move, or whether you would like to pick up or drop an item" << endl;
  char input[30];
  cin >> input;
    bool moved = true;
    if(strcmp(input, "NORTH")==0){ //if move North
    if(tempexits[0]!= 0)
      currentlocation = (tempexits[0]-1);	  
  }
    else if(strcmp(input, "EAST")==0){ //if move east
    if(tempexits[1]!= 0)
      currentlocation = (tempexits[1]-1);
  }
    else if(strcmp(input, "SOUTH")==0){ //if move South
    if(tempexits[2]!= 0){
      currentlocation = (tempexits[2]-1);
    }
  }
    else if(strcmp(input, "WEST")==0){ //if move West
    if(tempexits[3]!= 0)
      currentlocation = (tempexits[3]-1);
  }
    else if(strcmp(input, "pickup")==0){ //if Pickup
    item *t_item;
    moved = false;
    bool nothing = true;
    cout << "Here are the items in this room: "; //prints items again
    for (int k = 0; k < 5; k++)
      {
	t_item = temp->getitem(k);
	if(t_item != NULL) {
	  cout << t_item->getname() << endl;
	  nothing = false;
	}
      }
    if(nothing){
      cout << "Oops no item here" << endl;
    }
    else{
      cout << "which item would you like to pick up?" << endl;
      cin >> input;
      for(int l = 0; l < 5; l++)
	{
	  if(picked[l] == NULL)
	    {
	      picked[l] = temp->pickup_item(input);
	      break;
	    }
	}
    }
  }
    else if(strcmp(input, "drop")==0){ //if wants to drop
    moved = false;
    cout << "which item would you like to drop?" <<endl;
    cout << "this is the list of items you are carrying:" << endl;
    for(int l = 0; l < 5; l++)
      {
	if(picked[l] != NULL)
	  cout << picked[l]->getname() << endl;
      }
    cin >> input;
    
    
    item *temp_drop_item = NULL;
    
    for(int l = 0; l < 5; l++)
      {
	if(strcmp(input, picked[l]->getname())==0)
	  {
	    temp_drop_item = picked[l];
	    picked[l] = NULL;
	    break;
	    
	  }
	else
	  {
	    cout << "no such item" << endl;
	  }
	
      }
    temp->drop_item(temp_drop_item);
  }
  else if(strcmp(input,"QUIT")==0){
    return 100;
  }
  return currentlocation;
}

bool wincheck(item **itemdb){ //checks if the user has won
  int num_picked_items = 0;
  for (int i = 0; i < 5; i++) //for loop to see if the user has all the items
    {
      if(itemdb[i] != NULL)
	num_picked_items++;
    }
  if(num_picked_items == 5){ //you won!
    cout << "Great job you have WON!!";
    return true;
  }
  else{
    cout << endl << endl << "keep playing you have " << num_picked_items << " item so far" << endl;
    return false;
  } 
  return false;
}
