#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ,m ;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t;
            cin>>t;
            v[i][j] = t;;
        }

    }
    vector<vector<int>> vis(n,vector<int> (m,0));
    vector<vector<int>> dist(n,vector<int> (m,0));
    queue <pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==1){
                vis[i][j]=1;
                q.push({{i,j},0});
            }
        }
    }
    int dr[] = {1,0,-1,0};
    int dc[] = {0,-1,0,1};
    while(!q.empty()){
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int d = q.front().second;
        dist[cr][cc] = d;
        q.pop();
        for(int i=0;i<4;i++){
            int r = cr+dr[i];
            int c = cc + dc[i];
            if(r>=0 && r<n && c>=0 && c<m && vis[r][c]!=1){
                q.push({{r,c},d+1});
                vis[r][c] =1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}