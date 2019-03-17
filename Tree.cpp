#include "Tree.hpp"



ariel::Tree::Tree(){

    this->_root = nullptr;

}



void ariel::Tree::insert(int key)
{
    Node* newnode = new Node(key); 
  
    // Pointer to start traversing from root and 
    // traverses downward path to search 
    // where the new node to be inserted 
    Node* x = _root; 
  
    // Pointer y maintains the trailing 
    // pointer of x 
    Node* y = NULL; 
  
    while (x != NULL) { 
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



}

    int ariel::Tree::size()

    {

return 0;
}  
   

     bool ariel::Tree::contains(int key)
{
    Node* temp=_root;
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

       return _root->getKey();

    }

    int ariel::Tree::parent(int key)

    {

        Node* temp= search(_root,key);
        return temp->getParent()->getKey();

    }

    int ariel::Tree::left(int key)

    {
        Node* temp= search(_root,key);
        return temp->getLeft()->getKey();


    }

    int ariel::Tree::right(int key)

    {

Node* temp= search(_root,key);
        return temp->getRight()->getKey();

    }

    void ariel::Tree::print()

    {

	print2DUtil(_root, 0); 

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

	cout<<endl; 

	for (int i = COUNT; i < space; i++) 
		cout<<" "; 
	cout<<root->getKey()<<"\n"; 
	// Process left child 
	print2DUtil(root->getLeft(), space); 

} 

Node* ariel::Tree::search(Node* root, int key) {
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->getKey() == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->getKey() < key) 
       return search(root->getRight(), key); 
  
    // Key is smaller than root's key 
    return search(root->getLeft(), key); 
} 





