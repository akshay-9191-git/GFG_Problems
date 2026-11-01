## 01. Maximum Subarray Sum with One Square Allowed

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-sum-subarray--143510/1)

### Problem Description

**Task:** Given an integer array arr[], find the maximum subarray sum by squaring at most one element.Examples:Input: arr[] = [-1, -2, 3, -2, 3]Output: 10Explanation: The subarray {3, -2, 3} with squaring -2 will give the maximum sum as 3 + 4 + 3 = 10.Input: arr[] = [-4, -4, -2, 5, 2, -1]Output: 27Explanation: The subarray {5, 2} with squaring 5 will give a maximum sum of 25 + 2 = 27.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-01 15:36:27
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int maximumSubarray(vector<int>& arr) {
        int noSquare = arr[0];
        int oneSquare = arr[0] * arr[0];

        int ans = oneSquare;

        for (int i = 1; i < arr.size(); i++) {
            int x = arr[i];

            int newOneSquare = max({
                x * x,
                noSquare + x * x,
                oneSquare + x
            });

            int newNoSquare = max(x, noSquare + x);

            noSquare = newNoSquare;
            oneSquare = newOneSquare;

            ans = max({ans, noSquare, oneSquare});
        }

        return ans;
    }
};
```

*Generated on: 11/1/2026, 3:36:41 PM*