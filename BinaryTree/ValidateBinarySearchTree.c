/**
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMax(struct TreeNode *root) {
	while (root->right != NULL) {
		root = root->right;
	}
	return root->val;
}

int getMin(struct TreeNode *root) {
	while (root->left != NULL) {
		root = root->left; 
	}
	return root->val;
}

bool isValidBST(struct TreeNode* root) {
    if (root == NULL) return true;
    if (root->left != NULL && root->val <= getMax(root->left)) return 0;
    if (root->right != NULL && root->val >= getMin(root->right)) return 0;
    return isValidBST(root->left) && isValidBST(root->right);
}