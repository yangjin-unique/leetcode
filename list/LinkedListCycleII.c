/**
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* getCycle(struct ListNode *head) {
    struct ListNode *p1, *p2;
    
    if (head == NULL) return NULL;
    
    p1 = p2 = head;
    while (p1 != NULL && p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) return p1;
    }
    return NULL;
} 

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *p1, *p2, *found;

	found = getCycle(head);
	if (!found) return NULL;

	p1 = head;
	p2 = found;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}