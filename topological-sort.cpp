#include <bits/stdc++.h>
using namespace std;

void dfs(int start,int n ,vector<vector<int>> &v,vector<int> &vis,stack<int> &st){
    vis[start] = 1;
    for(auto it: v[start]){
        if(vis[it]!=1){
            dfs(it,n,v,vis,st);
        }
    }
    st.push(start);
}

int main(){
    int n ,m ;
    cin>>n>>m;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < m; i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    vector<int> vis(n+1,0);
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,n,v,vis,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}