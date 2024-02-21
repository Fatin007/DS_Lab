#include <bits/stdc++.h>
using namespace std;
int main() {
    cout<<"Enter array size: ";
    int n; cin>>n;
    int a[n];
    cout<<"Input sorted array: ";
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Input element to find: ";
    int find;
    cin>>find;
    int l=0;
    int r=n-1;
    int step=1;
    while(r>=l){
        int m=(l+r)/2;
        cout<<"Step "<<step<<": (Beg, Mid, End) = ("<<l<<", "<<m<<", "<<r<<")"<<endl;
        step++;
        if(a[m]==find){
            cout<<"Found\n";
            return 0;
        }
        else if(a[m]>find) r=m-1;
        else l=m+1;
    }
    cout<<"Not Found\n";
}