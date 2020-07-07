//https://www.geeksforgeeks.org/medium/dynamic-programming/5/
//recursion

#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int dp_lcs[MAX][MAX];
int lcs_memoization(string t1,string t2,int n,int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    
    if(dp_lcs[n][m]!=-1)
    {
        return dp_lcs[n][m];
    }
    
    if(t1[n-1]==t2[m-1])
    {
        dp_lcs[n][m]=1+lcs_memoization(t1,t2,n-1,m-1);
    }
    else
    {
        dp_lcs[n][m]=max(lcs_memoization(t1,t2,n-1,m),
            lcs_memoization(t1,t2,n,m-1));
    }
    
    return dp_lcs[n][m];
}

int sum_of_all_paritions(int n,int k)
{
     if(n<k)
    {
        return 0;
    }
    
    if(n<2*k)
    {
        return 1;
    }
    
    int res=1;
    for(int i=k;i<n;i++)
    {
        res+=sum_of_all_paritions(n-i,i);
    }
    
    return res;
}

int edit_distance(string t1,string t2,int n,int m,int dp_editdist[MAX][MAX])
{
    if(n==0 && m==0)
    {
        return 0;
    }
    
    if(n==0)
    {
        return m;
    }
    
    if(m==0)
    {
        return n;
    }
    
    if(dp_editdist[n-1][m-1]!=-1)
    {
        return dp_editdist[n-1][m-1];
    }
    
    if(t1[n-1]==t2[m-1])
    {
        return dp_editdist[n - 1][m - 1]=edit_distance(t1,t2,n-1,m-1,dp_editdist);
    }
    
    int c1=edit_distance(t1,t2,n-1,m-1,dp_editdist);
    int c2=edit_distance(t1,t2,n,m-1,dp_editdist);
    int c3=edit_distance(t1,t2,n-1,m,dp_editdist);
    
    return dp_editdist[n - 1][m - 1]=1+min(c1,min(c2,c3));
}

int max_sum_no_adj(int arr[],int n,int start)
{
    if(start>=n)
    {
        return 0;
    }
    
    return max(arr[start]+max_sum_no_adj(arr,n,start+2),
    max_sum_no_adj(arr,n,start+1));
}

int max_cost_path(int arr[][MAX],int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return INT_MIN;
    }
    
    if(x==n-1 && y==m-1)
    {
        return arr[n-1][m-1];
    }
    
    int num=x+y;
    if((num & (num - 1)) == 0)
    {
        return arr[x][y]+max_cost_path(arr,x+1,y+1,n,m);
    }
    
    
    return arr[x][y]+max(max_cost_path(arr,x+1,y,n,m),
            max_cost_path(arr,x,y+1,n,m));
}

vector<int> fib(int n)
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    for(int i=0;i<n;i++)
    {
        v[i]=v[i-1]+v[i-2];
        if(v[i]>n)
        {
            break;
        }
    }
    
    return v;
}

int ways_to_rep_n_asfibsum(int n,int k,vector<int> fib)
{
    if(n==0 && k==0)
    {
        return 1;
    }
    
    if(n<0 || k<0)
    {
        return 0;
    }
    
    int res=0;
    for(int i=fib.size()-1;i>=0;i--)
    {
        res+=ways_to_rep_n_asfibsum(n-fib[i],k-1,fib);
    }
    
    return res;
}

int main()
{
    // int n=6;
    // int k=2;
    // cout << n*sum_of_all_paritions(n,k);
    
    // string str1 = "sunday"; 
    // string str2 = "saturday"; 
    // int m = str1.length(); 
    // int n = str2.length(); 
    // int dp_editdist[MAX][MAX]; 
    // memset(dp_editdist, -1, sizeof dp_editdist); 
    // cout << edit_distance(str1, str2, m, n, dp_editdist); 
    
    // //linear array
    // int arr[] = {1, 2, 3, 4, 5, 1};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << max_sum_no_adj(arr,n,0);
    
    //circular array
    // int arr[] = {1, 2, 3, 4, 5, 1 ,10};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << max(max_sum_no_adj(arr,n,1),max_sum_no_adj(arr,n-2,0));
    
    // int a[][MAX] = { { 1, 2, 3, 1 }, 
    //                   { 4, 5, 6, 1 }, 
    //                   { 7, 8, 9, 1 }, 
    //                   { 1, 1, 1, 1 } }; 
    // int n = 4; 
    // cout << max_cost_path(a, 0, 0 , n ,n ); 
    
    // int n=13;int k=3;
    // vector<int> fib1=fib(n);
    // cout << ways_to_rep_n_asfibsum(n,k,fib1);
}