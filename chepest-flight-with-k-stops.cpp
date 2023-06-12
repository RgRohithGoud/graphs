#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k; //n->nodes,m->edges,k->min stops
    vector<vector<pair<int,int>>> gr(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        gr[a].push_back({b,c});
    }
    //return min cost to travel from 0->n-1 with max of k stops
    vector<int> cost(n,INT_MAX);
    cost[0] = 0;
    queue<pair<int,pair<int,int>>> q; //{stops,{node,cost}}
    q.push({0,{0,0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int c = it.second.second;
        if(stops>k) continue; 
        for(auto itr: gr[node]){
            int adjnode = itr.first;
            int edw = itr.second;
            if(c+edw< cost[adjnode] && stops<=k){
                cost[adjnode] = c+edw;
                q.push({stops+1,{adjnode,c+edw}});
            }
        }
    }
    if(cost[n-1]==INT_MAX){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<cost[n-1]<<endl;
    

    return 0;
}