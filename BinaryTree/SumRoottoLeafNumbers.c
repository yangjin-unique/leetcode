/***
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25
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
 * method 1:
 * recursion method
 * @sum represents one root-to-leaf path, like 12, 13.
 * @totalSum total sum.
 */
void calcTree(struct TreeNode *root, int sum, int *totalSum) {
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL) {
		*totalSum += sum * 10 + root->val;
		return;
	}
	sum = sum * 10 + root->val;
	calcTree(root->left, sum, totalSum);
	calcTree(root->right, sum, totalSum);
	return;
}

int sumNumbers(struct TreeNode* root) {
	int sum = 0;
	int totalSum = 0;

    calcTree(root, sum, &totalSum);
    return totalSum;
}

/**
 * method 2: simplier version
 */
int calcTree(struct TreeNode *root, int sum) {

	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL) {
		return sum + root->val;
	}
	sum += root->val;
	return calcTree(root->left, sum*10) + calcTree(root->right, sum*10);
}

int sumNumbers(struct TreeNode* root) {
	int sum = 0;

    return calcTree(root, sum);
}

/**
 * c++ solution
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int totalSum = 0;
        
        calcTree(root, sum, &totalSum);
        return totalSum;
    }
    
    void calcTree(TreeNode *root, int sum, int *totalSum) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            *totalSum += sum*10 + root->val;
            return;
        }
        sum = sum*10 + root->val;
        calcTree(root->left, sum, totalSum);
        calcTree(root->right, sum, totalSum);
        return;
    }
};


/**
 * python code
 */
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        totalSum = 0;
        
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        sum = 0;
        self.totalSum = 0;
        if not root:
            return 0;
        self.calcTree(root, sum);
        return self.totalSum;
        
    def calcTree(self, root, sum):
        if root.left == None and root.right == None:
            self.totalSum += sum*10 + root.val;
            return;
        sum = sum*10 + root.val;
        if root.left:
            self.calcTree(root.left, sum);
        if root.right:
            self.calcTree(root.right, sum);    


