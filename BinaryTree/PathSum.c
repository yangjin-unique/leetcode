/**
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
 * method 1: recursion.
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL)
    	return 0;

    if (root->left == NULL && root->right == NULL) {
    	return (sum == root->val);
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}


/**
 * method 2: non-recursive solution, using DFS with two stacks.
 * For general DFS solution, one stack is enough. Why it needs two?
 * As for node with right child, we push the node into stack two times.
 * when poping, the first poping we have to add left nodes of the node's 
 * right child into stack, but for the second poping, we shouldn't do that
 * again, so we use an aux_stack to record such nodes.
 */
bool isLeafNode(struct TreeNode *node) {
	return (node->left == NULL) && (node->right == NULL);
}
bool hasPathSum(struct TreeNode *root, int sum) {
#define STACK_SIZE	64
	struct TreeNode *stack[STACK_SIZE] = {NULL};
	struct TreeNode *aux_stack[STACK_SIZE] = {NULL};
	struct TreeNode *node = NULL;
	int top = 0;
	int aux_top = 0;
	int total = 0;

	while (root != NULL) {
		stack[top++] = root;
		total += root->val;
		root = root->left;
	}

	while (top > 0) {
		node = stack[--top]; /* pop a node */
		if (isLeafNode(node)) {
			if (total == sum)
				return true;
		}
		if (node->right != NULL && aux_top > 0 && node == aux_stack[aux_top-1]) {
			/* node's right child has been pushed before, that is to say node's value is added into total,
			 * so minus it
			 */
			total -= node->val;
			aux_top--;
		}
		else if (node->right != NULL) {
			stack[top++] = node; /* here we let node which has right child re-push into stack again */
			aux_stack[aux_top++] = node; /* we push node into auxiliary stack as records, so next time the node pops out, we would not 
											push all its right childs into stack again (as these nodes have done before) */
			node = node->right;
			while (node != NULL) {
				stack[top++] = node;
				total += node->val;
				node = node->left;
			}
		}
		else {
			total -= node->val;
		}
	}
	return false;
}


/**
 * python solution
 */
 # Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root == None:
        	return False;
        if root.left == None and root.right == None:
        	return sum == root.val;
        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val);