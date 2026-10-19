## 01. Count Indices That Escape Array

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/good-stones--170647/1)

### Problem Description

**Task:** Given an array arr[], where arr[i] represents the exact number of steps to move from index i. An index is considered good if repeatedly following the jumps eventually takes you outside the array. Otherwise, if the jumps result in an infinite loop, the index is considered bad. A positive value indicates a move to the rightA negative value indicates a move to the left.A 0 value means no move and considered bad.Return the number of good indices.Examples:Input: [2, 3, -1, 2, -2, 4, 1]

#### Examples

##### Example 1

- **Output:**
```text
3
```
- **Explanation:** Indices 3, 5, and 6 are good because their jump sequences eventually leave the array. Indices 1, 2, and 4 form a cycle, while index 0 eventually enters this cycle through index 2. Hence, the total number of good indices is 3.

##### Example 2

- **Input:**
```text
[1, 0, -3, 0, -5, 0]
```
- **Output:**
```text
2
```
- **Explanation:** Indices 2 and 4 are good because their jumps take them outside the array. Indices 1, 3, and 5 are bad because their jumps are zero. Index 0 is also bad because it jumps to index 1, which is a dead end. Hence, the total number of good indices is 2.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-19 16:24:28
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int goodIndices(vector<int>& arr) {
        int n = arr.size();
        vector<int> state(n, 0);
        vector<int> result(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (state[i] != 0) continue;

            vector<int> path;
            int curr = i;

            while (curr >= 0 && curr < n && state[curr] == 0) {
                state[curr] = 1;
                path.push_back(curr);
                curr += arr[curr];
            }

            int good = 0;

            if (curr < 0 || curr >= n) {
                good = 1;
            } else if (state[curr] == 1) {
                good = 0;
            } else {
                good = result[curr];
            }

            for (int j : path) {
                result[j] = good;
                state[j] = 2;
            }

            if (good) ans += path.size();
        }

        return ans;
    }
};
```

*Generated on: 10/19/2026, 4:24:39 PM*