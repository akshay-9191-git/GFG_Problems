## 01. Values with Equal Array Remainders

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/k-modulus-array-element0255/1)

### Problem Description

**Task:** Given an integer array arr[], count the number of positive integers k such that all elements of the array leave the same remainder when divided by k.If there are infinitely many such values of k, return -1.Examples:Input: arr[] = [38, 6, 34]

#### Examples

##### Example 1

- **Output:**
```text
-1Explanation: All elements in the array are equal. Therefore, for every positive integer k, all elements leave the same remainder when divided by k.
```
- **Explanation:** The values of k for which all elements leave the same remainder when divided by k are 1, 2, and 4. For k = 1, all elements leave remainder 0. For k = 2, all elements leave remainder 0. For k = 4, all elements leave remainder 2. No other positive integer satisfies the required condition. Hence, the answer is 3.Input: arr[] = [3, 2] Since there are infinitely many such values of k, the answer is -1.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + sqrt(g)) where g = gcd(|arr[i] - arr[0]|)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-11 02:16:26
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
public:
    int sameMod(vector<int>& arr) {
        int n = arr.size();

        int g = 0;

        for (int i = 1; i < n; i++) {
            g = gcd(g, abs(arr[i] - arr[0]));
        }
        if (g == 0)
            return -1;

        int ans = 0;

        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                ans++;

                if (i != g / i)
                    ans++;
            }
        }

        return ans;
    }
};
```

*Generated on: 9/11/2026, 2:19:49 AM*