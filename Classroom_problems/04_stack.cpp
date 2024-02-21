#include <iostream>
using namespace std;

const int N=100;

class Stack {
public:
    int arr[N];
    int t;
    Stack(){
        t=-1;
    }
    bool empty(){
        return t==-1;
    }
    bool full(){
        return t==N-1;
    }
    void push(int x){
        if (full()){
            cout<<"Stack overflow!"<<endl;
            return;
        }
        t++;
        arr[t]=x; 
    }
    void pop(){
        if(empty()){
            cout<<"Stack underflow!"<<endl;
            return;
        }
        t--;
    }
    int top(){
        if(empty()){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return arr[t];
    }
};

int main() {
    Stack s;
    int n; cin>>n;
    while(n--){
        int x; cin>>x;
        s.push(x);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}