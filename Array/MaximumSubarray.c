/**
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

/**
 * method 1: brute force, ugly, O(n*n), not passed, Time limit
 */
int maxSubArray(int* nums, int numsSize) {
    int i, j;
    int maxSum = nums[0];


    if (nums == NULL || numsSize ==0) return 0;
    for (i = 0; i < numsSize; i++) {
        int max = 0;
        for (j = i; j < numsSize; j++) {
            max += nums[j];
            if (max > maxSum)
                maxSum = max;
        }
    } 
    return maxSum;  
}

/**
 * method 2: divide and conquer.
 * 将数组从middle处分为两部分，最大字串要么在前半部分，要么在后半部分
 * 要么在中间部分，中间部分由两部分组成：前半部分必须包括middle,后半
 * 部分必须包括middle+1
 * 此方法有个优点是还能得到字串的位置信息
 * Time: O(nlogn)
 * 
 */
int max3(int a, int b, int c)
{
    if (a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}

int maxSubArrayRecur(int *array, int start, int end)
{
    int mid;
    int sumLeft, sumRight, sumMid;

    if (start == end) return array[start];

    mid = start + (end - start) / 2;
    sumLeft = maxSubArrayRecur(array, start, mid);
    sumRight = maxSubArrayRecur(array, mid+1, end);

    int i;
    int sum = 0;
    sumMid = array[mid];
    for (i = mid; i >= start; i--) {
        sum += array[i];
        if (sum > sumMid)
            sumMid = sum;
    }
    sum = sumMid;
    for (i = mid+1; i <= end; i++) {
        sum += array[i];
        if (sum > sumMid)
            sumMid = sum;
    }
    return max3(sumLeft, sumMid, sumRight);
}



 int maxSubArray(int *nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return NULL;

    return maxSubArrayRecur(nums, 0, numsSize-1);
 }


/**
 * method 3: 最快的算法，缺点就是不能得到字串的位置信息
 */
int maxSubArray(int *nums, int numsSize) {
    int maxSum = nums[0];

    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum > maxSum)
            maxSum = sum;
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}