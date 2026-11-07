class Solution {
public:

//same as before but instead of maxlen and start, we initiaillize count, and add

    int countSubstrings(string s) {

        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int count = n;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        count++;
                    }
                }
            }
        }

        return count;
        
    }
};
