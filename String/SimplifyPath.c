/**
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

/**
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

char* simplifyPath(char* path) {
    int end = 0;
    int i = 0;

    if (path == NULL) return NULL;
    
    while (path[i] != '\0') {
    	path[end] = path[i];
    	if (path[i] == '/' && path[i+1] == '.' && (path[i+2] == '/' || path[i+2] == '\0')) {
    		if (path[i+2] == '\0') {
    			end++;
    			break;
    		}
    		i += 2;
    	}
    	else if (path[i] == '/' && path[i+1] == '.' && path[i+2] == '.' && (path[i+3] == '/' || path[i+3] == '\0')) {

    		if (end > 0) end--;
    		while (end > 0 && path[end] != '/') {
    			end--;
    		}
    		//end++;
    		i += 3;
    	}
    	else if (path[i] == '/' && path[i+1] == '/') {
    		i++;
    	}
    	else {
    		i++;
    		end++;
    	}
    }
    if (end >= 1)
    	path[end] = '\0';
    if (end > 1 && path[end-1] == '/') {
    	path[end-1] = '\0';
    }
    return path;
}