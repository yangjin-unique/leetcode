/*
 *
 Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
 
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
        hist[*s]++;
        s++;
    }
    while (*t != '\0') {
        hist[*t]--;
        t++;
    }
    for (i = 0; i < 256; i++) {
        if (hist[i] != 0)
            return false;
    }
    return true;
}
