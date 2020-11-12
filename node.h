/*
Node .h file
By: Nividh Singh
Date: 10/21/20
*/

#include <cstring>
#include <iostream>

#ifndef STUDENT_H
#define STUDENT_H
#include "student.h"
#endif

using namespace std;

class node {
 private:
  student* thisStudent;
  node* nextNode;
 public:
  node* getNext();
  student* getStudent();
  void setNext(node* newNode); 
  node(student* newStudent);
  ~node();
};
