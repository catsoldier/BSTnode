/*
 * File:   bst_node.h
 * Author: rreaves
 *
 * Created on May 6, 2014, 3:06 PM
 */

#include <iostream>
#include <string>
#include <sstream>
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

class BSTNode {
 public:
  BSTNode();
  BSTNode(int contents);
  ~BSTNode();
  void SetContents(int contents);

  int GetContents() const;
  int& GetContents();

  void SetLeftChild(BSTNode* left);
  void SetRightChild(BSTNode* right);

  BSTNode* GetLeftChild() const;
  BSTNode*& GetLeftChild();

  BSTNode* GetRightChild() const;
  BSTNode*& GetRightChild();

 private:
  BSTNode* left_;
  BSTNode* right_;
  int contents_;
};
