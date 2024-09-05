class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
            }
        }
        int maxi=0;
        vector<int> dr={1,0,-1,0};
        vector<int> dc={0,1,0,-1};
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int time=q.front().second;
            maxi=max(maxi,time);
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dr[i];
                int yy=y+dc[i];
                if(xx>=0 && xx<n && yy>=0 && yy<m && vis[xx][yy]!=2 && grid[xx][yy]==1){
                    vis[xx][yy]=2;
                    q.push({{xx,yy},time+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=2) return -1;
            }
        }
        return maxi;
    }
};