//Find the maximum sum path between two leave nodes of a binary tree

int maxSum(Node *root, int &res) {
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL) 
		return root->data;
		
	int ls = maxSum(root->left, res);
	int rs = maxSum(root->right, res);
	
	if(root->left && root->right) {
		res = max(res, ls + rs + root->data);
		
		return max(ls, rs) + root->data;
	}
	
	if(root->left) {
		return ls + root->data;
	}
	if(root->right) {
		return rs + root->data;
	}
}

int maxSumPath(Node *root) {
	int res = INT_MIN;
	maxSum(root, res);
	return res;
}

/*
this recursive solution brilliantly shopisticats the process of finding maximum sum path between any two leave nodes of a binary tree
it finds the maximum leftsum and rightsum for each subtree of a binary tree and add it  with the root->data to find the maximum
sum that can be obtained.
*/
