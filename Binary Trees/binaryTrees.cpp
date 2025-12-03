#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node *buildTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }

    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);  // left subtree
    currNode->right = buildTree(nodes); // right subtree

    return currNode;
}

void preorder(Node *root)
{ // TC- O(n) linear time complexity
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//levelorder
void levelOrder(Node *root) {
    if (root == NULL) return;
    queue<Node *> Q;
    Q.push(root);
    Q.push(NULL);

    while (!Q.empty())
    {
        Node *curr = Q.front();
        Q.pop();

        if (curr == NULL)
        {
            cout << endl;
            if (Q.empty())
            {
                break;
            }
            Q.push(NULL);
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left != NULL)
            {
                Q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                Q.push(curr->right);
            }
        }
    }
}

//max height
int height(Node* root) {
    if (root == NULL) return 0;
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int currHt = max(leftHt, rightHt) + 1;       
    return currHt;
}

// count the nodes
int countNodes(Node* root) {
    if (root == NULL) return 0;
    int leftc = countNodes(root->left);
    int rightc = countNodes(root->right);
    return leftc+rightc+1;
}

//sum of nodes
int sumNodes(Node* root) {
    if (root == NULL) return 0;
    int sumLeft = sumNodes(root->left);
    int sumRight = sumNodes(root->right);
    return sumLeft+sumRight+root->data;
}

//Diameter of a tree
int diameter(Node* root) { // O(n^2)
    if (root == NULL) return 0 ;
    int currDiam = height(root->left) + height(root->right) + 1;

    int ld = diameter(root->left);
    int rd = diameter(root->right);
    return max(currDiam, max(ld, rd));
}

//Diameter of a tree optimised approach
pair<int, int> diameter2(Node* root) {
    if (root == NULL) {
        return make_pair(0, 0); // (diameter, height)
    }
    pair<int, int> linfo = diameter2(root->left);
    pair<int, int> rinfo = diameter2(root->right);

    int currDiam = linfo.second + rinfo.second + 1;
    int finalDiam = max(currDiam, max(linfo.first, rinfo.first));
    int finalHt = max(linfo.second, rinfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}

//subtree of another tree
bool isIdentical(Node* root1, Node* root2 ) {
    if (root1 == NULL && root2 == NULL) return true;
    
    if (root1 == NULL || root2 == NULL) return false;
    
    return (root1->data == root2->data) &&
        isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot) {
    if (subRoot == NULL) return true;
    if (root == NULL) return false;

    if (isIdentical(root, subRoot)) {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// Top view of tree
void topView(Node* root) {
    if (!root) return;
    queue<pair<Node*, int>> Q; // (node, HD)
    map<int, int> m; // hd, node->data

    Q.push(make_pair(root, 0));

    while (!Q.empty()) {
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if (m.count(currHD) == 0) {
            m[currHD] = currNode->data;
        }

        if (currNode->left != NULL) {
            Q.push(make_pair(currNode->left, currHD - 1));
        }

        if (currNode->right != NULL) {
            Q.push(make_pair(currNode->right, currHD + 1));
        }
    }

    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

//Kth level of tree
void KthHelper(Node* root, int K, int currLevel) {
    if (root == NULL) return;
    
    if (currLevel == K) {
        cout << root->data << " ";
        return;
    }

    KthHelper(root->left, K, currLevel+1); //left child node
    KthHelper(root->right, K, currLevel+1); // right child node
}

void KthLevel(Node* root, int K) { // TC O(n)
    KthHelper(root, K, 1);
}

// LOWEST COMMON ANCESTORS
bool rootToNodePath(Node* root, int n, vector<int> &path) {  // TC- O(n), SC- O(n)
    if (root == NULL) return false;

    path.push_back(root->data);
    if(root->data == n) {
        return true;
    }

    int isLeft = rootToNodePath(root->left, n, path);
    int isRight = rootToNodePath(root->right, n, path);

    if (isLeft || isRight) {
        return true;
    }
    
    path.pop_back();
    return false;

}

int LCA(Node* root, int n1, int n2) {
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++) {
        if (path1[i] != path2[j]) {
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

Node* LCA2(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}

//minimum distance between nodes; TC O(n)
int dist(Node* root, int n) {
    if (root == NULL) return -1;

    if (root->data == n) return 0;

    int leftDist = dist(root->left, n);
    if (leftDist != -1) {
        return leftDist + 1;
    }

    int rightDist = dist(root->right, n);
    if (rightDist != -1) {
        return rightDist + 1;
    }
    return -1;
}

int minDist(Node* root, int n1, int n2) {
    Node* lca = LCA2(root, n1, n2);

    int dist1 = dist(root, n1);
    int dist2 = dist(root, n2);

    return dist1 + dist2;
}

//Kth ancestor node;
int KthAncestor(Node* root, int node, int K) {
    if (root == NULL) return -1;
    if(root->data == node) return 0;

    int lDist = KthAncestor(root->left, node, K);
    int rDist = KthAncestor(root->right, node, K);

    if (lDist == -1 && rDist == -1) {
        return -1;
    }

    int validVal = lDist == -1 ? rDist : lDist;
    if(validVal + 1 == K) {
        cout << "Kth Ancestor : " << root->data << endl;
    }

    return validVal + 1;
}

// SumTree
int transform(Node* root) {
    if (root == NULL) return 0; // base case to prevent segmentation fault
    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld;
    
    if (root->left != NULL) {
        root->data += 
        root->left->data;
    }

    if (root->right != NULL) {
        root->data += 
        root->right->data;
    }

    return currOld;
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes); // 1
    // cout << "root = " << root->data << endl;

    // preorder(root);
    // cout << endl;

    // inorder(root);
    // cout << endl;

    // postorder(root);
    // cout << endl;

    // levelOrder(root);
    // cout << endl;

    // cout << "height: " << height(root) << endl;

    // cout << "Count Nodes: " << countNodes(root) << endl;

    // cout << "Sum of Nodes: " << sumNodes(root) << endl;  

    // cout << "Diameter Of Tree: " << diameter2(root).first << endl;
    
    // Build subRoot: 2 / \ 4 5
    // Node* subRoot = new Node(2);
    // subRoot->left = new Node(4);
    // subRoot->right = new Node(5);

    // cout << isSubtree(root, subRoot) << endl;

    // topView(root) << endl;

    // KthLevel(root, 1);

    int n1 = 4, n2 = 2;
    // cout << "lca: " << LCA2(root, n1, n2)->data; // lowest common ancestor

    // cout << "min dis: " << minDist(root, n1, n2);

    // int node = 5, K = 2;
    // KthAncestor(root, node, K);

    transform(root);
    levelOrder(root);
    return 0;
}