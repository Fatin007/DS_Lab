#include <iostream>
using namespace std;

const int N=100;

class Queue{
public:
    int arr[N];
    int f,r;
    Queue(){
        f=-1;
        r=-1;
    }
    bool empty(){
        return f==-1 && r==-1;
    }
    bool full(){
        return (r+1)%N==f;
    }
    void push(int x){
        if(full()){
            cout<<"Queue is full!"<<endl;
            return;
        }
        else if(empty()) f=r=0;
        else r=(r+1)%N;
        arr[r]=x;
    }
    void pop(){
        if(empty()){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        else if(f==r) f=r=-1;
        else f=(f+1)%N;
    }
    int front(){
        if(empty()){
            cout<<"Queue is empty!"<<endl;
            return-1;
        }
        return arr[f];
    }
};

int main() {
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