#include "bs_tree.h"

BSTree::BSTree() {
  root_ = NULL;
  size_ = 0;
}

BSTree::~BSTree() {
  Clear();
}

bool BSTree::Insert(int value) {
  return Insert(value, root_);
}

void BSTree::Clear() {
  Clear(root_);
}

unsigned int BSTree::GetSize() {
  return size_;
}

string BSTree::InOrder() {
  return InOrder(root_);
}

bool BSTree::Insert(int value, BSTNode* &root) {
  if (root == NULL) {
    root = new BSTNode(value);
    size_++;
    return true;
  } else if (value < root->GetContents()) {
    return Insert(value, root->GetLeftChild());
  } else if (value > root->GetContents()) {
    return Insert(value, root->GetRightChild());
  } else {
    return false;
  }
}

void BSTree::Clear(BSTNode* &root) {
  if (root != NULL) {
    Clear(root->GetLeftChild());
    Clear(root->GetRightChild());
    delete root;
    root = NULL;
    size_--;
  }
}

string BSTree::InOrder(BSTNode* root) {
  stringstream ss;

  if (root != NULL) {
    ss << InOrder(root->GetLeftChild());
    ss << root->GetContents() << " ";
    ss << InOrder(root->GetRightChild());
  }
  return ss.str();
}

bool BSTree::Remove(int value) {
  return Remove(value, root_);
}

int BSTree::FindMin() {
  return FindMin(root_);
}

bool BSTree::Remove(int value, BSTNode* &root) {
  bool found = false;

  if (root == NULL) {
    return false;
  } else if (root->GetContents() == value) {
    found = true;
  } else if (root->GetContents() < value) {
    return Remove(value, root->GetRightChild());
  } else if (root->GetContents() > value) {
    return Remove(value, root->GetLeftChild());
  }
  if (found == true) {
  // 1st case leaf with no children
    if (root->GetLeftChild() == NULL && root->GetRightChild() == NULL) {
      delete root;
      root = NULL;
      size_--;
      return true;

  // 2nd case tree with one child
    // 2.1 tree with only left child
    } else if (root->GetLeftChild() !=NULL && root->GetRightChild() == NULL) {
      BSTNode* temp = root;
      root = root->GetLeftChild();
      delete temp;
      size_--;
      return true;
    // 2.2 tree with only right child
    } else if (root->GetRightChild() !=NULL && root->GetLeftChild() == NULL) {
      BSTNode* temp = root;
      root = root->GetRightChild();
      delete temp;
      size_--;
      return true;
    // 3rd case tree with two children
    } else {
      root->SetContents(FindMin(root->GetRightChild()));
      Remove(FindMin(root->GetRightChild()), root->GetRightChild());
      // size_--;
      return true;
    }
  }
  return false;
}

int BSTree::FindMin(BSTNode* root) {
  if (root == NULL) {
    return 0;
  } else if (root->GetLeftChild() == NULL) {
    return root->GetContents();
  } else {
    return FindMin(root->GetLeftChild());
  }
}
