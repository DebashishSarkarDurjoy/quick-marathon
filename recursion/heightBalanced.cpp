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

pair<int, bool> heightBalanced(Node* root) {
    if (root == NULL) return make_pair(0, true);

    pair<int, bool> leftPair = heightBalanced(root->left);
    pair<int, bool> rightPair = heightBalanced(root->right);

    int newHeight = 1 + max(leftPair.first, rightPair.first);
    bool isBalanced = false;
    if ( abs(leftPair.first - rightPair.first) <= 1 && (leftPair.second && rightPair.second) ) {
        isBalanced = true;
        return make_pair(newHeight, isBalanced);
    }
    return make_pair(newHeight, isBalanced);
}

void levelOrderBuild(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* f = q.front();
        q.pop();

        int left, right;
        cin >> left >> right;

        if (left != -1) {
            f->left = new Node(left);
            q.push(f->left);
        }
        if (right != -1) {
            f->right = new Node(right);
            q.push(f->right);
        }
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
    // root->left->right->right = new Node(8);
    // root->left->right->right->left = new Node(9);
    // root->left->right->right->right = new Node(10);

    levelOrderPrint(root);
    cout << endl;

    pair<int, bool> p = heightBalanced(root);
    cout << "Height Balanced: " << (p.second ? "True" : "False") << endl;
    cout << "Height: " << p.first << endl;

    cout << endl;
    levelOrderPrint(root);
    cout << endl;

    return 0;
}