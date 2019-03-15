

#include <iostream>
using namespace std;

class Node {
  private:    // Not required. All is private by default.
    int key;
    Node* left;
    Node* right;

  public:
    // // Constructors:
    Node (int key) {
      this ->key= key;
      left=NULL;
      right=NULL;
    }
    
    int getKey() { return key; }
    Node* getLeft() { return left; }
    Node* getRight() {  return right; }
    bool hasLeft() { return (left!=NULL); }
    bool hasRight(){ return (right!=NULL); }
    void setLeft(int key) { this -> key = key; } 
    void setRight(int key) { this -> key = key; }

};
