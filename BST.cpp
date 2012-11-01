#include "BST.h"
#include <iostream>

template <typename T>
BST<T>::BST() {
  root = 0;
  n = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
Node<T>** BST<T>::find(T v) {
//  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;
  while (*curr !=0){
    if (v < (*curr)->getValue()) {
     curr = &((*curr)->getLeftChild());
     }
    else if (v > (*curr)->getValue()){
      curr = &((*curr)->getRightChild());
     }
    else 
       break;
   }
  tempv = (*curr)->getValue();
 //  std::cout << tempv << std::endl;
  return curr;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = find(v);
  
 if ((*curr)->getLeftChild() == 0){
    temp = (*curr);
    curr = &((*curr)->getRightChild());
    delete temp;
    }
   
 else if((*curr)->getRightChild() == 0){
   temp = (*curr);
   curr =&((*curr)->getLeftChild());
   delete temp; 
  }
 else {
  Node<T> **temps = &(*curr)->getLeftChild();
  while ((*temps)->getRightChild() != 0) {
   temps = &(*temps)->getRightChild();
   }
  curr = &((*temps));
  delete temps;
  }
 }


template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::printg() {
 graphicPrint(root);
 std::cout << " " << std::endl;
 }

template <typename T>
void BST<T>::graphicPrint(Node<T>* root) {
 if (root != 0) {
   
   graphicPrint (root->getLeftChild());
   std::cout << root->getValue() << std::endl;
   n++;
   for(int i = 0; i < n; ++i){
     std::cout << " ";
    }
   graphicPrint (root->getRightChild());
   n--;
  }
// std::cout << " " << std::endl;
 }


template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
