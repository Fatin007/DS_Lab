#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10; 
vector<int>graph[N];
bool vis_bfs[N];
bool vis_dfs[N];

void dfs(int src){
    cout<<src<<" ";
    vis_dfs[src]=true;
    for(auto child:graph[src]){
        if(!vis_dfs[child]) dfs(child);
    }
}

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis_bfs[src]=true;
    while(q.size()){
        int par=q.front();
        q.pop();
        cout<<par<<" ";
        for(auto child:graph[par]){
            if(!vis_bfs[child]){
                q.push(child);
                vis_bfs[child]=true;
            }
        }
    }
}

int main(){
    int n,e; cin>>n>>e;
    while(e--){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    // int src; cin>>src;
    memset(vis_bfs,false,sizeof(vis_bfs));
    memset(vis_dfs,false,sizeof(vis_dfs));
    cout<<"BFS Traversal: ";
    bfs(0);
    cout<<endl;
    cout<<"DFS Traversal: ";
    dfs(0);
}
// 7 8
// 0 1 
// 1 2 
// 0 4 
// 1 3 
// 2 0
// 3 4
// 1 5
// 3 6