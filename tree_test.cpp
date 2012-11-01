#include "BST.h"

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(5);
  bst->insert(6);
  bst->insert(3);
  bst->insert(2);
  bst->insert(7);
  bst->insert(12);
  bst->find(7);

  bst->printg();
  bst->print();
//  bst->remove(2);
//  bst->remove(12);
// bst->remove(7);
 bst->remove(3);
  bst->print();

}
