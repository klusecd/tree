#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

template <class TType>
class Node
{
public:
	TType key; 
	Node<TType> *left; 
	Node<TType> *right;
	Node<TType> *parent; 
	Node() { left = NULL; right = NULL; parent = NULL; };
	Node(const TType& k) { key = k; left = NULL; right = NULL; parent = NULL; };
};

template <class TType>
class Bintree
{
private:
	int size; 
public:
	Node<TType> *root;
	Bintree();
	~Bintree();
	void Insert(Node<TType>* &root, Node<TType> *node); 
	Node<TType>* Findkey(Node<TType> *root, const TType &); 
	Node<TType>* FindMax(Node<TType> *root); 
	Node<TType>* FindMin(Node<TType> *root); 
	Node<TType>* FindNext(Node<TType> *root, Node<TType> *node); 
	void Delete(Node<TType>* root, const TType &); 
};

template <class TType>
Bintree<TType>::Bintree()
{
	root = NULL;
	size = 0;
};

template <class TType>
Bintree<TType>::~Bintree()
{
	delete root;
};

template <class TType>
void Bintree<TType>::Insert(Node<TType>* &root, Node<TType> *node)
{
	TType a = node->key;
	if (root == NULL)
	{
		root = new Node<TType>;
		root->key = a;
		size++;
		return;
	}
	Node<TType>* x = root;
	Node<TType>* y = new Node<TType>;
	while (x != NULL)
	{
		y = x;
		if (x->key <= node->key)
			x = x->right;
		else
			x = x->left;
	}
	if (y->key <= node->key)
	{
		y->right = new Node<TType>;
		y->right->key = a;
		y->right->parent = y;
		size++;
	}
	else
	{
		y->left = new Node<TType>;
		y->left->key = a;
		y->left->parent = y;
		size++;
	}
};

template <class TType>
void Bintree<TType>::Delete(Node<TType>* root, const TType &)
{
	Node<TType>* x = Findkey(root, k);
	if (x == NULL)
		return;
	if ((x->left == NULL) && (x - right == NULL))
	{
		if (x->parent->right == x)
			x->parent->right = NULL;
		else
			x->parent.left = NULL;
		return;
	}
	if (x->left == NULL) && (x->right != NULL)
	{
		Node<TType>* y = x->right;
		y->parent = x->parent;
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		return;
	}
	if ((x->left != NULL) && (x->right == NULL))
	{
		Node<TType>* y = x->left;
		y->parent = x->parent;
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		return;
	}
	Node<TType>* y = FindMin(x->right);
	x->key = y->key;
	y->parent->left = y->right;
	if (y->right != NULL)
		y->right->parent = y->parent;
	delete y;
};

template <class TType>
Node<TType>* Bintree<TType>::Findkey(Node<TType> *root, const TType &k)
{
	while ((root != NULL) && (root->key != k))
	{
		if (k < root->key)
			root = root->left;
		if (k > root->key)
			root = root->right;
	}
	if (root == NULL)
		throw "key not found";
	return root;
};

template <class TType>
Node<TType>* Bintree<TType>::FindMin(Node<TType> *root)
{
	if (root == NULL)
		throw "empty tree";
	while (root->left != NULL)
		root = root->left;
	return root;
};

template <class TType>
Node<TType>* Bintree<TType>::FindMax(Node<TType> *root)
{
	if (root == NULL)
		throw "empty tree";
	while (root->right != NULL)
		root = root->right;
	return root;
};

template <class TType>
Node<TType>* Bintree<TType>::FindNext(Node<TType> *root, Node<TType> *node)
{
	if (root == NULL) throw "empty tree";
	if (node == NULL) throw "this key is empty";
	node = Findkey(root, node->key);
	if (node->right != NULL)
		return FindMin(node->right);
	while ((node->parent != NULL) && (node->parent->right == node))
		node = node->parent;
	return node->parent;
};