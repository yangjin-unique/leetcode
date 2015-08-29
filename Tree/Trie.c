/**
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#define MAX_NUM_CHILDS		26
#define KEY_TO_INDEX(c)     ((c) - 'a')

struct TrieNode {
    bool flag; /* mark it as it is end */
    struct TrieNode *child[MAX_NUM_CHILDS];
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct TrieNode *root;

    root = malloc(sizeof(*root));
    memset(root, 0, sizeof(*root));
    return root;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
    int index;

    if (*word != '\0') {
        index = KEY_TO_INDEX(*word);
        if (!root->child[index]) {
            root->child[index] = malloc(sizeof(struct TrieNode));
    	    if (root->child[index] == NULL) {
    		    printf("malloc failed\n");
    		    return;
    	        }
    	    memset(root->child[index], 0, sizeof(struct TrieNode));   
        }
        insert(root->child[index], word+1); 
    }
    else {
        root->flag = 1; /* mark it as end */
    }
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    int index;

    if (!word || !root) return false;
    if (*word == '\0' && root->flag)
        return true;
    index = KEY_TO_INDEX(*word);
    return search(root->child[index], word+1);
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    int index;

    if (!prefix || *prefix == '\0') return true;

    index = KEY_TO_INDEX(*prefix);
    if (!root->child[index]) return false;
    return startsWith(root->child[index], prefix+1);
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
//
