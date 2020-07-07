#include <bits/stdc++.h>
using namespace std;

// with recursion
// https://www.geeksforgeeks.org/easy/dynamic-programming/ 
int steps_to_1and2_with_onlyone3(int n,int key)
{
    if(n<0)
    {
        return 0;
    }
    
    if(n-3==0 && key==1)
    {
        return 1;
    }
    
    if(n==0 && key==0)
    {
        return 1;
    }
    
    if(key==0)
    {
        return steps_to_1and2_with_onlyone3(n-2,key)+steps_to_1and2_with_onlyone3(n-1,key);
    }
    else
    {
        return steps_to_1and2_with_onlyone3(n-2,key)+steps_to_1and2_with_onlyone3(n-1,key)+
                steps_to_1and2_with_onlyone3(n-3,0);
    }
}

int k_difference_index_subsequences(int arr[],int n,int k,int start)
{
    if(start>=n)
    {
        return 0;
    }
    
    return max(arr[start]+k_difference_index_subsequences(arr,n,k,start+k),
                k_difference_index_subsequences(arr,n,k,start+1));
}

int sum_path_matrix(int arr[3][3],int x,int y,int n,int m,int sum)
{
    if(x<0 || y<0 || x>n || y>m)
    {
        return INT_MIN;
    }
    
    if(x==n-1 && y==m-1)
    {
        return sum;
    }
    
    return max(sum_path_matrix(arr,x+1,y+1,n,m,sum+arr[x+1][y+1]),max(sum_path_matrix(arr,x+1,y,n,m,sum+arr[x+1][y]),
                    sum_path_matrix(arr,x,y+1,n,m,sum+arr[x][y+1])));
}

int no_of_ways_with123(int n)
{
    if(n<0)
    {
        return 0;
    }
    
    if(n==0)
    {
        return 1;
    }
    
    return no_of_ways_with123(n-1)+no_of_ways_with123(n-2)+no_of_ways_with123(n-3);
}

// string longest_subsequence_divisble_with3(string s,int start,int n,string prefix)
// {
//     https://www.geeksforgeeks.org/longest-sub-sequence-of-a-binary-string-divisible-by-3/
// }

bool mazie_with_ndoors_1key(int arr[3][3],int key,int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>n || y>m)
    {
        return INT_MIN;
    }
    
    if(x==n-1 && y==m-1)
    {
        if(arr[x][y]==1)
        {
        return 0;
        }
    }
}

const int MAX_nos2 = 101; 
int dp_nos2[MAX_nos2][2];

int count_with_nocons2(int n,int prev)
{
    if (dp_nos2[n][prev] != -1) 
        return dp_nos2[n][prev]; 
        
    if(n<0)
    {
        return 0;
    }
    
    if(n==0)
    {
        return 1;
    }
    
    if(prev==1)
    {
        dp_nos2[n][prev]=count_with_nocons2(n-1,0);
    }
    else
    {
        dp_nos2[n][prev]=count_with_nocons2(n-1,0)+count_with_nocons2(n-2,1);
    }
    
    return dp_nos2[n][prev];
}


int find_min_odd_cost(int given[5][5], int m, int n) 
{ 
    int M=5,N=5;
    int floor[M][N] = { { 0 }, { 0 } }; 
    int min_odd_cost = 0; 
    int i, j, temp; 
  
    for (j = 0; j < n; j++) 
        floor[0][j] = given[0][j]; 
  
    for (i = 1; i < m; i++) 
        for (j = 0; j < n; j++) { 
  
            // leftmost element 
            if (j == 0) { 
                floor[i][j] = given[i][j]; 
                floor[i][j] += min(floor[i - 1][j], floor[i - 1][j + 1]); 
            } 
  
            // rightmost element 
            else if (j == n - 1) { 
                floor[i][j] = given[i][j]; 
                floor[i][j] += min(floor[i - 1][j], floor[i - 1][j - 1]); 
            } 
  
            // Any element except leftmost and rightmost element of a row 
            // is reachable from direct upper or left upper or right upper 
            // row's block 
            else { 
  
                // Counting the minimum cost 
                temp = min(floor[i - 1][j], floor[i - 1][j - 1]); 
                temp = min(temp, floor[i - 1][j + 1]); 
                floor[i][j] = given[i][j] + temp; 
            } 
        } 
  
    min_odd_cost = INT_MAX; 
  
    // Find the minimum cost 
    for (j = 0; j < n; j++) { 
        if (floor[n - 1][j] % 2 == 1) { 
            if (min_odd_cost > floor[n - 1][j]) 
                min_odd_cost = floor[n - 1][j]; 
        } 
    } 
  
    if (min_odd_cost == INT_MIN) 
        return -1; 
  
    return min_odd_cost; 
}

int no_of_ways_traverse_matrix(int m, int n) 
{ 
    int dp[m+1][n+1]; 
      
    for (int i=1; i<=m; i++) 
    { 
        for (int j=1; j<=n; j++) 
        { 
           if (i==1 || j == 1) 
              dp[i][j] = 1; 
            else
              dp[i][j] = dp[i-1][j] + dp[i][j-1];               
        } 
    } 
    
    return dp[m][n]; 
} 
int main() {
//     int n =10;
// 	cout<< steps_to_1and2_with_onlyone3(n,1);
	
// 	int arr[] = { 135, 256, -235, 431, 3, 156 , 1, 239, -239 , 49 , 3, 10}; 
// 	int n = sizeof(arr) / sizeof(arr[0]); 
// 	int k = 4; 
//     cout << k_difference_index_subsequences(arr, n, k ,0 0);

    // int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    // int n=3;
    // int m=3;
    // cout << sum_path_matrix(arr,0,0,3,3,arr[0][0]);
    
    // cout <<  no_of_ways_with123(10);
    
    // memset(dp_nos2, -1, sizeof(dp_nos2)); 
    // cout << count_with_nocons2(5,0);
    
    cout << no_of_ways_traverse_matrix(5,5);
	return 0;
}