/**
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *cur, *prev;

    if (head == NULL) return NULL;
    prev = head;
    cur = head->next;
    while (cur) {
    	if (prev->val == cur->val) {
    		prev->next = cur->next;
    		free(cur);
    		cur = prev->next;
    	}
    	else {
    		prev = cur;
    		cur = cur->next;
    	}
    }
    return head;
}