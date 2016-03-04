/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    For the return value, each inner list's elements must follow the lexicographic order.
    All inputs will be in lower-case.
 *
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */



/*
 * c version
 */
/**
 * If the frequencies of each character in two strings are equal, 
 * two strings are a pair of anagram
 * Time: O(n); Space: O(1)
 *
 */
bool isAnagram(char* s, char* t) {
    int hist[256] = {0};
    int i;

    while (*s != '\0') {
        hist[(int)*s]++;
        s++;
    }
    while (*t != '\0') {
        hist[(int)*t]--;
        t++;
    }
    for (i = 0; i < 256; i++) {
        if (hist[i] != 0)
            return false;
    }
    return true;
}


void insertOrdered(char **array, int size, char *str) {
    int i;
    char *tmp;

    for (i = 0; i < size; i++) {
        if (strcmp(array[i], str) > 0) {
            tmp = array[i];
            array[i] = str;
            str = tmp;
        }
    }
    array[size] = str;
}


char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    char ***array;
    int i, j, k;
    int colum;
    int *isMarked;

    if (!strs || strsSize <= 0)
        return NULL;
    array = (char ***) malloc(sizeof(char **) * strsSize);
    memset(array, 0, sizeof(char **) * strsSize);
    isMarked = (bool *) malloc(sizeof(bool) * strsSize);
    memset(isMarked, 0, sizeof(int) * strsSize);
    *columnSizes = (int *) malloc(sizeof(int) * strsSize);
    memset(*columnSizes, 0, sizeof(int) * strsSize);
    *returnSize = 0;
    k = 0;
    for (i = 0; i < strsSize; i++) {
        if (!isMarked[i]) {
            colum = 0;

            isMarked[i] = 1;
            array[k] = (char **) malloc(sizeof(char *) * strsSize);
            memset(array[k], 0, sizeof(char *) * strsSize);

            array[k][colum] = (char *) malloc(strlen(strs[i]) + 1);
            strcpy(array[k][colum], strs[i]);
            colum++;
            for (j = i+1; j < strsSize; j++) {
                if (!isMarked[j] && isAnagram(strs[i], strs[j])) {
                    isMarked[j] = 1;
                    array[k][colum] = (char *) malloc(strlen(strs[j]) + 1);
                    strcpy(array[k][colum], strs[j]);
                    /* insert it into inner list orderly */
                    insertOrdered(array[k], colum, array[k][colum]);
                    colum++;
                } 
            } 
            (*columnSizes)[k] = colum; 
            k++;
        }
    }
    *returnSize = k;
    free(isMarked);
    return array;
}


/* c++ solution */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;  
        unordered_map<string, vector<string>> map;
        int i, j;

        sort(strs.begin(), strs.end());

        for (auto &s: strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end()); /* same group of anagrams have the same key ordered string */
            map[tmp].push_back(s);
        }
        for (auto &it: map) {
            res.push_back(it.second);
        }
        return res;
    }
};
