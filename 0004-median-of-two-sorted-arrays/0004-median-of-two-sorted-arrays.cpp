class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median=0.0;
        int i;
        vector<int> merged(nums1.size()+nums2.size());
        for(i=0;i<nums1.size();i++){
            merged[i]=nums1[i];
        }
        cout<<i;
        for(int k=i;k<nums1.size()+nums2.size();k++){
            merged[k]=nums2[k-nums1.size()];
        }
        for(int p=0;p<merged.size();p++){
            for(int q=0;q<merged.size();q++){
                if(merged[p]>merged[q]){
                    int temp=merged[p];
                    merged[p]=merged[q];
                    merged[q]=temp;
                }
            }
        }
        if(merged.size()%2!=0){
            median=merged[merged.size()/2];
        }
        else{
            median=(merged[merged.size()/2-1]+merged[(merged.size()/2)])/(double)2;
        }
        return median;
    }
};