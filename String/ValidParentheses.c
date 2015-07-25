/**
 *Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * */

bool isLeftPa(char s) {
    return (s == '(') || (s == '{') || (s == '[');
}

bool isRightPa(char s) {
    return (s == ')') || (s == '}') || (s == ']');
}

bool isMatch(char s1, char s2) {
    switch (s1) {
    case '{':
        return s2 == '}';
    case '(':
        return s2 == ')';
    case '[':
        return s2 == ']';
    }
    return 0;
} 


bool isValid(char* s) {
    char *stack;
    int top = 0;
    int len;
    
    if (s == NULL) return 1;
    len = strlen(s);
    stack = (char *) malloc(len * sizeof(char));
    while (*s != '\0') {
        if (isLeftPa(*s)) {
            stack[top++] = *s;
        }
        if (isRightPa(*s)) {
            if (top <= 0 || !isMatch(stack[--top], *s)) {
                free(stack);
                return 0;
            }
        }
        s++;
    }
    if (top != 0) return 0;
    return 1;
}
