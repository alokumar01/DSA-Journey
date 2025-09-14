#include <iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
        root->freq = -1;
    }

    void insert(string key) { // O(L) 
        // modifeid insert fxn for this problem
        Node* temp =  root;
        
        for(int i=0; i<key.size(); i++) {
            if (temp->children[key[i]] == 0) {
                temp->children[key[i]] = new Node(); //insert
                temp->children[key[i]]->freq = 1;
            } else {
                temp->children[key[i]]->freq++;
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    };

    // search is not need for this problem
    string getPrefix(string key) {
        Node* temp = root;
        string prefix = "";

        for(int i=0; i<key.size(); i++) {
            prefix += key[i];
            if (temp->children[key[i]]->freq == 1) {
                break;
            }
            temp = temp->children[key[i]];
        }

        return prefix;
    };

};

void prefixProblme(vector<string> &dict) {
    Trie trie;
    
    for(int i=0; i<dict.size(); i++) {
        trie.insert(dict[i]);
    }

    //to print all the prefix
    for(int i=0; i<dict.size(); i++) {
        cout << trie.getPrefix(dict[i]) << endl;
    }
}


int main() {
    vector<string> dict = {"zebra", "dog", "duck", "dove"};
    prefixProblme(dict);
    return 0;
}