/**
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

so columnSizes = [1, 2, 2]
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
int getHeight(struct TreeNode *root)  
{
    int hl = 0, hr = 0;
    
    if (root == NULL) return 0;
    hl = getHeight(root->left);
    hr = getHeight(root->right);
    return ((hl > hr) ? (hl + 1) : (hr + 1));
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) return NULL;

    struct TreeNode **queue;
    struct TreeNode *node;
    int front = 0, tail = 0;
    int col = 0;
    int height = getHeight(root);
    int **array;
    int level = 0;

    *returnSize = height; /* number of rows in array, equals to height of tree */
    array = (int **) malloc(sizeof(int *) * height);
    *columnSizes = (int *) malloc(sizeof(int) * height); /* size of columnSizes equals to height of tree */
    queue = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 1024);
    queue[tail++] = root;
    while (front < tail) {
        col = tail - front; /* each level of tree has col nodes */
        (*columnSizes)[level] = col;
        array[level] = (int *) malloc(sizeof(int) * col);
        int idx = 0;
        while (col--) {
            node = queue[front++];
            array[level][idx++] = node->val;
            if (node->left != NULL) queue[tail++] = node->left;
            if (node->right != NULL) queue[tail++] = node->right;
        }
        level++;
    }
    free(queue);
    return array;
}