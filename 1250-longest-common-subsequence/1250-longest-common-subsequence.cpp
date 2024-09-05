class Solution {
public:
    int LCS(string s1,string s2,int m,int n){
        int L[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    L[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1]){
                    L[i][j]=L[i-1][j-1]+1;
                }else{
                    L[i][j]=max(L[i-1][j],L[i][j-1]);
                }
            }
        }
        return L[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        int ans=LCS(text1,text2,m,n);
        return ans;

    }
};