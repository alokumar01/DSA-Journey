#include <bits/stdc++.h>
using namespace std;

class TrieNode { // represents one character node
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie { // represents the full data structure
private:
    TrieNode* root; //starting point (empty node);

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) { // puts words into the Trie character by character
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == NULL) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    };

    bool search(string word) {
        TrieNode* curr = root;

        for(char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == NULL) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isEnd;
    };

    bool startswith(string prefix) {
        TrieNode* curr = root;

        for (char c : prefix) {
            int idx = c - 'a';
            if(curr->children[idx] == NULL) {
                return false;
            }
            curr = curr->children[idx];
        }

        return true;
    };
};

int main() {
    Trie t;
    t.insert("cat");
    t.insert("car");

    cout << t.search("car") << endl;
    cout << t.search("cap") << endl;
    cout << t.startswith("c") << endl;
}