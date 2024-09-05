class Solution {
public:
    vector<int> dr={1,0,-1,0};
    vector<int> dc={0,1,0,-1};
    void bfs(int sr,int sc,vector<vector<int>>& ans,vector<vector<int>> image,int init,int color){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            ans[x][y]=color;
            q.pop();
            for(int i=0;i<4;i++){
                int xx=dr[i]+x;
                int yy=dc[i]+y;
                if(xx>=0 && xx<image.size() && yy>=0 && yy<image[0].size() && image[xx][yy]==init && ans[xx][yy]!=color){
                    ans[xx][yy]=color;
                    q.push({xx,yy});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int init=image[sr][sc];
        bfs(sr,sc,ans,image,init,color);
        return ans;
    }
};