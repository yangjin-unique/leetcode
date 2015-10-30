/**
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) 
    	return 0;
    int dl = maxDepth(root->left);
    int dr = maxDepth(root->right);
    return (dl > dr) ? (dl+1) : (dr+1);
}