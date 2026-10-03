## 01. Lexicographically Smallest Rotation

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/lexicographically-smallest-string--151951/1)

### Problem Description

**Task:** Given a string s, find the lexicographically smallest string after rotating the string left any number of times including 0.Example:Input: s = "abcd"Output: "abcd"Explanation: String after each rotation are "abcd", "bcda", "cdab", "dabc" and so on. Lexicographically smallest among them is "abcd".Input: s = "baca"

#### Examples

##### Example 1

- **Output:**
```text
"abac"
```
- **Explanation:** Strings after each rotation are "baca", "acab", "caba", "abac" and so on. Lexicographically smallest among them is "abac".

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-02 16:08:21
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
  public:
    string lexiString(string &s) {
        // code here
        int n = s.length();
        int i=0, j=1, k=0;
        string t = s+s;
        while(i<n && j<n && k<n){
            if(t[i+k] == t[j+k]){
                k++; continue;
            }
            if(t[i+k] > t[j+k]){
                i = i+k+1;
            }else{
                j = j+k+1;
            }
            if(i==j){
                j++;
            }
            k=0;
        }
        return t.substr(i , n);
    }
};
```

*Generated on: 10/3/2026, 6:24:49 PM*