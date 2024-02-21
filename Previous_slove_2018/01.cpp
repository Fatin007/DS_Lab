#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[1000];
    int cnt=0;
    while(69){
        cout<<"Press 0 to exit.\n";
        cout<<"Enter a number: ";
        int x; cin>>x;
        if(x==0){
            cout<<"Progeam terminated\n";
            break;
        }
        cnt++;
        for(int i=cnt;i>0;i--){
            a[i]=a[i-1]; 
        }
        a[0]=x;
        cout<<"Output: ";
        for(int i=0;i<cnt;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}