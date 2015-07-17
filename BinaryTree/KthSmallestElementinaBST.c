/**
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode* root, int k) {
    struct TreeNode **stack;
    int top = 0;
    int *array = NULL;
    int idx = 0;

    stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 512);
    array = (int *)malloc(sizeof(int) * k);
    if (root == NULL) return NULL;
    while (root != NULL) {
    	stack[top++] = root;
    	root = root->left;
    }
    while (top > 0) {
    	struct TreeNode *node = stack[--top];
    	array[idx++] = node->val;
    	if (idx == k) break;
    	if (node->right != NULL) {
    		node = node->right;
    		while (node != NULL) {
    			stack[top++] = node;
    			node = node->left;
    		}
    	}
    }
    idx = array[idx-1];
    free(array);
    free(stack);
    return idx;
}