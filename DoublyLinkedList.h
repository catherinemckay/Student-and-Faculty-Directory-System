/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*CPSC350-01
*Assignment 6 - Database: File 3 of 7
*@version 1.0
*Doubly Linked List Template Class
*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <exception>
using namespace std;

template <typename T>
class ListNode{
    public:
        ListNode();
        ListNode(T d);
        ~ListNode();
        ListNode<T> *next;
        ListNode<T> *prev;
        T data;
        string toString();

};

//implementation
template <typename T>
ListNode<T>::ListNode(){}

template <typename T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL; // 0 nullptr
    prev = NULL;
}

template <typename T>
ListNode<T>::~ListNode(){
    //research
}


template <typename T>
string ListNode<T>::toString(){
  bool integer = false;
  string retString = "";

  string s = to_string(data);

  if (isdigit(s[0])){
    integer = true;

    retString += s;
  }
  return retString;
}

///doublylinked list class
template <typename T>
class DoublyLinkedList{
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        void insertFront(T d);
        void insertBack(T d);
        T removeFront();
        T removeBack();
        T removeNode(T value);
        T remove(T key);
        T find(T value);
        bool isEmpty();
        unsigned int getSize();
        T peekAt(int index);
        string toString();
        void printList(bool isPrintLink);
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    //guess what??? build some character and research
    ListNode<T> *node = front;
    ListNode<T> *nodeToDelete = front;
    while (node != NULL){
        nodeToDelete = node->next;
        delete node;
        node = nodeToDelete;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    }
    else{
        //it's not empty
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}


template <typename T>
T DoublyLinkedList<T>::remove(T key){
    ListNode<T> *current = front;

    while(current->data != key){
        current = current->next;

        if(current == nullptr){
            return key;
        }
    }

    if(size == 1){
        front = nullptr;
        back = nullptr;
    } else if(current == front){
        front = current->next;
        cout << front << endl;
        front->prev = nullptr;
    } else if(current == back){
        back = current->prev;
        back->next = nullptr;
    } else if(current != front && current != back){
        current->next->prev = current->prev;
        current->prev->next = current->next;
    }

    current->next = nullptr;
    current->prev = nullptr;
    T temp = current->data;
    size--;
    delete current;

    return temp;

}


template <typename T>
T DoublyLinkedList<T>::peekAt(int index){
    if(index < 0 || index >= size){
        throw runtime_error("Invalid index");
    }

    ListNode<T>* curr = front;
    while(index > 0){
        curr = curr->next;
        --index;
    }
    return curr->data;
}


template <typename T>
void DoublyLinkedList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        front = node;
    }
    else{
        node->prev = back;
        back->next = node;
    }
    back = node;
    ++size;
}


template <typename T>
T DoublyLinkedList<T>::removeFront(){
    if(isEmpty()){
        throw runtime_error("list is empty!");
    }

    ListNode<T> *temp = front;

    if(front->next == NULL){
        back = NULL;
    }
    else{
        //more than one node in the list
        front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    T data = temp->data;
    --size;
    delete temp;
    return data;
}


template <typename T>
T DoublyLinkedList<T>::removeBack(){
    if(isEmpty()){
        throw runtime_error("list is empty");
    }

    ListNode<T> *temp = front;

    if(back->prev = NULL){
        //only node in the list
        front = NULL;
    }
    else{
        //more than one node in the list
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    T data = temp->data;
    --size;
    delete temp;
    return data;
}


template <typename T>
T DoublyLinkedList<T>::find(T value){
    int pos = -1;
    ListNode<T> *curr = front;

    while(curr != NULL){
        ++pos;
        if(curr->data == value)
            break;

        curr = curr->next;
    }
    //checks if curr is NULL which signifies value not in Linked List
    if(curr == NULL)
        pos = -1;

    return pos;
}

template <typename T>
T DoublyLinkedList<T>::removeNode(T value){
    if(isEmpty()){
        throw runtime_error("list is empty!");
    }

    //we could leverage the find method

    ListNode<T> *curr = front;
    while(curr->data != value){
        curr = curr->next;

        if(curr == NULL)
            return -1;
    }
    //but if we make it here, we found the value
    //we found it , let's proceed to remove it

    if(curr != front && curr != back){
        //it's in between front and back
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    if(curr == front){
        front = curr->next;
        front->prev = NULL;
    }

    if(curr == back){
        back = curr->prev;
        back->next = NULL;
    }

    curr->next = NULL;
    curr->prev = NULL;
    T data = curr->data;
    --size;
    delete curr;

    return data;
}

template <typename T>
string DoublyLinkedList<T>::toString(){
    string s = "";
    ListNode<T> *curr = front;

    while(curr != nullptr){
        string temp = curr->toString();
        s += temp;
        curr = curr->next;

        if(curr != nullptr){
            s += ", ";
        }
    }

    return s;
}



template <typename T>
unsigned int DoublyLinkedList<T>::getSize(){
    return size;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty(){
    return (size == 0);
}

#endif
