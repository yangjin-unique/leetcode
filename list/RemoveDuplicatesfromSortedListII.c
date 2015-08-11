/**
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode node;

    if (!head) return NULL;
    node.val = head->val + 1; /* any number should be ok, only to get a differenet value */
    node.next = head;

    struct ListNode *cur = &node, *tmp;
    while (cur->next) {
    	if (cur->next->next && cur->next->val == cur->next->next->val) {
    		while (cur->next->next && cur->next->val == cur->next->next->val) {
    			tmp = cur->next;
    			cur->next = cur->next->next;
    			free(tmp);
    		}
    		cur->next = cur->next->next;
    	}
    	else {
    		cur = cur->next;
    	}

    }
    return node.next;
}