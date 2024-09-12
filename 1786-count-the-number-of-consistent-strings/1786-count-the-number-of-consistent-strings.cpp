class Solution {
public:
    int countConsistentStrings(string s, vector<string>& words) {
        int count=0;
        for(auto it:words){
            bool flag=true;
            for(auto i:it){
                if(s.find(i)==string::npos){
                    flag=false;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};