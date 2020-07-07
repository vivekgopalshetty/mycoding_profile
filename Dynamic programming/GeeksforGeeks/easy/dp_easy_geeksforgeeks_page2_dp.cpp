//https://www.geeksforgeeks.org/easy/dynamic-programming/2/

#include <bits/stdc++.h>
using namespace std;

//only delete and insert operations
int editDistanceWith2Ops(string &X, string &Y) 
{ 
	// Find LCS of 2 strings  
	int m = X.length(), n = Y.length(); 
	int L[m+1][n+1]; 
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			if (i == 0 || j == 0) 
				L[i][j] = 0; 
			else if (X[i-1] == Y[j-1]) 
				L[i][j] = L[i-1][j-1] + 1; 
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]); 
		} 
	}	 
	int lcs = L[m][n]; 

	// Edit distance is delete operations + 
	// insert operations. 
	return (m - lcs) + (n - lcs); 
} 

int edit_distance_lcs(string s1,string s2,int n1,int n2)
{
    if(n1==0)
    {
        return n2;
    }
    
    if(n2==0)
    {
        return n1;
    }
    
    int dp[n1+1][n2+1];
    
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0)
            {
                dp[i][j]=j;
            }
            else if(j==0)
            {
                dp[i][j]=i;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
            
            
        }
    }
    
    return dp[n1][n2];
}
int longest_subsequence_increasing_diff1(int arr[],int n)
{
    int lis[n];
    
    lis[0]=1;
    
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    
    return *max_element(lis,lis+n);
}

#define INF INT_MAX
#define N 8
int shortest_path(int graph[N][N])
{
    int dist[N];
        
    dist[N-1]=0;
    
    for(int i=N-2;i>=0;i--)
    {
        dist[i]=INF;
        for(int j=i;j<N;j++)
        {
            if(graph[i][j]==INF)
            {
                continue;
            }
            
            dist[i]=min(dist[i],graph[i][j]+dist[j]);
        }
    }
    
    for(int i=0;i<N;i++)
    {
        cout << dist[i] << " ";
    }
    return dist[0];
}


int max_subarray_sum_excludeB(int A[], int B[], 
                        int n, int m) 
{ 
    int maxi=0;
    for(int i=0;i<m;i++)
    {
        if(B[i]>maxi)
        {
            maxi=B[i];
        }
    }
    
    int isPresent[maxi+1]={0};
    for(int i=0;i<m;i++)
    {
        isPresent[B[i]]=1;
    }

    int max_ending_here=0;
    int max_so_far=INT_MIN;
    
    for (int i = 0; i < n; i++) 
    { 
        if (isPresent[A[i]]==1) 
        { 
             max_ending_here = 0; 
             continue;
        } 
        
        max_ending_here=max(A[i],max_ending_here+A[i]);
        if(max_ending_here>max_so_far)
        {
            max_so_far=max_ending_here;
        }
        
    } 
    return max_so_far; 
} 


int min_sum_triangle(vector<vector<int> > A)
{
    int memo[A.size()]; 
    int n = A.size() - 1; 
  
    for (int i = 0; i < A[n].size(); i++)  
        memo[i] = A[n][i];     
  
    for (int i = A.size() - 2; i >= 0; i--)  
        for (int j = 0; j < A[i].size(); j++)  
            memo[j] = A[i][j] + min(memo[j], 
                                    memo[j + 1]); 
 
    return memo[0];
}

int max_array(int arr[],int n)
{
    int max_so_far=INT_MIN;
    int max_ending_here=0;
    int start=0,end=0;
    int s=0;
    
    for(int i=0;i<n;i++)
    {
        max_ending_here+=arr[i];
        if(max_ending_here>max_so_far)
        {
            max_so_far=max_ending_here;
            start = s;
            end = i;
        }
        
        if(max_ending_here<0)
        {
            max_ending_here=0;
            s=i+1;
        }
    }
    
    return end-start+1;
}

int zero_one_knapsack(int values[],int weights[],int w)
{
  // int dp[sizeof(values)/sizeof(values[0])+1];
   return 0;
   //https://www.geeksforgeeks.org/printing-items-01-knapsack/
}

int dp_maxmink[100][100];
int mini_removal_to_makemin_max_k(int arr[],int start,int end,int k)
{
    
    if(start>=end)
    {
        return 0;
    }
    
    if(arr[end]-arr[start]<=k)
    {
        return 0;
    }
    
    if(dp_maxmink[start][end]==-1)
    {
       dp_maxmink[start][end]=1+min(mini_removal_to_makemin_max_k(arr,start+1,end,k),
                        mini_removal_to_makemin_max_k(arr,start,end-1,k));
    }
    else
    {
        return dp_maxmink[start][end];
    }
    
    return dp_maxmink[start][end];
}


int max_segments_with_abc(int n,int a,int b,int c)
{
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    
    dp[0]=0;
    for(int i=0;i<=n;i++)
    {
        if(dp[i]!=-1)
        {
            if(i+a<=n)
            {
                dp[i+a]=max(dp[i]+1,dp[i+a]);
            }
            
            if(i+b<=n)
            {
                dp[i+b]=max(dp[i]+1,dp[i+b]);
            }
            
            if(i+c<=n)
            {
                dp[i+c]=max(dp[i]+1,dp[i+c]);
            }
        }
    }
    
    return dp[n];
}

int max_difference_ones_and_zeros(string str,int n)
{
    int max_so_far=INT_MIN;
    int max_ending_here=0;
    
    for(int i=0;i<n;i++)
    {
        max_ending_here+=(str[i]== '0' ? 1 : -1);
        if(max_so_far<max_ending_here)
        {
            max_so_far=max_ending_here;
        }
        
        if(max_ending_here<0)
        {
            max_ending_here=0;
        }
    }
    
    return max_so_far;
}

int count_with134(int n)
{
    int dp[n+1]={0};
    
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
int main() {
    
//    cout << count_with134(10);

//    string s = "11000010001"; 
//    int n = 11; 
//    cout << max_difference_ones_and_zeros(s,n);

//      int n=17;
//      int a=2;
//      int b=1;
//      int c=3;
//      cout << max_segments_with_abc(n,a,b,c);

//      int arr[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
//	    int n=sizeof(arr)/sizeof(arr[0]);
//	    sort(arr,arr+n);
//	    memset(dp_maxmink,-1,sizeof(dp_maxmink));
//	    int k=4;
//	    cout << mini_removal_to_makemin_max_k(arr,0,n-1,k);
	    
//	    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
//      int n = sizeof(a)/sizeof(a[0]); 
//      cout << max_array(a, n); 

//        vector<vector<int> > A{ { 2 }, 
//                            { 3, 9 }, 
//                            { 1, 6, 7 } }; 
//        cout << min_sum_triangle(A);

        //  int A[] = {1, 7, -10, 6, 2}; 
        //  int B[] = {5, 6, 7, 1}; 
  
        //  int n = sizeof(A) / sizeof(A[0]); 
        //  int m = sizeof(B) / sizeof(B[0]); 
        
        //  cout << max_subarray_sum_excludeB(A, B, n, m); 
        
        // int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };  
        // int n = sizeof(arr)/sizeof(arr[0]);  
        // cout << longest_subsequence_increasing_diff1(arr,n);
     
     string X = "sunday"; 
     string Y = "saturday"; 
     cout << edit_distance_lcs(X,Y,X.length(),Y.length());
	    return 0;
	
}