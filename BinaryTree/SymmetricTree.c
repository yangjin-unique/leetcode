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

/**
 * method 1: recursive 
 */
bool isSymm(struct TreeNode *node1, struct TreeNode *node2) {
	/* first compare node1 with node2 */
	if (node1 == NULL || node2 == NULL) {
		if (node1 != node2) 
			return 0;
		else 
			return 1;
	}
	if (node1->val != node2->val) {
		return 0;
	}
	/* then compare node1->left with node2->right */
	if (!isSymm(node1->left, node2->right))
		return 0;
	
	/* finally compare node1->right with node2->left */
	if (!isSymm(node1->right, node2->left))
		return 0;
	
	return 1;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return 1;

    return isSymm(root->left, root->right);
}


/**
 * method 2: iterative, inorder traverse for root->left and root->right
 */
 bool isSymmetric(struct TreeNode* root) {
 	struct TreeNode **stack1;
 	struct TreeNode **stack2;
 	struct TreeNode *node1, *node2;
 	int top1 =0, top2 = 0;
 	bool ret = 1; 

 	if (root == NULL) return 1;
 	node1 = root->left;
 	node2 = root->right;
 	if (node1 == node2) return 1;
 	stack1 = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 512);
 	stack2 = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 512);
    if (node1 != NULL)
 	    stack1[top1++] = node1;
 	if (node2 != NULL)
 	    stack2[top2++] = node2;
 	while (top1 > 0 && top2 > 0) {
 		node1 = stack1[--top1];
 		node2 = stack2[--top2];
 		
 		while (node1 != NULL && node2 != NULL) {
 			if (node1->val != node2->val) {
 				ret = 0;
 				break;
 			}
 			if (node1->right != NULL)
 				stack1[top1++] = node1->right;
 			if (node2->left != NULL)
 				stack2[top2++] = node2->left;
 			node1 = node1->left;
 			node2 = node2->right;
 		}
 		if (node1 != node2) {
 			ret = 0;
 			break;
 		} /* node1 = node2 = NULL */
 	}
 	if (ret == 1) {
 		if (top1 != top2)
 			ret = 0;
 	}
 	free(stack1);
 	free(stack2);
 	return ret;
 }