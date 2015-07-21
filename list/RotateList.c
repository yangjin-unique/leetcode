/**
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int total = 0;
    struct ListNode *node = head, *prev = head;

    if (head == NULL) return head;
    while (node != NULL) {
    	total++;
    	node = node->next;
    }
    
    k %= total;
    if (k == 0) return head;
    k = total - k;
    prev = node = head;
    while (k--) {
    	prev = node;
    	node = node->next;
    }
    /* now node is the new head, prev is the new end */
    while (node->next != NULL) {
        node = node->next;
    } 
    node->next = head;
    head = prev->next;
    prev->next = NULL;
    
    return head;
}