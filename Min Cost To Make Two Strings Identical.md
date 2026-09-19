## 01. Min Cost To Make Two Strings Identical

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1)

### Problem Description

**Task:** Given two strings s1 and s2, and two integers costS1 and costS2, where costS1 is the cost of deleting one character from s1 and costS2 is the cost of deleting one character from s2, find the minimum cost required to make the two strings identical.You can delete any number of characters from either string, but the order of the remaining characters must be preserved.Examples:Input: s1 = "abcd", s2 = "acdb", costS1 = 10, costS2 = 20

#### Examples

##### Example 1

- **Output:**
```text
60
```
- **Explanation:** The two strings have no common characters, so delete all characters from both strings. The total cost is (2 × 10) + (2 × 20) = 60.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|s1|*|s2|)
- **Expected Auxiliary Space Complexity:** O(min(|s1|, |s2|))

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-19 17:08:36
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        int n= s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m +1, 0));
        for(int i=1;i<=n;i++){
            dp[i][0] = i*costS1 ;
        }
        for(int j=1;j<=m;j++){
            dp[0][j] = j*costS2;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(costS1 + dp[i-1][j] , costS2 + dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
```

*Generated on: 9/19/2026, 5:08:50 PM*