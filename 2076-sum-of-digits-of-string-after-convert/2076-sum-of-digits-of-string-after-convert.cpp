class Solution {
public:
    int getLucky(string s, int k) {
        string num="";
        for(auto it:s){
            int temp=it-'a'+1;
            num+=to_string(temp);
        }
        int sum;
        while(k>0){
            sum=0;
            for(auto it:num){
                sum+=it-'0';
            }
            num=to_string(sum);
            k--;
        }
        return sum;
    }
};