## 01. Bird and Max Fruit Gathering

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/bird-and-maximum-fruit-gathering--170645/1)

### Problem Description

**Task:** Given an array arr[] representing the fruit values of trees arranged in a circle and an integer m, find the maximum total fruits the bird can collect by visiting at most m trees.
Bird can start from any tree and move to a neighboring tree.
The first and last trees are also considered neighbors.
The bird collects the fruit value of every tree it visits.

#### Examples

##### Example 1

- **Input:**
```text
arr[] = [2, 1, 3, 5, 0, 1, 4], m = 3Output: 9
```
- **Explanation:** The bird can start from the second tree and visit the second, third, and fourth trees.The total fruit value collected is 1 + 3 + 5 = 9.

##### Example 2

- **Input:**
```text
arr[] = [1, 6, 2, 5, 3, 4], m = 2Output: 8
```
- **Explanation:** The bird can start from the second tree and visit the second and third trees, collecting 6 + 2 = 8. It can also start from the fourth tree and visit the fourth and fifth trees, collecting 5 + 3 = 8. The maximum total fruit value is 8.

##### Example 3

- **Input:**
```text
arr[] = [7, 2, 1, 3, 4], m = 2Output: 11
```
- **Explanation:** The bird can start from the fifth tree and visit the fifth and first trees, collecting 4 + 7 = 11. These trees are neighbors because the trees are arranged in a circle. The maximum total fruit value is 11.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-10 21:53:34
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        long long sum = 0;

        for (int i = 0; i < m; i++) {
            sum += arr[i];
        }

        long long maxi = sum;

        for (int i = 1; i < n; i++) {
            sum -= arr[i - 1];
            sum += arr[(i + m - 1) % n];

            maxi = max(maxi, sum);
        }

        return maxi;
    }
};
```

*Generated on: 9/10/2026, 9:53:51 PM*