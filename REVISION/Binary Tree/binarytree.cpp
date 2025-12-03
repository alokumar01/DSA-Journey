#include<iostream>
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

static int idx = -1;

Node* buildTree(vector<int> nodes) {
    idx++;

    if (nodes[idx] == -1) return NULL;
    Node* root = new Node(nodes[idx]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);
    return root;
}

//Preoder Traversal
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//inorder traversal
void inorder(Node* root)  {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//postorder traversal
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left != NULL) {
            q.push(curr->left);
        }

        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
}

int main() {
    vector<int> nodes = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(nodes);
    // cout << "Root Node: " << root->data << endl;
    // preorder(root);
    // inorder(root);
    postorder(root);

    cout << endl;
}