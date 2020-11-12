/*
student .h file
By: Nividh Singh
Date: 10/21/20
*/

#include<cstring>
#include <iostream>

using namespace std;

class student {
 private:
  char* firstName;
  char* lastName;
  float GPA;
  int studentID;
 public:
  char* getFirstName();
  void setFirstName(char* newFirstName);
  char* getLastName();
  void setLastName(char* newLastName);
  float getGPA();
  void setGPA(float newGPA);
  int getStudentID();
  void setStudentID(int newStudentID);
  student();
 student (char* fName, char* lname, float nGPA, int nStudentID);
 student (float nGPA, int nStudentID);
 ~student();
};
