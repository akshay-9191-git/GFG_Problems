## 01. Minimum Sum Subarray

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1)

### Problem Description

**Task:** Given an array arr[], find the minimum sum of a subarray containing atleast one element in the given array.Examples:Input: arr[] = [3, -4, 2, -3, -1, 7, -5]

#### Examples

##### Example 1

- **Output:**
```text
1
```
- **Explanation:** The subarray [1] has the minimum sum, which is 1.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-21 11:16:02
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int maxsum = 0;
        int curr = 0;
        for(int x : arr){
            curr += x;
            if(curr > 0){
                curr = 0;
            }
            maxsum = min(maxsum , curr);
        }
        if(maxsum == 0){
            return (*min_element(arr.begin() , arr.end()));
        }else{
        return maxsum;
        }
    }
};
```

*Generated on: 10/21/2026, 7:09:14 PM*