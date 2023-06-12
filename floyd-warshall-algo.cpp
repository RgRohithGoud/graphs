#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j]; 
            // for input if it doesn't an edge, input is given as -1..
            // for solving we just need to change it to max value
            // if i==j matrix[i][j] =0
            if(matrix[i][j]==-1) matrix[i][j] = 1e9;
        }
    }
    //here k means we are travelling from i->j via k
    for(int k = 0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
    //to find negative cycle matrix[i][j]<0 for negative cycles so find that thing
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1e9) matrix[i][j] = -1;
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}