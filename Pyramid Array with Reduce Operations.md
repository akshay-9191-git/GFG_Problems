## 01. Pyramid Array with Reduce Operations

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/pyramid-form3044/1)

### Problem Description

**Task:** Given an array arr[] consisting of stones, where arr[i] represents the height of the i-th stone.
You need to transform the stones into a pyramid by only reducing the heights of the stones. Reducing the height of a stone by 1 costs 1 unit, and stones cannot be increased or moved.
A valid pyramid consists of a contiguous subarray whose heights follow the pattern: 1, 2, 3, ..., x - 1, x, x - 1, ..., 2, 1 for some positive integer x.
Every stone outside this subarray must have a height of 0.
Find the minimum total cost required to build a pyramid. It is guaranteed that at least one valid pyramid can always be formed.

#### Examples

##### Example 1

- **Input:**
```text
arr[] = [1, 2, 3, 4, 2, 1]
```
- **Output:**
```text
4
```
- **Explanation:** We can obtain the array [1, 2, 3, 2, 1, 0] by subtracting 2 out of 4, 1 out of 2, and 1 out of 1. In total, we will subtract 4.

##### Example 2

- **Input:**
```text
arr[] = [1, 2, 1]
```
- **Output:**
```text
0
```
- **Explanation:** The array is already in pyramid form.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-23 21:40:40
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int formPyramid(vector<int>& arr) {

        int n = arr.size();

        vector<int> left(n);
        vector<int> right(n);

        left[0] = 1;

        for (int i = 1; i < n; i++) {
            left[i] = min(arr[i], left[i - 1] + 1);
        }
        right[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(arr[i], right[i + 1] + 1);
        }

        long long total = 0;
        int maxHeight = 0;

        for (int i = 0; i < n; i++) {
            total += arr[i];

            int height = min(left[i], right[i]);

            maxHeight = max(maxHeight, height);
        }

        long long pyramidSum = 1LL * maxHeight * maxHeight;

        return total - pyramidSum;
    }
};
```

*Generated on: 9/23/2026, 9:40:57 PM*