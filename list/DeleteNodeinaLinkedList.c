/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
	struct ListNode *tmp;

    node->val = node->next->val;
    tmp = node->next;
    node->next = node->next->next;
    free(tmp);
}