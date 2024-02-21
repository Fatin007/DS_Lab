#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[1000];
    int cnt=0;
    cout<<"Press 0 to exit.\n";
    cout<<"Enter a number: ";
    int x; cin>>x;
    if(x==0){
        cout<<"Progeam terminated\n";
        return 0;
    }
    for(int i=cnt-1;i>=0;i++){
        a[i]=a[i-1];
    }
    for(int i=0;i<cnt;i++){
        
    }
}