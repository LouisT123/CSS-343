//file: bintree.cpp
//Class bintree implementations from bintree.h
//Louis Taing

#include "bintree.h"
#include "nodedata.h"
#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
//Ostream to print bintree object
ostream& operator<<(ostream& out, const BinTree& object)
{
	object.inorderHelper(object.root);
	out << endl;
	return out;
}
//-----------------------------------------------------------------------------
//helper for inorder print for ostream 
void BinTree::inorderHelper(Node* node) const
{
	if (node != nullptr)
	{
		inorderHelper(node->left);
		cout << *node->data << " ";
		inorderHelper(node->right);
	}

}
//-----------------------------------------------------------------------------
//constructor for polynomial class
BinTree::BinTree()
{
	root = nullptr;
}
//-----------------------------------------------------------------------------
//deep copy constructor for polynomial class
BinTree::BinTree(const BinTree& b)
{
	this->root = nullptr;

	*this = b;

}
//-----------------------------------------------------------------------------
//destructor
BinTree::~BinTree()
{
	makeEmpty();
}
//-----------------------------------------------------------------------------
//check to see if bintree is empty
bool BinTree::isEmpty() const
{
	if (root == nullptr)
	{
		return true;
	}
	return false;
}
//-----------------------------------------------------------------------------
//helper for destructor as well as a means to empty bintree
void BinTree::makeEmpty()
{
	makeEmptyHelper(root);
}
//-----------------------------------------------------------------------------
//helper for makeEmpty()
void BinTree::makeEmptyHelper(Node*& node)
{
	//traverse through each branch till at end and delete
	if (node != nullptr)
	{
		makeEmptyHelper(node->left);
		makeEmptyHelper(node->right);
		delete node->data;
		node->data = nullptr;
		delete node;
		node = nullptr;
	}
}

//-----------------------------------------------------------------------------
//overloaded assignment operator (assign a bintrees to another)
BinTree& BinTree::operator=(const BinTree& b)								
{																				
	//if tree is not same
	if (this != &b)
	{
		//clear it
		makeEmpty();
		
		if (b.root != nullptr)
		{
			NodeData* temp = new NodeData(*b.root->data); //deep copy
			assignHelper(root, b.root);
			delete temp;
		}
	}
	return *this;
}
//-----------------------------------------------------------------------------
//helper for overload assignment operator
void BinTree::assignHelper(Node*& node, Node* copy)
{
	if (copy != nullptr)
	{
		NodeData* temp = new NodeData(*copy->data); //deep copy
		node = new Node;
		node->data = temp;
		assignHelper(node->left, copy->left);
		assignHelper(node->right, copy->right);
	}
	else
	{
		node = nullptr;
	}
}
//-----------------------------------------------------------------------------
//overloaded equality comparison operator (compare 2 bintrees to see if equal)
bool BinTree::operator==(const BinTree& b) 
{
	return equalHelper(root, b.root);
}
//-----------------------------------------------------------------------------
//helper for overload equality comparison operator 
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
		if (*left->data == *right->data)
		{
			//make sure both sides of tree are the same, if so return true
			if (equalHelper(left->left, right->left) 
				&& equalHelper(left->right, right->right))
			{
				return true;
			}
		}
	}
	return false;
}
//-----------------------------------------------------------------------------
//overloaded inequality comparison operator (compare 2 bintrees to see if not equal)
bool BinTree::operator!=(const BinTree& b) 
{
	return !(*this == b);
}
//-----------------------------------------------------------------------------
//Inserts data for building bintree 
//(dupes deleted, smaller strings go left, bigger go right)
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
//-----------------------------------------------------------------------------
//retrieves nodedata in a bintree
bool BinTree::retrieve(const NodeData& in, NodeData*& out) const
{
	//if tree empty nothing to retrieve
	if (isEmpty())
	{
		return false;
	}
	Node* current = this->root;
	//while current node exists
	while (current != nullptr)
	{
		//if found the same data, output the data and return true
		if (*current->data == in)
		{
			out = current->data;
			return true;
		}
		//if current node value less than input data, traverse right...
		else if (*current->data < in)
		{
			current = current->right;
		}
		//...otherwise traverse left
		else
		{
			current = current->left;
		}
	}
	
	return false;
}

//-----------------------------------------------------------------------------
//gets height of tree
int BinTree::getHeight(const NodeData& value) const
{
	int height;
	height = 0;
	heightHelper(root, value, height);
	return height;
}
//-----------------------------------------------------------------------------
//helper for getHeight
int BinTree::heightHelper(Node* node, const NodeData& find, int& height ) const
{
	int left = 0;
	int right = 0;
	int maxHigh = 0;

	//if not at end of left branch, keep traversing
	if (node->left != nullptr)
	{
		left = heightHelper(node->left, find, height);
	}
	//if not at end of left branch, keep traversing
	if (node->right != nullptr)
	{
		right = heightHelper(node->right, find, height);
	}

	//once at end of branch, +1 the counter for the actual height
	if (right > left)
	{
		maxHigh = right + 1;
	}
	else
	{
		maxHigh = left + 1;
	}
	//if the data is the same than that height is the largest height
	if (find == *node->data)
	{
		height = maxHigh;
	}

	return maxHigh;
}
//-----------------------------------------------------------------------------
//binary search tree object to array
void BinTree::bstreeToArray(NodeData* arr[])
{
	bsTreeToArrayHelper(root, arr);
	makeEmpty();
}
//-----------------------------------------------------------------------------
//helper for bstToArray
int BinTree::bsTreeToArrayHelper(Node*& current, NodeData* arr[])
{
	if (current == nullptr)
	{
		return 0;
	}
	//traverse left and add to array
	int left = bsTreeToArrayHelper(current->left, arr);

	//set nodedata
	NodeData* temp;
	temp = current->data;
	current->data = nullptr;
	*(arr + left) = temp;
	temp = nullptr;

	//traverse right and add to array
	int right = bsTreeToArrayHelper(current->right, arr + left + 1);

	return left + right + 1;
}
//-----------------------------------------------------------------------------
//array to binary search tree
void BinTree::arrayToBSTree(NodeData* arr[])
{
	//make sure empty
	makeEmpty();
	
	int size = 0;
	//allocates size for array
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] != nullptr)
		{
			size++;
		}
		else
		{
			arr[i] = nullptr;
		}
	}

	arrayToBSTreeHelper(arr, root, 0, size - 1);
}
//-----------------------------------------------------------------------------
//helper for array to binary search tree
void BinTree::arrayToBSTreeHelper(NodeData* arr[], Node* current, int min, int max)
{
	//end of array
	if (min > max)
	{
		current = NULL;
	}
	else
	{
		// recursive root
		int recRoot = (min + max) / 2; 		
		// Inserts NodeData with new root
		NodeData* ptr;
		ptr = arr[recRoot];
		arr[recRoot] = NULL;
		insert(ptr);   
		
		// traverse left
		arrayToBSTreeHelper(arr, current, min, recRoot - 1); 
		// traverse right
		arrayToBSTreeHelper(arr, current, recRoot + 1, max);   
	}
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


