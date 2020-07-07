//https://www.geeksforgeeks.org/easy/dynamic-programming/5/
//dynamic-programming

#include<bits/stdc++.h>
using namespace std;
#define MAX 50

int count_ways_to_dest(int arr[][MAX],int n,int m)
{

    for(int i=0;i<n;i++)
    {
        if(arr[i][0]!=-1)
        {
            arr[i][0]=1;
        }
         else
        {
            break;
        }
    }
    
    for(int i=1;i<m;i++)
    {
        if(arr[0][i]!=-1)
        {
            arr[0][i]=1;
        }
        else
        {
            break;
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]!=-1)
            {
                if(arr[i-1][j]>0)
                {
                    arr[i][j]+=arr[i-1][j];
                }
                
                if(arr[i][j-1]>0)
                {
                    arr[i][j]+=arr[i][j-1];
                }
            }
        }
    }
    
    return arr[n-1][m-1];
}

int max_subsequence_sum_no3_cons(int arr[],int n)
{
    int dp[n];
    
    if (n >= 1) 
		dp[0] = arr[0]; 

	if (n >= 2) 
		dp[1] = arr[0] + arr[1]; 

	if (n > 2) 
		dp[2] = max(dp[1], max(arr[1] + arr[2], arr[0] + arr[2])); 
    
    for(int i=3;i<n;i++)
    {
        dp[i]=max(dp[i-1],max(dp[i-2]+arr[i],arr[i]+arr[i-1]+dp[i-3]));
    }
    
    return dp[n-1];
}

int max_difference_k_makingpairs(int arr[], int N, int k) 
{ 
    int maxSum = 0; 
    sort(arr, arr+N); 
 
    for (int i=N-1; i>0; --i) 
    { 
        if (arr[i]-arr[i-1] < k) 
        { 
            maxSum += arr[i]; 
            maxSum += arr[i-1]; 
            --i; 
        } 
    } 
  
    return maxSum; 
}

int findSum(vector<int> arr) 
{ 
    int sum = 0; 
    for (int i: arr) 
        sum += i; 
    return sum; 
} 
  

void print_longest_inc_subsequence(int arr[], int n) 
{ 
    vector <vector<int> > v(n); 
    v[0].push_back(arr[0]); 
 
    for (int i = 1; i < n; i++) 
    { 
        for (int j = 0; j < i; j++) 
        { 
            if ((arr[i] > arr[j]) && 
                (findSum(v[i]) < findSum(v[j]))) 
                v[i] = v[j]; 
        } 
 
        v[i].push_back(arr[i]); 
  
    } 
  
    vector<int> res = v[0]; 
  
    for (vector<int> x : v) 
        if (findSum(x) > findSum(res)) 
            res = x; 
 
    for (int i : res) 
        cout << i << " "; 
    cout << endl; 
} 

void print_longest_inc_subsequence_sum(int arr[], int n) 
{ 
    vector <vector<int> > v(n); 
    v[0].push_back(arr[0]); 
 
    for (int i = 1; i < n; i++) 
    { 
        for (int j = 0; j < i; j++) 
        { 
            if ((arr[i] > arr[j]) && 
                (v[i].size() < v[j].size())) 
                v[i] = v[j]; 
        } 
 
        v[i].push_back(arr[i]); 
  
    } 
  
    vector<int> res = v[0]; 
  
    for (vector<int> x : v) 
        if (findSum(x) > findSum(res)) 
            res = x; 
 
    for (int i : res) 
        cout << i << " "; 
    cout << endl; 
} 

int high_low_tasks(int low[],int high[],int end)
{
    int dp[end+1];
    dp[0]=0;
    dp[1]=high[0];
    
    for(int i=2;i<=end;i++)
    {
        dp[i]=max(low[i-1]+dp[i-1],high[i-1]+dp[i-2]);
    }
    
    return dp[end];
    
}

int countIntegralSolutions(int n) 
{ 
    return ((n+1)*(n+2))/2; 
} 


int lcs(string s1,string s2)
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

int lcs_optimized(string s1,string s2)
{
    bool b1;
    int n=s1.length();
    int m=s2.length();
    int dp[2][m+1];
    
    for(int i=0;i<=n;i++)
    {
        b1= i & 1;
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[b1][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[b1][j]=1+dp[1-b1][j-1];
            }
            else
            {
                dp[b1][j]=max(dp[1-b1][j],dp[b1][j-1]);
            }
        }
    }
    
    return dp[b1][m];
}

int max_length_snake_sequence(int arr[][MAX],int n,int m)
{
    int dp[n][m];
    int c1,c2;
    dp[0][0]=1;
    for(int i=1;i<n;i++)
    {
        if(abs(arr[i-1][0]-arr[i][0])==1)
        {
            dp[i][0]=1+dp[i-1][0];
        }
        else
        {
            dp[i][0]=0;
        }
    }
    
    for(int i=1;i<m;i++)
    {
        if(abs(arr[0][i-1]-arr[0][i])==1)
        {
            dp[0][i]=1+dp[0][i-1];
        }
        else
        {
            dp[0][i]=0;
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            c1=0;
            if(abs(arr[i-1][j]-arr[i][j])==1)
            {
                c1=dp[i-1][j]+1;
            }
            
            c2=0;
            if(abs(arr[i][j-1]-arr[i][j])==1)
            {
                c2=dp[i][j-1]+1;
            }
            
            dp[i][j]=max(c1,c2);
            
        }
    }
    
    return dp[n-1][m-1];
}

int permutationCoeff(int n, int k) 
{ 
    int P[n + 1][k + 1]; 
    for (int i = 0; i <= n; i++) 
    { 
        for (int j = 0; j <= std::min(i, k); j++) 
        { 
            if (j == 0) 
                P[i][j] = 1; 
  
            else
                P[i][j] = P[i - 1][j] +  
                          (j * P[i - 1][j - 1]); 
            P[i][j + 1] = 0; 
        } 
    } 
    return P[n][k]; 
}

//pascal triangle logic is same 
int combination_ncr(int n,int r,int p)
{
   int C[r+1]; 
   memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
}

//2*n grids fill with 2*1
int tiling_problem(int n)
{
    int dp[n];
    dp[0]=1;
    dp[1]=2;
    
    for(int i=2;i<n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n-1];
}

int tiling_problem_m(int n,int m)
{
    int dp[n];
    
    for(int i=0;i<n;i++)
    {
        if(i<m)
        {
            dp[i]=2;
        }
        else if(i==m)
        {
            dp[i]=1;
        }
        else
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        
    }
    return dp[n-1];
}

int main()
{
    // int maze[MAX][MAX] =  {{0,  0, 0, 0}, 
    //                   {0, -1, 0, 0}, 
    //                   {-1, 0, 0, 0}, 
    //                   {0,  0, 0, 0}}; 
    // cout << count_ways_to_dest(maze,4,4); 
    
    // int arr[]={3000, 2000, 1000, 3 ,10};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << max_subsequence_sum_no3_cons(arr,n);
    
    // int arr[] = {3, 5, 10, 15, 17, 12, 9}; 
    // int N = sizeof(arr)/sizeof(int); 
    // int K = 4; 
    // cout << max_difference_k_makingpairs(arr, N, K);
    
    // int arr[] = { 3, 2, 6, 4, 5, 1 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // print_longest_inc_subsequence(arr, n); 
    
    // int arr[] = { 3, 2, 6, 4, 5, 1 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // print_longest_inc_subsequence_sum(arr, n); 
    
    // int n = 5; 
    // int high[] = {3, 6, 8, 7, 6}; 
    // int low[] = {1, 5, 4, 5, 3}; 
    // cout << high_low_tasks(low,high,n ); 
    
    //  cout << countIntegralSolutions(10);
    
    // int mat[MAX][MAX] = 
    // { 
    //     {9, 6, 5, 2}, 
    //     {8, 7, 6, 5}, 
    //     {7, 3, 1, 6}, 
    //     {1, 1, 1, 7}, 
    // }; 
    // int n=4,m=4;
    // cout << max_length_snake_sequence(mat,n,m); 
    
    // string X = "AGGTAB"; 
    // string Y = "GXTXAYB"; 
    // cout << "lcs " << lcs(X,Y);
    // cout << "lcs_optimized" << lcs_optimized(X,Y);
    
    //cout << combination_ncr(10,2,8);
    
    cout << tiling_problem(4);
    return 0;
}