## 01. Visit Leaves with Budget

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/leaf-under-budget/1)

### Problem Description

**Task:** Given a binary tree and an integer k, where you start from the root at level 1. The cost of visiting a leaf node is equal to the level of that leaf node. You can visit any number of leaf nodes, but the total cost of visiting them must not exceed k. Return the maximum number of leaf nodes that can be visited within the given budget.Examples:Input: root[] = [10, 8, 2, 3, N, 3, 6, N, N, N, 4], k = 8

#### Examples

##### Example 1

- **Output:**
```text
2 Cost For visiting Leaf Node 3: 3 Cost For visiting Leaf Node 4: 4 Cost For visiting Leaf Node 6: 3 To maximize the number of visited leaves, choose the two cheapest leaves: Cost = 3 + 3 = 6 ≤ 8. Thus, the maximum number of leaf nodes that can be visited is 2.Input: root[] = [1, 2, 3, 4, 5, 6, 7], k = 5Output: 1Explanation: The leaf nodes are 4, 5, 6 and 7, and all are at level 3. Therefore, visiting each leaf costs 3. With a budget of 5, we can visit only one leaf because: 3 ≤ 5, but 3 + 3 > 5. Thus, the maximum number of leaf nodes that can be visited is 1.Input: root[] = [1], k = 1 Output: 1Explanation: The root node is also a leaf node and is at level 1. Therefore, its visiting cost is 1. Thus, the maximum number of leaf nodes that can be visited is 1.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-15 17:51:55
- **Status:** Correct
- **Marks:** 2

```cpp
/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  void dfs(Node* root , int level , vector<int>& cost){
      if(!root) return ;
      if(!root->left && !root->right){
          cost.push_back(level);
          return;
      }
      dfs(root->left , level+1 , cost);
      dfs(root->right , level+1 , cost);
  }
    int getCount(Node *root, int k) {
        // code here
        int ans = 0;
         vector<int> cost;
         dfs(root , 1 , cost);
         sort(cost.begin() , cost.end());
         for(int x:cost){
             if( k < x) break;
             k -= x;
             ans++;
         }
         return ans;
    }
};
```

*Generated on: 9/15/2026, 5:52:08 PM*