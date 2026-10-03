## 01. Coils in Matrix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/form-coils-in-a-matrix4726/1)

### Problem Description

**Task:** Given a positive integer n, consider a 4n * 4n matrix filled with integers from 1 to (4n) * (4n) in row-major order (left to right, top to bottom). Form two coils from the matrix:The first coil starts from the top-left cell (0, 0) and spirals inward.The second coil starts from the bottom-right cell (4n - 1, 4n - 1) and spirals inward in the opposite direction.Return these two coils in the same order.Examples:Input: n = 1Output: [[1, 5, 9, 13, 14, 15, 11, 7], [16, 12, 8, 4, 3, 2, 6, 10]]

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^2)
- **Expected Auxiliary Space Complexity:** O(n^2)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-03 19:21:02
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    vector<int> makeCoil(int n, bool first) {
        int N = 4 * n;

        int r = first ? 0 : N - 1;
        int c = first ? 0 : N - 1;

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        // First coil: down, right, up, left
        // Second coil: up, left, down, right
        if (!first) {
            dr[0] = -1; dc[0] = 0;
            dr[1] = 0;  dc[1] = -1;
            dr[2] = 1;  dc[2] = 0;
            dr[3] = 0;  dc[3] = 1;
        }

        vector<int> coil;
        coil.push_back(r * N + c + 1);

        int dir = 0;
        int len = N - 1;
        int segment = 0;

        while (len > 0) {
            for (int step = 0; step < len; step++) {
                r += dr[dir];
                c += dc[dir];
                coil.push_back(r * N + c + 1);
            }

            dir = (dir + 1) % 4;

            if (segment == 0) {
                len--;
            } else if (segment % 2 == 0) {
                len -= 2;
            }

            segment++;
        }

        return coil;
    }

    vector<vector<int>> formCoils(int n) {
        vector<int> first = makeCoil(n, true);
        vector<int> second = makeCoil(n, false);

        return {first, second};
    }
};
```

*Generated on: 10/3/2026, 9:56:26 PM*