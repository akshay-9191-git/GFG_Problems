## 01. Max Equal Sum in 3 Stacks

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-maximum-equal-sum-of-three-stacks/1)

### Problem Description

**Task:** Given three stacks s1, s2, and s3, represented by arrays where the first element of each array represents the top of the corresponding stack.Find the maximum possible equal sum(sum of all elements) of all three stacks by removing zero or more elements from the top of each stack.If it is not possible to make the sum of all three stacks equal, return 0.Examples:Input: s1 = [3, 2, 1, 1, 1], s2 = [4, 3, 2], s3 = [2, 5, 4, 1]Output: 5Explanation: Remove 3 from s1, 4 from s2, and 2, 5 from s3. The remaining sums of all three stacks are equal to 5.Input: s1 = [4,7], s2 = [10], s3 = [1,2,3]

#### Examples

##### Example 1

- **Output:**
```text
0
```
- **Explanation:** It is not possible to make the sums of all three stacks equal by removing elements from their tops.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n1 + n2 + n3)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-14 17:47:40
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int maxEqualSum(
                    vector<int>& s1, vector<int>& s2, vector<int>& s3) {
                        
                        int N1 = s1.size(); int N2 = s2.size() ; int N3 = s3.size();

        int sum1 = accumulate(s1.begin(), s1.end(), 0);
        int sum2 = accumulate(s2.begin(), s2.end(), 0);
        int sum3 = accumulate(s3.begin(), s3.end(), 0);

        int i = 0, j = 0, k = 0;

        while (i < N1 && j < N2 && k < N3) {

            if (sum1 == sum2 && sum2 == sum3) {
                return sum1;
            }

            if (sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= s1[i++];
            }
            else if (sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= s2[j++];
            }
            else {
                sum3 -= s3[k++];
            }
        }

        if (sum1 == sum2 && sum2 == sum3) {
            return sum1;
        }

        return 0;
    }
};
```

*Generated on: 11/14/2026, 5:47:51 PM*