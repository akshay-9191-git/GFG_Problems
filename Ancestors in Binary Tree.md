## 01. Ancestors in Binary Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1)

### Problem Description

**Task:** Given a Binary Tree and an integer target, find all the ancestors of the given target.
A node y is an ancesto x if at the upper level of x and on the path from x to root.
Root is ancestor of all other nodes and there is no ancestor of the root.
In case there are no ancestors available, return an empty list.

#### Examples

##### Example 1

- **Input:**
```text
root[] = [1, 2, 3, 4, 5, 6, 8, 7, N, N, N, N, N, N], target = 7 Output: [4 2 1]Explanation: The given target is 7, if we go above the level of node 7, then we find 4, 2 and 1. Hence the ancestors of node 7 are 4 2 and 1
```

##### Example 2

- **Input:**
```text
root[] = [1, 2, 3], target = 1
```
- **Output:**
```text
[]Explanation: Since 1 is the root node, there would be no ancestors. Hence we return an empty list.
```

#### Constraints

- **1.** `1 ≤ no. of nodes ≤ 10³¹ ≤ data of node ≤ 10⁴`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O( height of tree )

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-10 10:05:27
- **Status:** Correct
- **Marks:** 4

```cpp
/* Structure of a Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  bool solve(Node* root , int target , vector<int>& ans){
      if(root == NULL) return false;
      if(root->data == target) return true;
      ans.push_back(root->data);
      if(solve(root->left , target , ans) || solve(root->right , target , ans))
        return true;
    
    ans.pop_back();
    return false;
  }
    vector<int> ancestors(Node *root, int target) {
        // Code here
        vector<int> ans;
        solve(root , target , ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

*Generated on: 10/10/2026, 2:01:33 PM*