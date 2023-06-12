#include <bits/stdc++.h>
using namespace std;

void dfs(int start,int n ,vector<vector<int>> &v,vector<int> &vis,vector<int> &ans){
    ans.push_back(start);
    vis[start] = 1;
    for(auto it: v[start]){
        if(vis[it]!=1){
            dfs(it,n,v,vis,ans);
        }
    }
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
    vector<int> vis(n+1,0);
    vector<int> ans;
    dfs(6,n,v,vis,ans);
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}