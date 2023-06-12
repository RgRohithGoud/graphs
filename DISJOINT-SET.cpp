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
    disjoint ds(7);
    ds.unionbysize(1,2);
    ds.unionbysize(2,3);
    ds.unionbysize(4,5);
    ds.unionbysize(6,7);
    ds.unionbysize(5,6);
    if(ds.findparent(3)== ds.findparent(6)){
        cout<<"same"<<endl;
    }
    else cout<<"not same"<<endl;
    ds.unionbysize(3,7);
    if(ds.findparent(3)== ds.findparent(6)){
        cout<<"same"<<endl;
    }
    else cout<<"not same"<<endl;

    return 0;
}