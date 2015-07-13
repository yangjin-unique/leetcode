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


/**
 * method 2: using inorder to build tree recursively
 * The order of add tree node is same as order of node in list. 
 * In each recursion, we need move head to next, so pointer to pointer
 * for head is used.
 * Time: o(logN), Space: o(1)
 */
 struct TreeNode *lstToBST(struct ListNode **head, int start, int end);
 
 struct TreeNode* sortedListToBST(struct ListNode* head) {
    int n = 0;
    struct ListNode *p = head;
    
    while (p != NULL) {n++; p = p->next;}
    return lstToBST(&head, 0, n-1);
}

struct TreeNode *lstToBST(struct ListNode **head, int start, int end)
{
    if (start > end) return NULL;

    int mid = start + (end - start) / 2;
    struct TreeNode *left = lstToBST(head, start, mid-1);
    struct TreeNode *parent = malloc(sizeof(*parent));
    parent->val = (*head)->val;
    parent->left = left;
    *head = (*head)->next; /* move head to next */
    parent->right = lstToBST(head, mid+1, end);
    return parent;
}