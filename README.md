# Binary Search Tree (BST) Implementation
This is a simple implementation of a Binary Search Tree (BST) in C++. A BST is a binary tree data structure where each node has at most two children, and for each node:
- All nodes in its left subtree have values less than or equal to the node's value.
- All nodes in its right subtree have values greater than the node's value.
# Table of Contents
- [Usage](#Usage)
- [Implementation Details](#Implementation_Details)
- [Testing](#Testing)

# Usage
To use this BST implementation in your C++ project, follow these steps:
- Include the necessary header files in your code.
- Create an instance of the binary_search_tree class, and perform various operations such as insertion, deletion, and searching in the tree.
- Run your program to interact with the BST.

# Implementation_Details
- node.hpp: Defines the node template struct, which represents a node in the binary search tree. It has left and right child pointers and a value of type T.
- binary_search_tree.hpp: Contains the binary_search_tree class definition, which represents the BST. It includes member functions for various tree operations such as insertion, deletion, traversal (inorder, preorder, postorder, and level-order), and finding the minimum, maximum, and height of the tree.
- binary_search_tree.cpp: Provides the implementation for the member functions of the binary_search_tree class.

# Testing
The test.cpp file demonstrates how to use the binary_search_tree class by creating a BST, performing various operations, and printing the tree in different traversal orders.
