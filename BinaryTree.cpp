#include "BinaryTree.h"
#include<iostream>

using namespace mpcs51044;
using namespace std;

int main() {
	btree tree = btree();
	tree.insert(10);
	tree.insert(6);
	tree.insert(14);
	tree.insert(8);

	auto pt = tree.search(8);
	if (pt != nullptr)
	{
		cout << "found value at node ";
		pt->print();
	}
	else
	{
		cout << "couldn't find value in tree.";
	}

	
	return 0;
}