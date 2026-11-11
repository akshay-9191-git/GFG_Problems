## 01. Any Duplicate Within K Distance

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/kth-distance3757/1)

### Problem Description

**Task:** Given an array of integers, arr[] and an integer k, check whether there exist two distinct indices i and j such that arr[i] is equal to arr[j] and the absolute difference between i and j is at most k.Examples:Input: arr[] = [1, 5, 4, 5, 1], k = 3Output: trueExplanation: The element 5 occurs at indices 1 and 3. Their distance is |3 - 1| = 2, which is less than or equal to k.Input: arr[] = [10, 2, 3, 4, 10, 5], k = 3Output: falseExplanation: The element 10 occurs at indices 0 and 4. Their distance is |4 - 0| = 4, which is greater than k. Hence, no duplicate exists within the given distance.Input: arr[] = [5, 1, 3, 2, 4], k = 3Output: falseExplanation: All elements are distinct, so no duplicate exists.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(min(n, k))

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-11 18:31:33
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        int i = 0;

        for (int j = 0; j < arr.size(); j++) {
            mp[arr[j]]++;

            if (mp[arr[j]] > 1) {
                return true;
            }

            if (j - i + 1 == k + 1) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }
                i++;
            }
        }

        return false;
    }
};
```

*Generated on: 11/11/2026, 6:31:46 PM*