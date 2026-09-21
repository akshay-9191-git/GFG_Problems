## 01. Check Level Anagrams in Binary Trees

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-if-all-levels-of-two-trees-are-anagrams-or-not/1)

### Problem Description

**Task:** Given the roots of two binary trees root1 and root2, check whether the nodes at every corresponding level of the two trees are anagrams of each other. Two levels are considered anagrams if they contain the same node values with the same frequencies, regardless of their order.Examples:Input: root1 = [1, 3, 2, N, N, 5, 4], root2 = [1, 2, 3, 4, 5, N, N]Output: true

#### Examples

##### Example 1

- **Output:**
```text
false
```
- **Explanation:** Level 0: [1] and [1] Level 1: [2, 3] and [2, 4] Since the node values at level 1 are not anagrams, the answer is false.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-21 15:43:49
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 == NULL || root2 == NULL)
            return false;

        queue<Node*> q1, q2;

        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();

            if (n1 != n2)
                return false;

            vector<int> a, b;

            for (int i = 0; i < n1; i++) {
                Node* curr = q1.front();
                q1.pop();

                a.push_back(curr->data);

                if (curr->left)
                    q1.push(curr->left);

                if (curr->right)
                    q1.push(curr->right);
            }

            for (int i = 0; i < n2; i++) {
                Node* curr = q2.front();
                q2.pop();

                b.push_back(curr->data);

                if (curr->left)
                    q2.push(curr->left);

                if (curr->right)
                    q2.push(curr->right);
            }

            sort(a.begin(), a.end());
            sort(b.begin(), b.end());

            if (a != b)
                return false;
        }

        return q1.empty() && q2.empty();
    }
};
```

*Generated on: 9/21/2026, 3:44:03 PM*