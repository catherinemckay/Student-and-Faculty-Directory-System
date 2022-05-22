/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*CPSC350-01
*Assignment 6 - Database: File 4 of 7
*@version 1.0
*Student Class: Each student has a name, ID, major, grade, and advisor ID
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student {
public:
  Student();
  Student(int id, string name, string grade, string major, double gpa, int advisor = -1);
  ~Student();

  void printInfo();
  string toString();

  void setName(string name);
  string getName();
  void setID(int id);
  int getID();
  void setGrade(string g);
  string getGrade();
  void setMajor(string m);
  string getMajor();
  void setGPA(double num);
  double getGPA();
  int getAdvisor();
  void setAdvisor(int advisorID);

/*
  bool operator<(Student s);
  bool operator>(Student s);
  bool operator==(Student s);
  bool operator!=(Student s);
*/

  int m_id;
  string m_name;
  string m_grade;
  string m_major;
  double m_gpa;
  int m_advisor;

  friend ostream& operator<<(ostream& os, Student s);
};



#include "Student.h"

Student::Student() {
  m_id = 0;
  m_name = "";
  m_grade = "";
  m_major = "";
  m_gpa = 0;
  m_advisor = 0;
}

Student::Student(int id, string name, string grade, string major, double gpa, int advisor) {
  m_id = id;
  m_name = name;
  m_grade = grade;
  m_major = major;
  m_gpa = gpa;
  m_advisor = advisor;
}

Student::~Student() {}


void Student::setName(string name){
    m_name = name;
}

string Student::getName(){
    return m_name;
}

void Student::setID(int id){
    m_id = id;
}

int Student::getID(){
    return m_id;
}

string Student::getGrade(){
    return m_grade;
}

void Student::setGrade(string g){
    m_grade = g;
}

string Student::getMajor(){
    return m_major;
}

void Student::setMajor(string m){
    m_major = m;
}

double Student::getGPA(){
    return m_gpa;
}

void Student::setGPA(double gpa){
    m_gpa = gpa;
}

int Student::getAdvisor(){
    return m_advisor;
}

void Student::setAdvisor(int advisor){
    m_advisor = advisor;
}


void Student::printInfo() {
  cout << "____________________________________________" << endl;
  cout << "ID: " << m_id << endl;
  cout << "NAME: " << m_name << endl;
  cout << "GRADE: " << m_grade << endl;
  cout << "MAJOR: " << m_major << endl;
  cout << "GPA: " << m_gpa << endl;
  cout << "ADVISOR: " << m_advisor << endl;
  cout << "____________________________________________" << endl;
}

/*
bool Student::operator<(Student s){
  return (this->m_id < s.m_id);
}

bool Student::operator>(Student s){
  return (this->m_id > s.m_id);
}

bool Student::operator==(Student s){
  return (this->m_id == s.m_id);
}

bool Student::operator!=(Student s){
  return (this->m_id != s.m_id);
}
*/

string Student::toString(){
  string student;
  student += to_string(m_id) + ", " + m_name + ", " + m_grade + ", " + m_major + + ", ";
  student += to_string(m_gpa) ;
  student += ", " + to_string(m_advisor);
  return student;
}

ostream& operator<<(ostream& os, Student s){
  os << "ID: " << s.m_id << endl;
  os << "Name: " << s.m_name << endl;
  os << "Grade: " << s.m_grade << endl;
  os << "Major: " << s.m_major << endl;
  os << "GPA: " << s.m_gpa << endl;
  os << "Advisor: ";
  if (s.m_advisor != -1)
    os << s.m_advisor << endl;
  else
    os << "none" << endl;

  return os;
}




/*
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person
{
    protected:
        string grade;
        string major;
        double gpa;
        int advisor;

    public:
        Student();
        Student(string g, string m, double num, int advisorID);
        virtual ~Student();
        void printInfo();

        string getGrade();
        void setGrade(string g);
        string getMajor();
        void setMajor(string m);
        double getGPA();
        void setGPA(double num);
        int getAdvisor();
        void setAdvisor(int advisorID);

        bool operator<(Student s);
        bool operator>(Student s);
        bool operator==(Student s);
        bool operator!=(Student s);




        friend bool operator < (const Student &lhs, const Student &rhs);
        friend bool operator > (const Student &lhs, const Student &rhs);
        friend bool operator == (const Student &lhs, const Student &rhs);
        friend bool operator != (const Student &lhs, const Student &rhs);

};


Student::Student(){}

Student::Student(string g, string m, double num, int advisorID){
    grade = g;
    major = m;
    gpa = num;
    advisor = advisorID;
}

Student::~Student(){}

void Student::printInfo(){
    cout << "ID: " << id << endl;
    cout << "NAME: " << getName() << endl;
    cout << "GRADE: " << getGrade() << endl;
    cout << "MAJOR: " << getMajor() << endl;
    cout << "GPA: " << getGPA() << endl;
    cout << "ADVISOR ID: " << getAdvisor() << endl;
}

string Student::getGrade(){
    return grade;
}

void Student::setGrade(string g){
    grade = g;
}

string Student::getMajor(){
    return major;
}

void Student::setMajor(string m){
    major = m;
}

double Student::getGPA(){
    return gpa;
}

void Student::setGPA(double num){
    gpa = num;
}

int Student::getAdvisor(){
    return advisor;
}

void Student::setAdvisor(int advisorID){
    advisor = advisorID;
}


bool Student::operator<(Student s){
  return (this->id < s.id);
}

bool Student::operator>(Student s){
  return (this->id > s.id);
}

bool Student::operator==(Student s){
  return (this->id == s.id);
}

bool Student::operator!=(Student s){
  return (this->id != s.id);
}







bool operator < (const Student &lhs, const Student &rhs){
    return lhs.id < rhs.id;
}


bool operator > (const Student &lhs, const Student &rhs){
    return lhs.id > rhs.id;
}


bool operator == (const Student &lhs, const Student &rhs){
    return lhs.id == rhs.id;
}


bool operator != (const Student &lhs, const Student &rhs){
    return lhs.id != rhs.id;
}
*/

#endif
