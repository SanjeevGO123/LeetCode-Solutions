class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long long>> dp(5, vector<long long>(n, LLONG_MIN));

        
        dp[0][0] = 0;

        for (int i = 1; i <= 4; ++i) {
            long long maxPrev = LLONG_MIN;
            for (int j = 0; j < n; ++j) {
                if (i == 1) {
                    dp[i][j] = static_cast<long long>(a[i - 1]) * b[j];
                } else {
                    if (maxPrev != LLONG_MIN) {
                        dp[i][j] =
                            maxPrev + static_cast<long long>(a[i - 1]) * b[j];
                    }
                }
                maxPrev = max(maxPrev, dp[i - 1][j]);
            }
        }

        return *max_element(dp[4].begin(), dp[4].end());
    }
};