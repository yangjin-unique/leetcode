/**
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode *root) {
	if (root == NULL) return 0;

	int lh = height(root->left);
	int rh = height(root->right);
	return ((lh > rh) ? (lh+1) : (rh+1));
}

bool isBalanced(struct TreeNode* root) {
	if (root == NULL) return 1;

	int lh = height(root->left);
	int rh = height(root->right);
	if ((lh-rh) > 1 || (lh-rh) < -1) return 0;
	return isBalanced(root->left) && isBalanced(root->right);
}