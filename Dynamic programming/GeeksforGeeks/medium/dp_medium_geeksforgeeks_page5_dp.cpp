//https://www.geeksforgeeks.org/medium/dynamic-programming/5/
//dynamic-programming

#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int cnt_common_subsequence(string text1,string text2)
{
    int n=text1.length();
    int m=text2.length();
    
    int dp[n+1][m+1];
    int cnt=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(text1[i-1]==text2[j-1])
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+1;
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
    }
    
    return dp[n][m];
}

//some problem is still there
int min_cost_to_make_2digits_equal(string text1,string text2)
{
    int n=text1.length();
    int m=text2.length();
    
    int dp[n+1][m+1];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        dp[i][0]=0;
        sum+=text1[i]-'0';
    }
    
    for(int j=0;j<m;j++)
    {
        dp[0][j]=0;   
        sum+=text2[j]-'0';
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+(text1[i-1]-'0');
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return sum-2*dp[n][m];
}

int longest_dividing_subsequence(int arr[],int n)
{
    int dp[n+1];
    dp[0]=1;
    
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]!=0 && arr[i]%arr[j]==0 && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    
    return *max_element(dp,dp+n);
}

int max_sum_subarray(int arr[],int n)
{
    int max_so_far=0;
    int max_ending_here=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        max_ending_here=(arr[i],max_ending_here+arr[i]);
        
        if(max_ending_here>max_so_far)
        {
            max_so_far=max_ending_here;
        }
    }
}


int max_length_subarray_with_givensum(int arr[],int n)
{
    int k=max_sum_subarray(arr,n);
    map<int,int> m;
    int maxLen=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        
        if(sum==k)
        {
            maxLen=i+1;
        }
        
        if(m.find(sum)==m.end())
        {
            m[sum]=i;
        }
        
        if (m.find(sum - k) != m.end()) { 
            if (maxLen < (i - m[sum - k])) 
                maxLen = i - m[sum - k]; 
        } 
    }
    
    return maxLen;
}

int divide_into_segments(int start,int dp[],string adj,int n)
{
    if (start == n) 
        return 0; 
  
    if (dp[start] != -1) 
        return dp[start]; 
        
    
    dp[start]=0;
    int ones=0;
    int zeros=0;
    
    for(int i=start;i<n;i++)
    {
        if(adj[i]=='1')
        {
            ones++;
        }
        else
        {
            zeros++;
        }
        
        if(ones>zeros)
        {
            dp[start]=max(dp[start],
            divide_into_segments(i+1,dp,adj,n)+i-start+1);
        }
        else
        {
             dp[start]=max(dp[start],
            divide_into_segments(i+1,dp,adj,n));
        }
    }
    
    return dp[start];
}

// int largest_area_rectangular_matrix_withgivensum(int arr[][MAX],int k,int n,int m)
// {
   
    
// }

int max_sum_no_adj(int arr[],int n,int start)
{
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    
    dp[0]=0;
    dp[1]=arr[start];
    for(int i=start+1;i<=n;i++)
    {
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
    }
    
    return dp[n];
}

vector<int> fib(int n)
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    for(int i=0;i<n;i++)
    {
        if(v[i-1]+v[i-2]>n)
        {
            break;
        }
        v[i]=v[i-1]+v[i-2];
    }
    
    return v;
}

int ways_to_rep_n_asfibsum(int n)
{
    vector<int> v;
    v=fib(n);
    int ways[n+1];
    memset(ways,0,sizeof(ways));
    ways[0]=1;
    for(int i=0;i<v.size();i++)
    {
        for(int j=v[i];j<=n;j++)
        {
            ways[j]+=ways[j-v[i]];
        }
    }
    
    return ways[n];
}

int sumsubsequence(int arr[],int n,int m)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    
    int dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1; 
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            dp[i][j] += dp[i-1][j];
            if(v[i-1] <= j)
                dp[i][j] += dp[i-1][j-v[i-1]];
        }
    }
    
    int count = 0; 
    for (int j = 1; j <= sum; j++) 
        if (dp[n][j] > 0) 
            if (j % m == 0) 
                count += dp[n][j]; 
  
    return count; 
}
int main()
{
    // string S = "ajblqcpdz", T = "aefcnbtdi";
    // cout << cnt_common_subsequence(S,T);
    
    // string A = "9142", B = "1429";
    // cout << min_cost_to_make_2digits_equal(A,B);
    
    // int arr[] = { 2, 11, 16, 12, 36, 60, 71, 17,  
    //                  29, 144, 288, 129, 432, 993}; 
    // int n = sizeof(arr)/sizeof(arr[0]);  
    // cout << longest_dividing_subsequence(arr,n);
    
    // int arr[] = { 5, -2, -1, 3, -4 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << max_length_subarray_with_givensum(arr,n);
    
    // string adj = "100110001010001"; 
    // int n = adj.size(); 
    // int dp[n + 1]; 
    // memset(dp, -1, sizeof(dp)); 
    // cout << divide_into_segments(0, dp, adj, n) << endl; 
    
    //circular array
    // int arr[] = {1, 2, 3, 4, 5, 1 ,10};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << max(max_sum_no_adj(arr,n,1),max_sum_no_adj(arr,n-2,0));
    
    //no restriction
    // int n=13;
    // cout << ways_to_rep_n_asfibsum(n);
    // return 0;
    
    //with restriction i did using recursion
    
    int arr[]={1, 2, 3 }; 
    int m = 3; 
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << sumsubsequence(arr, n, m) << endl; 
}


