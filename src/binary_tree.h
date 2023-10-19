#pragma once

#include <functional>
#include <memory>

// A binary search tree of keys to values. Includes operations for
// inserting, removing, and finding key/value pairs.
template <typename K, typename V>
class BinaryTree {
private:

    // Private helper class that encapsulates the data for a single node
    // in the BST.
    class Node {
        friend BinaryTree;
        K key;
        V value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    public:
        Node(const K& key, const V& value) {
            this->key = key;
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    std::shared_ptr<Node> root;

    // Starting at the given node, adds a new node representing the given key
    // and value.
    std::shared_ptr<Node> insert(std::shared_ptr<Node> node, const K& key, const V& value) const {
        // TODO
        return nullptr;
    }

    // Starting at the given node, finds the node that holds the given key, then
    // removes it.
    std::shared_ptr<Node> remove(std::shared_ptr<Node> node, const K& key) const {
        // TODO
        return nullptr;
    }

    // Starting at the given node, finds the node matching the given key and
    // returns it.
    std::shared_ptr<Node> find(std::shared_ptr<Node> node, const K& key) const {
        // TODO
        return nullptr;
    }

    // Returns the node containing the minimum value in the subtree whose
    // root is the given node.
    std::shared_ptr<Node> minimum(std::shared_ptr<Node> node) const {
        // TODO
        return nullptr;
    }

    // Performs an inorder traversal starting at the given node.
    // Visiting a node is performed by invoking the provided visit lambda.
    // The "level" parameter is the level of the node being visited (0=root,
    // 1=root's children, 2=root's grandchildren, etc.).
    // The reverse parameter, if true, causes the inorder search to be
    // performed in reverse order.
    void inorderTraversal(std::shared_ptr<Node> node,
                          std::function<void(const K&, const V&, int level)> visit,
                          bool reverse,
                          int level) const {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(reverse ? node->right : node->left, visit, reverse, level + 1);
        visit(node->key, node->value, level);
        inorderTraversal(reverse ? node->left : node->right, visit, reverse, level + 1);
    }

public:

    class NotFoundException {};

    BinaryTree() : root(nullptr) {}

    // Inserts the key into the tree and associates it with the given value.
    void insert(const K& key, const V& value) {
        root = insert(root, key, value);
    }

    // Removes the given key and its associated value from the tree.
    void remove(const K& key) {
        root = remove(root, key);
    }

    // Performs an inorder traversal of the tree./ Visiting a node is performed
    // by invoking the provided visit lambda. The "level" parameter is the level
    // of the node being visited (0=root, 1=root's children, 2=root's grandchildren,
    // etc.). The reverse parameter, if true, causes the inorder search to be
    // performed in reverse order.
    void iterate(std::function<void(const K&, const V&, int level)> visit, bool reverse = false) const {
        inorderTraversal(root, visit, reverse, 0);
    }

    // Returns the value associated with the given key in the tree.
    // Throws NotFoundException if there is no such key in the tree.
    V get(const K& key) const {
        auto node = find(root, key);
        if (node == nullptr) {
            throw NotFoundException();
        }
        return node->value;
    }   
};
