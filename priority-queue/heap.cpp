class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Initialize an empty list
        // By default, priority_queue in C++ is a max-heap, which means the largest element is always at the top (root).
        priority_queue<int> pq; // max_heap

        //priority_queue <Type, vector<Type>, ComparisonType > min_heap;
        priority_queue<int, vector<int>, greater<int>> minHeap; //  creates a min-heap. This means the smallest element is at the top.

        // Add first k elements to the list
        for (int i = 0; i < k; i++)
            minHeap.push(nums[i]);

        // Loop through the remaining elements in the 'nums' array
        for (int i = k; i < nums.size(); i++) {
            // Compare the current element with the minimum
            // element (root) of the min-heap
            if (nums[i] > minHeap.top()) {
                // Remove the smallest element
                minHeap.pop();
                // Add the current element
                minHeap.push(nums[i]);
            }
        }

        // The root of the heap has the Kth largest element
        return minHeap.top();
    }
};