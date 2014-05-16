/*
 * File:   bst_node.h
 * Author: rreaves
 *
 * Created on May 6, 2014, 3:06 PM
 */

#include "bst_node.h"

BSTNode::BSTNode() {
  left_ = NULL;
  right_ = NULL;
  contents_ = 0;
}

BSTNode::BSTNode(int contents) {
  left_ = NULL;
  right_ = NULL;
  contents_ = contents;
}

BSTNode::~BSTNode() {
  left_ = NULL;
  right_ = NULL;
}

void BSTNode::SetContents(int contents) {
  contents_ = contents;
}

int BSTNode::GetContents() const {
  return contents_;
}

int& BSTNode::GetContents() {
  return contents_;
}

void BSTNode::SetLeftChild(BSTNode* left) {
  left_ = left;
}

void BSTNode::SetRightChild(BSTNode* right) {
  right_ = right;
}

BSTNode* BSTNode::GetLeftChild() const {
  return left_;
}

BSTNode*& BSTNode::GetLeftChild() {
  return left_;
}

BSTNode* BSTNode::GetRightChild() const {
  return right_;
}

BSTNode*& BSTNode::GetRightChild() {
  return right_;
}
