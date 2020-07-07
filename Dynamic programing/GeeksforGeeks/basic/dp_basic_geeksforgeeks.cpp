//ALL DP BASIC GEEKSFORGEEKS
//https://www.geeksforgeeks.org/basic/dynamic-programming/0/
//https://www.geeksforgeeks.org/basic/dynamic-programming/1/

#include <bits/stdc++.h>
using namespace std;

int count_no_path(int m,int n)
{
    int dp[m+1][n+1];
    memset(dp,-1,sizeof(dp));
    
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=1;
    }
    
    for(int i=1;i<=m;i++)
    {
        dp[i][0]=1;
    }
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    
    return dp[m][n];
}


int no_of_ways_to_cover_dist(int dist)
{
    int dp[dist+1];
    
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    
    for(int i=4;i<=dist;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    
    return dp[dist];
}

int prefixsum_2darray(int arr[][5],int n,int m)
{
    int dp[n+1][m+1];
    
    dp[0][0]=arr[0][0];
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=arr[0][i]+dp[0][i-1];
    }

    for(int i=1;i<=m;i++)
    {
        dp[i][0]=arr[i][0]+dp[i-1][0];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]
                         -dp[i-1][j-1]+arr[i][j];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

float probablity_to_reach(int n,float p)
{
    float dp[n+1];
    
    dp[2]=1*p;
    dp[3]=1*(1-p);
    dp[1]=0;
    for(int i=4;i<=n;i++)
    {
        dp[i]=p*dp[i-2]+(1-p)*dp[i-3];
    }
    
    return dp[n];
}

int longest_increasing_subsequence(int arr[],int n)
{
    int lis[n];
    lis[0]=1;
    
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
           if(arr[i]<arr[j] && lis[i] < lis[j]+1)
           {
               lis[i]=lis[j]+1;
           }
        }
    }
    
    return *max_element(lis,lis+n);
}

int longest_increasing_subsequence_oddeven(int arr[],int n)
{
    int lis[n];
    lis[0]=1;
    
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
           if(arr[i]<arr[j] && lis[i] < lis[j]+1 && (arr[i]+arr[j])%2!=0)
           {
               lis[i]=lis[j]+1;
           }
        }
    }
    
    return *max_element(lis,lis+n);
}

int longest_increasing_subsequence_posneg(int arr[],int n)
{
    int lis[n];
    lis[0]=1;
    
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
           if(arr[i]<arr[j] && lis[i] < lis[j]+1 && (arr[i]+arr[j])%2!=0)
           {
               lis[i]=lis[j]+1;
           }
        }
    }
    
    return *max_element(lis,lis+n);
}

void longest_increasing_subsequence_posned_ateveryindex(int arr[],int n)
{
    int lis[n];
    lis[n-1]=1;
    
   
    for (int i = n - 2; i >= 0; i--) { 
        if (arr[i] * arr[i + 1] < 0) 
            lis[i] = lis[i + 1] + 1; 
        else
            lis[i] = 1; 
    } 
   
     
    for(int i=0;i<n;i++)
    {
        cout << lis[i] << " ";
    }
    
}

int main() {
    
    int arr[] = {-5, -1, -1, 2, -2, -3 };
    
    longest_increasing_subsequence_posned_ateveryindex(arr,6);
	
}