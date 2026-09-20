## 01. Largest Subsquare Surrounded by X

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1)

### Problem Description

**Task:** Given a square matrix mat[][] of size n × n, where each cell contains either 'X' or 'O'. Find the size of the largest square submatrix whose boundary is completely surrounded by 'X'. The cells inside the submatrix can contain either 'X' or 'O'. Only the four sides of the submatrix must contain 'X'.Return side length of the largest such square submatrix. Note: A square of size 1 is valid if its only cell is 'X'. If no such square submatrix exists, return 0.Examples:Input: mat[][] = [[X,X,X,O],[X,O,X,X],[X,X,X,O],[X,O,X,X]] Output: 3

#### Examples

##### Example 1

- **Explanation:** Here, the input represents following matrix of size 4 x 4 The square submatrix starting at (0,0) and ending at (2,2) is the largest submatrix surrounded by X. Therefore, size of that matrix would be 3.Input: mat[][] = [[X,X],[X,X]] Output: 2Explanation: The largest square submatrix surrounded by X is the whole input matrix.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^3)
- **Expected Auxiliary Space Complexity:** O(n^2)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-20 15:13:19
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int largestSubsquare(vector<vector<char>>& mat) {
        int n = mat.size();

        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (mat[i][j] == 'X') {
                    right[i][j] = 1;
                    down[i][j] = 1;

                    if (j + 1 < n)
                        right[i][j] += right[i][j + 1];

                    if (i + 1 < n)
                        down[i][j] += down[i + 1][j];
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int len = min(right[i][j], down[i][j]);

                while (len > ans) {
                    int bottom = i + len - 1;
                    int rightCol = j + len - 1;

                    if (bottom < n && rightCol < n &&
                        right[bottom][j] >= len &&
                        down[i][rightCol] >= len) {

                        ans = len;
                        break;
                    }

                    len--;
                }
            }
        }

        return ans;
    }
};
```

*Generated on: 9/20/2026, 3:13:36 PM*