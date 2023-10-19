#include "binary_tree.h"

#include <cstdlib>
#include <iostream>

using namespace std;

// Performs a reverse inorder traversal to print the binary tree
// in a 2D fashion with the root on the left and the leaves on
// the right.
void print2D(const BinaryTree<int, string>& tree)
{
	const int SPACING = 8;
	tree.iterate([](auto key, auto value, int level) {
		cout << endl;
		for (int i = 0; i <= level * SPACING; i++) {
			cout << " ";
		}
		cout << key << endl;
	}, true);
}

// Performs an inorder traversal to print the binary tree with
// each key on a line by itself.
void print(const BinaryTree<int, string>& tree)
{
	tree.iterate([](auto key, auto value, int level) {
		cout << key << endl;
	});
}

int main()
{
	return EXIT_SUCCESS;
}
