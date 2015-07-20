/**
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/
#define MAX		2147483647
#define MIN		-2147483648

int myAtoi(char* str) {
	int neg = 0;
	char *p = str;
	long res = 0;

	while (*p == ' ') {p++;}
	if (*p == '-') {
		neg = 1;
		p++;
	}
	else if (*p == '+') {
	    p++;
	}
	
	while (*p != '\0' && *p >= '0' && *p <= '9') {
		res = res*10 + (*p - '0');
		if (!neg && res > MAX) return MAX;
		if (neg && -res <  MIN) return MIN;
		p++;
	}
	
	if (neg) return -res;
	
	return res;
}