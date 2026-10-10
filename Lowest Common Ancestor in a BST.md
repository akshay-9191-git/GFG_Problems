## 01. Lowest Common Ancestor in a BST

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1)

### Problem Description

**Task:** Given a Binary Search Tree (BST) with unique node values and two nodes n1 and n2 (n1 ! = n2), find their Lowest Common Ancestor (LCA).
The Lowest Common Ancestor (LCA) of two nodes is defined as the deepest node in the tree that has both n1 and n2 as descendants, where a node can be a descendant of itself.

#### Examples

##### Example 1

- **Input:**
```text
root = [5, 4, 6, 3, N, N, 7, N, N, N, 8], n1- > data = 7, n2- > data = 8 Output: 7Explanation: 7 is the lowest node that has both 7 and 8 as descendants.
```

##### Example 2

- **Input:**
```text
root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], n1- > data = 8, n2- > data = 14 Output: 8Explanation: 8 is the lowest node that has both 8 and 14 as descendants.
```

##### Example 3

- **Input:**
```text
root = [2, 1, 3], n1- > data = 1, n2- > data = 3
```
- **Output:**
```text
2Explanation: 2 is the lowest node that has both 1 and 3 as descendants.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(h)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-10 10:44:58
- **Status:** Correct
- **Marks:** 4

```cpp
/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/


class Solution {
  public:
  bool solve(Node* root , Node* target , vector<Node*>& ans){
      if(root == NULL) return false;
      if(root->data == target->data){
          ans.push_back(root);
       return true;
      }
      ans.push_back(root);
      if(solve(root->left , target , ans) || solve(root->right , target , ans))
        return true;

    ans.pop_back();
    return false;
  }
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        //  code here
        vector<Node*> ans1; 
        vector<Node*> ans2;
        solve(root , n1 , ans1);
        solve(root , n2 , ans2);
        Node* ans = NULL;
        for(int i=0;i<ans1.size() && i < ans2.size();i++){
            if(ans1[i] == ans2[i]){
                ans =  ans1[i];
            }else{
                break;
            }
        }
        return ans;
    }
};
```

*Generated on: 10/10/2026, 2:02:05 PM*