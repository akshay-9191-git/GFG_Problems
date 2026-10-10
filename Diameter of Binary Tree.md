## 01. Diameter of Binary Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1)

### Problem Description

**Task:** Given the root of a binary tree, find the diameter of the binary tree. The diameter of a binary tree is defined as the number of edges on the longest path between any two nodes. Note that this path may or may not pass through the root of the tree.Examples:Input: root = [1, 2, N, 3, 4]Output: 2Explanation: The longest path has 2 edges (node 3 - > node 2 - > node 4).Input: root = [5, 8, 6, 3, 7, 9, N]Output: 4Explanation: The longest path has 4 edges (node 3 - > node 8 - > node 5 - > node 6 - > node 9).

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(h)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-10 11:18:19
- **Status:** Correct
- **Marks:** 4

```cpp
/* Structure of binary tree Node 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  int solve(Node* root , int& ans){
      if(root == NULL) return 0;
      int lefth = solve(root->left , ans);
      int righth = solve(root->right , ans);
      ans = max(ans , lefth + righth);
      return 1+ max(lefth , righth );
  }
    int diameter(Node* root) {
        // code here
        int ans = 0;
        solve(root , ans);
        return ans;
    }
};
```

*Generated on: 10/10/2026, 2:03:01 PM*