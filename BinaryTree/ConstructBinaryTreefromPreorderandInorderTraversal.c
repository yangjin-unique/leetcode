/**
Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree
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
 * Example: 
 			4
 		  /   \
 		 2	   5
 	    / \
 	   1   3
 preorder: [4, 2, 1, 3, 5]
 inorder:  [1, 2, 3, 4, 5]	
 we use recursion to build the tree. Each node in preorder is a root, and we
 alloc a node for it. Then the node is used to divide inorder list into two 
 half lists, and both halves are new trees. So we can use a new root node and 
 the first half list to build the left sub tree, and use second half list to
 build the right sub tree.
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	struct TreeNode *node;
	int i = 0;

	if (preorderSize > 0) {
		node = malloc(sizeof(*node));
		node->val = preorder[0];
		while (inorder[i] != preorder[0])
			i++;
		node->left = buildTree(preorder+1, i, inorder, i);
		node->right = buildTree(preorder+i+1, preorderSize-i-1, inorder+i+1, preorderSize-i-1);
		return node;
	}
	return NULL;
}