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
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0}); //{dist,node}
    vector<int> dist(n,INT_MAX);
    vector<int> parent(n);
    for(int i=0;i<n;i++) parent[i] =i;
    dist[0] = 0;
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: gr[node]){
            if(dist[it.first]> d+ it.second ){
                dist[it.first] = d+it.second;
                parent[it.first] = node;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    if(dist[n-1]==INT_MAX){
        cout<<"-1"<<endl;
        return 0;
    }
    vector<int> ans;
    int x = n-1;
    while(parent[x] !=x){
        ans.push_back(x);
        x = parent[x];
    }
    reverse(ans.begin(),ans.end());
    for(auto it: ans) cout<<it<<" ";
    return 0;
}