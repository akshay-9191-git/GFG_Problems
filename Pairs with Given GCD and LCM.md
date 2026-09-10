## 01. Pairs with Given GCD and LCM

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/possible-pairs1550/1)

### Problem Description

**Task:** Given two integers x and y representing the GCD and LCM of two unknown positive integers a and b, count the number of valid pairs (a, b) satisfying these conditions. Note that (a, b) and (b, a) are counted as distinct pairs when a ≠ b.

#### Examples

##### Example 1

- **Input:**
```text
x = 2, y = 12
```
- **Output:**
```text
4
```
- **Explanation:** The valid pairs are (2, 12), (4, 6), (6, 4), and (12, 2), since each pair has GCD = 2 and LCM = 12.

##### Example 2

- **Input:**
```text
x = 6, y = 4
```
- **Output:**
```text
0
```
- **Explanation:** LCM must always be a multiple of GCD. Since y is not divisible by x, no valid pair exists.

#### Constraints

- **1.** `1 ≤ x, y ≤ 10⁴`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(sqrt(n)log(n))
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-10 19:42:09
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
    int pairCount(int x, int y) {
        if(y % x != 0) return 0;
        int n = y/x;
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(n % i ==0){
                int b = n/i;
                if(gcd(i , b) == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

*Generated on: 9/10/2026, 9:54:18 PM*