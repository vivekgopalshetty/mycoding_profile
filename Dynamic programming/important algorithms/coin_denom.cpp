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

    if(mem[capacity]==0)
    {
        int x1=coin_denom(a,mem,capacity-a[0]);
        int x2=coin_denom(a,mem,capacity-a[1]);
        int x3=coin_denom(a,mem,capacity-a[2]);
        mem[capacity]=x1+x2+x3;
    }
    return mem[capacity];
}


    int main()
{
    int a[3]={1,3,4};
    int mem[10000]={0};
    int x;
    cin >> x;
    cout << coin_denom(a,mem,x);
}
