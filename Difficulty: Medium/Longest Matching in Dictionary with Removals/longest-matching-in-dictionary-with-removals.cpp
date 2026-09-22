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