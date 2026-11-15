## 01. Sum of All Digit Subsequences

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-all-sub-sequences-of-a-number3437/1)

### Problem Description

**Task:** Given a string s which consists of digits, find sum of all digits across all non-empty subsequences of s.Note: Since the answer can be very large, return it modulo 10⁹ + 7.Examples:Input: s = "123"

#### Examples

##### Example 1

- **Output:**
```text
24
```
- **Explanation:** The non-empty subsequences are: [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]. The sum of all digits in these subsequences is: 1 + 2 + 3 + (1 + 2) + (1 + 3) + (2 + 3) + (1 + 2 + 3) = 24.

##### Example 2

- **Input:**
```text
s = "405"
```
- **Output:**
```text
36
```
- **Explanation:** The non-empty subsequences are: [4], [0], [5], [4, 0], [4, 5], [0, 5], [4, 0, 5]. The sum of all digits in these subsequences is 36.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|s|)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-15 12:29:16
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
    int subsequenceSum(string &s) {
        long long MOD = 1e9 + 7;
        long long sum = 0;

        for (char c : s) {
            sum = (sum + (c - '0')) % MOD;
        }

        long long power = 1;
        long long base = 2;
        int exp = s.size() - 1;

        while (exp > 0) {
            if (exp & 1) {
                power = (power * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return (sum * power) % MOD;
    }
};
```

*Generated on: 11/15/2026, 12:29:26 PM*