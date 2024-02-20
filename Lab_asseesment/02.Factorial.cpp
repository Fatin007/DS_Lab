#include <bits/stdc++.h>
using namespace std;

long long factorial(long long n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    long long n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Factorial: " << factorial(n) << endl;
}