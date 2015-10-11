/***
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * recursion method
 * @sum represents one root-to-leaf path, like 12, 13.
 * @totalSum total sum.
 */
void calcTree(struct TreeNode *root, int sum, int *totalSum) {
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL) {
		*totalSum += sum * 10 + root->val;
		return;
	}
	sum = sum * 10 + root->val;
	calcTree(root->left, sum, totalSum);
	calcTree(root->right, sum, totalSum);
	return;
}

int sumNumbers(struct TreeNode* root) {
	int sum = 0;
	int totalSum = 0;

    calcTree(root, sum, &totalSum);
    return totalSum;
}