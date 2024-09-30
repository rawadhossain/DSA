#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void minHeapify(vector<int> &nums, int N, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && nums[left] < nums[smallest])
    {
        smallest = left;
    }

    if (right < N && nums[right] < nums[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(nums[i], nums[smallest]);
        minHeapify(nums, N, smallest);
    }
}

void buildMinHeap(vector<int> &nums)
{
    int N = nums.size();
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        minHeapify(nums, N, i);
    }
}