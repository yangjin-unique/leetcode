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
        
        res.push_back(tmp);
        for (vector<int>::iterator ite = nums.begin(); ite != nums.end(); ite++) {
        	int size = res.size();
        	for (int i = 0; i < size; i++) {
        		std::vector<int> v;
        		for(vector<int>::iterator j = res[i].begin(); j != res[i].end(); j++) {
        			v.push_back(*j);
        		}
        		v.push_back(*ite);
        		res.push_back(v);
        	}

        }
        return res;
    }
};