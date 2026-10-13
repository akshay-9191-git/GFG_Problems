## 01. Adding Ones

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/adding-ones3628/1)

### Problem Description

**Task:** Consider an array arr[] of size n, initially containing all zeros. You are also given an array updates[] of k positive integers.For each value j in updates[], add 1 to every element arr[i] whose index satisfies i ≥ j.The indices in updates[] are 1-based.Perform all the updates and modify arr[] accordingly.Examples: Input: n = 3, updates[] = [1, 1, 2, 3]

#### Examples

##### Example 1

- **Output:**
```text
[3, 3]
```
- **Explanation:** Initially the array is [0, 0]. After the first 1, it becomes [1, 1]. After the second 1 it becomes [2, 2]. After the third 1, it becomes [3, 3].

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + k)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-13 16:47:08
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
public:
    vector<int> update(int n, vector<int>& updates) {
        vector<int> arr(n, 0);

        for (int j : updates) {
                arr[j - 1]++;
            }

            for (int i = 1; i < n; i++) {
                arr[i] += arr[i - 1];
            }

            return arr;
    }
};
```

*Generated on: 10/13/2026, 4:56:31 PM*