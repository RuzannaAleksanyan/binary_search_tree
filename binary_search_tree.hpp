#ifndef BST
#define BST

#include "node.hpp"
#include <queue>

template <typename T>
class binary_search_tree {
private:
    node<T>* root;

    bool search(node<T>* node, T val);

    void destroy_tree(node<T>* root);

    node<T>* copy_tree(node<T>* root);

    node<T>* get_predecessor(node<T>* node);
    node<T>* get_saccessor(node<T>* node);

    T get_min(node<T>* node);
    T get_max(node<T>* node);

    int get_hight(node<T>* node);

    node<T>* insert(node<T>* node, T val);

    node<T>* delete_node(node<T>* node, T key);

    void preorder(node<T>* node) const;
    void inorder(node<T>* node) const;
    void postorder(node<T>* node) const;

public:
    binary_search_tree();
    binary_search_tree(T val);

    binary_search_tree(const binary_search_tree<T>& other);
    binary_search_tree<T>& operator=(const binary_search_tree& other);

    binary_search_tree(binary_search_tree<T>&& other);
    binary_search_tree<T>& operator=(binary_search_tree<T>&& other);

    ~binary_search_tree();

    bool search(T val);

    T get_min();
    T get_max();

    int get_hight();

    void insert(T val);
    void delete_node(T key);

    void preorder() const;
    void inorder() const;
    void postorder() const;
    void level_order() const;
};

template <typename T>
binary_search_tree<T>::binary_search_tree() : root{nullptr}
{ }

template <typename T>
binary_search_tree<T>::binary_search_tree(T val) {
    root = new node<T>(val);
}

template <typename T>
binary_search_tree<T>::binary_search_tree(const binary_search_tree<T>& other) {
    root = copy_tree(other.root);
}

template <typename T>
binary_search_tree<T>& binary_search_tree<T>::operator=(const binary_search_tree& other) {
    if (this != &other) { 
        destroy_tree(root);

        root = copy_tree(other.root);
    }

    return *this;
}

template <typename T>
void binary_search_tree<T>::destroy_tree(node<T>* root) {
    if(root) {
        destroy_tree(root->left);
        destroy_tree(root->right);
        delete root;
    }
}

template <typename T>
node<T>* binary_search_tree<T>::copy_tree(node<T>* root) {
    if(!root) {
        return nullptr;
    }

    node<T>* newNode = new node<T>(root->value);
    newNode->left = copy_tree(root->left);
    newNode->right = copy_tree(root->right);
    
    return newNode;
}

template <typename T>
binary_search_tree<T>::binary_search_tree(binary_search_tree<T>&& other) {
    destroy_tree(root);
    root = other->root;
    other->root = nullptr;
}

template <typename T>
binary_search_tree<T>& binary_search_tree<T>::operator=(binary_search_tree<T>&& other) {
    if(root != other) {
        destroy_tree(root);
        root = other->root;
        other->root = nullptr;
    }

    return *this;
}

template <typename T>
binary_search_tree<T>::~binary_search_tree() {
    destroy_tree(root);
}

template <typename T>
bool binary_search_tree<T>::search(T val) {
    if(!root) {
        return false;
    }

    return search(root, val);
}

template <typename T>
bool binary_search_tree<T>::search(node<T>* node, T val) {
    if(!node) {
        return false;
    }

    if(node->value == val) {
        return true;
    } else if(node->value < val) {
        return search(node->right, val);
    } else {
        return search(node->left, val);
    }

}

template <typename T>
T binary_search_tree<T>::get_min() {
    return get_min(root);
}

template <typename T>
T binary_search_tree<T>::get_min(node<T>* node) {
    if(!node->left) {
        return node->value;
    }

    return get_min(node->left);
}

template <typename T>
T binary_search_tree<T>::get_max() {
    return get_max(root);
}

template <typename T>
T binary_search_tree<T>::get_max(node<T>* node) {
    if(!node->right) {
        return node->value;
    }

    return get_max(node->right);
}

template <typename T>
int binary_search_tree<T>::get_hight() {
    return get_hight(root);
}

template <typename T>
int binary_search_tree<T>::get_hight(node<T>* node) {
    if(!node) {
        return -1;
    }

    int left_height = get_hight(node->left);
    int right_height = get_hight(node->right);

    return std::max(left_height, right_height) + 1;
}

template <typename T>
node<T>* binary_search_tree<T>::get_predecessor(node<T>* nodee) {
    if (!nodee) {
        return nullptr;
    }

    if (nodee->left) {
        return get_max(nodee->left);
    } else {
        node<T>* pred = nullptr;
        node<T>* ancestor = root;

        while (ancestor != nodee) {
            if (nodee->value > ancestor->value) {
                pred = ancestor;
                ancestor = ancestor->right;
            } else {
                ancestor = ancestor->left;
            }
        }

        return pred;
    }
}


template <typename T>
node<T>* binary_search_tree<T>::get_saccessor(node<T>* nodee) {
    if (!nodee) {
        return nullptr;
    }

    if (nodee->right) {
        return get_min(nodee->right);
    } else {
        node<T>* sacc = nullptr;
        node<T>* ancestor = root;

        while (ancestor != nodee) {
            if (nodee->value > ancestor->value) {
                sacc = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }

        return sacc;
    }
}


template <typename T>
void binary_search_tree<T>::insert(T val) {
    root = insert(root, val);
}

template <typename T>
node<T>* binary_search_tree<T>::insert(node<T>* nodee, T val) {
    if (!nodee) {
        node<T>* tmp = new node<T>(val);
        return tmp;
    }

    if (val < nodee->value) {
        nodee->left = insert(nodee->left, val);
    } else if (val > nodee->value) {
        nodee->right = insert(nodee->right, val);
    }

    return nodee;
}


template <typename T>
void binary_search_tree<T>::delete_node(T key) {
    root = delete_node(root, key);
}

template <typename T>
node<T>* binary_search_tree<T>::delete_node(node<T>* nodee, T key) {
    if (!nodee) {
        return nodee;
    }

    if (key < nodee->value) {
        nodee->left = delete_node(nodee->left, key);
    } else if (key > nodee->value) {
        nodee->right = delete_node(nodee->right, key);
    } else {
        if (!nodee->left) {
            node<T>* tmp = nodee->right; 
            delete nodee;
            return tmp;
        } else if (!nodee->right) {
            node<T>* tmp = nodee->left; 
            delete nodee;
            return tmp;
        } else {
            T val = get_min(nodee->right);
            node<T>* tmp = new node<T>(val);
            nodee->value = tmp->value;
            nodee->right = delete_node(nodee->right, tmp->value);
        }
    }

    return nodee;
}

template <typename T>
void binary_search_tree<T>::preorder() const {
    preorder(root);
}

template <typename T>
void binary_search_tree<T>::preorder(node<T>* node) const {
    if (!node) {
        return;
    }

    std::cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}

template <typename T>
void binary_search_tree<T>::inorder() const {
    inorder(root);
}

template <typename T>
void binary_search_tree<T>::inorder(node<T>* node) const {
    if (!node) {
        return;
    }

    inorder(node->left);
    std::cout << node->value << " ";
    inorder(node->right);
}

template <typename T>
void binary_search_tree<T>::postorder() const {
    postorder(root);
}

template <typename T>
void binary_search_tree<T>::postorder(node<T>* node) const {
    if (!node) {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    std::cout << node->value << " ";
}

template <typename T>
void binary_search_tree<T>::level_order() const {
    if (!root) {
        return;
    }

    std::queue<node<T>*> q;
    q.push(root);

    while (!q.empty()) {
        node<T>* current = q.front();
        q.pop();

        std::cout << current->value << " ";

        if (current->left) {
            q.push(current->left);
        }

        if (current->right) {
            q.push(current->right);
        }
    }
}

#endif
