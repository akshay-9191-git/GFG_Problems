## 01. Maximum Without 3 Consecutive Set Bits

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/geek-hates-too-many-1s--170647/1)

### Problem Description

**Task:** Given a non-negative integer n, you can only change a set bit (1) to an unset bit (0). Find the maximum possible value of n such that its binary representation does not contain three consecutive set bits (111) after performing zero or more allowed operations.Examples:Input: n = 2

#### Examples

##### Example 1

- **Output:**
```text
6
```
- **Explanation:** The binary representation of 7 is 111, which contains three consecutive set bits. Changing the rightmost set bit to 0 gives: 111 - > 110. Thus, the maximum possible value is 6.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-15 12:04:39
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int maxValue(int n) {
        int count = 0;
        for (int i = 31; i >= 0; i--) {
            if (n & (1 << i)) {
                count++;
                if (count == 3) {
                    n &= ~(1 << i);  // clear the third consecutive set bit
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return n;
    }
};
```

*Generated on: 10/15/2026, 5:48:52 PM*