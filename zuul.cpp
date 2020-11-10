#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

int move(room**, int, item**);

bool wincheck(item **);

int main() {
  int num_room = 15;
  int total_items = 5;
  room *room_db[num_room] = {NULL};
  item *item_db[total_items] = {NULL};
  //ROOM_SETUP

  char r_name[num_room][100] = {"Glass room",
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
  char r_description[num_room][200] ={"You are in the glass room, all around you see the lucious green of the white house garden.",
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

	int exits[num_room][4] = {{0, 0, 2, 0},
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
	for (int i = 0; i< num_room; i++){
		room *room_temp = new room(r_name[i], r_description[i], i+1, &exits[i][0]);
//		for (int j = 0; j< 4; j++){
			//cout<< exits[i][j] << ' ';
//		}
//		cout << endl;
		room_db[i] = room_temp;
	}

	char item_name[total_items][10] = { "mop",
										"robot",
										"key",
										"book",
										"pen"};

	//items initial location
	int init_location[5] = {3, 4, 9, 2, 12};

	for (int i = 0; i < total_items; i++)
	{
		int location = init_location[i];
		item *item_temp = new item(item_name[i], location);
		item_db[i] = item_temp;

		//put the item in the room
		room_db[location]->drop_item(item_temp);
	}
	
	cout << "debug: ";
	for (int i = 0; i< num_room; i++){
		cout << "room number: " << i << "has the following items: "<< endl;
		item *it = NULL;
		for(int j = 0; j < 5; j++)
		{
			it = room_db[i]->getitem(j);
			if(it != NULL)
				cout << it->getname() << " ";
		}
	}



  //GAME_PLAY

	bool stop = false; //boolean to keep track if the user is still playing the game
	int currentlocation = 4;
	char input[30]; //char to track what the user wants to do
	item *picked_db[5] ={NULL, NULL, NULL, NULL, NULL};

    while (stop == false){
		
		currentlocation = move(room_db, currentlocation, picked_db);
		if(wincheck(picked_db)){
			stop = true;
		}
		if(currentlocation==100){
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

int move(room **roomdb, int currentlocation, item **picked){
	int curr = currentlocation;
	room *temp = roomdb[curr];
	cout << temp->getdescription()<<endl;
	cout << "The possible exits are "<<endl;
	int *tempexits = temp->getexits();
	for(int i = 0; i<4; i++){
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
			cout << temptwo->getname() << endl;
		}

	}
	cout << "Items:" << endl;
	for (int k = 0; k < 5; k++)
	{
		item *t_item = NULL;
		t_item = temp->getitem(k);
		if(t_item != NULL) {
			cout << t_item->getname() << endl;
		}
	}
	cout<<"Please input the direction you would like to move, or whether you would like to pick up or drop an item" << endl;
	char input[30];
	cin >> input;
	cout << input << endl;

	

	int tempoldlocation = currentlocation;
	if(strcmp(input, "NORTH")==0){
		
		currentlocation = tempexits[0];
	}
	else if(strcmp(input, "EAST")==0){
		currentlocation = tempexits[1];
	}
	else if(strcmp(input, "SOUTH")==0){
		currentlocation = tempexits[2];
	}
	else if(strcmp(input, "WEST")==0){
		currentlocation = tempexits[3];
	}
	else if(strcmp(input, "pickup")==0){
		item *t_item;
		bool nothing = true;
		cout << "Here are the items in this room:";
		for (int k = 0; k < 5; k++)
		{
			t_item = temp->getitem(k);
			if(t_item != NULL) {
				cout << t_item->getname();
				nothing = false;
			}
		}
		if(nothing)
			cout << "Oops no item here" << endl;
		else
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
	else if(strcmp(input, "drop")==0){
		cout << "which item would you like to drop?" <<endl;
		cout << "this is the list of items you are carrying:" << endl;
		for(int l = 0; l < 5; l++)
		{
			if(picked[l] != NULL)
				cout << picked[l]->getname() << endl;
		}
		cin >> input;
		
		
		item *drop_item = NULL;
		
		for(int l = 0; l < 5; l++)
		{
			if(input == picked[l]->getname())
			{
				drop_item = picked[l];
				picked[l] = NULL;
			}
			else
			{
				cout << "no such item" << endl;
			}
			
		}
		temp->drop_item(drop_item);
	}
	else if(strcmp(input,"QUIT")==0){
			return 100;
	}
	if(currentlocation != 0) {
		currentlocation = currentlocation -1;
		//cout << "new location"<< currentlocation;
		return currentlocation;
	} else {
		cout << "No exit here" << endl;
		return tempoldlocation;	
	}
}

bool wincheck(item **itemdb){
	int num_picked_items = 0;
	for (int i = 0; i << 5; i++)
	{
		if(itemdb[i] != NULL)
			num_picked_items++;
	}
	if(num_picked_items == 5){
		cout << "Great job you have WON!!";
		return true;
	}
	else{
		cout << "keep playing you have " << num_picked_items << "so far" << endl;
		return false;
	} 
	return false;
}