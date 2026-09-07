## 01. DFS of Graph

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)

### Problem Description

**Task:** Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.Note: Do traverse in the same order as they are in the given adjacency list.

#### Examples

##### Example 1

- **Input:**
```text
adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]Output: [0, 2, 4, 3, 1]Explanation: Starting from 0, the DFS traversal proceeds as follows:Visit 0 → Output: 0 Visit 2 (the first neighbor of 0) → Output: 0, 2 Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1
```

##### Example 2

- **Input:**
```text
adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
```
- **Output:**
```text
[0, 1, 2, 3, 4]
```
- **Explanation:** Starting from 0, the DFS traversal proceeds as follows: Visit 0 → Output: 0 Visit 1 (the first neighbor of 0) → Output: 0, 1 Visit 2 (the first neighbor of 1) → Output: 0, 1, 2 Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3 Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4

#### Constraints

- **1.** `1 ≤ V = adj.size() ≤ 10⁴⁰ ≤ adj[i][j] ≤ 10⁴^`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(V + E)
- **Expected Auxiliary Space Complexity:** O(V + E)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-07 22:21:10
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
    void helper(vector<vector<int>>& adj , vector<int>& ans , int s , vector<bool>& vis){
        vis[s] = true;
        ans.push_back(s);
        for(int x:adj[s]){
            if(!vis[x]){
                vis[x] = true;
                helper(adj , ans , x , vis);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<int> ans;
        vector<bool> vis(V , false);
        helper(adj , ans , 0 , vis);
        return ans;
    }
};
```

*Generated on: 9/7/2026, 10:26:11 PM*