#include <bits/stdc++.h>
using namespace std;

long long factorial(long long n){
    if(n==0) return 1;
    return n*factorial(n-1);
}

int main(){
    cout<<"Enter n: ";
    long long n; cin>>n;
    cout<<"Factorial: " << factorial(n)<<endl;
}