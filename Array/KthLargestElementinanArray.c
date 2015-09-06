/**
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length

*/

/**
 * using quick sort
 */
void quickSort(int *nums, int start, int end)
{
	if (start < end) {
		int pivot = nums[start];
		int i = start;
		int j = end;
		while (i < j) {
			while (i < j && nums[j] >= pivot) {
				j--;
			}
			nums[i] = nums[j];
			while (i < j && nums[i] <= pivot) {
				i++;
			}
			nums[j] = nums[i];
		}
		nums[i] = pivot;
		quickSort(nums, start, i-1);
		quickSort(nums, i+1, end);
	}
}

int findKthLargest(int* nums, int numsSize, int k) {
	 quickSort(nums, 0, numsSize-1);
	 return nums[numsSize - k];
}


/**
 * using heap sort
 */
void  swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void heapfy(int *nums, int i, int numsSize)
{
	int r = 0;

	if (i < (numsSize>>2)) {
		if (nums[2*i+1] > nums[2*i+2])
			r = 2*i+1;
		else
			r = 2*i+2;
		if (nums[i] > nums[r]) {
			swap(nums+i, nums+r);
			heapfy(nums, r, numsSize);
		}
	}
}

void heapSort(int *nums, int numsSize) {
	int i;

	for (i = 0; i < (numsSize>>2); i++) {
		heapfy(nums, i, numsSize)
	}
}

int findKthLargest(int* nums, int numsSize, int k) {
	 heapSort(nums, 0, numsSize);
	 return nums[numsSize - k];
} 


/**
 * using merge sort
 */
void merge(int *nums, int *res, int start, int mid, int end) {
	int i, j, k;

	i = start; j = mid+1; k = start;
	while (i <= mid && j <= end) {
		if (nums[i] > nums[j]) 
			res[k++] = nums[j++];
		else
			res[k++] = nums[i++];
	}
	while (i <= mid)
		res[k++] = nums[i++];
	while (j <= end) {
		res[k++] = nums[j++];
	}
	for (i = start; i <= end; i++)
		nums[i] = res[i];
	return;
}

void mergeSort(int *nums, int *res, int start, int end) {
	int mid;

	if (start < end) {
		mid = start + (end - start) / 2;
		mergeSort(nums, res, start, mid);
		mergeSort(nums, res, mid+1, end);
		merge(nums, res, start, mid, end);
	}
	return;
}

int findKthLargest(int* nums, int numsSize, int k) {
	int *res;

	res = malloc(sizeof(int) * numsSize);
	mergeSort(nums, res, 0, numsSize-1);
	free(res);
	return nums[numsSize - k];
}