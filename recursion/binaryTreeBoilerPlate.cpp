#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node (int data) {
        this->data = data;
        this->left = this->right = NULL;
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

void showTree(Node* root) {
    if (root == NULL) return;
    showTree(root->left);
    cout << root->data << " ";
    showTree(root->right);
}

int main(void) {
    Node* root = buildTree();

    showTree(root);

    return 0;
}