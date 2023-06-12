#include <bits/stdc++.h>
using namespace std;
class disjoint{

public:
    vector<int> size,parent;
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

int maxconnect( vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    disjoint ds(n*m);

    //step1 : combine all islands

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0) continue;
            int dr[] = {0,0,1,-1};
            int dc[] = {1,-1,0,0};
            for(int k=0;k<4;k++){
                int newr = i + dr[k];
                int newc = j+ dc[k];
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){
                    int cellno = i*m+ j;
                    int adjcell = newr*m + newc;
                    ds.unionbysize(cellno,adjcell);
                }
            }
        }
    }
    //step 2 : check at all zeroes whether if we convert it to 1.. what will be the max size of islands
    int maxans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) continue;
            unordered_set<int> st;
            int dr[] = {0,0,1,-1};
            int dc[] = {1,-1,0,0};
            for(int k=0;k<4;k++){
                int newr = i + dr[k];
                int newc = j+ dc[k];
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){
                    int adjcell = newr*m + newc;
                    st.insert(ds.findparent(adjcell));
                }
            }
            int ans =0;
            for(auto it: st){
                ans += ds.size[it];
            }
            ans++; // number we are converting
            maxans = max(ans,maxans);
        }
    }
    //for safety - if there is no zero in the given matrix find maximum size of parent of that island
    for(int i=0;i< n*m;i++){
        maxans = max(maxans,ds.size[ds.findparent(i)]);
    }
    return maxans;
}