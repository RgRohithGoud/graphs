#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> gr(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        gr[a].push_back({b,c});
        gr[b].push_back({a,c});
    }
    priority_queue <pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq; 
    vector<int> ways(n+1,0);
    ways[1] =1;
    vector<int> dist(n+1,INT_MAX);
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        for(auto it : gr[node]){
            int adjnode = it.first;
            int edw = it.second;
            if(edw+d== dist[adjnode]) ways[adjnode] += ways[node];
            if(edw+d< dist[adjnode]){
                dist[adjnode] = edw+d;
                ways[adjnode] = ways[node];
                pq.push({edw+d,adjnode});
            }
        }
    }
    cout<<ways[n-1]<<endl;
    return 0;
}