/**
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

bool isLeafNode(struct TreeNode *node) {
	return (node->left == NULL) && (node->right == NULL);
}
int** pathSum(struct TreeNode *root, int sum, int ** columnSizes, int *returnSize) {
#define STACK_SIZE	64
	struct TreeNode *stack[STACK_SIZE] = {NULL};
	struct TreeNode *aux_stack[STACK_SIZE] = {NULL};
	struct TreeNode *node = NULL;
	int top = 0;
	int aux_top = 0;
	int total = 0;
#define ARRAY_SIZE	512
	int *colum = (int *)malloc(ARRAY_SIZE * sizeof(int));
    
	int i;
	int **res ;//= (int **) malloc(ARRAY_SIZE * ARRAY_SIZE * sizeof(int));
	int m = 0;
	int k = 0;
	int *path;

	res = (int **) malloc(ARRAY_SIZE * sizeof(int *));
    *columnSizes = colum;
	while (root != NULL) {
		stack[top++] = root;
		total += root->val;
		root = root->left;
	}

	*returnSize = 0;
	while (top > 0) {
		node = stack[--top]; /* pop a node */
		if (isLeafNode(node)) {
			if (total == sum) {
				colum[m] = top + 1;
				
				//*(res + m) = (int *)malloc(sizeof(int) * (top + 1));
				//res[m] = (int **) malloc(sizeof(int *));

				path = (int *) malloc(sizeof(int) * (top+1));
				
				for (i = 0, k = 0; i < top; i++, k++) {
					//*(*(res+m) + k) = stack[i]->val;
					path[k] = stack[i]->val;
				}
				//*(*(res+m) + k) = node->val;
				path[k] = node->val;
				res[m++] = path;
			}
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
	*returnSize = m;
	return res;
}


/**
 * c++ non-recursive solution, is similar to PathSum problem
 */
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum){
    	std::vector<std::vector<int>> res;
    	std::vector<int> line;
        std::vector<TreeNode *> stack;
        std::vector<TreeNode *> aux_stack;
        TreeNode *node = NULL;
        int total = 0; 

        while (root != NULL) {
        	stack.push_back(root);
        	total += root->val;
        	root = root->left;
        }

        while (!stack.empty()) {
        	node = stack.back();
        	stack.pop_back();
        	if (isLeafNode(node)) {
        		if (sum == total) {
        			line.clear();
        			for (auto vs = stack.begin(); vs != stack.end(); vs++) {
        				line.push_back((*vs)->val);
        			}
        			line.push_back(node->val);
        			res.push_back(line);
        		}
        	}
        	if (node->right != NULL && !aux_stack.empty() && node == aux_stack.back()) {
        		aux_stack.pop_back();
        		total -= node->val;
        	}
        	else if (node->right != NULL) {
        		stack.push_back(node);
        		aux_stack.push_back(node);
        		node = node->right;
        		while (node != NULL) {
        			stack.push_back(node);
        			total += node->val;
        			node = node->left;
        		}
        	}
        	else {
        		total -= node->val;
        	}
        }
        return res;
    }
    bool isLeafNode(struct TreeNode *node) {
		return (node->left == NULL) && (node->right == NULL);
	}
};


/*
 * recursion 
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	std::vector<int> path;
    	std::vector<std::vector<int>> paths;

    	getPaths(root, sum, path, paths);
    	return paths;
    }

    void getPaths(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &paths) {
    	if (root == NULL)
    		return;
    	path.push_back(root->val);
    	if (root->left == NULL && root>right == NULL) {
    		if (sum == root->val) {
    			paths.push_back(path);
    		}
    	}
    	getPaths(root->left, sum - root->val, path, paths);
    	getPaths(root->right, sum - root->val, path, paths);
    	path.pop_back();
    }
};


/* python recursive solution */
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        path = []
        paths = []

        if root == None:
        	return []
        self.getPaths(root, sum, path, paths)
        return paths

    def getPaths(self, root, sum, path, paths):
    	if root == None:
    		return
    	path.append(root.val)
    	if root.left is None and root.right is None:
    		if sum == root.val:
    			paths.append(path[:])
    	if root.left:
    		self.getPaths(root.left, sum - root.val, path, paths)
    	if root.right:
    		self.getPaths(root.right, sum - root.val, path, paths)
    	path.pop()