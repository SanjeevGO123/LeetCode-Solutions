class Solution {
public:
    int f(int n){
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int mini=INT_MAX;
            for(int j=1;j<=sqrt(i);j++){
                int sq=pow(j,2);
                int curr=1+dp[i-sq];
                mini=min(mini,curr);
            }
            dp[i]=mini;
        }
        return dp[n];
    }
    int numSquares(int n) {
        return f(n);
    }
};