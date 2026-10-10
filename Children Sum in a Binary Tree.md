## 01. Children Sum in a Binary Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/children-sum-parent/1)

### Problem Description

**Task:** Given a binary tree, find if it satisfies the Children Sum Property which has the following rulesEach non-leaf node must have a value equal to the sum of its left and right children's values. A NULL child is considered to have a value of 0, and all leaf nodes are considered valid by default.Examples:Input: root = [35, 20, 15, 15, 5, 10, 5]

#### Examples

##### Example 1

- **Output:**
```text
False
```
- **Explanation:** Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(h)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-10 11:29:31
- **Status:** Correct
- **Marks:** 4

```cpp
/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  bool solve(Node* root){
      if(root == NULL) return true;
      if(root->left == NULL && root->right == NULL) return true;
      int left = (root->left) ? root->left->data : 0;
      int right = (root->right) ? root->right->data : 0;
      if(root->data != left + right) return false;
      return (solve(root->left) && solve(root->right));
      
   }
    bool isSumProperty(Node *root) {
        // code here
        return solve(root);
    }
};
```

*Generated on: 10/10/2026, 2:03:24 PM*