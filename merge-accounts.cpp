#include <bits/stdc++.h>
using namespace std;
class disjointset{
    vector<int> size;
    vector<int> parent;
public:
    disjointset(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int findparent(int n){
        if(parent[n]==n) return n;
        return parent[n] = findparent(parent[n]);
    }
    void unionbysize(int u,int v){
        int a = findparent(u);
        int b=  findparent(v);
        if(a==b) return ;
        if(size[a]==size[b]){
            parent[b] = a;
            size[a] += size[b];
            return;
        }
        if(size[a]>size[b]){
            parent[b] = a;
            size[a] += size[b];
            return;
        }
        else{
            parent[a] = b;
            size[b] += size[a];
            return;
        }
    }

};

vector<vector<string>> mergedetails(vector<vector<string>> &details){
    int n = details.size();
    disjointset ds(n);
    unordered_map<string,int> mp;
    for(int i=0;i<n ;i++){
        for(int j= 1;j< details[i].size();j++){
            if(mp.find(details[i][j])==mp.end()) mp[details[i][j]]=i;
            else{
                ds.unionbysize(i,mp[details[i][j]]);
            }
        }
    }
    vector<vector<string>> abc(n);
    for(auto it: mp){
        abc[ds.findparent(it.second)].push_back(it.first);
    }
    vector<vector<string>> ans;
    for(int i=0;i<n;i++){
        sort(abc[i].begin(),abc[i].end());
        if(abc.size()==0) continue;
        vector<string> v;
        v.push_back(details[i][0]);
        for(int x = 0;x<abc.size();x++){
            v.push_back(abc[i][x]);
        }
        ans.push_back(v);
    }
    return ans;

}