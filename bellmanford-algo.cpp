#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int,int>,int>> gr;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>> a>>b>>c;
        gr.push_back({{a,b},c});
    }
    vector<int> dist(n,INT_MAX);
    dist[0]  = 0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            int u = gr[j].first.first;
            int v = gr[j].first.second;
            int wt = gr[j].second;
            if(dist[u]!=INT_MAX){
                if(dist[u]+wt<dist[v]){
                    dist[v] = dist[u]+wt;
                }
            }
        }
    }
    int flag=0;
    //if array contain negative cycle return array with size 1 and value -1;
    for(auto it: gr){
        int u = it.first.first;
        int v = it.first.second;
        int wt = it.second;
        if(dist[u]!=INT_MAX){
            if(dist[u]+wt<dist[v]){
                flag=1;
                break;
            }
        }
    }
    if(flag ==0)for(auto it: dist) cout<< it<<" ";
    else{
        vector<int> a;
        a.push_back(-1);
        cout<<a[0]<<endl;
    }
    return 0;
}