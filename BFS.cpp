#include <bits/stdc++.h>
using namespace std;

vector<int> traverse(int start,int n ,vector<vector<int>> &v){
    vector<int> bfs;
    int vis[n+1] = {0};
    queue<int> q;
    vis[start] = 1;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);  
        for(auto it : v[node]){
            if(vis[it]!=1){
                vis[it] =1;
                q.push(it);
            }
        }
    }
    return bfs;
    
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
    vector<int> bfs = traverse(6,n,v);
    for(auto it : bfs){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}