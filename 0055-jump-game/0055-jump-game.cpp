class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(maxi<i){
                return false;
            }
            maxi=max(maxi,i+nums[i]);
        }
        return true;
    }
};