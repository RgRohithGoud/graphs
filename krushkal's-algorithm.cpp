#include <bits/stdc++.h>
using namespace std;
class disjoint{
    vector<int> size,parent;
public:
    disjoint(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1;i<n+1;i++) parent[i]=i;
    }
    
    int findparent(int n){
        if(parent[n]==n) return n;
        return parent[n] = findparent(parent[n]);
    }
    void unionbysize(int u,int v){
        int a = findparent(u);  //ultimate_parent of u
        int b = findparent(v);  //ultimate_parent of v
        if(a==b) return;
        if(size[a]>size[b]){
            parent[b] = a;
            size[a] +=size[b];
        }else if(size[a]<size[b]){
            parent[a] = b;
            size[b] += size[a];
        }
        else{
            parent[a] = b;
            size[b] += size[a];
        }
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges; //{wt,{u,v}}
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(),edges.end());
    disjoint ds(n);
    int ans =0;
    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findparent(u)!=ds.findparent(v)){
            ds.unionbysize(u,v);
            ans += wt;
        }
    }
    cout<<ans<<endl;

    return 0;
}