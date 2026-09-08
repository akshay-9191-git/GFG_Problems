## 01. Max Digit Sum Number in 1 to n

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/biggest-integer-having-maximum-digit-sum1704/1)

### Problem Description

**Task:** Given a number n, find a number in the range from 1 to n such that its digit sum is maximum. If there are multiple such numbers, return the largest of them.

#### Examples

##### Example 1

- **Input:**
```text
n = 48
```
- **Output:**
```text
48
```
- **Explanation:** There are two numbers with maximum digit sum = 12. The numbers are 48 and 39. Since 48 > 39, so 48 is the answer.

##### Example 2

- **Input:**
```text
n = 90
```
- **Output:**
```text
89Explanation: 89 gives us the largest digit sum in the range from 1 to n. Hence the answer is 89.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(m) where m is the number of digits in nAuxiliary Space: O(m) where m is the number of digits in n
- **Expected Auxiliary Space Complexity:** O(m) where m is the number of digits in n

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-09 01:01:16
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
  public:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int findMax(int n) {
        string s = to_string(n);
        string ans = s;

        for (int i = 0; i < s.size(); i++) {
            string temp = s;

            // Decrease current digit
            if (temp[i] == '0')
                continue;

            temp[i]--;

            // Make all following digits 9
            for (int j = i + 1; j < s.size(); j++) {
                temp[j] = '9';
            }

            // Compare digit sums
            if (digitSum(stoi(temp)) > digitSum(stoi(ans)) ||
                (digitSum(stoi(temp)) == digitSum(stoi(ans)) &&
                 stoi(temp) > stoi(ans))) {
                ans = temp;
            }
        }

        return stoi(ans);
    }
};
```

*Generated on: 9/9/2026, 1:01:34 AM*