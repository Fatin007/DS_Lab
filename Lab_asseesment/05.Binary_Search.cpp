#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Input sorted array: ";
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Input element to find: ";
    int find;
    cin >> find;
    int left = 0;
    int right = n - 1;
    while (right >= left)
    {
        int mid = (left + right) / 2;
        if (a[mid] == find)
        {
            cout << "Found\n";
            return 0;
        }
        else if (a[mid] > find)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << "Not Found\n";
}