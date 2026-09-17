## 01. Min Edge Reversals for Path

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-edges/1)

### Problem Description

**Task:** Given a directed graph with n vertices numbered from 1 to n. The graph is represented using a 2D array edges[][] of size m, where each entry edges[i] = [u, v] denotes a directed edge from vertex u to vertex v. You are also given a source vertex src and a destination vertex dst.Find the minimum number of edges that need to be reversed so that there exists at least one path from src to dst. If it is not possible to create a path from src to dst, return -1.Examples:Input: n = 3, edges[][] = [[1, 2], [3, 2]], src = 1, dst = 3 Output: 1

#### Examples

##### Example 1

- **Explanation:** One path already exists between 1 to 4 i.e. 1 - > 2 - > 3 - > 4.Constraints:1 ≤ n, m ≤ 10⁵¹ ≤ edges[i][0], edges[i][1] ≤ n1 ≤ src, dst ≤ n

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + m)
- **Expected Auxiliary Space Complexity:** O(n + m)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-17 23:16:47
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int minimumEdgeReversal( vector<vector<int>>& edges,int n , int src, int dst) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];


            adj[u].push_back({v, 0});

            adj[v].push_back({u, 1});
        }

        const int INF = 1e9;
        vector<int> dist(n + 1, INF);

        deque<int> dq;

        dist[src] = 0;
        dq.push_front(src);

        while (!dq.empty()) {

            int u = dq.front();
            dq.pop_front();

            for (auto &[v, cost] : adj[u]) {

                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;

                    if (cost == 0)
                        dq.push_front(v);
                    else
                        dq.push_back(v);
                }
            }
        }

        if (dist[dst] == INF)
            return -1;

        return dist[dst];
    }
};
```

*Generated on: 9/17/2026, 11:17:05 PM*