## 01. Subsets with MEX in Range

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/crazy-subsets--131708/1)

### Problem Description

**Task:** Given an array arr[] of integers and a range [l, r], count the number of subsets whose Minimum Excluded (MEX) value lies within the given range, inclusive.Minimum Excluded (or MEX) of a subset is the smallest non-negative integer that is not present in the subset. An empty subset has Minimum Excluded as zero. Since the answer can be very large, return the answer modulo 10⁹ + 7.Examples:Input: arr[] = [2, 0, 1, 0], l = 1, r = 2

#### Examples

##### Example 1

- **Output:**
```text
9
```
- **Explanation:** The subsets whose MEX lies in the range [1, 2] are counted as follows:MEX = 1: The subsets must contain at least one 0 and must not contain 1. These subsets are [0] (2 ways), [2, 0] (2 ways), [0, 0] (1 way), and [2, 0, 0] (1 way). Total = 6.MEX = 2: The subsets must contain both 0 and 1 but must not contain 2. These subsets are [0, 1] (2 ways) and [0, 1, 0] (1 way). Total = 3.The subsets [2, 0, 1] and [2, 0, 1, 0] have MEX = 3, which is outside the given range. Therefore, the total number of valid subsets is 6 + 3 = 9.Input: arr[] = [2, 0, 1], l = 1, r = 2Output: 3Explanation: The subsets whose MEX lies in the range [1, 2] are [0] (MEX = 1), [2, 0] (MEX = 1), and [0, 1] (MEX = 2). Hence, the answer is 3.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + r)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-30 10:27:52
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
  public:
    int cntSubsets(vector<int> &arr, int l, int r) {
        // code here
        const long long MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> freq(n+1 , 0);
        for(int x : arr){
            if(x <= n){
                freq[x]++;
            }
        }
        vector<long long> power(n+1);
        power[0] = 1;
        for(int i=1; i<=n;i++){
            power[i] = (power[i-1]*2) % MOD;
        }
        vector<long long> prefix(n+1,1);
        for(int i=0;i<n;i++){
            prefix[i+1] = (prefix[i]*(power[freq[i]] -1 + MOD)) % MOD;
        }
        vector<long long> suffix(n+2 , 0);
        for(int i=n;i>=0;i--){
            suffix[i] = suffix[i+1] + freq[i];
        }
        
        long long ans = 0;
        for(int i = l; i<=r; i++){
            if(prefix[i] == 0){
                break;
            }
            long long z = prefix[i];
            z = (z * power[suffix[i+1]]) % MOD;
            ans = (ans + z)%MOD;
        }
        return ans;
        
    }
};
```

*Generated on: 10/30/2026, 8:53:32 PM*