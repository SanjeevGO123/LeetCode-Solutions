class Solution {
public:
    int f(int ind,vector<int>& nums,vector<int>& dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+f(ind-2,nums,dp);
        int noPick=0+f(ind-1,nums,dp);
        return dp[ind]=max(pick,noPick);
    }
    int rob1(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return f(n-1,nums,dp);
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
    }
};