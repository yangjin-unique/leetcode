/**
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0, lenB = 0, len;
    struct ListNode *pA, *pB, *p;
    
    if (headA == NULL || headB == NULL) return NULL;
    pA = headA;
    while (pA != NULL) {
        lenA++;
        pA = pA->next;
    }
    pB = headB;
    while (pB != NULL) {
        lenB++;
        pB = pB->next;
    }
    len = (lenA > lenB) ? (lenA - lenB) : (lenB - lenA);
    pA = (lenA > lenB) ? headA : headB;
    pB = (pA == headA) ? headB : headA;
    while (len--) {
        pA = pA->next;
    }
    while (pA != NULL && pB != NULL && pA != pB) {
        pA = pA->next;
        pB = pB->next;
    }
    if (pA == pB && pA != NULL) return pA;
    return NULL;
}