class Solution {
public:
    int f(int i,int j,vector<vector<int>>& d,vector<vector<int>>& dp){
        int n=d.size();
        int m=d[0].size();
        if(i>=n || j>=m) return 1e9;
        if(i==n-1 && j==m-1) return d[i][j] > 0 ? 1:1-d[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int right=f(i+1,j,d,dp);
        int down=f(i,j+1,d,dp);
        int ans=min(right,down) -d[i][j];
        return dp[i][j]=ans>0 ? ans:1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,dungeon,dp);
    }
};