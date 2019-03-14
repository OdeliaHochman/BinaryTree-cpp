
#include <iostream>
#include "Node.hpp"
using namespace std;

namespace ariel {
class Tree
{
    private:
    Node* root;
    
    public:
    
    void insert(int key);
    void remove(int key);
    int size();
    bool contains(int key);
    Node* root();
    Node* parent(int key);
    Node* left(int key);
    Node* right(int key);
    void print();

};
}
