## 01. Maximum Packages within Time

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/bird-and-maximum-fruit-gathering0509/1)

### Problem Description

**Task:** A delivery agent has to deliver packages at locations arranged in a line. The number of packages at the ith location is given by arr[i]. The agent can start at any location and can only visit consecutive locations.Visiting each location takes 1 unit of time.Given arr[] and totalTime, find the maximum number of packages the agent can deliver within totalTime.Examples:Input: arr[] = [2, 1, 3, 5, 0, 1, 4], totalTime = 3

#### Examples

##### Example 1

- **Output:**
```text
8
```
- **Explanation:** The agent can visit two consecutive locations. Starting from the second location, it delivers arr[1] + arr[2] = 6 + 2 = 8 packages. Starting from the fourth location gives arr[3] + arr[4] = 5 + 3 = 8 packages. Hence, the maximum is 8 packages.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-31 19:50:21
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
public:
    int maxPackages(vector<int>& arr, int totalTime) {
        int n = arr.size();
        int k = min(totalTime, n);
        if (k <= 0) return 0;

        long long sum = 0;
        for (int i = 0; i < k; i++) sum += arr[i];

        long long ans = sum;
        for (int i = k; i < n; i++) {
            sum += arr[i] - arr[i - k];
            ans = max(ans, sum);
        }

        return (int)ans;
    }
};
```

*Generated on: 10/31/2026, 7:51:41 PM*