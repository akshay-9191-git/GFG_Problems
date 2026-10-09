## 01. Minimum Operations to Reach n

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-optimum-operation4504/1)

### Problem Description

**Task:** Given a number n. Find the minimum number of operations required to reach n starting from 0. You have two operations available:Double the number Add one to the numberExamples:Input: n = 8

#### Examples

##### Example 1

- **Output:**
```text
4
```
- **Explanation:** 0 + 1 = 1 -- > 1 + 1 = 2 -- > 2 * 2 = 4 -- > 4 * 2 = 8.

##### Example 2

- **Input:**
```text
n = 7
```
- **Output:**
```text
5
```
- **Explanation:** 0 + 1 = 1 -- > 1 + 1 = 2 -- > 1 + 2 = 3 -- > 3 * 2 = 6 -- > 6 + 1 = 7.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-09 09:57:03
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
    int minOperation(int n) {
        // code here
        int ans = 0;
        while( n > 0){
            if(n % 2 == 0){
                n /= 2; 
                ans++;
            }
            if(n % 2 != 0){
                n -= 1;
                ans++;
            }
        }
        return ans;
    }
};
```

*Generated on: 10/9/2026, 10:06:36 PM*