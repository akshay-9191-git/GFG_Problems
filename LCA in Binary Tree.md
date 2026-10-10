## 01. LCA in Binary Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1)

### Problem Description

**Task:** Given the root of a binary tree with all unique values and two nodes value, n1 and n2. Find the lowest common ancestor of the given two nodes. Both node values are always present in the Binary Tree.Note: LCA is the first common ancestor of both the nodes n1 and n2 from bottom of tree.Examples:Input: root = [1, 2, 3, 4, 5, 6, 7], n1 = 4, n2 = 5 Output: 2

#### Examples

##### Example 1

- **Output:**
```text
3
```
- **Explanation:** LCA of 7 and 8 is 3.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-10 10:19:28
- **Status:** Correct
- **Marks:** 4

```cpp
/* Structure of binary tree node
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
  bool solve(Node* root , int target , vector<Node*>& ans){
      if(root == NULL) return false;
      if(root->data == target){
          ans.push_back(root);
       return true;
      }
      ans.push_back(root);
      if(solve(root->left , target , ans) || solve(root->right , target , ans))
        return true;
        
    ans.pop_back();
    return false;
  }
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        vector<Node*> ans1; 
        vector<Node*> ans2;
        solve(root , n1 , ans1);
        solve(root , n2 , ans2);
        Node* ans = NULL;
        for(int i=0;i<ans1.size();i++){
            if(ans1[i] == ans2[i]){
                ans =  ans1[i];
            }
        }
        return ans;
    }
};
```

*Generated on: 10/10/2026, 2:02:36 PM*