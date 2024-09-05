class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        string r=s;
        reverse(s.begin(),s.end());
        vector<vector<int>> LCS(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    LCS[i][j]=0;
                }
                else if(s[i-1]==r[j-1]){
                    LCS[i][j]=1+LCS[i-1][j-1];
                }
                else{
                    LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
                }
            }
        }
        
        return s.size()-LCS[n][n];
    }
};