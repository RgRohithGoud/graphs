#include <bits/stdc++.h>
using namespace std;

vector<int> topo(int n,vector<vector<int>> gr){
    queue<int> q;
    int indeg[n]= {0};
    for(int i=0;i<n;i++){
        for(auto it:gr[i]) indeg[it]++;
    }
    for(int i=0;i<n;i++){
        if(indeg[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto it: gr[node]){
            indeg[it]--;
            if(indeg[it]==0) q.push(it);
        }
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<string> dic(n); 
    for(int i=0;i<n;i++){
        cin>>dic[i];
    }
    string a,b;
    vector<vector<int>> gr(k);
    for(int i=0;i<n-1;i++){
        a = dic[i];
        b= dic[i+1];
        int x=0;
        while(x<a.size() && x<b.size()){
            if(a[x]!=b[x]){
                gr[a[x]-'a'].push_back(b[x]-'a');
                break;
            }
            x++;
        }
    }
    vector<int> top = topo(k,gr);
    for(auto it:top) cout<<(char)(it+'a')<<" ";
    cout<<endl;
    return 0;
}