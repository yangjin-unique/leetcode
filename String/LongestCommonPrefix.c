/**
Write a function to find the longest common prefix string amongst an array of strings
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    int i, k;
    char *p = calloc(512, sizeof(char));

    if (strs == NULL || strsSize == 0) return p;
    if (strsSize == 1) return strs[0];

    int len = strlen(strs[0]);

    for (k = 0; k < len; k++) {
    	for (i = 1; i < strsSize; i++) {
    		if (strs[i][k] != strs[0][k])
    			break;
    	}
    }
   
   if (k != 0) {
   		memcpy(p, strs[0], k);
   		p[k] = 0;
   }
   return p;
}