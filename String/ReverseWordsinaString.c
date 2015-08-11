/**
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/
/**
 method 1: from end of str, copy word by word to new buffer;
 Time: o(n) Space: o(n)
 */
void reverseWords(char *s) {
    char *p;
    char *ns, *np;

    if (s == NULL) return;
    p = s + strlen(s) - 1;
    ns = (char *) malloc(strlen(s) + 1);
    memset(ns, 0, strlen(s)+1);
    np = ns;
    while (p >= s) {
        int len = 0;
        while (p >= s && *p == ' ') {p--;}
        while (p >= s && *p != ' ') {p--; len++;}
        if (len > 0) {
            memcpy(np, p+1, len);
            np += len;
            *np = ' ';
            np++;
        }
    }
    *(--np) = '\0';
    strcpy(s, ns);
    free(ns);
    return;
}


/**
 method 2: use o(1) space.
 first, delete redunt space;
 then, reverse each word: abc de --> cba ed;
 finally, reverse whole string: cba ed --> de abc
 */
void rev(char *start, char *end)
 {
    while (start < end) {
        *start = *start ^ *end;
        *end = *start ^ *end;
        *start = *start ^ *end;
        start++;
        end--;
    }
 }

 void trim(char *str)
 {
    char *prev = str, *p = str;

    /* remove redunt space */
    while (*p != '\0') {
        while (*p == ' ' && *(p+1) == ' ') p++; /* skip continuous space */
        if (prev == str && *p == ' ') p++; /* remove a (only one) leading space */
        *prev++ = *p++;
    }
    *prev = '\0';
    if (prev != str && *(prev-1) == ' ') *(prev-1) = '\0'; /* remove a (only one) trailing space */
 }


void reverseWords(char *s)
{
    char *start, *end;
    
    if (s == NULL || *s == '\0') return;
    trim(s);
    if (*s == '\0') return;
    start = end = s;
    while (*end != '\0') {
        if (*end == ' ') {
            rev(start, end-1);
            start = end + 1;
        }
        end++;
    }
    rev(start, end-1); /* reverse last word */
    rev(s, end-1); /* reverse whold string */
}