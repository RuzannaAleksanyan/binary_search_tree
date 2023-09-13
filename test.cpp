#include <iostream>
#include "binary_search_tree.hpp" 

int main() {
    binary_search_tree<int> bst;

    // Insert values into the tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Print the tree in different traversal orders
    std::cout << "Inorder traversal: ";
    bst.inorder();
    std::cout << std::endl;

    std::cout << "Preorder traversal: ";
    bst.preorder();
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    bst.postorder();
    std::cout << std::endl;

    std::cout << "Level-order traversal: ";
    bst.level_order();
    std::cout << std::endl;

    // Search for values in the tree
    int search_value = 30;
    if (bst.search(search_value)) {
        std::cout << search_value << " found in the tree." << std::endl;
    } else {
        std::cout << search_value << " not found in the tree." << std::endl;
    }

    // Get the minimum and maximum values in the tree
    int min_val = bst.get_min();
    int max_val = bst.get_max();
    int hight_val = bst.get_hight();
    std::cout << "Minimum value in the tree: " << min_val << std::endl;
    std::cout << "Maximum value in the tree: " << max_val << std::endl;
    std::cout << "Hight value in the tree: " << hight_val << std::endl;

    // Delete a node from the tree
    int delete_value = 30;
    bst.delete_node(delete_value);
    std::cout << "Deleted " << delete_value << " from the tree." << std::endl;

    // Print the tree after deletion
    std::cout << "Inorder traversal after deletion: ";
    bst.inorder();
    std::cout << std::endl;

    return 0;
}
