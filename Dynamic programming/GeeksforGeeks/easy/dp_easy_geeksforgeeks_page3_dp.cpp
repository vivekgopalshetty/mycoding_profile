//https://www.geeksforgeeks.org/easy/dynamic-programming/3/
//dynamic-programming

#include<bits/stdc++.h>
using namespace std;


int count_sum134(int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=1;
    dp[3]=2;
    
    for(int i=4;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-3]+dp[i-4];
    }
    
    return dp[n];
}

int unit=9;
int no_of_monotones(int k)
{
   int dp[k][unit];
   memset(dp,0,sizeof(dp));
   
   for(int i=0;i<unit;++i)
   {
       dp[0][i]=i+1;
   }
   
   for(int i=1;i<k;++i)
   {
       for(int j=1;j<unit;++j)
       {
           dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
       }
   }
  
    return dp[k-1][unit-1]; 
   
}

//now above problem with prefix sum
int maximum_subarray_sum_usingprefix(int arr[],int n)
{
   
    int min_prefix_sum = 0; 
    int res = numeric_limits<int>::min(); 
  
    int prefix_sum[n]; 
    prefix_sum[0] = arr[0]; 
    for (int i = 1; i < n; i++)  
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];         
  
    for (int i = 0; i < n; i++) { 
        res = max(res, prefix_sum[i] -  
                       min_prefix_sum); 
        min_prefix_sum = min(min_prefix_sum,  
                             prefix_sum[i]); 
    } 
      
    return res;
}

bool check_path_available(int arr[5][5],int m,int n)
{
    arr[0][0]=1;
    
    for(int i=1;i<m;i++)
    {
        if(arr[i][0]!=-1)
        {
            arr[i][0]=arr[i-1][0];
        }
    }
    
    for(int j=1;j<n;j++)
    {
        if(arr[0][j]!=-1)
        {
            arr[0][j]=arr[0][j-1];
        }
    }
    
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(arr[i][j]!=-1)
            {
               arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
            }
        }
    }
    
    return (arr[m-1][n-1]==1);
}


int product_increasing_subsequence(int arr[],int n)
{
    int dp[n+1]={1};
    
    for(int i=0;i<n;i++)
    {
        dp[i]=arr[i];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && dp[i]<dp[j]*arr[i])
            {
                dp[i]=dp[j]*arr[i];
            }
        }
    }
    
    return *max_element(dp,dp+n);
}


int hosaya_traingle(int n)
{
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    dp[2][2]=1;  
    
    for (int i = 2; i < n; i++) 
    { 
        for (int j = 0; j < n; j++) 
        {
            if ( i > j)
            {
                dp[i][j]=dp[i-1][j]+dp[i-2][j];
            }
            else if ( i == j) 
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-2][j-2];
            }
        }
    }
    
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j <= i; j++)  
            cout << dp[i][j] << " ";  
            
        cout << endl; 
    }
}

int eulerian_number(int n,int m)
{
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i>j)
            {
                if(j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j]=(i-j)*dp[i-1][j-1]+(j+1)*dp[i-1][j]; 
                }
            }
        }
    }
    
    return dp[n][m];
}

int smallestSumSubarr(int arr[], int n) 
{ 
    int min_ending_here = INT_MAX; 
    int min_so_far = INT_MAX; 
    
    for (int i=0; i<n; i++) 
    { 
        if (min_ending_here > 0) 
            min_ending_here = arr[i]; 
        else
            min_ending_here += arr[i]; 
          
        min_so_far = min(min_so_far, min_ending_here);             
    } 
    return min_so_far; 
} 

int coin_game_subtract_onexy(int n,int x,int y)
{
    bool dp[n+1];
    
    dp[0]=false;
    dp[1]=true;
    
    for(int i=2;i<=n;i++)
    {
        if(i-1>=0 && !dp[i-1])
        {
            dp[i]=true;
        }
        else if(i-x>=0 && !dp[i-x])
        {
            dp[i]=true;
        }
        else if(i-y>=0 && !dp[i-y])
        {
            dp[i]=true;
        }
        else
        {
            dp[i]=false;
        }
    }
    
    return dp[n];
}

int numberOfWays(int x) 
{ 
    int dp[x+1]; 
    dp[0] = dp[1] = 1; 
  
    for (int i=2; i<=x; i++) 
       dp[i] = dp[i-1] + (i-1)*dp[i-2]; 
  
    return dp[x]; 
} 

int smallestSumSubarr_v2(int arr[], int n) 
{ 
    int min_ending_here = INT_MAX; 
    int min_so_far = INT_MAX; 
    
    for (int i=0; i<n; i++) 
    { 
        if (min_ending_here > 0) 
            min_ending_here = arr[i]; 
        else
            min_ending_here += arr[i]; 
          
        min_so_far = min(min_so_far, min_ending_here);             
    } 
    return min_so_far; 
} 
  
int unique_paths(int arr[3][3],int n,int m)
{
    int dp[n+1][m+1];
    memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]!=1)
            dp[i][0]=1;
        else
        {
            dp[i][0]=0;
        }
    }
    
    for(int i=0;i<m;i++)
    {
        if(arr[0][i]!=1)
            dp[0][i]=1;
        else
        {
            dp[0][i]=0;
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]==0)
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    return dp[n-1][m-1];
    
}

#define MAX 50 
int max_array_end_remove(int arr[],int start,int end,int k,int dp_endarr[][MAX])
{
    if(start>end)
    {
        return 0;
    }
    
    if(dp_endarr[start][end]!=-1)
    {
        return dp_endarr[start][end];
    }
    
    dp_endarr[start][end]=max(arr[start]*k+max_array_end_remove(arr,start+1,end,k+1,dp_endarr)
    ,arr[end]*k+max_array_end_remove(arr,start,end-1,k+1,dp_endarr));
    
    return dp_endarr[start][end];
}

//to be improved
int longest_increasing_path(int arr[][MAX],int n,int m)
{
    int dp[n+1][m+1];
    memset(dp,-1,sizeof(dp));
    
    dp[0][0]=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i][0]>arr[i-1][0])
        {
            dp[i][0]=1+dp[i-1][0];
        }
        else
        {
            dp[i][0]=1;
        }
    }
    
    for(int i=1;i<m;i++)
    {
        if(arr[0][i]>arr[0][i-1])
        {
            dp[0][i]=1+dp[0][i-1];
        }
        else
        {
            dp[0][i]=1;
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]>arr[i][j-1])
            {
                dp[i][j]=1+max(dp[i-1][j],dp[i][j-1]);
            }
            else
            {
                dp[i][j]=1;
            }
        }
    }
    
    return dp[n-1][m-1];
}

//correct one
int longest_increasing_path_correct(int dp[][MAX], int mat[][MAX]
                              , int n, int m, int x, int y) 
{ 
	if (dp[x][y] < 0) { 
		int result = 0; 

 
		if (x == n - 1 && y == m - 1) 
			return dp[x][y] = 1; 

	
		if (x == n - 1 || y == m - 1) 
			result = 1; 

		if (mat[x][y] < mat[x + 1][y]) 
			result = 1 + longest_increasing_path_correct(dp, mat, n, m, x + 1, y); 

		if (mat[x][y] < mat[x][y + 1]) 
			result = max(result, 1 + longest_increasing_path_correct(dp, mat, n, m, x, y + 1)); 

		dp[x][y] = result; 
	} 

	return dp[x][y]; 
} 

void longest_alternating_subarray(int arr[],int n)
{
    int temp[n+1];
    
    int k=0;
    temp[k]=1;
    for(int i=1;i<n;i++)
    {
        if(abs(arr[i]-arr[i-1]))
        {
            temp[k]++;
        }
        else
        {
            k++;
            temp[k]=1;
        }
    }
    
    for(int i=0;i<=k;i++)
    {
        int l=temp[i];
        while(l>0)
        {
            cout << l-- << " ";
        }
    }
    
}

int main()
{
    // int n=10;
    // cout << count_sum134(n);
    
    
    // int k=2;
    // cout << no_of_monotones(k);
    
    // int arr[5][5] ={{ 0, 0, 0, -1, 0},
    //               {-1, 0, 0, -1, -1},
    //               { 0, 0, 0, -1, 0},
    //               {-1, 0, 0,  0, 0},
    //               { 0, 0, -1,  0, 0}};
                          
    // cout << check_path_available(arr,5,5);
    
    // int arr[] = { 3, 100, 4, 5, 150, 6 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << product_increasing_subsequence(arr, n ); 
        
    //  int n=5;
    //  hosaya_traingle(n);
    
    // int n = 3, m = 1; 
    // cout << eulerian_number(n, m) ;
    
    // int x = 3, y = 4, n = 5; 
    // if (coin_game_subtract_onexy(x, y, n)) 
    //     cout << 'A'; 
    // else
    //     cout << 'B'; 
    
    // int dp_endarr[MAX][MAX]; 
    // memset(dp_endarr, -1 , sizeof(dp_endarr)); 
    // int arr[] = { 1, 3, 1, 5, 2 , 8, 5, -2}; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << max_array_end_remove(arr,0,n-1,1,dp_endarr);
    
    // int dp_endarr[MAX][MAX]; 
    // memset(dp_endarr, -1 , sizeof(dp_endarr));
    // int mat[][MAX] = { 
	// { 1, 2, 3, 4244 }, 
	//	{ 2, 23, 3, 4}, 
	//	{ 3, 23, 33, 4 }, 
	//	{ 4314, 5, 6, 75},  
	// }; 
	// int n = 4, m = 4; 
	// cout << longest_increasing_path_correct(dp_endarr,mat, n, m , 0 ,0 ); 
	
	// int arr[] = { 1, 0, 1, 0, 0, 1 , 0, 1, 0, 0, 1 , 0, 0, 1 , 0, };  
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // longest_alternating_subarray(arr,n);
}