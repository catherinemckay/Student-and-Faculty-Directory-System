/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*CPSC350-01
*Assignment 6 - Database: File 2 of 7
*@version 1.0
*Node Template Class
*/
#ifndef NODE_H


#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
class Node{
  public:
    Node();
    Node(int key, T data);
    // Node(int k, object value)
    ~Node();
    int key;
    T data;
    Node* left;
    Node* right;

};


template <typename T>
Node<T>::Node(){
  left = NULL;
  right = NULL;
}

template <typename T>
Node<T>::Node(int key, T data){
  left = NULL;
  right = NULL;
  this->key = key;
  this->data = data;
}

template <typename T>
Node<T>::~Node(){
  left = NULL;
  right = NULL;
}


#endif
