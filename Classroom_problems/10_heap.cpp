#include <bits/stdc++.h>
using namespace std;
vector<int>v;
void insert(int x){
    v.push_back(x);
    int cur=v.size()-1;
    while(cur){
        int par=(cur-1)/2;
        if(v[par]>v[cur]) swap(v[cur],v[par]);
        cur=par;
    }
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        insert(x);
    }
    for(auto x:v) cout<<x<<" ";
}