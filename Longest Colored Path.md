## 01. Longest Colored Path

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-colored-path--151454/1)

### Problem Description

**Task:** Given an undirected acyclic graph (tree) with n nodes numbered from 1 to n. Each node is colored either Red (R) or Blue (B).The colors of the nodes are given by a string s of length n, where:s[i] = 'R' means node i + 1 is Red.s[i] = 'B' means node i + 1 is Blue.You are also given a list of n - 1 edges edges[][], where each edges[i] = [u, v] represents an undirected edge between nodes u and v.You can start from any node and traverse along the edges to form a path.A path is called valid if, once you visit a Blue node, you cannot visit any Red node after it on the same path.In other words, a valid path must have the following form:Only Red nodes, orOnly Blue nodes, orSome Red nodes followed by some Blue nodes.A path containing a pattern like Blue - > Red is invalid.Find the maximum number of nodes in a valid path.Examples:Input: s = "RBB", edges = [[1, 2], [1, 3]] Output: 2Explanation: The longest path is either 1 - > 2 or 1 - > 3. In both cases, the length of the path is 2.Input: s = "BB", edges = [[1, 2]]

#### Examples

##### Example 1

- **Output:**
```text
2Explanation: The longest path is 1 - > 2. The length of the path is 2.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-27 19:45:09
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
public:

    int longestPath(string& str, vector<vector<int>>& edges) {

        string s = str;
        int n = s.size();

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // -----------------------------
        // Build parent array + order
        // -----------------------------
        vector<int> parent(n, -1);
        vector<int> order;

        parent[0] = -2;
        order.push_back(0);

        for (int i = 0; i < (int)order.size(); i++) {

            int u = order[i];

            for (int v : adj[u]) {

                if (v == parent[u])
                    continue;

                parent[v] = u;
                order.push_back(v);
            }
        }

        vector<int> down(n, 1);
        vector<int> up(n, 1);

        int ans = 1;

        for (int i = n - 1; i >= 0; i--) {

            int u = order[i];

            int best1 = 0;
            int best2 = 0;

            for (int v : adj[u]) {

                if (parent[v] != u)
                    continue;

                // Same color only
                if (s[v] != s[u])
                    continue;

                int value = down[v];

                if (value > best1) {
                    best2 = best1;
                    best1 = value;
                }
                else if (value > best2) {
                    best2 = value;
                }
            }

            down[u] = 1 + best1;

            // Longest same-color path passing through u
            ans = max(ans, 1 + best1 + best2);
        }

        for (int u : order) {

            int best1 = 0;
            int best2 = 0;
            int bestChild = -1;

            // Find two best same-color children
            for (int v : adj[u]) {

                if (parent[v] != u)
                    continue;

                if (s[v] != s[u])
                    continue;

                int value = down[v];

                if (value > best1) {

                    best2 = best1;
                    best1 = value;
                    bestChild = v;
                }
                else if (value > best2) {

                    best2 = value;
                }
            }

            for (int v : adj[u]) {

                if (parent[v] != u)
                    continue;

                // Different color:
                // cannot continue a same-color path
                if (s[v] != s[u]) {

                    up[v] = 1;
                }

                else {

                    int bestSibling;

                    if (v == bestChild)
                        bestSibling = best2;
                    else
                        bestSibling = best1;

                    /*
                        Important:

                        v -> u -> sibling

                        contains BOTH u and sibling.

                        Therefore:
                        1 + max(up[u], 1 + bestSibling)
                    */

                    up[v] = 1 + max(up[u], 1 + bestSibling);
                }
            }
        }

        for (int u = 1; u < n; u++) {

            int p = parent[u];

            // Only consider R-B / B-R edges
            if (s[p] == s[u])
                continue;

            int sideParent = max(up[p], down[p]);
            int sideChild  = max(up[u], down[u]);

            ans = max(ans, sideParent + sideChild);
        }

        return ans;
    }
};
```

*Generated on: 9/27/2026, 7:45:27 PM*