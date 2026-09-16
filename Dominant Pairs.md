## 01. Dominant Pairs

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/dominant-pairs/1)

### Problem Description

**Task:** Given an even-sized integer array arr[], count the number of dominant pairs. A pair of indices (i, j) is called dominant if all of the following conditions hold:0 ≤ i < arr.size() / 2arr.size() / 2 ≤ j < arr.size() arr[i] ≥ 5 × arr[j] Return the total number of dominant pairs. Note: 0-based indexing is used.Examples:Input: arr[] = [10, 2, 2, 1]

#### Examples

##### Example 1

- **Output:**
```text
5
```
- **Explanation:** First half: [10, 8, 2], Second half: [1, 1, 2]. So valid five pairs are: {0, 3}: 10 >= 5 × 1{0, 4}: 10 >= 5 × 1 {0, 5}: 10 >= 5 × 2{1, 3}: 8 >= 5 × 1 {1, 4}: 8 >= 5 × 1

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-16 18:00:13
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
public:
    int dominantPairs(vector<int>& arr) {
        int n = arr.size();
        int mid = n / 2;

        vector<int> second(arr.begin() + mid, arr.end());
        sort(second.begin(), second.end());

        int ans = 0;

        for (int i = 0; i < mid; i++) {
            long long x = arr[i];

            int l = 0, r = second.size();

            while (l < r) {
                int m = l + (r - l) / 2;

                if (5LL * second[m] <= x)
                    l = m + 1;
                else
                    r = m;
            }

            ans += l;
        }

        return ans;
    }
};
```

*Generated on: 9/16/2026, 6:00:43 PM*