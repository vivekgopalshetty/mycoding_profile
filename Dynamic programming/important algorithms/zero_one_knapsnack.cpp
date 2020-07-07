#include<bits/stdc++.h>
using namespace std;


int zero_one(int weights[],int profits[],int dp[100][100],int start,int capacity,int n)
{
    if(capacity<0 || start>=n)
    {
        return 0;
    }

    if(dp[start][capacity]!=0)
    {
        return dp[start][capacity];
    }

    int x1=0;
    if(capacity>=weights[start])
    {
        x1=profits[start]+zero_one(weights,profits,dp,start+1,capacity-weights[start],n);
    }
    int x2=zero_one(weights,profits,dp,start+1,capacity,n);

    dp[start][capacity]=max(x1,x2);

    return dp[start][capacity];
}

int main()
{
    int n;
    cin>> n;

    int weights[n];
    int profits[n];

    for(int i=0;i<n;i++)
    {
        cin >> weights[i];
    }

    for(int i=0;i<n;i++)
    {
        cin >> profits[i];
    }

    int x;
    cin >> x;

    int dp[100][100]={};
    cout << zero_one(weights,profits,dp,0,x,n);
}
