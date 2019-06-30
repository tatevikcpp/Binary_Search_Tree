#include "BST.h"
#include <iostream>
using namespace std;

int main()
{
	BST t;

	t.insert(20);
	t.insert(25);
	t.insert(15);
	t.insert(10);
	t.insert(30);
	t.insert(40);
	t.insert(50);
	t.display();

	t.delet(20);
	t.display();

	system("pause");
}