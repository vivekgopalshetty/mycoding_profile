#include <bits/stdc++.h>
using namespace std;

// with recursion
// https://www.geeksforgeeks.org/easy/dynamic-programming/ 
int steps_to_1and2_with_onlyone3(int n)
{
   int included_3[n+1];
   int not_included_3[n+1];
   
   included_3[2]=0;
   included_3[3]=1;
   not_included_3[1]=1;
   not_included_3[2]=2;
   not_included_3[3]=3;
   
   
   for(int i=4;i<=n;i++)
   {
       included_3[i]=included_3[i-1]+included_3[i-2]+not_included_3[i-3];
       not_included_3[i]=not_included_3[i-1]+not_included_3[i-2];
   }
   
   return included_3[n];
   
}

int k_difference_index_subsequences(int arr[],int n,int k)
{
    int dp[n];
    
    for(int i=0;i<k;i++)
    {
        dp[i]=arr[i];
    }
    
    for(int i=k;i<n;i++)
    {
        dp[i]=max(arr[i]+dp[i-k],dp[i-1]);
    }
    
    return dp[n-1];
}

int sum_path_matrix(int arr[][3],int n,int m)
{
    int dp[n+1][m+1];
    
    dp[0][0]=arr[0][0];
    
    for(int i=1;i<n;i++)
    {
        dp[i][0]=arr[i][0]+dp[i-1][0];
    }
    
    for(int i=1;i<m;i++)
    {
        dp[0][i]=arr[0][i]+dp[0][i-1];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j]=arr[i][j]+max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
        }
    }
    return dp[n-1][m-1];
}

int no_of_ways_with123(int n)
{
    
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    
    for(int i=0;i<n;i++)
    {
        cout << dp[i] << " ";
    }
    
    return dp[n];
}

// string longest_subsequence_divisble_with3(string s,int start,int n,string prefix)
// {
//     https://www.geeksforgeeks.org/longest-sub-sequence-of-a-binary-string-divisible-by-3/
// }

int count_with_nocons2(int n,int prev)
{
    if(n<0)
    {
        return 0;
    }
    
    if(n==0)
    {
        return 1;
    }
    
    if(prev==2)
    {
        return count_with_nocons2(n-1,1);
    }
    
    return count_with_nocons2(n-1,1)+count_with_nocons2(n-2,2);
}

int min_odd_cost_path(int arr[5][5],int x,int y,int n,int m,int cost)
{
    if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return INT_MAX;
    }
    
    if(x==n-1 && y==m-1)
    {
        if(cost%2==0)
        {
            return INT_MAX;
        }
        else
        {
            return cost+arr[n-1][m-1];
        }
    }
    
    return min(min_odd_cost_path(arr,x+1,y-1,n,m,cost+arr[x+1][y-1]),
            min(min_odd_cost_path(arr,x+1,y,n,m,cost+arr[x+1][y]),
                    min_odd_cost_path(arr,x+1,y+1,n,m,cost+arr[x+1][y+1])));
    
}

int no_of_ways_traverse_mat(int m,int n)
{
    if (m == 1 || n == 1) 
        return 1; 
   
    return no_of_ways_traverse_mat(m - 1, n) +  
           no_of_ways_traverse_mat(m, n - 1);     
}

int no_of_ways_reachN_atmostk(int n,int k)
{
    int combo[N + 1] = { 0 };  
  
    combo[0] = 1;  
 
    for (int i = 1; i <= K; i++) {  

        for (int j = 0; j <= N; j++) {  
  
            if (j >= i) {  
                combo[j] += combo[j - i];  
            }  
        }  
    }  
  
    return combo[N];  
}
int main() {
//     int n=10;
// 	cout<< steps_to_1and2_with_onlyone3(n);
// 	return 0;

// 	int arr[] = { 135, 256, -235, 431, 3, 156 , 1, 239, -239 , 49 , 3, 10}; 
// 	int n = sizeof(arr) / sizeof(arr[0]); 
// 	int k = 4; 
//     cout << k_difference_index_subsequences(arr, n, k );

    // int a[3][3];
    // a[0][0] = 500; 
    // a[0][1] = 100; 
    // a[0][2] = 230; 
    // a[1][0] = 1000; 
    // a[1][1] = 300; 
    // a[1][2] = 100; 
    // a[2][0] = 200; 
    // a[2][1] = 1000; 
    // a[2][2] = 200; 
    // int n=3;
    // int m=3;
    // cout << sum_path_matrix(a,3,3);
	
	
// 	cout << no_of_ways_with123(10);
    
    // cout << count_with_nocons2(4,1);
    
//       int mat[5][5] = 
//   {{ 1, 2, 3, 4, 6},
// { 1, 2, 3, 4, 5 },
// { 1, 2, 3, 4, 5 },
// { 1, 2, 3, 4, 5 },
// { 100, 2, 3, 4, 5 }};
    
//     int m=5;
//     int n=5;
    
//     cout << min_odd_cost_path(mat,0,0,n,m,0);

//    cout << no_of_ways_traverse_mat(5,5);

    cout << no_of_ways_reachN_atmostk(5,3);
	return 0;
}