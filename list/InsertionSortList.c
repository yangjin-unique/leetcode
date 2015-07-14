/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *nh = head;
    struct ListNode *prev, *cur;
    
    if (head == NULL) {
        return NULL;
    }
    head = head->next;
    nh->next = NULL;
    while (head != NULL) {
        cur = nh;
        while (cur != NULL && head->val > cur->val) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nh) {
            nh = head;
            head = head->next;
            nh->next = cur;
        }
        else {
            prev->next = head;
            head = head->next;
            prev->next->next = cur;
        }
    }
    return nh;
}