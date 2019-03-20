
/**
 *  
 * We use code from this site : https://www.geeksforgeeks.org/binary-search-tree-data-structure/
 * @author Carmel , Odelia and Efrat
 * @since 2019-03
 */

#include "Tree.hpp"
#include <stdexcept>

ariel::Tree::Tree()
{

    _root = nullptr;
}

ariel::Tree::~Tree()
  {

    destroyTree(_root);
  }

void ariel::Tree::destroyTree(Node* leaf)
{
  if(leaf!=NULL)
  {
    destroyTree(leaf->getLeft());
    destroyTree(leaf->getRight());
    delete leaf;
  }
}


void ariel::Tree::insert(int key)
{

    if (search(_root, key) != NULL)
    {
        throw std::invalid_argument("already in the tree");
    }
    Node *newnode = new Node(key);

    // Pointer to start traversing from root and
    // traverses downward path to search
    // where the new node to be inserted
    Node *x = _root;

    // Pointer y maintains the trailing
    // pointer of x
    Node *y = NULL;

    while (x != NULL)
    {
        y = x;
        if (key < x->getKey())
            x = x->getLeft();
        else
            x = x->getRight();
    }

    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if (y == NULL)
        _root = newnode;

    // If the new key is less then the leaf node key
    // Assign the new node to be its left child
    else if (key < y->getKey())
        y->setLeft(newnode);

    // else assign the new node its right child
    else
        y->setRight(newnode);

    // Returns the pointer where the
    // new node is inserted
    newnode->setParent(y);
}

void ariel::Tree::remove(int key)
{

    Node *removeNode = search(_root, key);

    if (removeNode == NULL)
    {
        throw std::invalid_argument("not in the tree");
    }

    Node *temp = deleteNode(_root, key);

    if (removeNode == _root)
    {
        _root = temp;
    }
    if (temp == NULL)
    {
        _root = NULL;
    }
}
int ariel::Tree::size()

{

    return size(_root);
}

bool ariel::Tree::contains(int key)
{
    Node *temp = _root;
    while (temp != NULL)
    {
        // pass right subtree as new tree
        if (key > temp->getKey())
            temp = temp->getRight();

        // pass left subtree as new tree
        else if (key < temp->getKey())
            temp = temp->getLeft();
        else
            return true;
    }
    return false;
}

int ariel::Tree::root()

{
    if (_root == NULL)
        throw std::invalid_argument("the root is not exist");

    return _root->getKey();
}

int ariel::Tree::parent(int key)

{

    Node *temp = search(_root, key);
    if (temp == NULL || temp->getParent() == NULL)
        throw std::invalid_argument("the parent is not exist");

    return temp->getParent()->getKey();
}

int ariel::Tree::left(int key)

{
    Node *temp = search(_root, key);
    if (temp == NULL || temp->getLeft() == NULL)
        throw std::invalid_argument("the left child is not exist");

    return temp->getLeft()->getKey();
}

int ariel::Tree::right(int key)

{

    Node *temp = search(_root, key);
    if (temp == NULL || temp->getRight() == NULL)
        throw std::invalid_argument("the right child is not exist");

    return temp->getRight()->getKey();
}

void ariel::Tree::print()

{

    print2DUtil(_root, 0);
}

/**  Private methods */

int ariel::Tree::size(Node *node)
{
    if (node == NULL)
        return 0;
    else
        return (size(node->getLeft()) + 1 + size(node->getRight()));
}
Node *ariel::Tree::deleteNode(Node *root, int key)
{

    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->getKey())
        root->setLeft(deleteNode(root->getLeft(), key));

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->getKey())
        root->setRight(deleteNode(root->getRight(), key));

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->getLeft() == NULL)
        {
            Node *temp = root->getRight();
            if (temp != NULL)
                temp->setParent(root->getParent());
            delete root;
            return temp;
        }
        else if (root->getRight() == NULL)
        {
            Node *temp = root->getLeft();
            if (temp != NULL)
                temp->setParent(root->getParent());
            delete root;
            return temp;
        }
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node *temp = minValueNode(root->getRight());

        // Copy the inorder successor's content to this node
        root->setKey(temp->getKey());

        // Delete the inorder successor
        root->setRight(deleteNode(root->getRight(), temp->getKey()));
    }
    return root;
}

Node *ariel::Tree::minValueNode(Node *node)
{
    Node *current = node;
    /* loop down to find the leftmost leaf */
    while (current->getLeft() != NULL)
        current = current->getLeft();

    return current;
}

void ariel::Tree::print2DUtil(Node *root, int space)

{

    // Base case
    if (root == NULL)
        return;
    // Increase distance between levels
    space += COUNT;
    // Process right child first
    print2DUtil(root->getRight(), space);
    // Print current node after space
    // count

    cout << endl;

    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->getKey() << "\n";
    // Process left child
    print2DUtil(root->getLeft(), space);
}

Node *ariel::Tree::search(Node *root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL)
        return root;

    if (root->getKey() == key)
        return root;

    // Key is greater than root's key
    if (root->getKey() < key)
        return search(root->getRight(), key);

    // Key is smaller than root's key
    return search(root->getLeft(), key);
}
