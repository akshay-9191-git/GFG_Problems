## 01. Generate Usernames

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/new-registration-system--150419/1)

### Problem Description

**Task:** Given an array of strings arr[]. The array represents first names of users, generate a unique username for each entry in the order it appears.Initially, consider all usernames present in the input array as reserved.If a username has not already been assigned to any previous user, keep it unchanged.Otherwise, append the smallest positive integer suffix that produces a username that has not been reserved or assigned to any previous user.Return the array of generated usernames.Examples:Input: arr[] = ["aba", "ab", "aba", "aba", "ab"]Output: ["aba", "ab", "aba1", "aba2", "ab1"]Explanation: The first occurrences of "aba" and "ab" are new, so they remain unchanged. The next "aba" is already used, so "aba1" is assigned. When "aba" appears again, "aba1" is already used, so "aba2" is assigned. Similarly, the second occurrence of "ab" becomes "ab1".Input: arr[] = ["a", "a", "a1", "a"]

#### Examples

##### Example 1

- **Output:**
```text
["aba1", "aba", "aba2"]
```
- **Explanation:** Initially, "aba1" and "aba" are reserved. The first occurrence of each retains its original name. For the second occurrence of "aba", "aba1" is already reserved, so "aba2" is assigned.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n * m)
- **Expected Auxiliary Space Complexity:** O(n * m)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-07 22:34:05
- **Status:** Correct
- **Marks:** 2

```cpp
class Solution {
public:
    vector<string> generateUsernames(vector<string>& arr) {
        unordered_set<string> reserved;
        unordered_set<string> used;
        unordered_map<string, int> nextSuffix;

        for (string &s : arr) {
            reserved.insert(s);
        }

        vector<string> ans;

        for (string &s : arr) {
            if (!used.count(s)) {
                used.insert(s);
                ans.push_back(s);
            } 
            else {
                int &num = nextSuffix[s];

                if (num == 0) num = 1;

                string candidate;

                while (true) {
                    candidate = s + to_string(num);
                    num++;

                    if (!reserved.count(candidate) && !used.count(candidate)) {
                        break;
                    }
                }

                used.insert(candidate);
                ans.push_back(candidate);
            }
        }

        return ans;
    }
};
```

*Generated on: 11/7/2026, 10:34:24 PM*