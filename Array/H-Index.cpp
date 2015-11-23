/**
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/

/**
 * use sort in decreasing order
 */
bool compare(int i, int j) {
    return i > j;
}

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int hIdx = 0;
        vector<int>::const_iterator ite;

        sort(citations.begin(), citations.end(), compare);
        for (ite = citations.begin(); ite != citations.end(); ite++) {
        	if (*ite >= hIdx+1) 
        		hIdx++;
        	else
        		break;
        }
        return hIdx;
    }
};