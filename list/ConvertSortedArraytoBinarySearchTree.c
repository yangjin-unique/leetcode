/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 /**
  * select middle element as root node in each recursion
  * Time: o(logN), Space: o(1)
  */
 struct TreeNode *arrayToBST(struct TreeNode *root, int *nums, int start, int end);
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	struct TreeNode *root = NULL;
    if (nums == NULL || numsSize <= 0) 
        return NULL;
    
    return arrayToBST(root, nums, 0, numsSize-1); 
}

struct TreeNode *arrayToBST(struct TreeNode *root, int *nums, int start, int end)
{
	if (start > end) return NULL;

	if (root == NULL) 
		root = malloc(sizeof(struct TreeNode));
	int mid = start + (end - start) / 2;
	root->val = nums[mid];
	root->left = root->right = NULL;
	root->left = arrayToBST(root->left, nums, start, mid-1);
	root->right = arrayToBST(root->right, nums, mid+1, end);
	return root;
}