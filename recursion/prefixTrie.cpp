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

    Node(char c) {
        this->c = c;
        this->isTerminal = false;
        this->word = "";
    }
};

class Trie {
private:
    Node* root;

    void suggestions_rec(Node* node, vector<string> &results) {
        if (node->m.empty()) {
            results.push_back(node->word);
            return;
        }

        if (node->isTerminal) results.push_back(node->word);

        for (auto it: node->m) {
            suggestions_rec(it.second, results);
        }

    }

public:

    Trie() {
        this->root = new Node('\0');
    }

    void insert(string word) {
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

    void suggestions(string word) {
        Node* temp = this->root;

        for (char c: word) {
            temp = temp->m[c];
        }

        vector<string> results;
        this->suggestions_rec(temp, results);

        for (string result: results) {
            cout << result << ", ";
        }
        cout << endl;
    }

};

int main(void) {
    vector<string> words = {"apple", "ape", "no", "new", "not", "never", "always"};

    Trie t;
    for (string word: words) {
        t.insert(word);
    }

    string search_word;
    cin >> search_word;

    while (search_word != "!") {
        t.suggestions(search_word);
        cin >> search_word;
    }


    return 0;
}