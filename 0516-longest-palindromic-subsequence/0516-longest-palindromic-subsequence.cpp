class Solution {
public:
    int LCS(string s1, string s2, int m, int n){
        int L[m+1][n+1];
        for (int i=0;i<=m;i++){
            for (int j=0;j<=n;j++){
                if (i==0 || j==0){
                    L[i][j]=0;
                }
                else if (s1[i-1]==s2[j-1]){
                    L[i][j]=L[i-1][j-1]+1;
                }
                else{
                    L[i][j]=max(L[i-1][j], L[i][j-1]);
                }
            }
        }
        return L[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string inverse="";
        for(int i=s.size()-1;i>=0;i--){
            inverse+=s[i];
        }
        int n=s.size();
        int ans=LCS(s,inverse,n,n);
        return ans;
    }
};