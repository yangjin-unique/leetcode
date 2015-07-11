/**
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
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
 * method 1: use middle node as the parent each time recursively.
 * Time: o(nlogn), Space: o(1)
 */

struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct ListNode *cur, *prev, *mid;
    struct TreeNode *node;
    
    if (head == NULL) return NULL;
    
    node = malloc(sizeof(struct TreeNode));
    if (head->next == NULL) {
        node->val = head->val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    cur = mid = head;
    while (cur != NULL && cur->next != NULL) {
        prev = mid;
        mid = mid->next;
        cur = cur->next->next;
    }
    node->val = mid->val;
    prev->next = NULL; /* split one list into two lists: before mid and after mid */
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(mid->next);
    free(mid);
    return node;
}
