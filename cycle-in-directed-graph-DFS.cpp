#include <bits/stdc++.h>
using namespace std;

bool cyc(int node,vector<vector<int>> &gr,int *vis,int* pathvis){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto it : gr[node]){
        if(!vis[it]){
            if(cyc(it,gr,vis,pathvis)==1) return 1;
        }
        else if(pathvis[it]==1){
            return 1;
        }
    }
    pathvis[node] = 0;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> gr(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        gr[u].push_back(v);
    }
    int vis[n+1] = {0};
    int pathvis[n+1] = {0};
    bool c = false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(cyc(1,gr,vis,pathvis)==1){
                c = true;
                break;
            } 
        }
    }
    cout<<c<<endl;
    return 0;
}