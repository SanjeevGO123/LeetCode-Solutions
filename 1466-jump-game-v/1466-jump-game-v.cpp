class Solution {
public:
    int f(int i,int d,vector<int>& v,vector<int>& dp){
        if(dp[i]!=-1) return dp[i];
        int ans=1;
        for(int ii=i-1;ii>=0 && ii>=i-d && v[ii]<v[i];ii--){
            ans=max(ans,1+f(ii,d,v,dp));
        }
        for(int ii=i+1;ii<v.size() && ii<=i+d && v[ii]<v[i];ii++){
            ans=max(ans,1+f(ii,d,v,dp));
        }
        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> dp(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,f(i,d,arr,dp));
        }
        return ans;
    }
};