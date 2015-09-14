/**
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
*/

int strStr(char* haystack, char* needle) {
    int dl = strlen(haystack);
    int sl = strlen(needle);
	char *dest = haystack;
	int found = 0;

	if (haystack == NULL || needle == NULL) return -1;

	while (dl >= sl) {
		dl--;
		if (memcmp(dest, needle, sl) == 0) {
			found = 1;
			break;
		}
		dest++;
	}  
	if (!found) return -1;
	return (dest - haystack);
}