#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> wordlist(n);
    string startword;
    string endword;
    cin>>startword;
    cin>>endword;
    for(int i=0;i<n;i++){
        cin>>wordlist[i];
    }
    set<string> st(wordlist.begin(),wordlist.end());
    queue<pair<string,int>> q;
    q.push({startword,1});
    st.erase(startword);
    while(!q.empty()){
        string word = q.front().first;
        int dist = q.front().second;
        if(word==endword) {
            cout<<dist<<endl;
            return 0;
        }
        q.pop();
        for(int i=0;i<word.size();i++){
            char org = word[i];
            for(char x = 'a';x<='z';x++){
                word[i] = x;
                if(st.find(word)!=st.end()){
                    q.push({word,dist+1});
                    st.erase(word);
                }
            }
            word[i]=org;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}