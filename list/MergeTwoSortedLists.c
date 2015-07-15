/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1, *p2, *cur, *prev;
    struct ListNode *nh = NULL;
    
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    p1 = l1; p2= l2;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val > p2->val) {
            cur = p2;
            p2 = p2->next;
        }
        else {
            cur = p1;
            p1 = p1->next;
        }
        if (nh == NULL) {
            nh = cur;
            nh->next = NULL;
            prev = nh;
        }
        else {
            prev->next = cur;
            prev = cur;
        }
    }
    if (p1 == NULL) prev->next = p2;
    if (p2 == NULL) prev->next = p1;
    return nh;
}