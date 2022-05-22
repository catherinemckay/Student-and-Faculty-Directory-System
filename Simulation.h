/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*CPSC350-01
*Assignment 6 - Database: File 4 of 7
*@version 1.0
*Simulation Class: runs the whole database and all options;
* creates a student BST and faculty BST to hold their information
*/


#ifndef SIMULATION_H
#define SIMULATION_H
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "DoublyLinkedList.h"
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Simulation{
    public:
        Simulation();
        ~Simulation();

        void startSimulation();
        void printMenu();

        // BST of all students
        BST<Student> masterStudent;

        // BST of all faculty
        BST<Faculty> masterFaculty;


        // Holds all student IDs in database
        vector<int> studentIDs;

        // Holds all faculty IDs in database
        vector<int> facultyIDs;

        // Helper fuction to sort ids in vectors when needed
        vector<int> sortIDs(vector<int> vec);

        bool studentExists(int id);
        bool facultyExists(int id);
        void assignNewAdvisor(int id);


        // option 1:
        void printAllStudents();

        // option 2:
        void printAllFaculty();

        // option 3:
        void displayStudent(int id);

        // option 4:
        void displayFaculty(int id);

        // option 5:
        void printStudentsAdvisor(int id);

        // option 6:
        void printFacultysAdvisees(int id);

        // option 7:
        void addNewStudent();

        // option 8:
        void deleteStudent(int id);

        // option 9:
        void addNewFaculty();

        // option 10:
        void deleteFaculty(int id);

        // option 11:
        void changeStudentAdvisor(int studentID, int advisorID);

        // option 12:
        void removeAdviseefromFaculty(int id);

        /*
        // option 13:
        void rollBack();
        // option 14:
        void printTablesToFiles();
        */

};

/* Default constructor:
initializes BST's for students and faculty
*/
Simulation::Simulation(){
    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;
    //BST<Student> *masterStudent = new BST<Student>();
    //BST<Faculty> *masterFaculty = new BST<Faculty>();
}

// Destructor
Simulation::~Simulation(){}


/* startSimulation():
 prints menu to user
 prompts for database option, executes option, recursivly starts new simulation after each option is finished
*/
void Simulation::startSimulation(){
    printMenu();
    int userChoice;
    cin >> userChoice;
    int id;
    if(userChoice == 1){
        printAllStudents();
        startSimulation();
    } else if(userChoice == 2){
        printAllFaculty();
        startSimulation();
    } else if(userChoice == 3){
        cout << "What is the id of the student you would like to display? " << endl;
        cin >> id;
        if(studentExists(id)){
            displayStudent(id);
        } else{
            cout << "There is no student in the database with that id. " << endl;
        }
        startSimulation();
    } else if(userChoice == 4){
        cout << "What is the id of the faculty member you would like to display? " << endl;
        cin >> id;
        if(facultyExists(id)){
            displayFaculty(id);;
        } else{
            cout << "There is no faculty member in the database with that id. " << endl;
        }
        startSimulation();
    } else if(userChoice == 5){
        cout << "What is students id? " << endl;
        cin >> id;
        if(studentExists(id)){
            printStudentsAdvisor(id);
        } else{
            cout << "There is no student in the database with that id. " << endl;
        }
        startSimulation();
    } else if(userChoice == 6){
        cout << "What is the faculty member's id? " << endl;
        cin >> id;
        if(facultyExists(id)){
            printFacultysAdvisees(id);
        } else{
            cout << "There is no faculty member in the database with that id. " << endl;
        }
        startSimulation();
    } else if(userChoice == 7){
        addNewStudent();
        cout << "The student was added to the database." << endl;
        startSimulation();
    } else if(userChoice == 8){
        cout << "What is the student's id? " << endl;
        cin >> id;
        if(studentExists(id)){
            deleteStudent(id);
            cout << "Student " << id << " was deleted from the database." << endl;
        } else{
            cout << "There is no student in the database with that id. " << endl;
        }
        startSimulation();
    } else if(userChoice == 9){
        addNewFaculty();
        cout << "The faculty member was added to the database. " << endl;
        startSimulation();
    } else if(userChoice == 10){
        cout << "What is the faculty member's id? " << endl;
        cin >> id;
        if(facultyExists(id)){
            deleteFaculty(id);
        } else{
            cout << "There is no faculty member in the database with that id. " << endl;
        }
        startSimulation();
    } else if(userChoice == 11){
        int advisorID;
        cout << "What is the students id? " << endl;
        cin >> id;
        cout << "What is their new advisor's ID? " << endl;
        cin >> advisorID;
        if(studentExists(id) && facultyExists(advisorID)){
            changeStudentAdvisor(id, advisorID);
        } else{
            cout << "Invalid id; not in database. " << endl;
        }
        startSimulation();
    } else if(userChoice == 12){
        cout << "What is the student's id? " << endl;
        cin >> id;
        if(studentExists(id)){
            removeAdviseefromFaculty(id);
        } else{
            cout << "There is no student in the database with that id. " << endl;
        }
        startSimulation();
    } else if(userChoice == 13){
        startSimulation();
        // rollBack();
    } else if(userChoice == 14){

        //printTablesToFiles();
        return;
    } else{
        cout << "Not a valid option. Pick again. " << endl;
        startSimulation();
    }

}

/* printMenu():
prints all options to user
*/
void Simulation::printMenu(){
    cout << "________________________________________________________________________________________" << endl;
    cout << "Pick one of the following options: " << endl;
    cout << "1. Print all students and their information. " << endl;
    cout << "2. Print all faculty and their information." << endl;
    cout << "3. Find and display student information given the students id. " << endl;
    cout << "4. Find and display faculty information given the faculty id. " << endl;
    cout << "5. Given a student's id, print the name and info of their faculty advisor." << endl;
    cout << "6. Given a faculty id, print ALL the names and info of their advisees. " << endl;
    cout << "7. Add a new student. " << endl;
    cout << "8. Delete a student given the id. " << endl;
    cout << "9. Add a new faculty member. " << endl;
    cout << "10. Delete a faculty member given the id. " << endl;
    cout << "11. Change a student's advisor given the student id and the new faculty id. " << endl;
    cout << "12. Remove an advisee from a faculty member given the id. " << endl;
    cout << "13. Rollback. " << endl;
    cout << "14. Exit. " << endl;
    cout << "FYI : To ensure students have an advisor at all times, user will be prompted when " << endl;
    cout << "necessary to appoint a new advisor. Students cannot be added to database if there are " << endl;
    cout << "no faculty members." << endl;
    cout << "________________________________________________________________________________________" << endl;
}

// option 1: prints all students information in database
void Simulation::printAllStudents(){
    if(studentIDs.size() == 0){
        cout << "No students in database. " << endl;
        return;
    }
    studentIDs = sortIDs(studentIDs);
    for(int i = 0; i < studentIDs.size(); ++i){
        masterStudent.get(studentIDs.at(i)).printInfo();
    }
}

// option 2: prints all faculty informtion in database
void Simulation::printAllFaculty(){
    if(facultyIDs.size() == 0){
        cout << "No faculty in database. " << endl;
        return;
    }
    facultyIDs = sortIDs(facultyIDs);
    for(int i = 0; i < facultyIDs.size(); ++i){
        masterFaculty.get(facultyIDs.at(i)).printInfo();
    }
}

// option 3: displays a students information with the specified id
void Simulation::displayStudent(int id){
    Student s = masterStudent.get(id);
    s.printInfo();
}

// option 4: displays a facultys information wit specified id
void Simulation::displayFaculty(int id){
    Faculty f = masterFaculty.get(id);
    f.printInfo();
}

// option 5: prints a students advisors info given students id
void Simulation::printStudentsAdvisor(int studentID){
    cout << masterStudent.get(studentID).getName() << "'s Advisor: " << endl;
    int advisorID = masterStudent.get(studentID).getAdvisor();
    Faculty advisor = masterFaculty.get(advisorID);
    advisor.printInfo();
}

// option 6: prints faculty members advisee info given faculty id
void Simulation::printFacultysAdvisees(int id){
    Faculty faculty = masterFaculty.get(id);


    if(faculty.hasStudents()){
        DoublyLinkedList<int>* list = masterFaculty.get(id).m_students;
        int size = list->getSize();
        cout << masterFaculty.get(id).getName() << "'s Advisees: " << endl;
        for(int i = 0; i < size; ++i){
            masterStudent.get(list->peekAt(i)).printInfo();
        }
    } else{
        cout << "This faculty member does not have any advisees in the database yet. " << endl;
        return;
    }
}


// option 7: adds new student to database; prompts user for all necessary information
void Simulation::addNewStudent(){
    Student student;
    string name;
    int id;
    string grade;
    string major;
    double gpa;
    int advisorID;
    string empty;

    cout << "What is the students name? " << endl;
    getline(cin, empty);
    getline(cin, name);
    student.setName(name);

    cout << "What is the students id number? " << endl;
    cin >> id;
    if(studentExists(id)){
        cout << "There is already a student in the database with that id. " << endl;
        return;
    } else{
        student.setID(id);
        studentIDs.push_back(id);
    }


    cout << "What is the students grade? " << endl;
    cin >> grade;
    student.setGrade(grade);


    cout << "What is the students major? " << endl;
    getline(cin, empty);
    getline(cin, major);
    student.setMajor(major);

    cout << "What is the students GPA? " << endl;
    cin >> gpa;
    student.setGPA(gpa);



    while(true){
        cout << "What is the students advisor ID? " << endl;
        cin >> advisorID;
        if(facultyExists(advisorID)){
            student.setAdvisor(advisorID);
            masterFaculty.get(advisorID).addAdvisee(id);
            masterStudent.insert(id, student);
            break;
        } else{
            cout << "That advisor does not exist in the database. Try again." << endl;
        }
    }



}

// option 8: deletes student from database from specified id
void Simulation::deleteStudent(int id){
    int advisorID = masterStudent.get(id).getAdvisor();


    // Remove from advisor:
    masterFaculty.get(advisorID).removeStudent(id);

    // Remove from list of student ids:
    for(int j = 0; j < studentIDs.size(); ++j){
        if(studentIDs[j] == id){
            studentIDs.erase(studentIDs.begin() + j);
            break;
        }
    }

    // Remove from student Tree:
    masterStudent.deleteNode(id);

}

// option 9: adds new faculty member to database; prompts user for all necessary info
void Simulation::addNewFaculty(){
    Faculty faculty;
    string name;
    int id;
    string level;
    string department;
    string empty;
    int adviseeID;

    cout << "What is the faculty members name? " << endl;
    getline(cin, empty);
    getline(cin, name);
    faculty.setName(name);

    cout << "What is the faculty members id number? " << endl;
    cin >> id;
    if(facultyExists(id)){
        cout << "There is already a faculty member in the database with that id." << endl;
        return;
    } else{
        faculty.setID(id);
        facultyIDs.push_back(id);
    }

    cout << "What is the faculty members level? " << endl;
    getline(cin, empty);
    getline(cin, level);
    faculty.setLevel(level);

    cout << "What is the faculty members department? " << endl;
    cin >> department;
    faculty.setDepartment(department);

    cout << "Does the faculty member have any existing advisees? yes/no"<< endl;
    string reply;
    cin >> reply;
    if(reply == "yes"){
        int numAdvisees;
        cout << "How many advisees do they have? " << endl;
        cin >> numAdvisees;
        for(int i = 0; i < numAdvisees; ++i){
            adviseeID = 0;
            cout << "Enter advisee ID: " << endl;
            cin >> adviseeID;
            if(studentExists(adviseeID)){
                faculty.addAdvisee(adviseeID);
            } else{
                cout << "No student with that ID exists in database. " << endl;
            }
        }
    }
    masterFaculty.insert(id, faculty);
}

// option 10: delets faculty member from database with given id
void Simulation::deleteFaculty(int id){
    if(masterFaculty.get(id).hasStudents()){
        cout << "The faculty member you are deleting has advisee(s) who now need to be appointed new advisor(s). " << endl;
        DoublyLinkedList<int>* list = masterFaculty.get(id).m_students;
        int size = list->getSize();
        cout << "SIZE OF m_student: " << size << endl;

        // Delete advisor from faculty
        for(int i = 0; i <= size; ++i){
            cout << "NEXT ADVISEE TO CHANGE: " << endl;
            cout << masterFaculty.get(id).m_students->peekAt(i) << endl;


            cout << "ENTER HERE " << endl;
            Student updatedStudent;
            cout << "WHAT" << endl;
            int studentID = list->peekAt(i);
            cout << "SHABUYA" << endl;
            updatedStudent.setID(studentID);
            updatedStudent.setName(masterStudent.get(studentID).getName());
            updatedStudent.setGrade(masterStudent.get(studentID).getGrade());
            updatedStudent.setMajor(masterStudent.get(studentID).getMajor());
            updatedStudent.setGPA(masterStudent.get(studentID).getGPA());
            cout << "AINT NO WAY " << endl;
            int newAdvisorID;
            while(true){
                cout << "Enter a new advisor's ID for student " << studentID << ": " << endl;
                cin >> newAdvisorID;
                if(facultyExists(newAdvisorID)){
                    updatedStudent.setAdvisor(newAdvisorID);
                    masterFaculty.get(newAdvisorID).addAdvisee(newAdvisorID);
                    break;
                } else{
                    cout << "That advisor does not exist in the database. Try again." << endl;
                }
            }

            deleteStudent(studentID);
            studentIDs.push_back(updatedStudent.getID());
            masterStudent.insert(studentID, updatedStudent);

            cout << "NEW ADVISOR: " << updatedStudent.getAdvisor() << endl;
        }
    }

    // Remove from list of faculty ids:
    for(int j = 0; j < facultyIDs.size(); ++j){
        if(facultyIDs[j] == id){
            facultyIDs.erase(facultyIDs.begin() + j);
            break;
        }
    }

    // Delete from faculty tree
    if(masterFaculty.deleteNode(id)){
        cout << "Faculty member " << id << " was deleted from the database." << endl;
    }
}

// option 11: changes a students advisor with given ids
void Simulation::changeStudentAdvisor(int studentID, int advisorID){
    Student updatedStudent;
    updatedStudent.setID(studentID);
    updatedStudent.setName(masterStudent.get(studentID).getName());
    updatedStudent.setGrade(masterStudent.get(studentID).getGrade());
    updatedStudent.setMajor(masterStudent.get(studentID).getMajor());
    updatedStudent.setGPA(masterStudent.get(studentID).getGPA());
    updatedStudent.setAdvisor(advisorID);

    int oldAdvisorID = masterStudent.get(studentID).getAdvisor();
    deleteStudent(111);
    studentIDs.push_back(updatedStudent.getID());
    masterStudent.insert(studentID, updatedStudent);
    masterFaculty.get(advisorID).addAdvisee(updatedStudent.getID());

    cout << "Student " << studentID << " advisor has been changed to faculty member " << advisorID << " sucessfully." << endl;
}

// option 12: remoes an advisee from a faculty member with given ids
void Simulation::removeAdviseefromFaculty(int id){
    int advisorID = masterStudent.get(id).getAdvisor();
    cout << "Student " << id << " is being removed from faculty member " << advisorID << ". " << endl;
    assignNewAdvisor(id);
}

// sortIDs(): sorts vector of IDs
vector<int> Simulation::sortIDs(vector<int> vec){
    sort(vec.begin(), vec.end());
    vector<int> temp;
    for(auto x : vec){
        temp.push_back(x);
    }
    return temp;
}

//studentExists(): helper function returns true if specified student exists
bool Simulation::studentExists(int id){
    for(int i = 0; i < studentIDs.size(); ++i){
        if(studentIDs[i] == id){
            return true;
        }
    }
    return false;
}

//facultyExists(): helper function returns true if specified faculty member exists
bool Simulation::facultyExists(int id){
    for(int i = 0; i < facultyIDs.size(); ++i){
        if(facultyIDs[i] == id){
            return true;
        }
    }
    return false;
}

// assignNewAdvisor(): assigns new advisor to student when necessary; prompts user for necessary info
void Simulation::assignNewAdvisor(int id){
    int advisorID;
    while(true){
        cout << "Enter a new advisor's ID for student " << id << ": " << endl;
        cin >> advisorID;
        if(facultyExists(advisorID)){
            changeStudentAdvisor(id, advisorID);
            break;
        } else{
            cout << "That advisor does not exist in the database. Try again." << endl;
        }
    }
}



#endif
