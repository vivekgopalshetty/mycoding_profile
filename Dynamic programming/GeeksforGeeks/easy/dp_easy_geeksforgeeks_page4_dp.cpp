//https://www.geeksforgeeks.org/easy/dynamic-programming/4/
//dynamic-programming

#include <bits/stdc++.h>
using namespace std;

#define MAX 50

int theif_problem(int arr[],int n)
{
    int dp[n];
    
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    
    for(int i=2;i<n;i++)
    {
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
    }
    
    return dp[n-1];
}

int lcs(int arr[],int start,int n)
{
    int lis[n-start];
    
     for(int i=start;i<n;i++)
    {
        lis[i]=1;
    }
    
    for(int i=start+1;i<n;i++)
    {
        for(int j=start;j<i;j++)
        {
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    
    int res=INT_MIN;
    for(int i=start;i<n;i++)
    {
        res=max(res,lis[i]);
    }
    
    return res;
}

int circular_lcs(int arr[],int n)
{
    int res=INT_MIN;
    int circular_buff[2*n];
    
    for(int i=0;i<n;i++)
    {
        circular_buff[i]=arr[i];
    }
    for(int i=n;i<2*n;i++)
    {
        circular_buff[i]=arr[i-n];
    }
    
    
    for(int i=0;i<n;i++)
    {
        res=max(res,lcs(circular_buff,i,i+n));
    }
    
    return res;
}

int sum_all_substring(string s)
{
    int ans=0;
    long long int mf=1;
    for(int i=s.size()-1;i>=0;i--)
    {
        ans+=(s[i]-'0')*(i+1)*mf;
        
        mf=mf*10+1;
    }
    
    return ans;
}

void print_distinct_order(string s)
{
    int arr[256]={0};
    
    for(int i=0;i<s.size();i++)
    {
        arr[s[i]]++;
    }
    
    for(int i=0;i<s.size();i++)
    {
        if(arr[s[i]]==1)
        {
            cout << s[i] ; 
        }
    }
}

int min_deletions_tomake_sortedarray(int arr[],int n)
{
    return n-lcs(arr,0,n);
}

int gold_mine(int arr[][MAX],int n,int m)
{
    int dp[n][m];
    memset(dp, 0, sizeof(dp)); 
    
    for(int col=n-1;col>=0;col--)
    {
        for(int row=0;row<m;row++)
        {
            int right = (col==n-1)? 0: dp[row][col+1]; 
  
            int right_up = (row==0 || col==n-1)? 0: 
                            dp[row-1][col+1]; 
  
            int right_down = (row==m-1 || col==n-1)? 0: 
                             dp[row+1][col+1]; 
  
            dp[row][col] = arr[row][col] + 
                              max(right, max(right_up, right_down));
        }
    }
    
    int maxi=0;
    for(int i=0;i<m;i++)
    {
        maxi=max(dp[i][0],maxi);
    }
    
    return maxi;
}

#define N 4
int MaximumPath(int Mat[][N]) 
{ 
    int result = 0 ; 
    int dp[N][N+2]; 
  
    memset(dp, 0, sizeof(dp)); 
  
    for (int i = 0 ; i < N ; i++) 
    {
        dp[0][i+1] = Mat[0][i];
    }
    
    for (int i = 1 ; i < N ; i++) 
        for (int j = 1 ; j <= N ; j++) 
            dp[i][j] = max(dp[i-1][j-1], 
                           max(dp[i-1][j], 
                               dp[i-1][j+1])) + 
                       Mat[i][j-1] ; 
  
    for (int i=0; i<=N; i++) 
        result = max(result, dp[N-1][i]); 
  
    return result ; 
}

int friends_pairing(int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+(i-1)*dp[i-2];
    }
    
    return dp[n];
}

int max_sum_path_triangle(int arr[][MAX],int n)
{
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<n;i++)
    {
        dp[n-1][i]=arr[n-1][i];    
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i][j]=arr[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    
    return dp[0][0];
}

//2 strings lcs
int longest_common_subsequence(string s1,string s2)
{
    int n=s1.length();
    int m=s2.length();
    
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return dp[n][m];
}

//3 string lcs
int longest_common_subsequence_3(string s1,string s2,string s3)
{
    int n=s1.length();
    int m=s2.length();
    int l=s3.length();
    
    int dp[n+1][m+1][l+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=l;k++)
            {
                if(i==0 || j==0 || k==0)
                {
                    dp[i][j][k]=0;
                }
                else if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
                {
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                }
                else
                {
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    
    return dp[n][m][l];
}

int count_subarray_max_k(int arr[], int n, int k) 
{ 
	int s = 0; 

	int i = 0; 
	while (i < n) { 

		if (arr[i] > k) { 
			i++; 
			continue; 
		} 
		int count = 0; 
		while (i < n && arr[i] <= k) { 
			i++; 
			count++; 
		} 
		s += ((count * (count + 1)) / 2); 
	} 

	return (n * (n + 1) / 2 - s); 
} 

int longest_bitonic_sequence(int arr[],int n)
{
    int lis_inc[n+1];
    int lis_dsc[n+1];
    
    for(int i=0;i<n;i++)
    {
        lis_inc[i]=arr[i];
        lis_dsc[i]=arr[i];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis_inc[i]<lis_inc[j]+arr[i])
            {
                lis_inc[i]=lis_inc[j]+arr[i];
            }
        }
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j] && lis_dsc[i]<lis_dsc[j]+arr[i])
            {
                lis_dsc[i]=lis_dsc[j]+arr[i];
            }
        }
    }
    
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,lis_inc[i]+lis_dsc[i]-arr[i]);   
    }
    
    return maxi;
    
}

void max_path_sum_divisibility(int arr[],int n)
{
    int dp[n+1];
    
    for(int i=0;i<n;i++)
    {
        dp[i+1]=arr[i];
    }

    int ans=0;
    for(int i=2;i<=n;i++)
    {
        ans=0;
        for(int j=1;j<=sqrt(i);j++)
        {
           if(i%j==0)
            {
                ans=max(ans,dp[j]);
                if(j!=1)
                {
                    ans=max(ans,dp[i/j]);
                }
            }
        }
        dp[i]+=ans;
    }

    for(int i=1;i<=n;i++)
    {
        cout << dp[i] << " ";
    }
}


int main() {
	
	// int hval[] = {6, 7, 1, 3, 8, 2, 4}; 
    // int n = sizeof(hval)/sizeof(hval[0]); 
    // cout << "Maximum loot possible : "
    //   << theif_problem(hval, n); 

    // int arr[] = { 1, 4, 6, 2, 3 }; 
    // int n = sizeof(arr)/sizeof(arr[0]); 
    // cout << "Length of LICS is " << circular_lcs( arr,n );
    
    // string num = "6759"; 
    // cout << sum_all_substring(num) << endl; 
    
    // int arr[] = {30, 40, 2, 5, 1, 
    //               7, 45, 50, 8}; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << "Minimum number of deletions = "
    //      << min_deletions_tomake_sortedarray(arr, n); 
    
    // int gold[MAX][MAX]= {{10, 33, 13, 15},
    //               {22, 21, 04, 1},
    //               {5, 0, 2, 3},
    //               {0, 6, 14, 2}};
    // int m = 4, n = 4; 
    // cout << gold_mine(gold,n,m);
    
    // int mat[N][N] = { { 4, 2 , 3 , 4 }, 
    //     { 2 , 9 , 1 , 10}, 
    //     { 15, 1 , 3 , 0 }, 
    //     { 16 ,92, 41, 44 } 
    // }; 
    
    // int m = 4, n = 4;
    // cout << MaximumPath(mat);
    
    // cout << friends_pairing(4);
    
    // int tri[MAX][MAX] = { {8, 0, 0,0}, 
				// 	{2, -4, 0,0}, 
    //                 { 2 , 2, 6, 0},
				// 	{1, 1, 1 , 1 } }; 
    // cout << max_sum_path_triangle(tri, 4); 
    
    // int arr[] = { 1, 15, 51, 45, 33, 100, 12, 18, 9 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << "Maximum Sum : " << longest_bitonic_sequence(arr, n); 
    
    // int arr[] = { 2, 3, 1, 4, 6, 5 }; 
    // int n = sizeof(arr) / sizeof(arr[0]);
    // max_path_sum_divisibility(arr,n);
    
    // string s1 = "AGGTAB";  
    // string s2 = "GXTXAYB";  
    // cout<<"Length of LCS is "<< longest_common_subsequence( s1, s2 ) ; 
    
    // string X = "AGGT12"; 
    // string Y = "12TXAYB"; 
    // string Z = "12XBA"; 
    // cout << "Length of LCS is " << longest_common_subsequence_3(X, Y, Z); 
    
    int arr[] = { 1, 2, 3 , 6 , 5 , 3 }; 
	int k = 2; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << count_subarray_max_k(arr, n, k);
	return 0;
}