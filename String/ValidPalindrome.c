/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome
*/
/**
 * method 1
 */
#define DIFF ('a' - 'A')

bool isPalindrome(char* s) {
    char *p1, *p2;

    if (s == NULL) return 1;
    p1 = s;
    p2 = s + strlen(s) - 1;
    while (p1 < p2) {
    	while (p1 < p2 && !isalnum(*p1)) {p1++;}
    	while (p1 < p2 && !isalnum(*p2)) {p2--;}
    	if (!(*p1 == *p2 || *p1 == (*p2 + DIFF) || *p1 == (*p2 - DIFF))) {
    		return 0;
    	}
    	p1++; p2--;
    }
    return 1;
}

/**
 * method 2
 */

bool isPalindrome(char* s) {
    char *p1, *p2;

    if (s == NULL) return 1;
    p1 = s;
    p2 = s + strlen(s) - 1;
    while (p1 < p2) {
    	while (p1 < p2 && !isalnum(*p1)) {p1++;}
    	while (p1 < p2 && !isalnum(*p2)) {p2--;}
    	if (tolower(*p1) != tolower(*p2)) {
    		return 0;
    	}
    	p1++; p2--;
    }
    return 1;
}

