#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;


int main() {
  int num_room = 15;
  int total_items = 5;
  room *room_db[num_room] = {NULL};
  item *item_db[total_items] = {NULL};
  //ROOM_SETUP

  char r_name[num_room][20] = {"Glass room",
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
							 "AA",
							 "BB",
							 "CC",
							 "PASS PASS",
							 "FAIL FAIL",
							 "Are we done yet?"};
	
	int exits[num_room][4] = {(0, 0, 2, 0),
						  (0, 0, 5, 0),
						  (0, 0, 7, 0),
						  (0, 5, 9, 0),
						  (2, 6, 10, 4),
						  (0, 7, 11, 5),
						  (3, 0, 0, 6),
						  (0, 9, 12, 0),
						  (4, 10, 0, 8),
						  (5, 11, 13, 9),
						  (6, 0, 0, 10),
						  (8, 0, 0, 0),
						  (10, 0, 14, 0),
						  (13, 0, 15, 0),
						  (14, 0, 0, 0)};
  for (int i = 0; i< num_room; i++){
	  room *room_temp = new room(r_name[i], r_description[i], i+1, exits[i]);
	  room_db[i] = room_temp;
  }

char item_name[total_items][50] = { "mop",
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




  //GAME_PLAY

	bool stop = false; //boolean to keep track if the user is still playing the game
	int i = 0; //keeps track of how many students are made
	char input[30]; //char to track what the user wants to do
    while (stop == false){ 
		cout << "Please enter PLAY, QUIT, PLAY_AGAIN. If you would like to close the close enter QUIT" << endl;
		cin >> input;
		if(strcmp(input,"PLAY")==0){

		cout << "Please enter the type of the digital media (Videogame, Music, Movie)" << endl;
		
		bool running = true;
		while(running == true){
			char temptitle[100];
				int tempyear;

			cin >> input;

		}
		i++;
		}
		else if(strcmp(input,"PLAY_AGAIN")==0){
			cout << "would you like to delete a title or year?" << endl;
			cin >> input;
			if (strcmp(input,"title")==0){
				cout << "What title do you want to delete?" << endl;
				input[0] = '0';
				cin >> input;
				for(int i = 0; i < num_room; i++){
					if(room_db[i] != NULL){
					}//dm_Db = NULL
				}// for
			} //if title
			else if (strcmp(input,"year")==0){
				cout << "What year do you want to delete?" << endl;
				cin >> input;
				for(int i = 0; i < num_room; i++){
					if(room_db[i] != NULL){
						int intput;
						cin >> intput;
						/*
						if(intput == (dm_db[i]->getYear())){
							if(dm_db[i]->getid() == 0){
								//videogame
								video_games* vd;
								vd = (video_games*)dm_db[i];
								cout << "Are you sue you want to delete: "<< vd->getTitle() << ", " << vd->getYear() << ", " << vd ->getpublisher() << ", " << vd -> getrating() << endl;
								cin >> input;
								if(strcmp(input, "yes")==0){
									delete vd;
									dm_db[i] = NULL;
								}
							}
							else if(dm_db[i]->getid() == 1){
								music* mu;
								mu = (music*)dm_db[i];
								cout <<"Are you sure you want to delete: "<< mu->getTitle() << ", " << mu->getYear() << ", " << mu ->getartist() << ", " << mu -> getduration() << ", " << mu -> getpublisher() << endl;
								cin >> input;
								if (strcmp(input, "yes")==0){
									delete mu;
									dm_db[i] = NULL;
								}
							}
							else if(dm_db[i]->getid() == 2){
								movie* mv;
								mv = (movie*)dm_db[i];
								cout <<"Are you sure you want to delete: " << mv->getTitle() << ", " << mv->getYear() << ", " << mv ->getdirector() << ", " << mv -> getrating() << ", " << mv -> getduration() << endl;
								cin >> input;
								if(strcmp(input, "yes")==0){
									delete mv;
									dm_db[i] = NULL;
								}
							} getid
						} //getyear
					*/
					} //room_db != NULL
				} //for
			} //year
		} // play_again
		else if(strcmp(input,"QUIT")==0){
			stop = true; //stops while loop
			for (int x = 0;x < total_items; x++){ //for loop to free all Students
				delete item_db[x];
			}
			for (int x = 0;x < num_room; x++){ //for loop to free all Students
				delete room_db[x];
			}
		}
		else{
			cout << "That was not a valid command" << endl;
		}
	}//while
}//main
  
