//https://www.youtube.com/watch?v=5Z9dn2WTg9o
void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp) {
    if (l + 1 >= r) {
        return;
    }
    // divide
    int m = l + (r - l) / 2;
    merge_sort(nums, l, m, temp);
    merge_sort(nums, m, r, temp);
    // conquer
    // Initialize pointers p (to the start of the left half), q (to the start of the right half), and i (to the start of the temp array for merging).
    // Merge the two halves into the temp array:
    // If the right half is exhausted (q >= r), or the current element in the left half is less than or equal to the current element in the right half (nums[p] <= nums[q]), copy the element from the left half (nums[p]) to temp[i] and increment p.
    // Otherwise, copy the element from the right half (nums[q]) to temp[i] and increment q.
    // Continue this process until both halves are fully merged into temp.
    int p = l, q = m, i = l;
    while (p < m || q < r) {
        if (q >= r || (p < m && nums[p] <= nums[q])) {
            temp[i++] = nums[p++];
        } else {
            temp[i++] = nums[q++];
        }
    }
    for (i = l; i < r; ++i) {
        nums[i] = temp[i];
    }
}

// Consider merging two sorted subarrays from the array [38, 27, 43, 3, 9, 82, 10]:

// Let's merge [3, 27, 38, 43] and [9, 10, 82].

// Initial state:

// p = l = 0
// q = m = 4
// i = l = 0
// left subarray = [3, 27, 38, 43]
// right subarray = [9, 10, 82]
// Step-by-Step:
// First Iteration:

// p = 0, q = 4, i = 0
// Compare nums[p] (3) with nums[q] (9).
// Since 3 <= 9, copy 3 to temp[0].
// Increment p and i.
// Second Iteration:

// p = 1, q = 4, i = 1
// Compare nums[p] (27) with nums[q] (9).
// Since 9 < 27, copy 9 to temp[1].
// Increment q and i.
// Third Iteration:

// p = 1, q = 5, i = 2
// Compare nums[p] (27) with nums[q] (10).
// Since 10 < 27, copy 10 to temp[2].
// Increment q and i.
// Fourth Iteration:

// p = 1, q = 6, i = 3
// Compare nums[p] (27) with nums[q] (82).
// Since 27 <= 82, copy 27 to temp[3].
// Increment p and i.
// Fifth Iteration:

// p = 2, q = 6, i = 4
// Compare nums[p] (38) with nums[q] (82).
// Since 38 <= 82, copy 38 to temp[4].
// Increment p and i.
// Sixth Iteration:

// p = 3, q = 6, i = 5
// Compare nums[p] (43) with nums[q] (82).
// Since 43 <= 82, copy 43 to temp[5].
// Increment p and i.
// Seventh Iteration:

// p = 4, q = 6, i = 6
// Since p >= m (left subarray exhausted), copy nums[q] (82) to temp[6].
// Increment q and i.