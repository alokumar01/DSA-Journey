#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key) {
        int idx = 0;

        for(int i=0; i<key.size(); i++) {
            idx = idx + (key[i] * key[i]) % totSize;
        } 
        return idx%totSize;
    }

    void rehash() { //creating new tbale of double size
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2*totSize;
        currSize = 0;
        table = new Node*[totSize];

        for(int i=0; i<totSize; i++) {
            table[i] = NULL;
        }

        //copy old values
        for(int i=0; i<oldSize; i++) {
            Node* temp = oldTable[i];
            while(temp!=NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if (oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int size) {
        totSize = size;
        currSize = 0;

        table = new Node*[totSize];

        for(int i=0; i<totSize; i++) {
            table[i] = NULL;
        } 
    }

    void insert(string key, int val) { //avg O(1), worst O(n)
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize/(double)totSize;
        if(lambda > 1) {
            rehash(); 
        }
    }

    bool exists(string key) {
        int idx = hashFunction(key);
        
        Node* temp = table[idx];
        while(temp != NULL) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    int search(string key) {
        int idx = hashFunction(key);
        
        Node* temp = table[idx];
        while(temp != NULL) {
            if (temp->key == key) {
                return temp->val;
            }
            temp = temp->next;
        }

        return -1;
    }

    void remove(string key) {
        int idx =  hashFunction(key); //constant

        Node* temp = table[idx]; // constant
        Node* prev = temp;
        while(temp != NULL) {
            if (temp->key == key) { //erase
                if (prev == temp) {// lambda
                    table[idx] = temp->next;
                }else {
                    prev->next = temp->next;
                }
                break;
            }
            prev = temp;
            temp = prev->next;
        }
    }

    void print() {

        for(int i=0; i<totSize; i++) {
            cout << "idx" << i << "->";
            Node* temp = table[i];
            while(temp != NULL) {
                cout << temp->key << "," << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

};


int main() {
    HashTable ht(7);
    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    ht.print();
    cout << endl;
    // if (ht.exists("Nepal")) {
        //     cout << "Nepal population : " << ht.search("Nepal") << endl;
        // }
    ht.remove("China");
    ht.print();

    return 0;
}