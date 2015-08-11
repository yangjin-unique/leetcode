/**
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

/**
 * use hash table.
 */
struct hnode {
    int val;
    struct hnode *next;
};

void freeHtbl(struct hnode **htbl, int size)
{
    struct hnode *node;

    for (int i = 0; i < size; i++) {
        node = htbl[i];
        while (node != NULL) {
            htbl[i] = htbl[i]->next;
            free(node);
            node = htbl[i];
        }
    }
    free(htbl);
}

bool containsDuplicate(int* nums, int numsSize) {
    struct hnode **htbl;
    int i;
    int key;
    struct hnode *node;

    if (nums == NULL || numsSize == 0) return false;

    htbl = (struct hnode **) malloc(sizeof(struct hnode *) * numsSize);
    memset((void *)htbl, 0, sizeof(struct hnode *) * numsSize);
    for (i = 0; i < numsSize; i++) {
        key = abs(nums[i]) % numsSize;
        node = htbl[key];
        while (node != NULL) {
            if (node->val == nums[i]) {
                freeHtbl(htbl, numsSize);
                return true;
            }
            node = node->next;
        }
        node = (struct hnode *) malloc(sizeof(struct hnode));
        node->val = nums[i];
        node->next = htbl[key];
        htbl[key] = node;
    }
    freeHtbl(htbl, numsSize);
    return false;
}