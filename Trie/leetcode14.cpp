#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    int freq;

    Node() {
        freq = 0;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& key) {
        Node* temp = root;
        for (char ch : key) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
            temp->freq++;
        }
    }

    string getPrefix(const string& key, int totalSize) {
        Node* temp = root;
        string prefix = "";

        for (char ch : key) {
            if (temp->children.count(ch) == 0) break;
            temp = temp->children[ch];
            if (temp->freq < totalSize) break;
            prefix += ch;
        }

        return prefix;
    }
};

void longestCommonPrefix(const vector<string>& dict) {
    if (dict.empty()) {
        cout << "Longest common Prefix: " << "" << endl;
        return;
    }

    Trie trie;
    for (const string& word : dict) {
        trie.insert(word);
    }

    string lcp = trie.getPrefix(dict[0], dict.size());
    cout << "Longest common Prefix: " << lcp << endl;
}

int main() {
    vector<string> dict = {"flower", "flow", "flight"};
    longestCommonPrefix(dict);
    return 0;
}
