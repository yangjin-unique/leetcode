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

        }
        return res;
    }
};




/**
 * DFS, for each element, we choose for left subtree, and not choose for right subtree
   Example: {1, 2}
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
        int start = 0;
        
        dfs(nums, start, tmp);
        return res;
    }
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int start, std::vector<int>& tmp) {
        if (start == nums.size()) {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(nums[start]);
        dfs(nums, start+1, tmp);
        tmp.pop_back();
        dfs(nums, start+1, tmp);
    }
};