/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy = {0, NULL}; /* use a dummy node to simplify process */
    struct ListNode *cur = &dummy;

    while (l1 != NULL && l2 != NULL) {
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
    if (l1 != NULL) cur->next = l1;
    if (l2 != NULL) cur->next = l2;
    return dummy.next;
}
