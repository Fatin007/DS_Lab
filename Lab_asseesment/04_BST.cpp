#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int Tree[N];

void insert(int idx,int x){
    if(Tree[idx]==-1){
        Tree[idx]=x;
        return;
    }
    if(x<Tree[idx]) insert(idx*2+1,x);
    else if(x>Tree[idx]) insert(idx*2+2,x);
}

void inorder(int idx){
    if(Tree[idx]!=-1){
        inorder(idx*2+1);
        cout<<Tree[idx]<<" ";
        inorder(idx*2+2);
    }
}

int main(){
    int head=0;
    memset(Tree,-1,sizeof(Tree));
    cout<<"Enter number of node: "<<endl;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        insert(head,x);
    }
    cout<<"Inorder Traversal: ";
    inorder(head);
}