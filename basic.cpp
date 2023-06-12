#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ,m ;
    cin>>n>>m;
    vector<vector<pair<int,int>>> v(n+1);
    for (int i = 0; i < m; i++)
    {
        int x,y,weight;
        cin>>x>>y>>weight;
        v[x].push_back({y,weight});
        v[y].push_back({x,weight});
    }
    
    return 0;
}