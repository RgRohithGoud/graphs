#include <bits/stdc++.h>
using namespace std;

bool detect(int start,int n ,vector<vector<int>> &v){
    int vis[n+1] = {0};
    queue<pair<int,int>> q;
    vis[start] = 1;
    q.push({start,-1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent  = q.front().second;
        q.pop(); 
        for(auto it : v[node]){
            if(vis[it]!=1){
                vis[it] =1;
                q.push({it,node});
            }
            else if(it  !=parent){
                return 1;
            }
        }
    }
    return false;
    
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
    bool x = detect(1,n,v);
    cout<<x<<endl;
    return 0;
}