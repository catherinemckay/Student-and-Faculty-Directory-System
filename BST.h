/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*CPSC350-01
*Assignment 6 - Database: File 1 of 7
*@version 1.0
*BST Template Class
*/
#ifndef BST_H
#define BST_H

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class BST{
  public:
    BST();
    ~BST();

    void insert(int key, T data);
    bool contains(int key); // aka search
    T get(int key);
    bool deleteNode(int key);
    bool isEmpty();

    T getMin();
    T getMax();

    Node<T>* getSuccessor(Node<T>* d); // we're gonna use this later for delete

    void recPrint(Node<T>* node); // recursive print
    Node<T>* getRoot();

    Node<T>* root;
    void destroyRecursive(Node<T>* node);

};

template <typename T>
Node<T>* BST<T>::getRoot(){
  return root;
}

template <typename T>
BST<T>::BST(){
  root = NULL;
}

template <typename T>
BST<T>::~BST(){
  destroyRecursive(root);
}

template <typename T>
void BST<T>::destroyRecursive(Node<T>* node){
  if (node){
    destroyRecursive(node->left);
    destroyRecursive(node->right);
    delete node;
  }
}

template <typename T>
T BST<T>::get(int key){

  Node<T>* current = root;

  while (current->key != key){
    if (key < current->key){
      current = current->left;
    }
    else{
      current = current->right;
    }

    if (current == NULL){
      throw runtime_error("item not found");
    }
  }

  return current->data;
}

template <typename T>
void BST<T>::insert(int key, T data){
  Node<T>* node = new Node<T>(key, data);


  if (isEmpty()){
    root = node;
  }
  else{
    Node<T>* current = root;
    Node<T>* parent = NULL;

    while (true){
      parent = current;

      if (key < current->key){
        current = current->left;

        if (current == NULL){
          parent->left = node;
          break;
        }
      }
      else{
        current = current->right;

        if (current == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <typename T>
bool BST<T>::contains(int key){
  if (isEmpty()){
    return false;
  }
  else{
    Node<T>* current = root;

    while (current->key != key){
      if (key < current->key){
        current = current->left;
      }
      else{
        current = current->right;
      }

      if (current == NULL){
        return false;
      }
    }

    return true;
  }
}

template <typename T>
bool BST<T>::deleteNode(int key){
  if (isEmpty()){
    return false;
  }

  Node<T>* parent = NULL;
  Node<T>* current = root;
  bool isLeftNode = true;

  while (current->key != key){
    parent = current;

    if (key < current->key){
      isLeftNode = true;
      current = current->left;
    }
    else{
      isLeftNode = false;
      current = current->right;
    }

    if (current == NULL){
      return false;
    }
  }

  // node is leaf
  if (current->left == NULL && current->right == NULL){
    if (current == root){
      root = NULL;
    }
    else if (isLeftNode){
      parent->left = NULL;
    }
    else{
      parent->right = NULL;
    }
  }
  // node has one child on the left
  else if (current->right == NULL){
    if (current == root){
      root = current->left;
    }
    else if (isLeftNode){
      parent->left = current->left;
    }
    else{
      parent->right = current->left;
    }
  }

  // node has one child on the right
  else if (current->left == NULL){
    if (current == root){
      root = current->right;
    }
    else if (isLeftNode){
      parent->left = current->right;
    }
    else{
      parent->right = current->right;
    }
  }

  // node has two children
  else {
    Node<T>* successor = getSuccessor(current);

    if (current == root){
      root = successor;
    }
    else if (isLeftNode){
      parent->left = successor;
    }
    else{
      parent->right = successor;
    }

    successor->left = current->left;
  }

  return true;
}

template <typename T>
bool BST<T>::isEmpty(){
  return (root == NULL);
}

template <typename T>
T BST<T>::getMin(){
  if (root == NULL){
    return NULL;
  }

  Node<T>* current = root;
  while (current->left != NULL){
    current = current->left;
  }

  return current->key;
}

template <typename T>
T BST<T>::getMax(){
  if (root == NULL){
    return NULL;
  }

  Node<T>* current = root;
  while (current->right != NULL){
    current = current->right;
  }

  return current->key;
}

template <typename T>
Node<T>* BST<T>::getSuccessor(Node<T>* d){
  Node<T>* sp = d;
  Node<T>* successor = d;
  Node<T>* current = d->right;

  while (current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }

  if (successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;

  }
  return successor;
}

template <typename T>
void BST<T>::recPrint(Node<T>* node){
  if (node == NULL){
    return;
  }

  recPrint(node->left);
  cout << node->data << endl;
  recPrint(node->right);
}



#endif



/*
#ifndef BST_H
#define BST_H

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class BST{
  public:
    BST();
    ~BST();

    void insert(int key, T data);
    bool contains(int key); // aka search
    T get(int key);
    bool deleteNode(int key);
    bool isEmpty();

    T getMin();
    T getMax();

    Node<T>* getSuccessor(Node<T>* d); // we're gonna use this later for delete

    //void recPrint(Node<T>* node); // recursive print
    Node<T>* getRoot();

    Node<T>* root;
    void destroyRecursive(Node<T>* node);

};

template <typename T>
Node<T>* BST<T>::getRoot(){
  return root;
}

template <typename T>
BST<T>::BST(){
  root = NULL;
}

template <typename T>
BST<T>::~BST(){
  destroyRecursive(root);
}

template <typename T>
void BST<T>::destroyRecursive(Node<T>* node){
  if (node){
    destroyRecursive(node->left);
    destroyRecursive(node->right);
    delete node;
  }
}

template <typename T>
T BST<T>::get(int key){

  Node<T>* current = root;

  while (current->key != key){
    if (key < current->key){
      current = current->left;
    }
    else{
      current = current->right;
    }

    if (current == NULL){
      throw runtime_error("item not found");
    }
  }

  return current->data;
}

template <typename T>
void BST<T>::insert(int key, T data){
  Node<T>* node = new Node<T>(key, data);

  if (isEmpty()){
    root = node;
  }
  else{
    Node<T>* current = root;
    Node<T>* parent = NULL;

    while (true){
      parent = current;
      cout << current->key << endl;



      if (key < current->key){
        cout << "bye" << endl;
        current = current->left;
        if (current == NULL){
          parent->left = node;
          break;
        }
      }
      else{
        current = current->right;

        if (current == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <typename T>
bool BST<T>::contains(int key){
  if (isEmpty()){
    return false;
  }
  else{
    Node<T>* current = root;

    while (current->key != key){
      if (key < current->key){
        current = current->left;
      }
      else{
        current = current->right;
      }

      if (current == NULL){
        return false;
      }
    }

    return true;
  }
}

template <typename T>
bool BST<T>::deleteNode(int key){
  if (isEmpty()){
    return false;
  }

  Node<T>* parent = NULL;
  Node<T>* current = root;
  bool isLeftNode = true;

  while (current->key != key){
    parent = current;

    if (key < current->key){
      isLeftNode = true;
      current = current->left;
    }
    else{
      isLeftNode = false;
      current = current->right;
    }

    if (current == NULL){
      return false;
    }
  }

  // node is leaf
  if (current->left == NULL && current->right == NULL){
    if (current == root){
      root = NULL;
    }
    else if (isLeftNode){
      parent->left = NULL;
    }
    else{
      parent->right = NULL;
    }
  }
  // node has one child on the left
  else if (current->right == NULL){
    if (current == root){
      root = current->left;
    }
    else if (isLeftNode){
      parent->left = current->left;
    }
    else{
      parent->right = current->left;
    }
  }

  // node has one child on the right
  else if (current->left == NULL){
    if (current == root){
      root = current->right;
    }
    else if (isLeftNode){
      parent->left = current->right;
    }
    else{
      parent->right = current->right;
    }
  }

  // node has two children
  else {
    Node<T>* successor = getSuccessor(current);

    if (current == root){
      root = successor;
    }
    else if (isLeftNode){
      parent->left = successor;
    }
    else{
      parent->right = successor;
    }

    successor->left = current->left;
  }

  return true;
}

template <typename T>
bool BST<T>::isEmpty(){
  return (root == NULL);
}

template <typename T>
T BST<T>::getMin(){
  if (root == NULL){
    return NULL;
  }

  Node<T>* current = root;
  while (current->left != NULL){
    current = current->left;
  }

  return current->key;
}

template <typename T>
T BST<T>::getMax(){
  if (root == NULL){
    return NULL;
  }

  Node<T>* current = root;
  while (current->right != NULL){
    current = current->right;
  }

  return current->key;
}

template <typename T>
Node<T>* BST<T>::getSuccessor(Node<T>* d){
  Node<T>* sp = d;
  Node<T>* successor = d;
  Node<T>* current = d->right;

  while (current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }

  if (successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;

  }
  return successor;
}


template <typename T>
void BST<T>::recPrint(Node<T>* node){
  if (node == NULL){
    return;
  }

  recPrint(node->left);
  cout << node->data << endl;
  recPrint(node->right);
}




#endif
*/
