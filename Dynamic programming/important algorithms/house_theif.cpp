#include<bits/stdc++.h>
using namespace std;

int house_theif(int arr[],int mem[],int start,int n)
{
    if(start >= n)
    {
        return 0;
    }

    if(mem[start]==0)
    {
        int x1=arr[start]+house_theif(arr,mem,start+2,n);
        int x2=house_theif(arr,mem,start+1,n);
        mem[start]=max(x1,x2);
    }
    return mem[start];
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

    int mem[1000]={0};
    cout << house_theif(arr,mem,0,n);
}
