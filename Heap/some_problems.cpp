#include <iostream>
#include <vector>
#include <queue>
#include "Max_heap.h"

void convertMinToMaxHeap(vector<int> &arr, int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, N, i);
    }
}

int findKthLargest(vector<int> &nums, int k)
{
    buildMaxHeap(nums);
    int N = nums.size();
    for (int i = N - 1; i >= N - k + 1; i--)
    {
        swap(nums[0], nums[i]);
        maxHeapify(nums, i, 0);
    }
    return nums[0];
}

int kthSmallest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    while (pq.size() != n - k + 1)
        pq.pop();

    return pq.top();
}