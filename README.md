# Lab 30: Binary Search Tree

In this lab we will focus on the binary search tree, or BST. Our implementation will associate a set of keys with a set of values. The keys and values can be any type.

A `BinaryTree` class has been provided for you, along with a variety of helper methods and test cases. Your task is to implement some of the fundamental operations of the BST:

* minimum: finds the minimum key
* get: returns the value associated with the given key
* insert: adds a new key/value pair
* remote: removes the key/value pair

## Part 1: Insert

New nodes always start as a leaf in the BST. Therefore, to insert a new node into a BST, start at the root and descend the tree, choosing the left or right path according to whether the node is less than or greater than the new key. Once the path ends (child is a nullptr), the child can become the new node.

Here is the pseudocode:

    Algorithm TreeInsert(k,v,n):
        Input: A search key k, an associated value, v, and a node n of T
        Output: A new node in the subtree T(n) that stores the entry (k,v)
 
        if n is null then
            return a new node containing k and v

        if k < n.key then
            n.left ← TreeInsert(k,v,n.left)
        else if k > n.key then
            n.right ← TreeInsert(k,v,n.right)

        return n

Implement this algorithm in the `insert` method of the provided `BinaryTree` class. You can use the `print` and `print2D` functions in `main.cpp` to test it. You should also make sure the "Insert" test case passes before continuing.

## Part 2: Find

The find operation is very similar to insert: Descend the tree until the node is found, or return null.

    Algorithm TreeFind(k,n):
        Input: A search key k and a node n of T
        Output: The node containing key k or null if not found
 
        if n is null then
            return null

        if k < n.key then
            return TreeFind(k,n.left)
        else if k > n.key then
            return TreeFind(k,n.right)
        else
            return n

Implement this algorithm in the `find` method of the provided `BinaryTree` class. Make sure the "Get" test case passes before continuing.

## Part 3: Minimum

The minimum value in a BST is always in the leftmost node. Therefore, you can find the minimum value simply by walking the left-hand nodes until none are left.

    Algorithm TreeMinimum(k,n):
        Input: A search key k and a node n of T
        Output: The node containing the smallest value in T
        while n.left is not null do
            n ← n.left
        return n

Implement the `minimum` method so that it returns the minimum node. Test your code by adding a temporary public test function to `BinaryTree` and invoking it from `main`. (There are no unit tests for `minimum`.)

## Part 4: Remove

Removal of a node from a BST takes a bit more effort than the other operations. Since this is a BST, it is guaranteed that each node will have at most two children. Given that, we can assume the following scenarios:

* The node we want to delete has no children.
* The node we want to delete has one child.
* The node we want to delete has two children.

If the node we want to delete has zero children, then all we have to do is set this node to null.

If the node we want to delete has one child, then we need to replace the node with the node's child.

If the node we want to delete has two children:
1. Find the minimum value in the right subtree
2. Replace the node value with this minimum value.
3. Remove the node that is now duplicated in the right subtree.

To get a better understanding of these cases, draw some examples and perform the operations on them by hand.

    Algorithm TreeRemove(k,n):
        Input: A search key k and a node n of T
        Output: The node that was removed

        if n is null then
            return null
        else if k < n.key then
            n.left ← TreeRemove(k,n.left)
        else if k > n.key then
            n.right ← TreeRemove(k,n.right)
        else
            if n.left is null and n.right is null then
                n ← null
            else if n.left is null then
                n ← n.right
            else if n.right is null then
                n ← n.left
            else
                m ← TreeMinimum(n.right)
                n.key ← m.key
                n.value ← m.value
                n.right ← = TreeRemove(n.right,m.key)
        return n

Implement this algorithm in the `remove` method of the provided `BinaryTree` class. You can use the `print` and `print2D` functions in `main.cpp` to test it. You should also make sure the "Delete" test cases pass before continuing.
