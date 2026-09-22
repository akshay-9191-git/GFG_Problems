## 01. Longest Matching in Dictionary with Removals

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-largest-word-in-dictionary2430/1)

### Problem Description

**Task:** Given a lowercase string s and a dictionary d[] containing lowercase words, find the longest word in the dictionary that can be obtained by deleting some characters from s without changing the order of the remaining characters.Note: If multiple words have the same maximum length, return the lexicographically smallest one. If no valid word exists, return an empty string.Examples : Input: d = ["ale", "apple", "monkey", "plea"], s = "abpcplea"Output: "apple" Explanation: After deleting "b", "c", "a" s became "apple" which is present in d.

#### Examples

##### Example 1

- **Input:**
```text
d = ["a", "b", "c"], s = "abpcplea"Output: "a"Explanation: After deleting "b", "p", "c", "p", "l", "e", "a" s became "a" which is present in d.Constraints:1 ≤ |s| ≤ 5 * 10⁵¹ ≤ n ≤ 10⁴, where n is the number of words in dictionary^1 ≤ m ≤ 100, where m is the length of word in dictionarys and all words in dictionary consist only of lowercase English letters.
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|s| + n × m × log|s|)
- **Expected Auxiliary Space Complexity:** O(|s|)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-09-22 19:29:45
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int n = s.size();

        vector<array<int, 26>> nextPos(n + 1);

        for (int c = 0; c < 26; c++)
            nextPos[n][c] = -1;

        for (int i = n - 1; i >= 0; i--) {
            nextPos[i] = nextPos[i + 1];
            nextPos[i][s[i] - 'a'] = i;
        }

        auto isSubsequence = [&](const string& word) {
            int pos = 0;

            for (char ch : word) {
                if (pos > n)
                    return false;

                int nxt = nextPos[pos][ch - 'a'];

                if (nxt == -1)
                    return false;

                pos = nxt + 1;
            }

            return true;
        };

        string ans = "";

        for (string& word : d) {
            if (isSubsequence(word)) {
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};
```

*Generated on: 9/22/2026, 7:29:54 PM*