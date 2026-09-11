## 01. Max Product Subsequence of Size K

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-product4633/1)

### Problem Description

**Task:** Given an array arr[] of integers and an integer k, find a subsequence of size k whose product is maximum among all possible subsequences of size k. Return the maximum product that can be obtained.Examples:Input: arr[] = [1, 2, 0, 3], k = 2

#### Examples

##### Example 1

- **Output:**
```text
144
```
- **Explanation:** Subsequence containing {2, -3, -6, 4} gives maximum product: 2*(-3)*(-6)*4 = 144

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-12 00:46:39
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
public:
    int maxProduct(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        long long ans = 1;

        if (k % 2 == 1) {

            if (arr[right] > 0) {
                ans *= arr[right];
                right--;
                k--;
            }
            else {
 
                for (int i = 0; i < k; i++) {
                    ans *= arr[right - i];
                }
                return ans;
            }
        }

        while (k > 0) {

            long long leftProduct =
                1LL * arr[left] * arr[left + 1];

            long long rightProduct =
                1LL * arr[right] * arr[right - 1];

            if (leftProduct > rightProduct) {
                ans *= leftProduct;
                left += 2;
            }
            else {
                ans *= rightProduct;
                right -= 2;
            }

            k -= 2;
        }

        return ans;
    }
};
```

*Generated on: 9/12/2026, 12:46:58 AM*