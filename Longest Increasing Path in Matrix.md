## 01. Longest Increasing Path in Matrix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-increasing-path-in-a-matrix/1)

### Problem Description

**Task:** Given a matrix with n rows and m columns, find the length of the longest path such that:The path can start and end at any cell.A cell cannot be visited more than once.The values in path are strictly increasing. From each cell, you can move left, right, up, or down. Diagonal moves and moves outside the matrix are not allowed.Examples:Input: n = 3, m = 3, matrix[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

#### Examples

##### Example 1

- **Output:**
```text
1
```
- **Explanation:** There can at most one vertex as all vertices are same.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n * m)
- **Expected Auxiliary Space Complexity:** O(n * m)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-06 18:55:52
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
public:

    int n, m;

    int dfs(int i, int j,
            vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Current cell itself
        int ans = 1;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {

            int ni = i + dr[k];
            int nj = j + dc[k];

            // Check boundaries
            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < m) {

                // Move only to a greater value
                if (matrix[ni][nj] > matrix[i][j]) {

                    ans = max(ans,
                              1 + dfs(ni, nj, matrix, dp));
                }
            }
        }

        dp[i][j] = ans;

        return dp[i][j];
    }

    int longIncPath(vector<vector<int>>& matrix, int n, int m) {

        // Set class variables
        this->n = n;
        this->m = m;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                answer = max(answer,
                             dfs(i, j, matrix, dp));
            }
        }

        return answer;
    }
};
```

*Generated on: 10/6/2026, 6:56:04 PM*