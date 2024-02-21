#include <bits/stdc++.h>
using namespace std;

const int N=3;

class Queue{
public:
    int a[N];
    int f,r;
    Queue(){
        f=-1;
        r=-1;
    }
    bool empty(){
        return f==-1 && r==-1;
    }
    bool full(){
        if(r+1==N) r==0;
        return (r+1)%N==f;
    }
    void push(int x){
        if(full()){
            cout<<"Queue is full!"<<endl;
            return;
        }
        else if(empty()) f=r=0;
        else if(r+1==N) r=0;
        else r++;
        a[r]=x;
    }
    void pop(){
        if(empty()){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        else if(f==r) f=r=-1;
        else if(f+1==N) f=0;
        else f++;
    }
    int front(){
        if(empty()){
            cout<<"Queue is empty!"<<endl;
            return-1;
        }
        return a[f];
    }
};

int main(){
    Queue q;
    int n; cin>>n;
    while(n--){
        int x; cin>>x;
        q.push(x);
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}