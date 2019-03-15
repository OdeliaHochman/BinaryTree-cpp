
// #include <iostream>
#include "Node.hpp"
// using namespace std;

namespace ariel {
class Tree
{
    private:
    Node* _root;
    
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
