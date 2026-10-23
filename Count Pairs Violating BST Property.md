## 01. Count Pairs Violating BST Property

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1)

### Problem Description

**Task:** Given root of a binary tree in which all node values are distinct, count pairs of nodes that violate any of the following Binary Search Tree (BST) properties. All values in the left subtree are strictly smaller.All values in the right subtree are strictly greater.Examples:Input: root[] = [10, 50, 40, N, N, 20, 30]Output: 5

#### Examples

##### Example 1

- **Explanation:** There are total 10 pairs (80, 30), (80, 60), (80, 50), (30, 60), (40, 70), (40, 30), (40, 50), (70, 30), (70, 60), (70, 50) which violate the BST properties.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-23 13:14:02
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    long long cnt = 0;

    void mergeCount(vector<int>& arr, vector<int>& temp, int l, int r) {
        if (r - l <= 1) return;
        int m = l + (r - l) / 2;
        mergeCount(arr, temp, l, m);
        mergeCount(arr, temp, m, r);

        int j = m;
        for (int i = l; i < m; i++) {
            while (j < r && arr[j] < arr[i]) j++;   // strict
            cnt += (j - m);
        }

        merge(arr.begin() + l, arr.begin() + m,
              arr.begin() + m, arr.begin() + r,
              temp.begin() + l);
        copy(temp.begin() + l, temp.begin() + r, arr.begin() + l);
    }

    int pairsViolatingBST(Node *root) {
        vector<int> arr;
        stack<Node*> st;
        Node* curr = root;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            arr.push_back(curr->data);
            curr = curr->right;
        }

        vector<int> temp(arr.size());
        cnt = 0;
        mergeCount(arr, temp, 0, arr.size());
        return (int)cnt;
    }
};
```

*Generated on: 10/23/2026, 7:30:49 PM*