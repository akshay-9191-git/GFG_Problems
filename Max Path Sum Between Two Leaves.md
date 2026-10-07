## 01. Max Path Sum Between Two Leaves

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-path-sum/1)

### Problem Description

**Task:** Given the root of a binary tree, where each node contains an integer value, find the maximum possible path sum between any two leaf nodes. If the tree has fewer than two leaf nodes, return -1.

#### Examples

##### Example 1

- **Input:**
```text
root = [3, 4, 5, -10, 4, N, N]
```
- **Output:**
```text
16
```
- **Explanation:** The leaf nodes are -10, 4 (right child of 4), and 5. Possible paths between leaf nodes are: -10 - > 4 - > 3 - > 5 = -10 + 4 + 3 + 5 = 2 -10 - > 4 - > 4 = -10 + 4 + 4 = -2 4 - > 4 - > 3 - > 5 = 4 + 4 + 3 + 5 = 16Hence, the maximum path sum is obtained from the path 4 - > 4 - > 3 - > 5, giving 16.

##### Example 2

- **Input:**
```text
root = [-15, 5, 6, -8, 1, 3, 9, 2, -3, N, N, N, N, N, 0, N, N, N, N, 4, -1, N, N, 10]Output: 27Explanation: The leaf nodes are 2, -3, 1, 4, and 10. Some possible paths between leaves are: 2 - > -8 - > 5 - > 1 = 2 + (-8) + 5 + 1 = 0 -3 - > -8 - > 5 - > 1 = -3 + (-8) + 5 + 1 = -5 2 - > -8 - > 5 - > -15 - > 6 - > 3 = 2 + (-8) + 5 + (-15) + 6 + 3 = -7 1 - > 5 - > -15 - > 6 - > 9 - > 0 - > 4 = 1 + 5 + (-15) + 6 + 9 + 0 + 4 = 10 3 - > 6 - > 9 - > 0 - > -1 - > 10 = 3 + 6 + 9 + 0 + (-1) + 10 = 27 Hence, the maximum path sum is obtained from the path 3 - > 6 - > 9 - > 0 - > -1 - > 10, giving 27.
```

##### Example 3

- **Input:**
```text
root = [3, 4, 1, -10, 4, N, N]
```
- **Output:**
```text
12
```
- **Explanation:** The leaf nodes are -10, 4 (right child of 4), and 1. Possible paths between leaf nodes are: -10 - > 4 - > 4 = -10 + 4 + 4 = -2 -10 - > 4 - > 3 - > 1 = -10 + 4 + 3 + 1 = -2 4 - > 4 - > 3 - > 1 = 4 + 4 + 3 + 1 = 12 Hence, the maximum path sum is obtained from the path 4 - > 4 - > 3 - > 1, giving 12.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-07 19:46:40
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
public:

    int ans;

    int dfs(Node* root) {

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            return root->data;
        }

        // Only right child
        if (root->left == NULL) {
            return root->data + dfs(root->right);
        }

        // Only left child
        if (root->right == NULL) {
            return root->data + dfs(root->left);
        }

        // Both children exist
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        // Path between two leaves through current node
        ans = max(ans, leftSum + root->data + rightSum);

        // Return best path from current node to one leaf
        return root->data + max(leftSum, rightSum);
    }

    int maxPathSum(Node* root) {

        if (root == NULL) {
            return -1;
        }

        ans = INT_MIN;

        dfs(root);

        // If ans was never updated,
        // tree has fewer than two leaves.
        if (ans == INT_MIN) {
            return -1;
        }

        return ans;
    }
};
```

*Generated on: 10/7/2026, 7:46:52 PM*