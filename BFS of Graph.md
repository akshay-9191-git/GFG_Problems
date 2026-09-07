## 01. BFS of Graph

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1)

### Problem Description

**Task:** Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i.
Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the graph.Note: Do traverse in the same order as they are in the given adjacency list.

#### Examples

##### Example 1

- **Input:**
```text
adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]Output: [0, 2, 3, 1, 4]Explanation: Starting from 0, the BFS traversal will follow these steps: Visit 0 → Output: 0 Visit 2 (first neighbor of 0) → Output: 0, 2 Visit 3 (next neighbor of 0) → Output: 0, 2, 3 Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 1Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4
```

##### Example 2

- **Input:**
```text
adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]Output: [0, 1, 2, 3, 4]Explanation: Starting from 0, the BFS traversal proceeds as follows: Visit 0 → Output: 0 Visit 1 (the first neighbor of 0) → Output: 0, 1 Visit 2 (the next neighbor of 0) → Output: 0, 1, 2 Visit 3 (the first neighbor of 2 that hasn't been visited yet) → Output: 0, 1, 2, 3 Visit 4 (the next neighbor of 2) → Final Output: 0, 1, 2, 3, 4
```

#### Constraints

- **1.** `1 ≤ V = adj.size() ≤ 10⁴⁰ ≤ adj[i][j] ≤ 10⁴`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(V + E)
- **Expected Auxiliary Space Complexity:** O(V + E)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-07 20:04:12
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> ans;
        int V = adj.size();
        queue<int> q;
        vector<bool> vis(V , false);
        q.push(0);
        vis[0] = true;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int x:adj[curr]){
                if(!vis[x]){
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
        return ans;
    }
};
```

*Generated on: 9/7/2026, 10:25:30 PM*