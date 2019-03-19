/**
 *  
 *
 * @author Carmel , Odelia and Efrat
 * @since 2019-03
 */

#include "Node.hpp"
#define COUNT 10

namespace ariel
{
class Tree
{
private:
  Node *_root;
  void print2DUtil(Node *root, int space);
  Node *search(Node *root, int key);
  Node *deleteNode(Node *root, int k);
  Node *minValueNode(Node *node);
  int size(Node *node);

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