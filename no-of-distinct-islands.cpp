#include <bits/stdc++.h>
using namespace std;
void dfs(int r,int c,vector<vector<int>> &v,vector<vector<int>> &vis,vector<pair<int,int>> &x, int b0,int b1){
    vis[r][c] = 1;
    x.push_back({r-b0,c-b1});
    int dr[] = {0,0,1,-1};
    int dc[] = {1,-1,0,0};
    for(int i=0;i<4;i++){
        int rr = r + dr[i];
        int cc = c+ dc[i];
        if(rr>=0 && rr<v.size() && cc>=0 && cc< v[0].size() && vis[rr][cc]!=1 && v[rr][cc]==1){
            dfs(rr,cc,v,vis,x,b0,b1);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==1 && vis[i][j]==0){
                vector<pair<int ,int>> x;
                dfs(i,j,v,vis,x,i,j);
                st.insert(x);
            }
        }
    }
    cout<<st.size()<<endl;
    
    return 0;
}