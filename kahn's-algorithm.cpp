#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ,m ;
    cin>>n>>m;
    vector<vector<int>> v(n+1);
    for (int i = 0; i < m; i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    int indeg[n+1] = {0};
    for(int i=1;i<=n;i++){
        for(auto it: v[i]){
            indeg[it]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto it: v[node]){
            indeg[it]--;
            if(indeg[it]==0) q.push(it);
        }
    }
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}