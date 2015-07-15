/**
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    struct TreeNode **stack;
    int top;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct BSTIterator *iter = malloc(sizeof(struct BSTIterator));

    iter->stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 1024); /* or we can get height of tree to replace 1024 */
    iter->top = 0;

    while (root != NULL) {
        iter->stack[iter->top++] = root;
        root = root->left;
    }
    return iter;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
    if (iter->top > 0) 
        return 1;
    return 0;
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
    struct TreeNode *node;

    if (iter->top <= 0) return NULL;
    node = iter->stack[--iter->top];
    if (node->right != NULL) {
        struct TreeNode *root = node->right;
        while (root != NULL) {
            iter->stack[iter->top++] = root;
            root = root->left;
        }
    }
    return node->val;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
    free(iter->stack);
    free(iter);
}
/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */