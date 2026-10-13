## 01. Minimum Squares with Full Cuts

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/squares-in-reactangle3340/1)

### Problem Description

**Task:** Given a rectangular paper with dimensions n × m, find the minimum number of squares that can be formed by cutting the paper. Each cut must be made completely across the remaining paper, either horizontally or vertically.Examples:Input: n = 4, m = 5

#### Examples

##### Example 1

- **Output:**
```text
8
```
- **Explanation:** One square of size 11 x 11, five squares of size 2 x 2, and two squares of size 1 x 1 are formed by following the rule. Please note that if we are allowed to make partial horizontal or vertical cuts, we can have 6 squares which is a different interesting problem, Min Cut Square.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log(min(n, m)))
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-12 20:06:31
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int minSquares(int n, int m) {
        long long ans = 0;

        while (n > 0 && m > 0) {
            if (n < m) swap(n, m);

            ans += n / m;
            n %= m;
        }

        return ans;
    }
};
```

*Generated on: 10/13/2026, 4:56:53 PM*