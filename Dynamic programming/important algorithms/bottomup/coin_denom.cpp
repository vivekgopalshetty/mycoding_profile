#
#include<bits/stdc++.h>
using namespace std;

int coin_denom(int a[],int mem[],int capacity)
{
    if(capacity==0 || capacity==1 || capacity==2)
    {
        return 1;
    }
    else if(capacity==3)
    {
        return 2;
    }

    int n=capacity;
    for(int i=4;i<=n;i++)
    {
        mem[i]=mem[i-a[0]]+mem[i-a[1]]+mem[i-a[2]];
    }

    return mem[n];
}


    int main()
{
    int a[3]={1,3,4};
    int mem[10000]={0};
    mem[0]=1;
    mem[1]=1;
    mem[2]=1;
    mem[3]=2;
    int x;
    cin >> x;
    cout << coin_denom(a,mem,x);
}
