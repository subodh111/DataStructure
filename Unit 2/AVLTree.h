#ifndef AVLTREE_H
#define AVLTREE_H


#include <iostream>
using namespace std;

class AVLTree
{
private:
	struct Node
	{
		int value;
		Node* left;
		Node* right;
	};
	Node * root;



	//clear - accepts the root pointer of a tree by reference.  Frees all memory used by the tree, leaving the tree in a valid state.
	void clear(Node *& r)
	{
		if (r != NULL)
		{
			clear(r->left);
			clear(r->right);
			delete r;

		}
		r = NULL;
	}

	int height(Node* r) {
		
		if (r == NULL)
		{
			return 0;
		}
		 int lh = height(r->left);
		 int rh = height(r->right);
			
			if (rh> lh)
				return rh + 1;
			else
				return lh + 1;
		
	}

	void rotateRight(Node*&r) {

		Node*p = r;
		r=r->left;
		
	
		p->left = r->right;
		r->right = p;
		}
	void rotateLeft(Node*& r) {
		Node *p = r;
		r = r->right;
		p->right = r->left;
		r->left = p;
		
	
	}
	void rotateRightLeft(Node*& r) {
		rotateRight(r->right);
		rotateLeft(r);
	}
	void rotateLeftRight(Node*&r) {
		rotateLeft(r->left);
		rotateRight(r);
	}
	int difference(Node* r)
	{
		
		return (height(r->right) - height(r->left));
		
	}
	void balance(Node*&r) {
		if (difference(r) == -2)
		{
			if (difference(r->left) == -1)
				rotateRight(r);
			else
				rotateLeftRight(r);
		}
		else if (difference(r) == 2)
		{
			if (difference(r->right) == 1) {
				rotateLeft(r);
			}

			else
				rotateRightLeft(r);
		}
	}


	//append - accepts the pointer, by reference, for a tree to add a value to and the value to be added.
	void append(Node*& r, int i) {
		
		if (r == NULL)
		{
			if (!isFull())
			{

				r = new Node{ i };
				
			}
		}
		else if (i < r->value)
		{
			append(r->left, i);
			
		}
			 		
		else 
			append(r->right, i);

			balance(r);
		
		
	}

	//remove - accepts the pointer, by reference, for a tree to remove a value from and the value to be removed.  Removes the node containing the matching value, if found.
	void remove(Node*& r, int i) {
		if (r == NULL)
			return;
		else if (i < r->value)
			remove(r->left, i);
		else if (r->value < i)
			remove(r->right, i);

		else//no children
			if (r->left == NULL && r->right == NULL)
			{
				delete r;
				r = NULL;
			}
			else if (r->left != NULL && r->right == NULL){
			Node* p;
			p = r;
			r = r->left;
		delete p;
			}
			else if (r->left == NULL && r->right != NULL)
			{
				Node*p;
				p = r;
				r = r->right;
				delete p;
			}
			else//two children
			{
				Node*p;
				p = r->right;
				while (p->left != NULL)
					p = p->left;

				p->left = r->left;
				p = r;
				r = r->right;
				delete p;

			}
		if(r!=NULL)
			balance(r);


	}
	//find - accepts the pointer for a tree to search for a value, and the value to search for.  returns true if value is found, false otherwise.
	bool find(Node*r, int i) {
		while (r != NULL)
		{
			if (r->value == i)
				return true;
			else if (i < r->value)
				r = r->left;
			else
				r = r->right;
		}
			return false;
		
	}
	//print - accepts the pointer for a tree, and displays it's contents.  Contents is displayed using inorder traversal.
	void print(Node *r)
	{
		if (r != NULL)
		{
			print(r->left);
			cout << r->value<<endl;
			print(r->right);
		}
	}

	int count(Node *r)
	{

		int c = 1;
		if (r->left != NULL) {
			c += count(r->left);
		}

		if (r->right != NULL) {
			c += count(r->right);
		} 
		return c;
		
	}

public:


	int count()
	{
		int co;
		co= count(root);
		return co;
		
	}
	
	//AVLTree - the constructor initializes root to null.
	AVLTree()
	{
		root = NULL;
	}

	//~AVLTree - the deconstructor frees up all memory used by the object.
	~AVLTree() {
		clear();
	}
	//append - accepts the value to add to the tree.  Calls private append, passing the appropriate arguments.
	void append(int i)
	{
		append(root, i);
	}
	//remove - accepts a value to be removed from the tree.  Calls private remove, passing the appropriate arguments.
	void remove(int i) {
		remove(root, i);
	}

	//find - accepts a value to search the tree for.  Calls private find, passing the appropriate arguments.  Returns true if value is found, false otherwise.
	bool find(int i) {
		bool o= find(root, i);
		return o;
	}
	//print - accepts no arguments and merely calls the private print and height, passing the appropriate arguments.
	void print() {
		print(root);
	}
	//isEmpty - returns true if the tree is empty, false otherwise.

	bool isEmpty()
	
	{
		if (root == NULL)
			return true;
		else
			return false;

	}
	//isFull - returns false if there are enough resources to create a new node, false otherwise.
	bool isFull() {
		Node *n = new Node;
		if (n == NULL)
			return true;

		delete n;

		return false;
	}
	//clear - calls the private clear, passing appropriate arguments.
	void AVLTree::clear()
	{
		clear(root);
	}
};
	
#endif