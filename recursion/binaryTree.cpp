#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* buildTree() {
    int n;
    cin >> n;

    if (n == -1) return NULL;

    Node* node = new Node(n);
    node->left = buildTree();
    node->right = buildTree();

    return node;
}

int main(void) {
    Node* root;

    root = buildTree();

    return 0;
}