/**
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/


/* use hash table and double linked list */
typedef struct cache_elem_s {
	int key;
	int value; 
	struct cache_elem_s *prev;
	struct cache_elem_s *next;
	struct cache_elem_s *hlist;
} cache_elem_t;

#define HASH_SIZE	1024	

typedef struct cache_s {
	cache_elem_t head;
	cache_elem_t *htbl[HASH_SIZE];
	int capacity;
	int count;
} cache_t;

cache_t g_cache_list;
#if 0
{
	.head = {0, 0, &g_cache_list.head, &g_cache_list.head, NULL},
	.capacity = 0,
	.count = 0,
};
#endif

int hashKey(int val) {
	return (val % HASH_SIZE);
}

void htbl_add(cache_elem_t *elem) {
	int idx;
	cache_elem_t *cur;

	idx = hashKey(elem->key);
	if (g_cache_list.htbl[idx] == NULL) {
		g_cache_list.htbl[idx] = elem;
	}
	else {
		cur = g_cache_list.htbl[idx];
		elem->hlist = g_cache_list.htbl[idx];
		g_cache_list.htbl[idx] = elem;
	}
	return;
}

cache_elem_t* htbl_find(int key, bool del)
{
	int idx;

	idx = hashKey(key);
	cache_elem_t *hnode = g_cache_list.htbl[idx], *prev;
	while (hnode != NULL) {
		if (hnode->key == key) {
			if (del) {
				if (hnode == g_cache_list.htbl[idx])
					g_cache_list.htbl[idx] = hnode->hlist;
				else {
					prev->hlist = hnode->hlist;
				}
			}
			return hnode;
		}
		prev = hnode;
		hnode = hnode->hlist;
	}
	return NULL;
} 


void lruCacheInit(int capacity) {
    g_cache_list.head.key = 0;
    g_cache_list.head.value = 0;
    g_cache_list.head.prev = &g_cache_list.head;
    g_cache_list.head.next = &g_cache_list.head;
    g_cache_list.head.hlist = NULL;
    g_cache_list.capacity = capacity;
    g_cache_list.count = 0;
}

void lruCacheFree() {
    cache_elem_t *elem = g_cache_list.head.next, *prev;

    while (elem != &g_cache_list.head) {
    	prev = elem;
    	elem = elem->next;
    	free(prev);
    	prev = NULL;
    }
    memset(&g_cache_list, 0, sizeof(g_cache_list));
}

/* double linked list */
void list_add_tail(cache_elem_t *head, cache_elem_t *elem) {
	elem->next = head;
    elem->prev = head->prev;
    elem->prev->next = elem;
    head->prev = elem;
}

void list_del(cache_elem_t *elem) {
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
    elem->prev = NULL;
    elem->next = NULL;
}

/**
 * put elem being accessed (get/add/change) recently to tail of list;
 * so the head of list is for eviction
 */
int lruCacheGet(int key) {
	cache_elem_t *elem, *prev, *cur;
	int value = -1;

    elem = htbl_find(key, 0);
    if (!elem)
    	return -1;
    /* delete elem */
    list_del(elem);
    /* insert elem to tail, e.g. previous pos of head */
    list_add_tail(&g_cache_list.head, elem);
    return elem->value;
}
    
void lruCacheSet(int key, int value) {
	int v = lruCacheGet(key);
	cache_elem_t *elem, *cur;

	if (v == -1) {
		/* no such key, add new one */
		
		if (g_cache_list.count < g_cache_list.capacity) {
			/* append to cache list */
			elem = (cache_elem_t *) malloc(sizeof(cache_elem_t));
            memset(elem, 0, sizeof(cache_elem_t));
			elem->key = key;
			elem->value = value;
			/* insert elem into tail */
			list_add_tail(&g_cache_list.head, elem);
			htbl_add(elem);		
			g_cache_list.count++;
		}
		else {
			/* cache full, evict the head of cache list */
			elem = g_cache_list.head.next;
			list_del(elem);
			htbl_find(elem->key, 1);
			elem->key = key;
			elem->value = value;
            elem->hlist = NULL;
			list_add_tail(&g_cache_list.head, elem);
			htbl_add(elem);
		}
	}
	else {
		if (v == value)
			return; /* key existed, and not change, lruCacheGet already updates cache list */
		/* key existed, but value changed, so update value 
		 * since lruCacheGet called before would move this elem to tail of list,
		 * so the tail of list is the elem to be updated
		*/
		elem = g_cache_list.head.prev;
		elem->value = value;
	}
}



/***********************************************************************/
/**
 * Method 2: using doule linked list and stl unordered_map
 */
typedef struct CacheElem {
    struct CacheElem *prev;
    struct CacheElem *next;
    int key;
    int value;
}CacheElem_t;

class LRUCache {
    CacheElem_t head;
    int capacity;
    int count;
    unordered_map<int, CacheElem_t *> cache_map;
public:
    LRUCache(int capacity): capacity(capacity), count(0) {
        head.prev = head.next = &head;
        head.key = head.value = -1;
    }

    int getCount() {return count; }

    int get(int key) {
        CacheElem_t *elem = NULL;
        unordered_map<int, CacheElem_t*>::iterator got = cache_map.find(key); 
        if (got != cache_map.end()) {
            elem = got->second;
            list_del(elem);
            list_add_tail(&head, elem);
            return elem->value;
        }
        return -1;
    }

    void set(int key, int value) {
        CacheElem_t *elem = NULL;
        pair<int, CacheElem_t*> m(-1, NULL);
        unordered_map<int, CacheElem_t*>::const_iterator got;

        got = cache_map.find(key);
        if (got == cache_map.end()) {
            /* not found */
            if (count >= capacity) {
                /* cache full, so select the head of list as the eviction */
                elem = head.next;
                cache_map.erase(elem->key); /* remove the evicted and deleted key */
                elem->key = key;
                elem->value = value;
                if (elem != head.prev) {
                    list_del(elem);
                    list_add_tail(&head, elem);
                }
            }
            else {
                /* cache not full, alloc a new one */
                elem = new CacheElem_t;
                elem->key = key;
                elem->value = value;
                list_add_tail(&head, elem);
                count++;
            }
            assert(elem);
            /* add the new key map to cache_map */
            m.first = key;
            m.second = elem;
            cache_map.insert(m);
        }
        else {
            /* found one, then update it, and move it to tail of list */ 
            elem = got->second;
            elem->value = value;
            if (elem != head.prev) {
                /* elem not in tail, move elem to tail of list */
                assert(elem);
                list_del(elem);
                list_add_tail(&head, elem);
            }
        }
    }
    /* double linked list */
    void list_add_tail(CacheElem_t *head, CacheElem_t *elem) {
	    elem->next = head;
        elem->prev = head->prev;
        elem->prev->next = elem;
        head->prev = elem;
    }

    void list_del(CacheElem_t *elem) {
	    elem->prev->next = elem->next;
	    elem->next->prev = elem->prev;
        elem->prev = NULL;
        elem->next = NULL;
    }

};
