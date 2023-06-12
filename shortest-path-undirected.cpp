#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> gr(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    vector<int> dist(n,INT_MAX);
    int start = 0;
    dist[start] = 0;
    queue<pair<int,int>> q; 
    q.push({start,dist[start]});
    while (!q.empty())
    {
        int node = q.front().first;
        dist[node] = q.front().second;
        q.pop();
        for(auto it: gr[node]){
            if(dist[it]==INT_MAX){
                q.push({it,dist[node]+1});
            }
        }
    }
    for(auto it: dist ) cout<<it<<" ";

    return 0;
}