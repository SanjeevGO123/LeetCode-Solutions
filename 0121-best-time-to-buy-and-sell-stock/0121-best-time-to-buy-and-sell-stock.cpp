class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev=prices[0];
        int maxi=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            int cost=prices[i]-prev;
            maxi=max(maxi,cost);
            prev=min(prev,prices[i]);
        }
        return maxi;
    }
};