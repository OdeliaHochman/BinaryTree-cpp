
// #include <iostream>
#include "Node.hpp"
#define COUNT 10 

namespace ariel {
class Tree
{
    private:
    Node* _root;
    void print2DUtil(Node *root, int space);
    Node* search(Node* root, int key);

    public:
    
    Tree();
    ~Tree(){

    };
    void insert(int key);
    void remove(int key);
    int size();
    bool contains(int key);
    int root();
    int parent(int key);
    int left(int key);
    int right(int key);
    void print();

};

}

