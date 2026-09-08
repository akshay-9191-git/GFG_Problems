## 01. Word in Grid - All Occurrences

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-the-string-in-grid0111/1)

### Problem Description

**Task:** Given a 2D grid mat[][] of size n × m consisting of characters and a string word, find all starting positions where the word occurs in the grid.
The word can be formed from any cell by moving in any of the 8 directions (2 horizontal, 2 vertical, and 4 diagonal) in a straight line without changing direction.
Each cell can be used at most once per occurrence.
Return all unique starting coordinates in lexicographically smallest order.

#### Examples

##### Example 1

- **Input:**
```text
mat[][] = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}, word = "abe"
```
- **Output:**
```text
{{0,0}, {0,2}, {1,0}}
```
- **Explanation:** From (0,0) we can find "abe" in right-down diagonal. From (0,2) we can find "abe" in left-down diagonal. From (1,0) we can find "abe" in horizontally right direction.

##### Example 2

- **Input:**
```text
mat[][] = {{G,E,E,K,S,F,O,R,G,E,E,K,S}, {G,E,E,K,S,Q,U,I,Z,G,E,E,K}, {I,D,E,Q,A,P,R,A,C,T,I,C,E}}, word = "GEEKS"
```
- **Output:**
```text
{{0,0}, {0,8}, {1,0}}
```
- **Explanation:** From (0,0) we can find "GEEKS" horizontally right. From (0,8) we can find "GEEKS" horizontally right. From (1,0) we can find "GEEKS" horizontally right.

#### Constraints

- **1.** `1 <= n <= m <=`
- **2.** `501 <= |word| <= 20`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n*m*k) where k is constantAuxiliary Space: O(1)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-08 15:01:08
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code 
        int n = mat.size();
      int m = mat[0].size();
      vector<vector<int>> ans;
      
      int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
      int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
      
      for(int r=0;r<n;r++){
          for(int c=0;c<m;c++){
              if(mat[r][c] != word[0]) continue;
              for(int d=0;d<8;d++){
                  int x = r;
                  int y = c;
                  int i=0;
                  
                  while(i < word.size()){
                      if(x < 0 || x >= n || y < 0 || y >= m) break;
                      if(mat[x][y] != word[i]) break;
                      x += dr[d];
                      y += dc[d];
                      i++;
                  }
                  if(i == word.size()){
                      ans.push_back({r ,c});
                      break;
                  }
              }
          }
      }
    return ans;
        
    }
};
```

*Generated on: 9/8/2026, 3:01:24 PM*