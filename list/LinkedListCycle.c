/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p1, *p2;
    
    if (head == NULL) return 0;
    if (head == head->next) return 1;
    p1 = p2 = head;
    while (p1 != NULL && p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) return 1;
    }
    return 0;
}