#include <iostream>

#include "BTree.h"

int main() {

	using namespace maintree_manager;

	BTree tree;
	tree.Set(100);
	tree.Append(3);
	tree.Append(4);
	tree.Append(5);
	tree.Push(200, 1);
	tree.Append(3);
	tree.Append(4);
	tree.Pop();
	tree.Append(3);
	tree.Append(6);
	tree.Push(300, 4);
	tree.Append(5);

}