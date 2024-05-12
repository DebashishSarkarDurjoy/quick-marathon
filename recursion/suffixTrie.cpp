#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    char c;
    unordered_map<char, Node*> m;
    bool isTerminal;

    Node (char c) {
        this->c = c;
        this->isTerminal = false;
    }

};

class SuffixTrie {
private:
    Node* root;

    void insert_helper(string word) {
        Node* temp = this->root;

        for (char c: word) {
            if (temp->m.count(c) == 0) {
                temp->m[c] = new Node(c);
            }
            temp = temp->m[c];
        }

        temp->isTerminal = true;
    }

public:
    SuffixTrie() {
        this->root = new Node('\0');
    }

    // picking all possible substrings of word
    void insert(string word) {
        for (int i = 0; word[i] != '\0'; i++) {
            this->insert_helper(word.substr(i));
        }
    }

    // void insert(string word) {
    //     this->insert_helper(word);
    // }

    bool search(string word) {
        Node* temp = root;

        for (char c: word) {
            if (temp->m.count(c) == 0) return false;
            else temp = temp->m[c];
        }

        return temp->isTerminal;
    }
};

int main(void) {
    vector<string> words = { "apple", "ape", "always", "mango", "banana", "lettuce", "capsicum", "chilli", "melon" };

    SuffixTrie t;
    for (string word: words) {
        t.insert(word);
    }

    string input = "";
    do {
        cin >> input;
        cout << (t.search(input) ? "Found": "Not Found") << endl;
    } while (input != "!");


    return 0;
}