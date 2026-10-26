## 01. Minimize Max Min Diff with Subarray Removal

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimize-the-difference/1)

### Problem Description

**Task:** You are given an array arr[] of size n. You need to remove a subarray of size k , such that the difference between the maximum and minimum values of the remaining array is minimized. Find the minimum value obtained after performing the operation of the removal of the subarray.Examples:Input: arr = [1, 2, 3, 4, 5], k = 3 Output: 1Explanation: We remove first subarray of length 3, the remaining array is [4,5] and the difference of maximum and minimum element is 1 i.e 5 - 4 = 1Input: arr = [2, 3, 1, 4, 6, 7], k = 3Output: 2Explanation: If we remove the subarray [2,3,1] then remaining array is [4,6,7] and the difference = 7-4 = 3If we remove the subarray [3,1,4] then remaining array is [2,6,7] and the difference = 7-2 = 5If we remove the subarray [1,4,6] then remaining array is [2,3,7] and the difference = 7-2 = 5If we remove the subarray [4,6,7] then remaining array is [2,3,1] and the difference = 3-1 = 2So the answer is min(3,5,5,2) = 2

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-26 12:43:44
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        int n = arr.size();

        if (k == 0) return *max_element(arr.begin(), arr.end())
                            - *min_element(arr.begin(), arr.end());

        vector<int> preMin(n), preMax(n);
        vector<int> sufMin(n), sufMax(n);

        preMin[0] = preMax[0] = arr[0];

        for (int i = 1; i < n; i++) {
            preMin[i] = min(preMin[i - 1], arr[i]);
            preMax[i] = max(preMax[i - 1], arr[i]);
        }

        sufMin[n - 1] = sufMax[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            sufMin[i] = min(sufMin[i + 1], arr[i]);
            sufMax[i] = max(sufMax[i + 1], arr[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i + k <= n; i++) {
            int mn = INT_MAX;
            int mx = INT_MIN;

            if (i > 0) {
                mn = min(mn, preMin[i - 1]);
                mx = max(mx, preMax[i - 1]);
            }

            if (i + k < n) {
                mn = min(mn, sufMin[i + k]);
                mx = max(mx, sufMax[i + k]);
            }

            ans = min(ans, mx - mn);
        }

        return ans;
    }
};
```

*Generated on: 10/26/2026, 3:22:01 PM*