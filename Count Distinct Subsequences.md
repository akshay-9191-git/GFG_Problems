## 01. Count Distinct Subsequences

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1)

### Problem Description

**Task:** Given a string str consisting of lowercase english alphabets, find the number of distinct subsequences of the string

> **Note:** Answer can be very large, so, return answer modulo 10⁹+7.

#### Examples

##### Example 1

- **Input:**
```text
str = "gfg"
```
- **Output:**
```text
7
```
- **Explanation:** The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .

##### Example 2

- **Input:**
```text
str = "ggg"
```
- **Output:**
```text
4
```
- **Explanation:** The four distinct subsequences are "", "g", "gg", "ggg".

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (5)

#### Solution 1 (C++)

- **Submitted:** 2026-09-07 15:43:11
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int n = str.size();
        int mod = 1000000007;
        int res = 1;
        vector<int> last(26 , 0);
        for(int i=1;i<=n;i++){
            int curr = ((2LL * res)%mod - last[str[i-1]-'a'] + mod)%mod;
            last[str[i-1] - 'a'] = res;
            res = curr;
        }
        return res;
        
    }
};
```

#### Solution 2 (C++)

- **Submitted:** 2026-09-07 15:37:29
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int n = str.size();
        int mod = 1000000007;
        int res = 1;
        vector<int> last(26 , 0);
        for(int i=1;i<=n;i++){
            int curr = ((2LL * res)%mod - last[str[i-1]-'a'] + mod)%mod;
            last[str[i-1] - 'a'] = res;
            res = curr;
        }
        return res;
        
    }
};
```

#### Solution 3 (C++)

- **Submitted:** 2026-09-07 15:34:50
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int n = str.size();
        int mod = 1000000007;
        int res = 1;
        vector<int> last(26 , 0);
        for(int i=1;i<=n;i++){
            int curr = ((2LL * res)%mod - last[str[i-1]-'a'] + mod)%mod;
            last[str[i-1] - 'a'] = res;
            res = curr;
        }
        return res;
        
    }
};
```

#### Solution 4 (C++)

- **Submitted:** 2026-09-07 15:33:36
- **Status:** Correct
- **Marks:** 0

```cpp
class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int n = str.size();
        int mod = 1000000007;
        int res = 1;
        vector<int> last(26 , 0);
        for(int i=1;i<=n;i++){
            int curr = ((2LL * res)%mod - last[str[i-1]-'a'] + mod)%mod;
            last[str[i-1] - 'a'] = res;
            res = curr;
        }
        return res;
        
    }
};
```

#### Solution 5 (C++)

- **Submitted:** 2026-09-07 15:31:37
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int n = str.size();
        int mod = 1000000007;
        int res = 1;
        vector<int> last(26 , 0);
        for(int i=1;i<=n;i++){
            int curr = ((2LL * res)%mod - last[str[i-1]-'a'] + mod)%mod;
            last[str[i-1] - 'a'] = res;
            res = curr;
        }
        return res;
        
    }
};
```

*Generated on: 9/7/2026, 3:46:48 PM*