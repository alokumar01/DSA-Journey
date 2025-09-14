#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;

    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool searchBST(Node* root, int key) {
    if (root == NULL) return false;

    if (root->data == key) return true;

    if (root->data < key) {
        return searchBST(root->right, key);
    }else {
        return searchBST(root->left, key);
    }
}

//Delete Node
Node* getInorderSucessor(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int val) {
    if (root == NULL) return NULL;

    if (val < root->data) {
        root->left = delNode(root->left, val);
    } else if (val > root->data) {
        root->right = delNode(root->right, val);
    }else {
        // root == val
        // case1 : 0 children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // case2 : 1 child
        if(root->left == NULL || root->right == NULL) {
            return root->left == NULL ? root->right : root->left;
        }

        // case3 : 2children
        Node* IS = getInorderSucessor(root->right); 
        root->data = IS->data;
        root->right = delNode(root->right, IS->data);
    }
    return root;
}

void printInRange(Node* root, int start, int end) {
    if (root == NULL) return;

    if (start <= root->data && root->data <= end) {
        printInRange(root->left, start, end);
        cout << root->data << " ";
        printInRange(root->right, start, end);
    } else if (root->data < start) {
        printInRange(root->right, start, end);
    }else {
        printInRange(root->left, start, end);
    }
}

// sorted Array to balanced bst

// convert bst to balanced bst


int main() {
    // int arr[6] = {5, 1, 3, 4, 2, 7};
    int arr[9] = {8, 5,3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);  

    // inorder(root);
    // cout << endl;
    // searchBST();
    // inorder(root);
    // cout << endl;
    // delNode(root, 5);
    // cout << endl;
    // inorder(root);

    // printInRange(root, 5, 11);


    return 0;
}