#include "BST.h"

void BST::display()
{
	std::cout << "traversal in inorder " << std::endl;
	inorder(root);
	std::cout << std::endl;

	std::cout << "traversal in postorder " << std::endl;
	postorder(root);
	std::cout << std::endl;

	std::cout << "traversal in preorder " << std::endl;
	preorder(root);
	std::cout << std::endl;
}

void BST::search(int x)
{
	root = find(root, x);
}

void BST::delet(int x)
{
	root = delet(x, root);
}

void BST::insert(int x)
{
	root = insert(x, root);
}