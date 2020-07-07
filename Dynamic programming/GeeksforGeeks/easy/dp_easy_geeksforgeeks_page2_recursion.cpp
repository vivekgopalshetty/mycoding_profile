//https://www.geeksforgeeks.org/easy/dynamic-programming/2/

#include <bits/stdc++.h>
using namespace std;
//next version with only insert delete

//standard version with insert replace delete
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
    
    if(s1[n1]==s2[n2])
    {
        return edit_distance_lcs(s1,s2,n1-1,n2-1);
    }
    
    int c2=edit_distance_lcs(s1,s2,n1-1,n2); //delete
    int c3=edit_distance_lcs(s1,s2,n1,n2-1); //insert
    int c4=edit_distance_lcs(s1,s2,n1-1,n2-1); //replace
    
    return 1+min(c2,min(c3,c4));
}

int longest_subsequence_increasing_diff1(int arr[],int n,int start,int prev,string prefix)
{
    if(start==n)
    {
        return 0; 
    }
    
    int c1=0;
    if((arr[start]>prev  && arr[start]-prev==1) || prev==-133)
    {
        c1=1+longest_subsequence_increasing_diff1(arr,n,start+1,arr[start],
        prefix+to_string(arr[start]));
    }
    
    return max(c1,longest_subsequence_increasing_diff1(arr,n,start+1,prev,prefix));
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

int zero_one_knapsack(int value[],int weights[],int start,int end,int w)
{ 
    if(start>end)
    {
        return 0;
    }
    
    if(w<0)
    {
        return INT_MIN;
    }
    
    if(w==0)
    {
        return 0;
    }
    
    return max(value[start]+zero_one_knapsack(value,weights,start+1,end,w-weights[start])
    ,zero_one_knapsack(value,weights,start+1,end,w));
}

int mini_removal_to_makemin_max_k(int arr[],int start,int end,int k)
{
    if(start>=end)
    {
        return 0;
    }
    
    if(abs(arr[start]-arr[end])==k)
    {
        return 0;
    }
    
    return 1+min(mini_removal_to_makemin_max_k(arr,start+1,end,k),
    mini_removal_to_makemin_max_k(arr,start,end-1,k));
    
}

int max_segments_with_abc(int n,int a,int b,int c,int num)
{
    if(n<0)
    {
        return 0;
    }
    
    if(n==0)
    {
        return num;
    }
    
    return max(max_segments_with_abc(n-a,a,b,c,num+1),
    max(max_segments_with_abc(n-b,a,b,c,num+1),max_segments_with_abc(n-c,a,b,c,num+1)));
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
    if(n<0)
    {
        return 0;
    }
    
    if(n==0)
    {
        return 1;
    }
    
    return count_with134(n-1)+count_with134(n-3)+count_with134(n-4);
}
int main() {
    
//    cout << count_with134(10);
    
//    string s = "11000010001"; 
//    int n = 11; 
//    cout << max_difference_ones_and_zeros(s,n);

//    int n=17;
//    int a=2;
//    int b=1;
//    int c=3;
//    cout << max_segments_with_abc(n,a,b,c,0);
	
//	  int arr[5] = {1, 2, 5, 6, 8};
//	  int n=sizeof(arr)/sizeof(arr[0]);
//	  int k=2;
//	  cout << mini_removal_to_makemin_max_k(arr,0,n-1,k);

//      int val[] = { 60,120,234,67, 100, 120 }; ; 
//      int wt[] = { 10, 34,7,35,20, 30 }; 
//      int w = 80; 
//      int n = sizeof(val) / sizeof(val[0]); 
//      cout << zero_one_knapsack(val, wt , 0 , n ,w); 

//        int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
//        int n = sizeof(a)/sizeof(a[0]); 
//        cout << max_array(a, n); 

//        vector<vector<int> > A{ { 2 }, 
//                            { 3, 9 }, 
//                            { 1, 6, 7 } }; 
//        cout << min_sum_triangle(A);

        //  int A[] = {1, 7, -10, 6, 2}; 
        //  int B[] = {5, 6, 7, 1}; 
  
        //  int n = sizeof(A) / sizeof(A[0]); 
        //  int m = sizeof(B) / sizeof(B[0]); 
        
        //  cout << max_subarray_sum_excludeB(A, B, n, m); 
        
    // int graph[N][N] = 
    //   {{INF, 1, 2, 5, INF, INF, INF, INF}, 
    //   {INF, INF, INF, INF, 4, 11, INF, INF}, 
    //   {INF, INF, INF, INF, 9, 5, 16, INF}, 
    //   {INF, INF, INF, INF, INF, INF, 2, INF}, 
    //   {INF, INF, INF, INF, INF, INF, INF, 18}, 
    //   {INF, INF, INF, INF, INF, INF, INF, 13}, 
    //   {INF, INF, INF, INF, INF, INF, INF, 2}}; 
  
    // cout << shortest_path(graph); 
  
    // int a[] = {6, 7, 8, 3, 4, 5, 9, 10}; 
    // int n = sizeof(a) / sizeof(a[0]); 
    // cout << longest_subsequence_increasing_diff1(a,n,0,-133,"");
    
    //  string X = "sunday"; 
    //  string Y = "saturday"; 
    //  cout << edit_distance_lcs(X,Y,X.length(),Y.length());
	  return 0;
}