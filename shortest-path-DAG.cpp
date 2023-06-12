#include <bits/stdc++.h>
using namespace std;

void dfs(int start,vector<vector<pair<int,int>>> &gr,vector<int> &vis,stack<int> &st){
    vis[start] = 1;
    for(auto it:gr[start]){
        if(vis[it.first]!=1){
            dfs(it.first,gr,vis,st);
        }
    }
    st.push(start);
}

int main(){
    int n ,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> gr(n);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        gr[a].push_back({b,c});
    }
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i,gr,vis,st);
    }
    vector<int> dist(n,INT_MAX);
    int start = 6;
    dist[start] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it: gr[node]){
            dist[it.first] = min(dist[node]+it.second,dist[it.first]);
        }
    }
    for(auto it: dist) cout<<it<<" ";
    return 0;
}