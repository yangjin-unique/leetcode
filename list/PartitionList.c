/**
 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /**
  * move bigger nodes into a new list nh. head still points to smaller nodes list.
  * Time: o(n), Space: o(1)
  */
struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode *cur = NULL, *prev = NULL, *nh = NULL, *ncur = NULL;

	if (head == NULL) return NULL;
	cur = head;
	prev = head;

	while (cur != NULL) {
		if (cur->val >= x) {
			/* move bigger node into nh */
			if (cur == head) {head = cur->next; prev = head;}
			if (nh == NULL) {
				nh = cur;
				ncur = cur;
				cur = cur->next;
			}
			else 
			{
				/* insert end of list nh */
				ncur->next = cur;
				ncur = cur;
				cur = cur->next;
			}
			if (cur != head)
				prev->next = cur;
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}
	/* ncur is the end of list nh, and set next to null */
	if (ncur != NULL) ncur->next = NULL;
	/* prev is the end of list head, point its next to 
	 * nh, so two lists are linked to one list.
	 */
	if (prev != NULL) prev->next = nh;
	/* if all nodes have bigger value */
	if (head == NULL) return nh;
	return head;
}