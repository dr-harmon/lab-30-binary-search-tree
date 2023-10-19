#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "binary_tree.h"

using namespace std;

BinaryTree<int, string> makeTree()
{
	BinaryTree<int, string> tree;
	tree.insert(46, "46");
	tree.insert(49, "49");
	tree.insert(47, "47");
	tree.insert(24, "24");
	tree.insert(22, "22");
	tree.insert(90, "90");
	tree.insert(26, "26");
	tree.insert(30, "30");
	tree.insert(80, "80");
    return tree;
}

vector<pair<int, string>> treeAsList()
{
    return vector<pair<int, string>> {
        {22, "22"},
        {24, "24"},
        {26, "26"},
        {30, "30"},
        {46, "46"},
        {47, "47"},
        {49, "49"},
        {80, "80"},
        {90, "90"},
    };
}

TEST_CASE("Insert")
{
	auto tree = makeTree();
    vector<pair<int, string>> result;
	tree.iterate([&result](auto key, auto value, int level) {
		result.push_back(make_pair(key, value));
	});
    REQUIRE(result == treeAsList());
}

TEST_CASE("Insert (duplicate)")
{
	auto tree = makeTree();
    tree.insert(22, "22");
    vector<pair<int, string>> result;
	tree.iterate([&result](auto key, auto value, int level) {
		result.push_back(make_pair(key, value));
	});
    REQUIRE(result == treeAsList());
}

TEST_CASE("Remove (not found)")
{
	auto tree = makeTree();
    tree.remove(0);
    vector<pair<int, string>> result;
	tree.iterate([&result](auto key, auto value, int level) {
		result.push_back(make_pair(key, value));
	});
    REQUIRE(result == treeAsList());
}

TEST_CASE("Remove (leaf)")
{
	auto tree = makeTree();
    tree.remove(22);
    vector<pair<int, string>> result;
	tree.iterate([&result](auto key, auto value, int level) {
		result.push_back(make_pair(key, value));
	});
    REQUIRE(result == vector<pair<int, string>> {
        {24, "24"},
        {26, "26"},
        {30, "30"},
        {46, "46"},
        {47, "47"},
        {49, "49"},
        {80, "80"},
        {90, "90"},
    });
}

TEST_CASE("Remove (single child)")
{
	auto tree = makeTree();
    tree.remove(26);
    vector<pair<int, string>> result;
	tree.iterate([&result](auto key, auto value, int level) {
		result.push_back(make_pair(key, value));
	});
    REQUIRE(result == vector<pair<int, string>> {
        {22, "22"},
        {24, "24"},
        {30, "30"},
        {46, "46"},
        {47, "47"},
        {49, "49"},
        {80, "80"},
        {90, "90"},
    });
}

TEST_CASE("Remove (double child)")
{
	auto tree = makeTree();
    tree.remove(49);
    vector<pair<int, string>> result;
	tree.iterate([&result](auto key, auto value, int level) {
		result.push_back(make_pair(key, value));
	});
    REQUIRE(result == vector<pair<int, string>> {
        {22, "22"},
        {24, "24"},
        {26, "26"},
        {30, "30"},
        {46, "46"},
        {47, "47"},
        {80, "80"},
        {90, "90"},
    });
}

TEST_CASE("Get")
{
  	auto tree = makeTree();
    REQUIRE(tree.get(22) == "22");
    REQUIRE(tree.get(30) == "30");
    REQUIRE(tree.get(49) == "49");
    REQUIRE(tree.get(90) == "90");
    REQUIRE_THROWS(tree.get(0));
}
