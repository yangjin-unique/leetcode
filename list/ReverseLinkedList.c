/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev, *cur;

    prev = NULL;
    cur = head;
    while (cur != NULL) {
    	head = head->next;
    	cur->next = prev;
    	prev = cur;
    	cur = head;
    }
    return prev;
}