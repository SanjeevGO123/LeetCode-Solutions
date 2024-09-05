class Solution {
public:
    vector<int> dr={1,0,-1,0};
    vector<int> dc={0,1,0,-1};
    void bfs(vector<vector<int>>& mat,vector<vector<int>>& vis){
        queue<pair<pair<int,int>,int>> q;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int len=q.front().second;
            q.pop();
            mat[x][y]=len;
            for(int i=0;i<4;i++){
                int xx=x+dr[i];
                int yy=y+dc[i];
                if(xx>=0 && xx<n && yy>=0 && yy<m && vis[xx][yy]!=1){
                    vis[xx][yy]=1;
                    q.push({{xx,yy},len+1});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        bfs(mat,vis);
        return mat;
    }
};