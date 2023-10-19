#include "binary_tree.h"

#include <cstdlib>
#include <iostream>

using namespace std;

// Performs a reverse inorder traversal to print the binary tree
// in a 2D fashion with the root on the left and the leaves on
// the right.
template <typename K, typename V>
void print2D(const BinaryTree<K, V>& tree)
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
template <typename K, typename V>
void print(const BinaryTree<K, V>& tree)
{
	tree.iterate([](auto key, auto value, int level) {
		cout << key << endl;
	});
}

int main()
{
	BinaryTree<int,string> tree;
	tree.insert(1, "1");
	tree.insert(4, "4");
	tree.insert(2, "2");
	tree.insert(3, "3");
	print2D(tree);
	return EXIT_SUCCESS;
}
