#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> gr(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        gr[a].push_back({b,c});
        gr[b].push_back({a,c});
    }
    set<pair<int,int>> pq;
    pq.insert({0,0}); //{dist,node}
    vector<int> dist(n,INT_MAX);
    dist[0] = 0;
    while(!pq.empty()){
        int d = (*pq.begin()).first;
        int node =(*pq.begin()).second;
        pq.erase(*pq.begin());
        for(auto it: gr[node]){
            if(dist[it.first]> d+ it.second ){
                if(dist[it.first]!=INT_MAX) pq.erase({dist[it.first],it.first});
                dist[it.first] = d+it.second;
                pq.insert({dist[it.first],it.first});
            }
        }
    }
    for(auto it: dist) cout<<it<<" ";
    return 0;
}