/*
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain
 * a single digit. Add the two numbers and return it as a linked list.

 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 *
 * */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode *p1 = l1, *p2 = l2, *p, *prev;
    
    while (p1 != NULL && p2 != NULL) {
        p2->val += p1->val + carry;
        if (p2->val > 9) {
            p2->val -= 10;
            carry =1;
        }
        else {
            carry = 0;
        }
        p = p2;
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p2 == NULL) {
        p->next = p1;
    }
    prev = p;
    p = p->next;
    /*hanld case: 3->null + 9->9->9->1  =  2->0->0->0->2 */
    while (carry != 0 && p != NULL) {
        p->val += carry;
        if (p->val > 9) {
            p->val -= 10;
            carry = 1;
        }
        else { 
            carry = 0;
        }
        prev = p;
        p = p->next;
    }
    /* handle special case: 3->null + 9->null = 2->1->null */
    /* see if last digit has a carry */
    if (carry != 0 && p == NULL) {
        struct ListNode *tmp = malloc(sizeof(struct ListNode));
        tmp->val = 1;
        tmp->next = NULL;
        prev->next = tmp;
    }
    return l2;
}
