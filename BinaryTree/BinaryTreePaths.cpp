/**
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string str;
            
        getPaths(root, str, paths);
        return paths;
    }
    void getPaths(TreeNode *root, string &str, vector<string> &paths) {
    	if (root == NULL) 
    		return;
    	string s("->");
    	if (str.size() == 0) {
    	    s.clear();
    	}
    	s += to_string(root->val);
    	str.append(s);
    	if (root->left == NULL && root->right == NULL) {
    		paths.push_back(str);
    	}
    	getPaths(root->left, str, paths);
    	getPaths(root->right, str, paths);
    	str.erase(str.size() - s.size());
    }
};


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        path = ''
        paths = []
        if root is None:
        	return []
        self.getPaths(root, path, paths)
        return paths

    def getPaths(self, root, path, paths):
    	if root is None:
    		return
    	
    	if path != '':
    		s = '->' + str(root.val)
    	else:
    	    s = str(root.val)
    	    
    	path += s

    	if root.left is None and root.right is None:
    		paths.append(path)
    	self.getPaths(root.left, path, paths);
    	self.getPaths(root.right, path, paths);
    	path = path[ : len(path)-len(s)]

