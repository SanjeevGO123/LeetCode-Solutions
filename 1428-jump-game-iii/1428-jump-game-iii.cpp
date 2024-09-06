class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> q;
        vector<int> vis(n,0);
        q.push(start);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            int x=a+arr[a];
            int y=a-arr[a];
            if(x>=0 && x<n){
                if(arr[x]==0) return true;
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                }
            }
            if(y>=0 && y<n){
                if(arr[y]==0) return true;
                if(!vis[y]){
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0 && vis[i]){
                return true;
            }
        }
        return false;
    }
};