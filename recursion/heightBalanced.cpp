#include <iostream>
#include <queue>
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

void levelOrderPrint(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* f = q.front();
        q.pop();
        if (f == NULL) {
            cout << endl;
            if (q.empty()) return;
            else q.push(NULL);
            continue;
        }
        cout << f->data << " ";
        if (f->left != NULL) q.push(f->left);
        if (f->right != NULL) q.push(f->right);
    }
}


int main(void) {
    Node* root;

    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(6);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->left->right->right->left = new Node(9);
    root->left->right->right->right = new Node(10);

    levelOrderPrint(root);

    return 0;
}