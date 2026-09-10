## 01. Longest Subsequence with Adjacent Diff as 1

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-sub-sequence-such-that-difference-between-adjacents-is-one2558/1)

### Problem Description

**Task:** Given an array arr[] with n elements. find the longest subsequence such that the absolute difference between adjacent elements is one.

#### Examples

##### Example 1

- **Input:**
```text
arr[] = [10, 9, 4, 5, 4, 8, 6]
```
- **Output:**
```text
3
```
- **Explanation:** Longest subsequences with difference 1 are [10, 9, 8], [4, 5, 4] and [4, 5, 6].

##### Example 2

- **Input:**
```text
arr[] = [1, 2, 3, 2, 3, 7, 2, 1]
```
- **Output:**
```text
7Explanation: Longest subsequences with difference 1 is [1, 2, 3, 2, 3, 2, 1].
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-10 22:46:42
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int longestSubseq(vector<int>& arr) {
        int maxi = 1;

        vector<int> dp(1000002, 0);

        for (int x : arr) {
            dp[x] = 1 + max(dp[x - 1], dp[x + 1]);
            maxi = max(maxi, dp[x]);
        }

        return maxi;
    }
};
```

*Generated on: 9/10/2026, 10:47:26 PM*