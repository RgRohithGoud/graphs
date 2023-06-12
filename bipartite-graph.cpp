#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &v,int start,int n){
    queue<int> q;
    vector<int> vis(n+1,-1);
    q.push(1);
    vis[1] = 0;
    while(!q.empty()){
        int node  = q.front();
        q.pop();
        for(auto it: v[node]){
            if(vis[it] == -1){
                vis[it] = 1-vis[node];
                q.push(it);
            }
            else if(vis[it]==vis[node]) return false;
        }
    }
    return true;
}

int main(){
    int n ,m ;
    cin>>n>>m;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < m; i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    cout<<bfs(v,1,n)<<endl;
    
    return 0;
}