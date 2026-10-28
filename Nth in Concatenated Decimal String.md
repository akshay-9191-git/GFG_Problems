## 01. Nth in Concatenated Decimal String

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/nth-character-in-concatenated-decimal-string0245/1)

### Problem Description

**Task:** Consider a string s formed by concatenating the decimal representations of all positive integers in order:s = "12345678910111213141516171819202122232425262728293031..."Given an integer n, find the nth character (1-based indexing) in the string s.Examples:Input: n = 10

#### Examples

##### Example 1

- **Output:**
```text
'0'
```
- **Explanation:** The 11th character in "12345678910.." is '0'.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-28 10:03:08
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    char nthCharacter(int n) {
        // code here
       long long len = 1;
       long long count = 9;
       long long start = 1;
       
       while(n > len* count){
           n -= len*count;
           len++;
           count *= 10;
           start *= 10;
       }
       long long number = start + (n-1)/len;
       string s = to_string(number);
       return s[(n-1)%len];
       
    }
    
};
```

*Generated on: 10/28/2026, 10:33:02 PM*