## 01. Shortest Safe Route in Grid

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1)

### Problem Description

**Task:** Given a 2D matrix mat[][] of size n × m, where each cell is either 0 (landmine) or 1 (safe), find the minimum number of steps required to travel from any cell in the leftmost column to any cell in the rightmost column.You can move only in four directions: up, down, left, and right. A cell is unsafe if it contains a landmine or is directly adjacent (up, down, left, or right) to a landmine, and such cells must be avoided. Return -1 if no safe path exists.Examples:Input: mat[][] = [[1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 0, 1], [1, 1, 1, 1, 0]]Output: 6

#### Examples

##### Example 1

- **Explanation:** There is no possible path from first column to last column.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n * m)
- **Expected Auxiliary Space Complexity:** O(n * m)

### Accepted Solutions (2)

#### Solution 1 (C++)

- **Submitted:** 2026-09-15 17:37:34
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> unsafe(n, vector<int>(m, 0));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    unsafe[i][j] = 1;

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                            unsafe[ni][nj] = 1;
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            if (!unsafe[i][0]) {
                q.push({i, 0});
                dist[i][0] = 1;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (c == m - 1)
                return dist[r][c];

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    !unsafe[nr][nc] && dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-09-14 18:31:16
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> unsafe(n, vector<int>(m, 0));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    unsafe[i][j] = 1;

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                            unsafe[ni][nj] = 1;
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            if (!unsafe[i][0]) {
                q.push({i, 0});
                dist[i][0] = 1;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (c == m - 1)
                return dist[r][c];

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    !unsafe[nr][nc] && dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};
```

*Generated on: 9/15/2026, 5:37:46 PM*