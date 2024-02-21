#include <bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter array size: ";
    int n; cin>>n;
    int a[n];
    cout<<"Input array: ";
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++){
        cout<<"Pass "<<i+1<<":\n";
        for(int j=0;j<n-i-1;j++){
            if(a[j]<a[j+1]) swap(a[j],a[j+1]);
            for(int k=0;k<n;k++) cout<<a[k]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<"Final array: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}