/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSymm(struct TreeNode *node1, struct TreeNode *node2) {
	/* first compare node1 with node2 */
	if (node1 == NULL || node2 == NULL) {
		if (node1 != node2) {
			return 0;
		}
		else {
			return 1;
		}
	}
	if (node1->val != node2->val) {
		return 0;
	}
	/* then compare node1->left with node2->right */
	if (node1->left != NULL && node2->right != NULL) {
		if (!isSymm(node1->left, node2->right))
			return 0;
	}
	else {
		if (node1->left != node2->right)
			return 0;
	}
	/* finally compare node1->right with node2->left */
	if (node1->right != NULL && node2->left != NULL) {
		if (!isSymm(node1->right, node2->left))
			return 0;
	}
	else {
		if (node1->right != node2->left)
			return 0;
	}
	return 1;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return 1;

    return isSymm(root->left, root->right);
}