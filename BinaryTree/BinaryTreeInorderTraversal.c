/**
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /**
  * method 1: recursion
  */
void inorder(struct TreeNode *root, int *array, int *size) {
	if (root == NULL) return;
	inorder(root->left, array, size);
	array[*size] = root->val;
	(*size)++;
	inorder(root->right, array, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *array;

    *returnSize = 0;
    if (root == NULL) return NULL;
    array = (int *)malloc(512*sizeof(int));
    memset(array, 0, 512*sizeof(int));
    inorder(root, array, returnSize);
    return array;
}

 
 /**
  * method 2: iterative
  */
  int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *array, idx = 0;
    struct TreeNode *stack[512] = {0};
    int top = 0;
    struct TreeNode *node;

    *returnSize = 0;
    if (root == NULL) return NULL;
    array = (int *)malloc(512*sizeof(int));
    memset(array, 0, 512*sizeof(int));
    

    while (root != NULL) {
    	stack[top++] = root;
    	root = root->left;
    }
    
    while (top > 0) {
    	node = stack[--top];
    	array[idx++] = node->val;
    	if (node->right != NULL) {
    		node = node->right;
    		while (node != NULL) {
    			stack[top++] = node;
    			node = node->left;
    		}
    	}
    }
    *returnSize = idx;
    return array;
}