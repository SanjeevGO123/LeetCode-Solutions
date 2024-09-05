class Solution {
public:
    void bfs(int i,vector<int>& vis,vector<int> adj[]){
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            for(auto it:adj[ele]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                bfs(i,vis,adj);
            }
        }
        return count;
    }
};