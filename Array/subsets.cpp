/**
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
/**
 * using iteration
 * Each time we copy existed subsets, then add a new element to each of these cloned subsets.
 * Example: {1, 2, 3}
 * 1) res = {[]}
 * 2) res = {[], [1]}, copy a [], then add 1 to [] ---> {[], [1]} 
 * 3) res = {[], [1]} ---> {[], [1]} + {[2], [1, 2]}
 * 4) res = {[], [1], [2], [1, 2]}  ---> {[], [1], [2], [1, 2]} + {[3], [1, 3], [2, 3], [1, 2, 3]}
 * ...
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        vector<int> tmp;
        
        res.push_back(tmp); /* empty set */
        for (vector<int>::iterator ite = nums.begin(); ite != nums.end(); ite++) { /* each time add a new element */
            int size = res.size();
            for (int i = 0; i < size; i++) {
                res.push_back(res[i]); /* clone existed subset */
                res.back().push_back(*ite); /* add the new element */
            }
	    if (res.size() == res.back().size()) {
	    	res.push_back(*it);
	    }
        }
        return res;
    }
};




/**
 * DFS, for each element, we choose for left subtree, and not choose for right subtree
   Example: {1, 2}, $ means null
               $
            /    \
          1        $
        /   \    /   \
      1,2    1  2     $
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        
        dfs(nums, 0, tmp);
        return res;
    }
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int path, std::vector<int>& tmp) {
        if (path == nums.size()) {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(nums[path]);
        dfs(nums, path+1, tmp);
        tmp.pop_back();
        dfs(nums, path+1, tmp);
    }
};



/**
 * using bitmap, use a unsigned long long integer (total 64 bits), each bit 
 * represents an element in the set. 1 means the element is placed in the set,
 * and 0 means not. 
 * Now let's increse the integer from 0 to 0xff...fff (total bits equal to # of elements
 * in set), then each value of integer is a subset.
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        unsigned long long bitmap = 0;
        std::vector<int> v;
        vector<vector<int>> res;
        int size = 0;
        unsigned long long max = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            max |= (1 << i);
        }
        
        for (bitmap = 0; bitmap != max; bitmap++) {
            v.clear();
            for (int i = 0; i < nums.size(); i++) {
                if (bitmap & (1 << i)) {
                    v.push_back(nums[i]);
                }
            }
            res.push_back(v);
        }
        res.push_back(nums);
        return res;
    }
};
