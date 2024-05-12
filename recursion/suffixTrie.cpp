#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    char c;
    unordered_map<char, Node*> m;
    bool isTerminal;
    string word;

    Node (char c) {
        this->c = c;
        this->isTerminal = false;
        this->word = "";
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
        temp->word = word;
    }

    void possibleWords_rec(vector<string> &result, Node* node) {
        if (node->m.empty()) {
            result.push_back(node->word);
            return;
        }

        if (node->isTerminal) {
            result.push_back(node->word);
        }

        for (auto it: node->m) {
            Node* temp = it.second;
            possibleWords_rec(result, temp);
        }
    }

public:
    SuffixTrie() {
        this->root = new Node('\0');
    }

    // picking all possible substrings of word
    // void insert(string word) {
    //     for (int i = 0; word[i] != '\0'; i++) {
    //         this->insert_helper(word.substr(i));
    //     }
    // }

    void insert(string word) {
        this->insert_helper(word);
    }

    bool search(string word) {
        Node* temp = root;

        for (char c: word) {
            if (temp->m.count(c) == 0) return false;
            else temp = temp->m[c];
        }

        return temp->isTerminal;
    }

    vector<string> possibleWords(string word) {
        Node* temp = this->root;
        vector<string> result;

        for (char c: word) {
            if ( temp->m.count(c) != 0 ) {
                temp = temp->m[c];
            }
        }

        possibleWords_rec(result, temp);

        return result;
    }
};

int main(void) {
    vector<string> words = { "apple", "ape", "always", "mango", "banana", "lettuce", "capsicum", "chilli", "melon" };

    SuffixTrie t;
    for (string word: words) {
        t.insert(word);
    }

    // string input = "";
    // do {
    //     cin >> input;
    //     cout << (t.search(input) ? "Found": "Not Found") << endl;
    // } while (input != "!");


    cout << "Find possible words: " << endl;
    string input = "";
    cin >> input;
    vector<string> results = t.possibleWords(input);
    for (string word: results) {
        cout << word << ", ";
    }
    cout << endl;

    return 0;
}