/**
Sort a linked list in O(n log n) time using constant space complexity
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * merge sort, O(nlogn)
 */
struct ListNode* merge(struct ListNode *l1, struct ListNode *l2) {
	struct ListNode dummy = {0, NULL}; /* use a dummy node to simplify process */
	struct ListNode *cur1 = l1;
	struct ListNode *cur2 = l2;
	struct ListNode *cur;

	cur = &dummy;
	while (l1 && l2) {
		if (l1->val > l2->val) {
			cur->next = l2;
			l2 = l2->next;
		}
		else {
			cur->next = l1;
			l1 = l1->next;
		}
		cur = cur->next;
	}
	if (l1 != NULL)
		cur->next = l1;
	if (l2 != NULL)
		cur->next = l2;
	return dummy.next;
}


struct ListNode* sortList(struct ListNode* head) {
	   struct ListNode *fast, *slow;

	   if (head == NULL || head->next == NULL) return head;
	   slow = head;
	   fast = head->next->next;
	   while (fast != NULL) {
	   		slow = slow->next;
	   		if (fast->next == NULL)
	   			break;
	   		fast = fast->next->next;
	   }
	   fast = slow->next;
	   slow->next = NULL;
	   slow = sortList(head);
	   fast = sortList(fast);
	   head = merge(slow, fast);
	   return head;
}