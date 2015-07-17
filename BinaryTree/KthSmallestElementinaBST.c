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

/**
 * method 2: using properties of bst.
 * if number of nodes in left-subtree greater than (k-1), then the k-th smallest 
 * must be in left-rubtree;
 * if number less than (k-1), then k-th node must be in right-subtree.
 * if equal, root is the one
 * Time: averag o(logn)
 */
int countNodes(struct TreeNode *root)
 {
 	int nl = 0, nr = 0;

 	if (root == NULL) return 0;
 	nl = countNodes(root->left);
 	nr = countNodes(root->right);
 	return (nl + nr + 1);
 }

 int kthSmallest(struct TreeNode* root, int k) {
 	int n = 0;
    
    n = countNodes(root->left);
 	if ((k-1) > n)
 		return kthSmallest(root->right, k-n-1);
 	else if ((k-1) < n)
 		return kthSmallest(root->left, k);
 	else 
 		return root->val;
 }