/**
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc",
 which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

void initArray(int *a, int n) {
    int i;
    
    for (i = 0; i < n; i++)
        a[i] = -1;
}

int lengthOfLongestSubstring(char* s) {
    int pos[256];
    int i;
    
    if (!s) return 0;
    for (i = 0; i < 256; i++) 
        pos[i] = -1;
    int n = strlen(s);
    int len = 0;
    int maxLen = 0;
    for (i = 0; i < n; i++) {
        if (pos[s[i]] > -1) {
            i = pos[s[i]]; /* the char is repeated, so go back, e.g. abcabc, when the second 'a' is found, we need to go back to 'b' */
            initArray(pos, 256);
            if (len > maxLen) maxLen = len;
            len = 0;
        }
        else {
            pos[s[i]] = i; /* the char not repeat, remember its pos */
            len++;
        }
    }
    if (len > maxLen) maxLen = len;
    return maxLen;
}


/**
 * simpler version
 */
 int lengthOfLongestSubstring(char* s) {
    int pos[256];
    int i;
    
    if (!s) return 0;
    for (i = 0; i < 256; i++) 
        pos[i] = -1;
    int n = strlen(s);
    int index = -1; /* keep the start of substring minus 1 */
    int maxLen = 0;
    for (i = 0; i < n; i++) {
        if (pos[s[i]] > index) {
            index = pos[s[i]];
        }
        if (i - index > maxLen)
            maxLen = i - index;
        pos[s[i]] = i;
    }
    return maxLen;
}