class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(word1==word2) return 0;
        int L[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) L[i][j]=0;
                else if(word1[i-1]==word2[j-1]) L[i][j]=L[i-1][j-1]+1;
                else L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
        }
        return word1.size()+word2.size()-2*L[n][m];
    }
};