#ifndef NODE
#define NODE

template <typename T>
struct node {
    node(T& val) 
            : left{nullptr}, right{nullptr}, value{val}
    {
    }

    node* left;
    node* right;
    T value; 
};

#endif
