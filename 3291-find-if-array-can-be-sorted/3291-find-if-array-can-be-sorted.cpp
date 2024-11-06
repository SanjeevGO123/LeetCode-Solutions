class Solution {
public:
    int bit(int val){
        return bitset<10>(val).count();
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        bool flag=true;
        while(flag){
            flag=false;
            for(int i=0;i<n-1;i++){
                if(nums[i]>nums[i+1]){
                    if(bit(nums[i])==bit(nums[i+1])){
                        swap(nums[i],nums[i+1]);
                        flag=true;
                    }
                }
            }
        }
        return is_sorted(nums.begin(),nums.end());
    }
};