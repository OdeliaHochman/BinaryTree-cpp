/**
 *  
 *
 * @author Carmel , Odelia and Efrat
 * @since 2019-03
 */

#include <iostream>
using namespace std;

class Node {
  private:    // Not required. All is private by default.
    int key;
    Node* left;
    Node* right;
    Node* parent;

  public:
    // // Constructors:
    Node();
    Node (int key) {
      this ->key= key;
      left=NULL;
      right=NULL;
      parent=NULL;
    }
    
    int getKey() { return key; }
    Node* getParent(){return parent;}
    Node* getLeft() {return left;}
    Node* getRight() {return right;}
    bool hasLeft() { return (left!=NULL);}
    bool hasRight(){ return (right!=NULL);}
    bool hasParent(){return (parent!=NULL);}
    void setKey(int key) { this -> key = key;} 
    void setParent(Node* parent) {this-> parent= parent;}
    void setRight(Node* right) { this -> right = right;}
    void setLeft(Node* left) { this -> left = left;}

};

