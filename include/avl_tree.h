#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include <vector>
#include <sstream>

template <typename T>
struct Node {
  T info;
  Node *llink;
  Node *rlink;
  Node(): llink(nullptr), rlink(nullptr) {}
  Node(T info) : info(info), llink(nullptr), rlink(nullptr) {}
};

template <typename T>
class AVLTree {
public:
  AVLTree() : root(nullptr) {}
  AVLTree(const AVLTree<T> &bt) { copy(root, bt.root); }

  int height(const Node<T> *node) const {
    // TODO
  }

  const Node<T>* maximum(Node<T>* node) const {
    // TODO
  }

  void insert(T e){ return insert(e, root); }
  void insert(T e, Node<T>* &node){
    if(node == nullptr){
      node = new Node<T>(e);
    }else if( e < node->info) {
      insert(e, node->llink);
    }else{
      insert(e, node->rlink);
    }

    balance(node);
  } 

  void balance( Node<T>* &node ) {
    // TODO
  }

  void remove(T e){ remove(root, e); }
  void remove(Node<T>* &node, T e){
    if(node){
      if(e < node->info){
        remove(node->llink, e);
      }else if(e > node->info){
        remove(node->rlink, e);
      }else if(node->llink && node->rlink) {// Two children
        node->info = maximum(node->llink)->info;
        remove(node->llink, node->info);
      }else{
        Node<T> *temp = node;
        node  = (node->llink ) ? node->llink : node->rlink;
        delete temp;
      }

      balance(node);
    }
  }




  AVLTree<T> &operator=(AVLTree<T> &bt){
    if (this != &bt) {
      destroy(root);
      copy(root, bt.root);
    }

    return *this;
  }

  bool empty() const { return root == nullptr; }
  int size() const { return size(root); }
  int size(const Node<T>* node) const {
    return node ? 1 + size(node->llink) + size(node->rlink) : 0;
  }
  void inorderTraversal(void (*showFunc)(const Node<T>*, int)) const { inorderTraversal(showFunc, root, 0); }
  void inorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const{
    if(node){
      inorderTraversal(showFunc, node->llink, depth + 1);
      showFunc(node, depth);
      inorderTraversal(showFunc, node->rlink, depth + 1);
    }
  }

  void preorderTraversal(void (*showFunc)(const Node<T>*, int)) const { preorderTraversal(showFunc, root, 0); }
  void preorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const {
    if (node){
      showFunc(node, depth);
      preorderTraversal(showFunc, node->llink, depth + 1);
      preorderTraversal(showFunc, node->rlink, depth + 1);
    }
  }

  void postorderTraversal(void (*showFunc)(const Node<T>*, int)) const { postorderTraversal(showFunc, root, 0); }
  void postorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const {
    if(node){
      postorderTraversal(showFunc, node->llink, depth + 1);
      postorderTraversal(showFunc, node->rlink, depth + 1);
      showFunc(node, depth);
    }
  }

  bool search(T e) const{
    auto current = root;
    while(current){
      if(current->info == e) return true;
      else if(e < current->info) current = current->llink;
      else current = current->rlink;
    }

    return false;
  }  

  
  void clear(){ destroy(root); };

  ~AVLTree(){ destroy(root); }
  
private:
  Node<T> *root;
  void destroy(Node<T>* &node) {
    if (node){
      destroy(node->llink);
      destroy(node->rlink);

      delete node;
      node = nullptr;
    }
  }
  void copy(Node<T> *&dest, const Node<T> *src) {
    if (src){
      dest = new Node<T>(src->info);
      copy(dest->llink, src->llink);
      copy(dest->rlink, src->rlink);
    } else {
      dest = nullptr;
    }
  }

  const Node<T>* maximum() const { return maximum(root); }
  
};

#endif