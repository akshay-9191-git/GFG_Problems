## 01. Max Adjacent Diffs Sum with 1 Replacements

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/modify-array-to-maximize-sum-of-adjacent-differences1729/1)

### Problem Description

**Task:** Given an integer array arr[], you are allowed to replace any elements with 1. Find the maximum sum of absolute differences between consecutive elements after any number of modifications.

#### Examples

##### Example 1

- **Input:**
```text
arr[] = [3, 2, 1, 4, 5]
```
- **Output:**
```text
8
```
- **Explanation:** Modify the array as arr[] = [3, 1, 1, 4, 1]. Sum = |1-3| + |1-1| + |4-1| + |1-4| = 8, the maximum possible.

##### Example 2

- **Input:**
```text
arr[] = [1, 5]
```
- **Output:**
```text
4
```
- **Explanation:** No modification needed. Sum = |5-1| = 4.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-10 22:59:43
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();

        if (n == 1)
            return 0;

        long long keep = 0;
        long long one = 0;

        for (int i = 1; i < n; i++) {

            long long newKeep = max(
                keep + abs(arr[i - 1] - arr[i]),
                one + abs(1 - arr[i])
            );

            long long newOne = max(
                keep + abs(arr[i - 1] - 1),
                one
            );

            keep = newKeep;
            one = newOne;
        }

        return max(keep, one);
    }
};
```

*Generated on: 9/10/2026, 10:59:55 PM*