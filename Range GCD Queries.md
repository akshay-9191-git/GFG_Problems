## 01. Range GCD Queries

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/range-gcd-queries3654/1)

### Problem Description

**Task:** Given an integer array arr[] and a 2D array queries[][] containing q queries, where each query is one of the following two types:Type 1: [0, l, r] - > Return the GCD of all elements in the range [l, r] (both inclusive).Type 2: [1, index, value] - > Update arr[index] to value.Return an array containing the answers to all Type 1 queries in the order they appear in queries[][].Note: Use 0-based indexing.Examples:Input: arr[] = [2, 3, 4, 6, 8, 16], q = 3, queries[][] = [[0, 0, 2], [1, 3, 8], [0, 2, 5]]

#### Examples

##### Example 1

- **Output:**
```text
[1, 4]
```
- **Explanation:** Initially, arr[] = [2, 3, 4, 6, 8, 16]. Query [0, 0, 2]: Find the GCD of the subarray arr[0...2] = [2, 3, 4]. The GCD is 1. Query [1, 3, 8]: Update arr[3] from 6 to 8. The array becomes [2, 3, 4, 8, 8, 16]. Query [0, 2, 5]: Find the GCD of the subarray arr[2...5] = [4, 8, 8, 16]. The GCD is 4. Therefore, the answers to all Type 0 queries are [1, 4].

##### Example 2

- **Input:**
```text
arr[] = [12, 18, 24, 30, 36], q = 4, queries[][] = [[0, 1, 3], [1, 2, 15], [0, 0, 2], [0, 2, 4]]Output: [6, 3, 3]Explanation: Initially, arr[] = [12, 18, 24, 30, 36].Query [0, 1, 3]: Find the GCD of the subarray arr[1...3] = [18, 24, 30]. The GCD is 6.Query [1, 2, 15]: Update arr[2] from 24 to 15. The array becomes [12, 18, 15, 30, 36].Query [0, 0, 2]: Find the GCD of the subarray arr[0...2] = [12, 18, 15]. The GCD is 3.Query [0, 2, 4]: Find the GCD of the subarray arr[2...4] = [15, 30, 36]. The GCD is 3.Therefore, the answers to all Type 0 queries are [6, 3, 3].Constraints:1 ≤ arr.size() ≤ 10⁵¹ ≤ q ≤ 10⁵⁰ ≤ l, r, index ≤ arr.size()-11 ≤ arr[i], value ≤ 10⁵
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O((arr.size()+q)*log n*log(max_element(arr)))
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-28 22:37:18
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:

    vector<int> tree;

    // Build segment tree
    void build(vector<int>& arr, int node, int start, int end) {

        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);

        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }


    // Range GCD query
    int query(int node, int start, int end, int l, int r) {

        // Completely outside
        if (r < start || end < l) {
            return 0;
        }

        // Completely inside
        if (l <= start && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;

        int leftGCD = query(2 * node, start, mid, l, r);
        int rightGCD = query(2 * node + 1, mid + 1, end, l, r);

        return gcd(leftGCD, rightGCD);
    }


    // Point update
    void update(int node, int start, int end, int index, int value) {

        if (start == end) {
            tree[node] = value;
            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid) {
            update(2 * node, start, mid, index, value);
        }
        else {
            update(2 * node + 1, mid + 1, end, index, value);
        }

        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }


    vector<int> processQueries(vector<int>& arr,
                               vector<vector<int>>& queries) {

        int n = arr.size();

        tree.resize(4 * n);

        // Build tree
        build(arr, 1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {

            if (q[0] == 0) {

                int l = q[1];
                int r = q[2];

                int result = query(1, 0, n - 1, l, r);

                ans.push_back(result);
            }

            else {

                int index = q[1];
                int value = q[2];

                update(1, 0, n - 1, index, value);
            }
        }

        return ans;
    }
};
```

*Generated on: 9/28/2026, 10:37:47 PM*