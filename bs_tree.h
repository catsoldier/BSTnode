/*
 * File:   bs_tree.h
 * Author: rreaves
 *
 * Created on May 6, 2014, 3:06 PM
 */

#include <iostream>
#include <string>
#include <sstream>
#include "bst_node.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::stringstream;

class BSTree {
 public:
    BSTree();
    ~BSTree();
    bool Insert(int value);
    void Clear();
    unsigned int GetSize();
    string InOrder();
    bool Remove(int value);
    int FindMin();

 private:
    BSTNode* root_;
    unsigned int size_;

    bool Insert(int value, BSTNode* &root);
    void Clear(BSTNode* &root);
    string InOrder(BSTNode* root);

    bool Remove(int value, BSTNode* &root);
    int FindMin(BSTNode* root);
};

// #endif /* REAVES_BS_TREE_H_ */
