#pragma once

#include <iostream>
using namespace std;

class BST
{
	struct node
	{
		int key;
		node *left, *right;
	};

	node *root;
	node *tree;

	node* empty(node* t)
	{
		if (t == nullptr)
			return nullptr;
		{
			empty(t->left);
			empty(t->right);
			delete t;
		}
		return nullptr;
	}

	node* insert(int x, node* t)
	{
		if (t == nullptr)
		{
			t = new node;
			t->key = x;
			t->left = t->right = nullptr;
		}
		else if (x < t->key)
			t->left = insert(x, t->left);
		else if (x > t->key)
			t->right = insert(x, t->right);
		return t;
	}

	node* findMin(node* t)
	{
		if (t == nullptr)
			return nullptr;
		else if (t->left == nullptr)
			return t;
		else
			return findMin(t->left);
	}

	node* findMax(node* t)
	{
		if (t == nullptr)
			return nullptr;
		else if (t->right == nullptr)
			return t;
		else
			return findMax(t->right);
	}

	node* delet(int x, node* t)
	{
		node* temp;
		if (t == nullptr)
			return nullptr;
		else if (x < t->key)
			t->left = delet(x, t->left);
		else if (x > t->key)
			t->right = delet(x, t->right);
		else if (t->left && t->right)
		{
			temp = findMin(t->right);
			t->key = temp->key;
			t->right = delet(t->key, t->right);
		}
		else
		{
			temp = t;
			if (t->left == nullptr)
				t = t->right;
			else if (t->right == nullptr)
				t = t->left;
			delete temp;
		}

		return t;
	}

	node* find(node* t, int x)
    {
        if(t == nullptr)
            return nullptr;
        else if(x < t->key)
            return find(t->left, x);
        else if(x > t->key)
            return find(t->right, x);
        else
            return t;
    }
	
	void inorder(node* t)
	{
		if (t == nullptr)
			return;
		inorder(t->left);
		cout << t->key << " ";
		inorder(t->right);
	}

	
	void postorder(node *t)
	{
		if (t == nullptr)
			return;
		postorder(t->left);
		postorder(t->right);
		cout << t->key << " ";
	}
	
	void preorder(node *t)
	{
		if (t == nullptr)
			return;
		cout << t->key << " ";
		preorder(t->left);
		preorder(t->right);
	}
	
public:

	BST()
	{
		root = nullptr;
	}

	~BST()
	{
		root = empty(root);
	}

	void insert(int x);
	
	void delet(int x);
	
	void display();
	
	void search(int x);

	
	void print(node* tree) {
		
			if (tree) {
				
					print(tree->left);
				
					cout << tree->key << endl;
				
					print(tree->right);
				
			}
		
	}

	void printtree(node * tree)
		
	{
		
			if (tree != nullptr)
				
			{
				
					print(tree->left);
				
					printtree(tree->left);
				
					printtree(tree->right);
				
			}
		
	}

	
};





