## 01. Flood fill Algorithm

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1)

### Problem Description

**Task:** You are given a 2D grid image[][], where each image[i][j] represents the color of a pixel in the image. Also provided a coordinate (sr, sc) representing the starting pixel (row and column) and a new color value newColor.
Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.

#### Examples

##### Example 1

- **Input:**
```text
image[][] = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]], sr = 1, sc = 2, newColor = 2Output: [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]]Explanation: Starting from pixel (1, 2) with value 1, flood fill updates all connected pixels (up, down, left, right) with value 1 to 2, resulting in [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]].
```

##### Example 2

- **Input:**
```text
image[][] = [[0, 1, 0], [0, 1, 0]], sr = 0, sc = 1, newColor = 0
```
- **Output:**
```text
[[0, 0, 0], [0, 0, 0]]
```
- **Explanation:** Starting from pixel (0, 1) with value 1, flood fill changes all 4-directionally connected pixels with value 1 to 0, resulting in [[0, 0, 0], [0, 0, 0]]

#### Constraints

- **1.** `1 ≤ n ≤ m ≤ 5000 ≤ image[i][j] ≤ 10 0 ≤ newColor ≤ 10 0 ≤ sr ≤ (n-1) 0 ≤ sc ≤ (m-1)`

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n * m)
- **Expected Auxiliary Space Complexity:** O(n * m)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-15 23:45:51
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    void dfs(int row , int col , int n , int m , vector<vector<int>>& image , vector<vector<bool>>& vis , int newcolor , int oldcolor){
        vis[row][col] = true;
        image[row][col] = newcolor;

        if(row-1 >= 0 && !vis[row-1][col] && image[row-1][col] == oldcolor){
            dfs(row-1 , col , n , m , image , vis , newcolor , oldcolor);
        }
         if(row+1 < n && !vis[row+1][col] && image[row+1][col] == oldcolor){
            dfs(row+1 , col , n , m , image , vis , newcolor , oldcolor);
        }
         if(col -1 >= 0 && !vis[row][col-1] && image[row][col-1] == oldcolor){
            dfs(row , col -1, n , m , image , vis , newcolor , oldcolor);
        }
         if(col +1 < m && !vis[row][col+1] && image[row][col+1] == oldcolor){
            dfs(row, col +1, n , m , image , vis , newcolor , oldcolor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        dfs(sr , sc , n , m , image , vis , newcolor , image[sr][sc]);
        return image;
    }
};
```

*Generated on: 9/15/2026, 11:46:04 PM*