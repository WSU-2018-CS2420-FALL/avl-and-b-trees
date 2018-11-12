#include <iostream>
#include "avl_tree.h"
#include <string>
using namespace std;

template <typename T> 
void showIndented(const Node<T>* node, int depth){
   std::cout << "  " <<  node->info << std::endl;
}

int main(){
  AVLTree<char> bt;

  bt.insert('A');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('B');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('C');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('D');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('G');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('E');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('F');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.clear();

  bt.insert('H');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('G');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('G');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('E');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('D');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('C');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('B');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.insert('A');
  bt.preorderTraversal(showIndented); cout << endl << endl;

  bt.remove('C');
  bt.preorderTraversal(showIndented); cout << endl << endl;
  bt.remove('G');
  bt.preorderTraversal(showIndented); cout << endl << endl;

  return 0;
}