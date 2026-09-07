## 01. Minimum Elements Outside Subsequences

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-number-of-elements-which-are-not-part-of-increasing-or-decreasing-subsequence2617/1)

### Problem Description

**Task:** Given an array arr[] of size n, partition its elements into a strictly increasing subsequence and a strictly decreasing subsequence.
Each element can belong to at most one of these subsequences, and some elements may remain unused.
Determine the minimum number of elements that cannot be included in either subsequence.

#### Examples

##### Example 1

- **Input:**
```text
arr[] = [7, 8, 1, 2, 4, 6, 3, 5, 2, 1, 8, 7]
```
- **Output:**
```text
2
```
- **Explanation:** One possible increasing subsequence is: [1, 2, 4, 5, 8]. One possible decreasing subsequence is: [7, 6, 3, 2, 1]. The remaining elements are 8 and 7, so the minimum number of unselected elements is 2.

##### Example 2

- **Input:**
```text
arr[] = [1, 4, 2, 3, 3, 2, 4]
```
- **Output:**
```text
0
```
- **Explanation:** One possible increasing subsequence is: [1, 2, 3, 4]. One possible decreasing subsequence is: [4, 3, 2]. All elements are included in one of the two subsequences.

#### Constraints

- **1.** `1 ≤ n ≤ 1001 ≤ arr[i] ≤ 100`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^3)
- **Expected Auxiliary Space Complexity:** O(n^3)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-07 23:04:32
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
public:
    int minCount(vector<int>& arr) {
        int n = arr.size();

        // dp[i][j] = maximum selected elements
        // i = last index of increasing subsequence
        // j = last index of decreasing subsequence
        //
        // n is used as a dummy index meaning "empty"
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Both subsequences are initially empty
        dp[n][n] = 0;

        for (int k = 0; k < n; k++) {

            vector<vector<int>> next = dp;

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {

                    if (dp[i][j] == -1)
                        continue;

                    int curr = dp[i][j];

                    // 1. Put arr[k] in increasing subsequence
                    if (i == n || arr[k] > arr[i]) {
                        next[k][j] = max(next[k][j], curr + 1);
                    }

                    // 2. Put arr[k] in decreasing subsequence
                    if (j == n || arr[k] < arr[j]) {
                        next[i][k] = max(next[i][k], curr + 1);
                    }

                    // 3. Don't use arr[k]
                    next[i][j] = max(next[i][j], curr);
                }
            }

            dp = next;
        }

        int maximumUsed = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                maximumUsed = max(maximumUsed, dp[i][j]);
            }
        }

        return n - maximumUsed;
    }
};
```

*Generated on: 9/7/2026, 11:05:48 PM*