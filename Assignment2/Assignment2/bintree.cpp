//need comments


#include "bintree.h"
#include "nodedata.h"
#include <iostream>
using namespace std;


ostream& operator<<(ostream& out, const BinTree& object)
{
	object.inorderHelper(object.root);
	out << endl;
	return out;
}
void BinTree::inorderHelper(Node* node) const
{
	if (node != nullptr)
	{
		inorderHelper(node->left);
		cout << *node->data << " ";
		inorderHelper(node->right);
	}

}

BinTree::BinTree()
{
	root = nullptr;
}

BinTree::BinTree(const BinTree& b)
{
	this->root = nullptr;

	*this = b;

}

BinTree::~BinTree()
{
	makeEmpty();
}

bool BinTree::isEmpty() const
{
	if (root == nullptr)
	{
		return true;
	}
	return false;
}

void BinTree::makeEmpty()
{
	makeEmptyHelper(root);
}

void BinTree::makeEmptyHelper(Node*& node)
{
	//traverse through each branch till at end and delete
	if (node != NULL)
	{
		makeEmptyHelper(node->left);
		makeEmptyHelper(node->right);
		delete node->data;
		node->data = NULL;
		delete node;
		node = NULL;
	}
}


BinTree& BinTree::operator=(const BinTree& b)								
{																				
	//if tree is not same
	if (this != &b)
	{
		//clear it
		this->makeEmpty();
		//
		if (b.root != nullptr)
		{
			NodeData* temp = new NodeData(*b.root->data); //deep copy
			assignHelper(root, b.root);
		}
	}
	return *this;
}

bool BinTree::operator==(const BinTree& b) 
{
	return equalHelper(root, b.root);
}

bool BinTree::equalHelper(Node*& left, Node* right) const
{
	//if both empty
	if (left == nullptr && right == nullptr)
	{
		return true;
	}
	//if one empty
	else if (left == nullptr || right == nullptr)
	{
		return false;
	}
	else 
	{
		//if data is matching
		if (left->data == right->data)
		{
			//make sure both sides of tree are the same, if so return true
			if (equalHelper(left->left, right->left) 
				&& equalHelper(left->right, right->right))
			{
				return true;
			}
		}
	}
}

bool BinTree::operator!=(const BinTree& b) 
{
	return !(*this == b);
}

void BinTree::assignHelper(Node*& node, Node* copy)								
																				
{
	if (copy != nullptr)
	{
		
		node = new Node;
		NodeData* temp = new NodeData(*copy->data); //deep copy
		node->data = temp; 
		assignHelper(node->left, copy->left);
		assignHelper(node->right, copy->right);
	}
	else
	{
		node = nullptr;
	}
}

//bst (dupes deleted, smaller strings go left, bigger go right)
bool BinTree::insert(NodeData* data)
{
	//creates new node and sets default value
	Node* nextNode = new Node;
	nextNode->data = data;
 	nextNode->right = nextNode->left = nullptr;
	bool in = false;
	//no existing nodes, so makes first node
	if (root == NULL)
	{
		root = nextNode;
		return true;
	}
	//make the root the current node for comparison
	Node* current = root;

	while (!in)
	{
		//dupe check (dupes deleted)
		if (*nextNode->data == *current->data)
		{
			delete nextNode->data;
			nextNode->data = NULL;
			delete nextNode;
			nextNode = NULL;
			in = true;
		}
		//if next node less 
		else if (*nextNode->data < *current->data)
		{
			//if empty slot, insert 
			if (current->left == NULL)
			{
				current->left = nextNode;
				in = true;
			}
			//otherwise keep going left
			else
			{
				current = current->left;
			}
		}
		//if next node is more 
		else
		{
			//if empty slot, insert 
			if (current->right == NULL)
			{
				current->right = nextNode;
				in = true;
			}
			//otherwise keep going left
			else
			{
				current = current->right;
			}
		}
	}
	return true;
}


//given

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}


