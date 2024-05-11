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

Node* insertIntoBST(Node* node, int n) {
    // recursive case
    if (node == NULL) return new Node(n);

    // base case
    if (node->data > n) {
        node->left = insertIntoBST(node->left, n);
    }
    else {
        node->right = insertIntoBST(node->right, n);
    }

    return node;
}

void printBST(Node* node) {
    // recursive case
    if (node == NULL) return;

    // base case
    printBST(node->left);
    cout << node->data << " ";
    printBST(node->right);

}

bool search(int num, Node* node) {
    // base case
    if (node == NULL) return false;

    // recursive case
    bool isFound = false;
    if (node->data > num) {
        isFound = search(num, node->left);
    }
    else if (node->data < num) {
        isFound = search(num, node->right);
    }
    else {
        isFound = true;
    }

    return isFound;
}

int findClosest(Node* node, int target) {
    int closest;
    int diff = INT_MAX;

    Node* temp = node;

    while (temp != NULL) {
        int current_diff = abs(temp->data - target);

        if (current_diff == 0) return temp->data;

        if (current_diff < diff) {
            diff = current_diff;
            closest = temp->data;
        }

        if (target < temp->data) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    return closest;
}

int main(void) {
    Node* root1 = NULL;
    int arr[] = { 8, 10, 3, 5, 6, 11, 9, 7, 1, 13, 15, 4 };

    for (int num: arr) {
        root1 = insertIntoBST(root1, num);
    }

    printBST(root1);
    cout << endl;

    // int toSearch;
    // cout << "Search: ";
    // cin >> toSearch;
    // cout << (search(toSearch, root1) ? "Found" : "Not Found") << endl; 


    int toSearch;
    cout << "Search: ";
    cin >> toSearch;
    cout << findClosest(root1, toSearch) << endl;

    return 0;
}