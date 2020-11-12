/*
Node cpp file
By: Nividh Singh
Date: 10/21/20
*/

#include <cstring>
#include <iostream>


#ifndef STUDENT_H
#define STUDENT_H
#include "student.h"
#endif

#ifndef NODE_H
#define NODE_H
#include "node.h"
#endif


using namespace std;

node* node::getNext() {
  return nextNode;  
}
student* node::getStudent() {
  return thisStudent;
}
void node::setNext(node* newNode) {
  nextNode = newNode;
}
node::node(student* newStudent) {
  thisStudent = newStudent;
}
node::~node() {
  delete thisStudent;
}
