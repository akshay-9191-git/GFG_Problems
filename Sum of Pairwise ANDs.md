## 01. Sum of Pairwise ANDs

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-products5049/1)

### Problem Description

**Task:** Given an array arr[] of integers, calculate the sum of bitwise AND for all pairs of elements such that the first index is less than the second index.

#### Examples

##### Example 1

- **Input:**
```text
arr = [5, 10, 15]
```
- **Output:**
```text
15
```
- **Explanation:** Consider all pairs of elements where the first index is less than the second index (i < j). For the array [5, 10, 15], the valid pairs are: (5, 10) - > 5 & 10 = 0 (5, 15) - > 5 & 15 = 5 (10, 15) - > 10 & 15 = 10 Now, add all these results: 0 + 5 + 10 = 15 So, the total sum of bitwise ANDs for all such pairs is 15

##### Example 2

- **Input:**
```text
arr = [10, 20, 30, 40]
```
- **Output:**
```text
46
```
- **Explanation:** Consider all pairs of elements where the first index is less than the second index (i < j). For the array [10, 20, 30, 40], the valid pairs are: (10, 20) - > 10 & 20 = 0 (10, 30) - > 10 & 30 = 10 (10, 40) - > 10 & 40 = 8 (20, 30) - > 20 & 30 = 20 (20, 40) - > 20 & 40 = 0 (30, 40) - > 30 & 40 = 8 Now, add all these results: 0 + 10 + 8 + 20 + 0 + 8 = 46 So, the total sum of bitwise ANDs for all such pairs is 46

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-10 22:24:36
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        long long ans = 0;
        // code here
        for(int bit = 0;bit < 31;bit++){
            long long count = 0;
            for(int x:arr){
                if(x & (1LL<<bit)){
                    count++;
                }
            }
            long long pairs = count * (count -1) /2;
            ans += pairs*((1LL<<bit));
        }
        return ans;
    }
};
```

*Generated on: 9/10/2026, 10:24:58 PM*