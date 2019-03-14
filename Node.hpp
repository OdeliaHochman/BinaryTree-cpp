

#include <iostream>
using namespace std;

class Node {
  private:    // Not required. All is private by default.
    int key;
    Node* left;
    Node* right;

  public:
    // methods defined inline:
    int getKey() { return key;  }

    // // Constructors:
    Node (int key) ;
void setLeft(int key);
void setRight(int key);

};
