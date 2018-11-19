#ifndef _B_TREE_H_
#define _B_TREE_H_

#include <vector>
#include <sstream>

template <typename T, int order>
struct BNode {
    int n;
    T keys[order - 1];
    BNode<T, order>* children[order];
};

template <typename T, int order>
class BTree {

private:
    BNode<T, order>* root;
};
#endif