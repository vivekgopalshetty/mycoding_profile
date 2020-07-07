#include<bits/stdc++.h>
using namespace std;

int house_theif(int arr[],int start,int n)
{
    int mem[n];
    mem[n-1]=arr[n-1];
    mem[n-2]=max(arr[n-1],arr[n-2]);

    for(int i=n-3;i>=0;i--)
    {
        mem[i]=max(arr[i]+mem[i+2],mem[i+1]);
    }

    return mem[0];
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    cout << house_theif(arr,0,n);
}
