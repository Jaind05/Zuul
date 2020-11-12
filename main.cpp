// Dhruv Jain
// 10/18/2020
//Student List
//Pointers and Structs

#include "node.h"
#include <iostream>
#include <cstring>

using namespace std;

void addnewnode(node *temp, student *newstudent);
void print(node *current, int i);
void plsaverage(node *start, int i, float average);

int main(){
  
  student *s1 = new student(" ", " ", 0, 0);
  node *Head = new node(s1);
  Head->setNext(NULL);
  bool stop = false; //boolean to keep track if the user is still using the application
  int i = 0; //keeps track of how many students are made
  char input[30]; //char to track what the user wants to do 
  while (stop == false){ // while loop for application
    cout << "Please enter ADD, PRINT, or DELETE. If you would like to close the application enter QUIT" << endl; 
    cin >> input;// Reads user input
    if(strcmp(input,"ADD")==0){

      student *newstudent = new student();
      
      cout << "Please enter the first name of the student" << endl;

      char temp[100];
      
      cin >> temp; //reads name

      newstudent -> setFirstName(temp);
      
      cout << "Please enter the Last name of the student" << endl;
      
      cin >> temp; //reads last name

      newstudent -> setLastName(temp);
      
      cout << "Please enter the ID of the student" << endl;

      int tempint;

      cin >> tempint;

      newstudent -> setStudentID(tempint);
      
      cout << "Please enter the Gpa of the student" << endl;

      float tempfloat;
      
      cin >> tempfloat; //reads gpa

      newstudent -> setGPA(tempfloat);

      addnewnode (Head, newstudent);
      }
    else if(strcmp(input,"DELETE")==0){
      /*
      cout << "Please enter student id of student you would like to delete" << endl;
      int temp = 0;
      cin >> temp;
      for (int x = 0; x<i; x++){
	if(temp == s_member[x]->id){
	  free(s_member[x]); //frees memory of the student that the user asks for
	  s_member[x]=NULL; //makes the pointer null
	}
	
	}
      */
    }
    else if(strcmp(input,"PRINT")==0){
      print(Head,0);
    }
    else if(strcmp(input,"QUIT")==0){
      //stop = true; //stops while loop
      //for (int x = 0;x<i; x++){ //for loop to free all Students
      //free(s_member[x]);
      //}
    }
    else if(strcmp(input,"AVERAGE")==0){
      plsaverage(Head,0,0);
    }
    else{
      cout << "That was not a valid command" << endl; 
    }
  }
}
void addnewnode(node *temp, student *newstudent){
  if(temp->getNext() == NULL){
    node *newnode = new node(newstudent);
    temp->setNext(newnode);
    newnode->setNext(NULL);
  }
  else if(((temp->getNext())->getStudent())->getStudentID() < newstudent -> getStudentID()){
    addnewnode(temp->getNext(), newstudent);
  }
  else if(((temp->getNext())->getStudent())->getStudentID() >= newstudent -> getStudentID()){
    node *newnode = new node(newstudent);
    newnode->setNext(temp->getNext());
    temp->setNext(newnode);
  }
}
void print(node *current, int i){

  if(current->getNext()==NULL && i == 0){
    cout << "no students yet";
  }
  else if(current->getNext()!=NULL && i == 0){
    print(current->getNext(), i+1);
  }
  else if(current->getNext()==NULL && i != 0){
    cout << current->getStudent()->getFirstName() << "  " << current->getStudent()->getLastName() << "  " << current->getStudent()-> getStudentID() << "  " << current->getStudent()->getGPA() << endl;
  }
  else if(current->getNext() != NULL && i != 0){
    cout << current->getStudent()->getFirstName() << "  " << current->getStudent()->getLastName() << "  " << current->getStudent()-> getStudentID() << "  " << current->getStudent()->getGPA() << endl;
    print(current->getNext(), i+1);
  }

}
void plsaverage(node *start, int i, float average){
  if(start->getNext()==NULL && i == 0){
    cout << "no students to average"<< endl;
  }
  else if(start->getNext()!=NULL && i == 0){
    plsaverage(start -> getNext(), i+1, average);
  }
  else if(start->getNext()==NULL && i != 0){
    average += (start->getStudent())->getGPA();
    average = average/i;
    cout << "average is: " << average << endl;
  }
  else if(start->getNext() != NULL && i != 0){
    average += (start->getStudent())->getGPA();
    plsaverage(start->getNext(), i+1, average);
  }

}

