#ifndef __BST_H__
#define __BST_H__

#include "Node.h"
#include <string>

template <typename T>
class BST {
 private:
  Node<T>* root;
  void traversalPrint(Node<T>* root);
  void graphicPrint(Node<T>* root);
  T tempv;
  int n; 
 public:
  BST<T>();
  ~BST<T>();

  Node<T>** find(T v);
  void remove(T v);
  void insert(T v);
  void print();
  void printg();
};


#endif
