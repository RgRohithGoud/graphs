#include <bits/stdc++.h>
using namespace std;

void dfs(int r,int c, vector<vector<char>> &v,vector<vector<int>> &vis){
    vis[r][c] = 1;
    int dr[] = {0,0,-1,1};
    int dc[] = {1,-1,0 ,0};
    for(int i=0;i<4;i++){
        int cr = r+dr[i];
        int cc = c+dc[i];
        if(cr>=0 &&cr< v.size() && cc>=0 && cc< v[0].size() && vis[cr][cc]!=1 && v[cr][cc]=='o'){
            dfs(cr,cc,v,vis);
        }
    }
}

int main(){
    int n ,m ;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m,'o'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<m;i++){
        if(v[0][i]=='o' && vis[0][i]!=1){
            dfs(0,i,v,vis);
        }
        if(v[n-1][i]=='o' && vis[n-1][i]!=1){
            dfs(n-1,i,v,vis);
        }
    }
    for(int i=0;i<n;i++){
        if(v[i][0]=='o'&& vis[i][0]!=1){
            dfs(i,0,v,vis);
        }
        if(v[i][m-1]=='o' && vis[i][m-1]!=1){
            dfs(i,m-1,v,vis);
        }
    }
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(vis[i][j]==0 && v[i][j]=='o'){
                v[i][j] = 'x';
            }
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}