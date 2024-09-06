class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size();
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        return l;
    }
};