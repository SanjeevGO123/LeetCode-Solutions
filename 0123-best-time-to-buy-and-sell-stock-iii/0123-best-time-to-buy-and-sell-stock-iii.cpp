class Solution {
public:
    int f(int i,int buy,vector<int>& prices,int n,vector<vector<vector<int>>>& dp,int cap){
        if(i==n) return 0;
        if(cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+f(i+1,0,prices,n,dp,cap),f(i+1,1,prices,n,dp,cap));
        }
        else{
            profit=max(prices[i]+f(i+1,1,prices,n,dp,cap-1),f(i+1,0,prices,n,dp,cap));
        }
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return f(0,1,prices,n,dp,2);
    }
};