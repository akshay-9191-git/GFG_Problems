## 01. Minimum Absolute Difference In BST

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1)

### Problem Description

**Task:** Given the root of a Binary Search Tree (BST) containing n (n > 1) nodes, find the minimum absolute difference between the values of any two different nodes in the tree.Return the minimum absolute difference.Examples:Input: root[] = [50, 30, 70, 20, N, 60, 80]Output: 10Explanation: There are no two nodes whose absolute difference is smaller than 10.Input: root[] = [60, 30, 90, 10]Output: 20Explanation: There are no two nodes whose absolute difference is smaller than 20.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(h)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-18 18:35:02
- **Status:** Correct
- **Marks:** 4

```cpp
/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
  void inorder(Node* root , vector<int>& ans){
      if(root != NULL){
          inorder(root->left , ans);
          ans.push_back(root->data);
          inorder(root->right , ans);
      }
  }
    int absDiff(Node *root) {
        // code here
        vector<int> ans;
        inorder(root , ans);
        int mini = INT_MAX;
        for(int i=1;i<ans.size();i++){
            int a = ans[i] - ans[i-1];
            mini = min(mini , a);
        }
        return mini;
        
    }
};
```

*Generated on: 9/18/2026, 8:18:07 PM*