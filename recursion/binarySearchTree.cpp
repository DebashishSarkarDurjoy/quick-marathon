#include <iostream>
#include <vector>
#include <algorithm>
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

Node* minHeight(int* arr, int start_idx, int end_idx) {
    // base case
    if (start_idx >= end_idx) return NULL;

    // recursive case
    int mid = (start_idx + end_idx) / 2;
    Node* node = new Node(arr[mid]);
    node->left = minHeight(arr, 0, mid-1);
    node->right = minHeight(arr, mid+1, end_idx);

    return node;
}

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
    Node* root1 = NULL;
    int arr[] = { 8, 10, 3, 5, 6, 11, 9, 7, 1, 13, 15, 4 };

    for (int num: arr) {
        root1 = insertIntoBST(root1, num);
    }
    cout << "Root 1: " << endl;
    printBST(root1);
    cout << endl;

    cout << "Level order print: " << endl;
    levelOrderPrint(root1);

    // int toSearch;
    // cout << "Search: ";
    // cin >> toSearch;
    // cout << (search(toSearch, root1) ? "Found" : "Not Found") << endl; 


    // int toSearch;
    // cout << "Search: ";
    // cin >> toSearch;
    // cout << findClosest(root1, toSearch) << endl;

    int arr_len = sizeof(arr)/sizeof(int);
    sort(arr, arr + arr_len);

    Node* root2 = minHeight(arr, 0, arr_len-1);
    cout << "Root 2: " << endl;
    printBST(root2);


    return 0;
}