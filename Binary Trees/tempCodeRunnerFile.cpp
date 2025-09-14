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
