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
        vector<int> vis(n,0);
        vis[0] = 1;
        priority_queue <pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>> > pq;
        pq.push({{0,0},-1}); //{{dist, node} , parent}
        int count =0;
        vector<pair<int,int>> ans;
        while(!pq.empty()){
            auto it  = pq.top();
            pq.pop();
            int d = it.first.first;
            int node = it.first.second;
            int parent = it.second;
            if(vis[node]==1) continue;
            vis[node] = 1;
            if(parent!=-1){
                ans.push_back({parent,node});
                count += d;
            }
            for(auto itr: gr[node]){
                if(vis[itr.first]!=1){
                    pq.push({{itr.second,itr.first},node});
                }
            }
        }
        cout<<count<<endl;
        for(auto it: ans) cout<<it.first<<" "<<it.second<<endl;
    return 0;
}