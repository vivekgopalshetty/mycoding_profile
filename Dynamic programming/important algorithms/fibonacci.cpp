
#include<bits/stdc++.h>
using namespace std;

int fibonacci(int arr[],int n)
{
    if(n==1)
    {
        return 0;
    }
    else if(n==2)
    {
        return 1;
    }

    if(arr[n]==0)
    {
        arr[n]=fibonacci(arr,n-1)+fibonacci(arr,n-2);
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    int arr[10000];
    arr[0]=0;
    arr[1]=1;
    cout << fibonacci(arr,n);
}


