## 01. Maximum Height Disc Stack

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/stacking-up-discs1315/1)

### Problem Description

**Task:** Given two arrays r[] and h[] of size n, where r[i] and h[i] represent the radius and height of the i-th circular disc, respectively. A disc can be placed above another disc only if both its radius and height are strictly smaller than those of the disc below it. Find the maximum possible height of a stack that can be formed using the given discs. Each disc can be used at most once.Examples:Input: r[] = [5, 7, 3], h[] = [6, 5, 4]

#### Examples

##### Example 1

- **Output:**
```text
7
```
- **Explanation:** Neither disc can be placed above the other because both required dimensions are not strictly smaller. Therefore, the maximum possible height is 7.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-24 19:53:24
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
public:

    int query(vector<int>& bit, int idx) {
        int ans = 0;

        while (idx > 0) {
            ans = max(ans, bit[idx]);
            idx -= idx & (-idx);
        }

        return ans;
    }

    void update(vector<int>& bit, int idx, int value) {
        int n = bit.size();

        while (idx < n) {
            bit[idx] = max(bit[idx], value);
            idx += idx & (-idx);
        }
    }

    int maxStackHeight(vector<int>& r, vector<int>& h) {

        int n = r.size();

        vector<pair<int, int>> discs;

        for (int i = 0; i < n; i++) {
            discs.push_back({r[i], h[i]});
        }

        // Sort by radius
        sort(discs.begin(), discs.end());

        // h[i] <= 1000
        vector<int> bit(1002, 0);

        int answer = 0;

        int i = 0;

        while (i < n) {

            int j = i;

            // Find all discs having the same radius
            while (j < n && discs[j].first == discs[i].first) {
                j++;
            }

            vector<pair<int, int>> pending;

            // Calculate DP values first
            for (int k = i; k < j; k++) {

                int height = discs[k].second;

                // Only heights STRICTLY smaller than current height
                int best = query(bit, height - 1);

                int current = best + height;

                pending.push_back({height, current});

                answer = max(answer, current);
            }

            // Now update BIT
            // Important: don't update while processing same radius
            for (auto p : pending) {
                update(bit, p.first, p.second);
            }

            i = j;
        }

        return answer;
    }
};
```

*Generated on: 9/24/2026, 7:53:40 PM*