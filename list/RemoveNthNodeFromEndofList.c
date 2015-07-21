/**
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	int total = 0;
	struct ListNode *node = head, *prev = head;

	if (head == NULL) return NULL;
	while (node != NULL) {
		total++;
		node = node->next;
	}
	int idx = total - n + 1;
	node = head;
	while (--idx) {
		prev = node;
		node = node->next;
	}
	if (node == head) {
		head = head->next;
		free(node); 
	}
	else {
		prev->next = node->next;
		free(node);
	}
	return head;
}