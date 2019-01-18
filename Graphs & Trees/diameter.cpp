/*
Diameter of a binary tree is defined as the maximum number of nodes in path between any two leaf nodes.
*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Computes the diameter of binary tree with given root.  */

int diameterUtil(Node *root, int &ans) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    int hl = diameterUtil(root->left, ans);
    int hr = diameterUtil(root->right, ans);
    
    if(root->left && root->right) {
        ans = max(ans, hl+hr + 1);
        return max(hl, hr) + 1;
    }
    
    if(root->left)
        return hl + 1;
    if(root->right)
        return hr + 1;
}


int diameter(Node* root) {
    int ans = INT_MIN;
    diameterUtil(root, ans);
    
    return ans;
}
