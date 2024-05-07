#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <class Type> struct binaryTreeNode {
  Type data;
  binaryTreeNode<Type> *leftLink;
  binaryTreeNode<Type> *rightLink;
};

template <class Type> class binaryTree {
private:
  binaryTreeNode<Type> *root;
  void inorder(binaryTreeNode<Type> *node) const;

public:
  binaryTree();
  bool isEmpty();
  void insert(const Type &insert);
  void inorderTraverse() const;
};

#endif

#include <iostream>

using namespace std;

template <class Type> binaryTree<Type>::binaryTree() { 
  root = nullptr; 
}

template <class Type> bool binaryTree<Type>::isEmpty() { 
  return root; }

template <class Type> void binaryTree<Type>::insert(const Type &insert) {
  binaryTreeNode<Type> *current;
  binaryTreeNode<Type> *trail;
  binaryTreeNode<Type> *newNode;
  newNode = new binaryTreeNode<Type>;
  newNode->data = insert;
  newNode->leftLink = NULL;
  newNode->rightLink = NULL;
  if (root == NULL) {
    root = newNode;
  } else {
    current = root;
    trail = NULL;
    while (current != NULL) {
      trail = current;
      if (current->data > insert) {
        current = current->leftLink;
      } else if (current->data < insert) {
        current = current->rightLink;
      } else {
        cerr << "Duplicate value cannot be inserted to tree" << endl;
        return;
      }
    }
    if (trail->data > insert) {
      trail->leftLink = newNode;
    } else {
      trail->rightLink = newNode;
    }
  }
}

template <class Type> void binaryTree<Type>::inorderTraverse() const {
  inorder(root);
}

template <class Type>
void binaryTree<Type>::inorder(binaryTreeNode<Type> *node) const {
  if (node != NULL) {
    inorder(node->leftLink);
    cout << node->data << " ";
    inorder(node->rightLink);
  }
}