/**
 *  A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *  Return a deep copy of the list.
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
 /**
  * method 1
  * first, copy old list to new one with random pointer unchaged (still points to old list members);
  * then, traverse new list and correct the random pointer.
  * Time: O(n^2), Space: O(1)
  */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *cur = NULL;
    struct RandomListNode *new = NULL, *prev = NULL, *nhead = NULL;
    int first = 1;
    
    cur = head;
    prev = NULL;
    while (cur != NULL) {
        new = malloc(sizeof(struct RandomListNode));
        memcpy(new, cur, sizeof(*cur));
        if (first) {
            nhead = new;
            prev = new;
            first = 0;
        }
        else {
            prev->next = new;
            prev = new;
        }
        cur = cur->next;
    }
    
    cur = head;
    struct RandomListNode *node = nhead;
    while (node != NULL) {
        if (node->random != NULL) {
            cur = head;
            new = nhead;
            while (cur != node->random) {
                cur = cur->next;
                new = new->next;
            }
            /* if node->random points to cur, then new is the node that node->random should points to */
            node->random = new;
        }
        node = node->next;
    }
    return nhead;
}


/**
 * method 2
 * first copy each node in older list.
 * for example: 1 -> 2 -> 3 -> null => 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> null;
 * then, ajust random pointer in each newly added node.
 * example: if 1 points to 2, then clone 1' should point to clone 2', which is right after 2.
 * finally, split list into two list.
 * Time: O(n), Space: O(1)
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) 
{
    struct RandomListNode *cur = NULL;
    struct RandomListNode *new;
    
    cur = head;
    while (cur != NULL) {
        new = malloc(sizeof(struct RandomListNode));
        new->label = cur->label;
        new->next = cur->next;
        new->random = NULL;
        cur->next = new;
        cur = new->next;
    }
    
    cur = head;
    while (cur != NULL) {
        new = cur->next;
        if (cur->random != NULL) {
            new->random = cur->random->next;
        }
        cur = new->next;
    }
    
    cur = head;
    struct RandomListNode *nh = NULL;
    if (head != NULL) nh = head->next;
    while (cur != NULL) {
        new = cur->next;
        cur->next = new->next;
        cur = cur->next;
        if (cur != NULL)
            new->next = cur->next;
    }
    return nh;
}
