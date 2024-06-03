#include <vector>
using namespace std;

class Solution {
    void swap(vector<int>& nums, int i, int l) {
        int temp = nums[i];
        nums[i] = nums[l];
        nums[l] = temp;
    }

    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int mid = l;
        for (int i = l; i < r; i++) {
            if (nums[i] < pivot) {
                swap(nums, i, mid);
                mid++;
            }
        }
        swap(nums, mid, r);
        return mid;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int r = nums.size() - 1, l = 0, mid;
        while (l < r) {
            mid = partition(nums, l, r);
            if (mid == k) return nums[mid];
            if (mid < k) l = mid + 1;
            else r = mid - 1;
        }
        return nums[l];
    }
};
