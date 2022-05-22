/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*CPSC350-01
*Assignment 6 - Database: File 5 of 7
*@version 1.0
*Faculty Class: Each faculty has a name, ID, level, department, and list of advisee IDs
*/


#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include "Student.h"
#include "DoublyLinkedList.h"
using namespace std;

class Faculty{
public:

  Faculty();
  Faculty(int id, string name, string level, string department);
  Faculty(int id, string name, string level, string department, DoublyLinkedList<int>* students);
  ~Faculty();

  void addAdvisee(int id);
  void removeStudent(int student);
  void printInfo();
  bool hasStudents();
  string toString();


  void setName(string name);
  string getName();
  void setID(int id);
  int getID();
  void setLevel(string level);
  string getLevel();
  void setDepartment(string department);
  string getDepartment();
  //DoublyLinkedList<int> getStudents();


  bool operator<(Faculty f);
  bool operator>(Faculty f);
  bool operator==(Faculty f);
  bool operator!=(Faculty f);

  int m_id;
  string m_name;
  string m_level;
  string m_department;
  DoublyLinkedList<int>* m_students;

  friend ostream& operator<<(ostream& os, Faculty f);
};


Faculty::Faculty() {
  m_id = 0;
  m_name = "";
  m_department = "";
  m_level = "";
  m_students = new DoublyLinkedList<int>();
}

Faculty::Faculty(int id, string name, string level, string department) {
  m_id = id;
  m_name = name;
  m_department = department;
  m_level = level;
  m_students = new DoublyLinkedList<int>();
}


Faculty::Faculty(int id, string name, string level, string department, DoublyLinkedList<int>* students) {
  m_id = id;
  m_name = name;
  m_department = department;
  m_level = level;
  m_students = students;
}


Faculty::~Faculty() {}


void Faculty::setName(string name){
    m_name = name;
}

string Faculty::getName(){
    return m_name;
}

void Faculty::setID(int id){
    m_id = id;
}

int Faculty::getID(){
    return m_id;
}

string Faculty::getLevel(){
    return m_level;
}

void Faculty::setLevel(string level){
    m_level = level;
}


string Faculty::getDepartment(){
    return m_department;
}

void Faculty::setDepartment(string department){
    m_department = department;
}


void Faculty::addAdvisee(int id) {
    m_students->insertBack(id);
    cout << "Advisee " << id << " was added. " << endl;
}

void Faculty::removeStudent(int student) {
  m_students->remove(student);
}

void Faculty::printInfo() {
  cout << "____________________________________________" << endl;
  cout << "ID: " << m_id << endl;
  cout << "NAME: " << m_name << endl;
  cout << "LEVEL: " << m_level << endl;
  cout << "DEPARTMENT: " << m_department << endl;
  cout << "ADVISEES: ";

  int size = m_students->getSize();

  int temp;
  if(m_students->getSize() == 1){
      temp = m_students->peekAt(0);
      cout << temp << endl;
  } else if(m_students->getSize() > 1){
      for (int i = 0; i < size; ++i) {
        temp = m_students->peekAt(i);
        cout << temp << ", ";
      }
     cout << endl;
  } else{
      cout << "No advisees yet. " << endl;
  }

  cout << "____________________________________________" << endl;
}

bool Faculty::hasStudents(){
  return (!m_students->isEmpty());
}

bool Faculty::operator<(Faculty f){
  return (this->m_id < f.m_id);
}

bool Faculty::operator>(Faculty f){
  return (this->m_id > f.m_id);
}

bool Faculty::operator==(Faculty f){
  return (this->m_id == f.m_id);
}

bool Faculty::operator!=(Faculty f){
  return (this->m_id != f.m_id);
}

string Faculty::toString(){
  string facultyString = "";
  facultyString += to_string(m_id) + ", " + m_name + ", " + m_level + ", " + m_department + ", ";
  int listSize = m_students->getSize();
  for (int i = 0; i < listSize; ++i){
    facultyString += to_string(m_students->peekAt(i));
    facultyString += " ";
  }
  return facultyString;
}

ostream& operator<<(ostream& os, Faculty f){
  os << "ID: " << f.m_id << endl;
  os << "Name: " << f.m_name << endl;
  os << "Level: " << f.m_level << endl;
  os << "Department: " << f.m_department << endl;
  os << "Advisees: ";
  if (f.m_students->isEmpty()) {
    os << "none" << endl;
  }
  else {
    os << f.m_students->toString() << endl;
  }

  return os;
}



/*


#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include "Person.h"
#include "DoublyLinkedList.h"
using namespace std;

class Faculty : public Person
{
    protected:
        string level;
        string department;
        // should this list be a pointer??
        DoublyLinkedList<int> *advisees;

    public:
        Faculty();
        Faculty(string g, string d);
        virtual ~Faculty();
        void printInfo();
        //void printAdvisees();

        string getLevel();
        void setLevel(string l);
        string getDepartment();
        void setDepartment(string d);


        bool operator<(Faculty f);
        bool operator>(Faculty f);
        bool operator==(Faculty f);
        bool operator!=(Faculty f);



        friend bool operator < (const Faculty &lhs, const Faculty &rhs);
        friend bool operator > (const Faculty &lhs, const Faculty &rhs);
        friend bool operator == (const Faculty &lhs, const Faculty &rhs);
        friend bool operator != (const Faculty &lhs, const Faculty &rhs);

};


Faculty::Faculty(){}

Faculty::Faculty(string l, string d){
    level = l;
    department = d;
    advisees = new DoublyLinkedList<int>();
}

Faculty::~Faculty(){}

void Faculty::printInfo(){
    cout << "ID: " << id << endl;
    cout << "NAME: " << name << endl;
    cout << "LEVEL: " << level << endl;
    cout << "DEPARTMENT: " << department << endl;
    //printAdvisees();
}


void Faculty::printAdvisees(){
    ListNode<int> *curr = advisees->front;
    while(curr != NULL){
        cout << "ADVISEE: " << curr->data;
        curr = curr->next;
    }
}

string Faculty::getLevel(){
    return level;
}

void Faculty::setLevel(string l){
    level = l;
}


string Faculty::getDepartment(){
    return department;
}

void Faculty::setDepartment(string d){
    department = d;
}


bool Faculty::operator<(Faculty f){
  return (this->id < f.id);
}

bool Faculty::operator>(Faculty f){
  return (this->id > f.id);
}

bool Faculty::operator==(Faculty f){
  return (this->id == f.id);
}

bool Faculty::operator!=(Faculty f){
  return (this->id != f.id);
}






bool operator < (const Faculty &lhs, const Faculty &rhs){
    return lhs.id < rhs.id;
}


bool operator > (const Faculty &lhs, const Faculty &rhs){
    return lhs.id > rhs.id;
}


bool operator == (const Faculty &lhs, const Faculty &rhs){
    return lhs.id == rhs.id;
}


bool operator != (const Faculty &lhs, const Faculty &rhs){
    return lhs.id != rhs.id;
}
*/

#endif
