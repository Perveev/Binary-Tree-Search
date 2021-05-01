#include <iostream>

class Node {
public:
    explicit Node(int key);
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
};

Node::Node(int key) {
    this->key = key;
}


class Tree {
public:
    Tree()
    {
        this->root = 0;
    }

    Tree(Node *nd)
    {
        root = nd;
    }
    void Insert(int x);
    void remove(Node nd);
    void search(int a, Node nd);
    Node* root;

};

void Tree::Insert(int x) {
    Node** cur = &root;
    while (*cur) {
        Node& node = **cur;
        if (x < node.key) {
            cur = &node.left;
        } else if (x >= node.key) {
            cur = &node.right;
        }
    }
    *cur = new Node(x);

}

void Tree::search(int a,Node nd) {
    if(nd.key == a){
        std::cout << "Find!! " << nd.key;
        return;
    }
    if(a > nd.key){
        if(nd.right == nullptr) {
            std::cout << "Not Found!\n";
        } else {
            search(a,*nd.right);
            return;
        }
    } else {
        if(nd.left == nullptr) {
            std::cout << "Not Found!\n";
        } else {
            search(a,*nd.left);
            return;
        }
    }
}


int main() {
    Node nd(3);

    Tree tree(&nd);
    tree.Insert(4);
    tree.Insert(5);
    tree.Insert(2);
    tree.Insert(7);
    tree.Insert(6);

    tree.search(5,*tree.root);

    return 0;
}
