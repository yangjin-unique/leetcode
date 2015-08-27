/**
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
#define MAX_NUM_CHILDS		26

struct TrieNode {
    char ch;
    int val;
    struct TrieNode *child[MAX_NUM_CHILDS];
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct TrieNode *root;

    root = malloc(sizeof(*root));
    memset(root, 0, sizeof(*root));
    root->ch = '.'; /* root value */
    return root;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
	int i;

    for (i = 0; i < MAX_NUM_CHILDS; i++) {
    	if (root->child[i] && root->child[i]->ch == *word)
    		break;
    }
    if (i != MAX_NUM_CHILDS) {
    	if (*word != '\0') 
    		insert(root->child[i], word+1);
    }
    else {
    	for (i = 0; i < MAX_NUM_CHILDS; i++) {
    		if (!root->child[i])
    			break;
    	}
    	root->child[i] = malloc(sizeof(struct TrieNode));
    	if (root->child[i] == NULL) {
    		printf("malloc failed\n");
    		return;
    	}
    	memset(root->child[i], 0, sizeof(struct TrieNode));
    	root->child[i]->ch = *word;
    	if (*word != '\0')
    		insert(root->child[i], word+1);
    }
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    int i;

    if (!word) return false;

    for (i = 0; i < MAX_NUM_CHILDS; i++) {
    	if (root->child[i] && root->child[i]->ch == *word) {
    		if (*word == '\0')
    			return true;
    		else
    			return search(root->child[i], word+1);
    	}
    }
    return false;
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    int i;

    if (!prefix || *prefix == '\0') return true;
    for (i = 0; i < MAX_NUM_CHILDS; i++) {
    	if (root->child[i] && root->child[i]->ch == *prefix) {
    		if (*(prefix+1) == '\0')
    			return true;
    		else
    			return startsWith(root->child[i], prefix+1);
    	}
    }
    return false;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    int i;

    if (!root) return;
    for (i = 0; i < MAX_NUM_CHILDS; i++) {
    	if (root->child[i]) {
    		trieFree(root->child[i]);
    	}
    }
    free(root);
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);