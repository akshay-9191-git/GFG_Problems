## 01. Largest Sum Cycle

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-sum-cycle--170645/1)

### Problem Description

**Task:** Given an array edge[] of size n, there are n cells numbered from 0 to n - 1. Each cell has at most one outgoing edge.For every cell i:edge[i] is the cell reached from i in one step.edge[i] = -1 means that cell i has no outgoing edge.A cycle is a sequence of cells where, by following the outgoing edges, we eventually return to the starting cell. The sum of a cycle is the sum of the indices of all cells in that cycle.Return the maximum cycle sum. If there is no cycle, return -1.Examples:Input: edge[] = [1, 2, 0, -1]Output: 3Explanation: There is only one cycle in the graph i.e. 0 - > 1 - > 2 - > 0. Sum of the cell index in that cycle = 0 + 1 + 2 = 3.Input: edge[] = [2, 0, -1, 2]Output: -1Explanation: There is no cycle in the graph. The edges are 1 - > 0 - > 2 < - 3. Hence, 2 has no outgoing edge, so no cycle exists.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-02 12:22:30
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
  public:
  int ans;
  
  void dfs(vector<int>& edge , vector<int>& path ,
  vector<int>& vis , vector<int>& pathVis , int node){
      vis[node] = 1;
      pathVis[node] = 1;
      path.push_back(node);
      int child = edge[node];
      if(child != -1){
          if(!vis[child]){
              dfs(edge , path , vis , pathVis , child);
          }else if(pathVis[child]){
              int sum = 0;
              for(int i=path.size()-1;i>=0;i--){
                  sum += path[i];
                  if(path[i] == child){
                      break;
                  }
              }
              ans = max(ans , sum);
          }
      }
      pathVis[node] = 0;
      path.pop_back();
  }
    int largestSumCycle(vector<int>& edge) {
        // code here
        int n = edge.size();
        vector<int> vis(n , 0);
        vector<int> pathVis(n,0);
        ans = -1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> path;
                dfs(edge , path , vis , pathVis , i);
            }
        }
        return ans;
    }
};
```

*Generated on: 11/2/2026, 7:27:29 PM*