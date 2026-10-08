## 01. Maximum Frequency with K Increments

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-frequency-1662528911/1)

### Problem Description

**Task:** Given an integer array arr[]. In one operation, you can choose an index and increment its value by 1.Find the maximum possible frequency of any element after performing at most k operations.Examples:Input: arr[] = [2, 2, 4], k = 4

#### Examples

##### Example 1

- **Output:**
```text
3
```
- **Explanation:** Apply two increment operations on index 0 and two operations on index 1 to make arr[] = [4, 4, 4]. Frequency of 4 is 3.

##### Example 2

- **Input:**
```text
arr[] = [7, 7, 7, 7], k = 5
```
- **Output:**
```text
4
```
- **Explanation:** The frequency of 7 is already 4, so no operations are needed.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-08 18:56:43
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int j = 0;
        long long sum = 0;
        int freq = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            while (1LL * arr[i] * (i - j + 1) - sum > k) {
                sum -= arr[j];
                j++;
            }

            freq = max(freq, i - j + 1);
        }

        return freq;
    }
};
```

*Generated on: 10/8/2026, 6:56:55 PM*