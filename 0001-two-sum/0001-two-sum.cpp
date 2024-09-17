class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int c=target-nums[i];
            if(mp.count(c)){
                return {mp[c],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};