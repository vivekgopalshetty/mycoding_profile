//https://www.geeksforgeeks.org/easy/dynamic-programming/5/
//recursion

#include<bits/stdc++.h>
using namespace std;
#define MAX 50

int count_ways_to_dest(int arr[][MAX],int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return 0;
    }
    
    if(x==n-1 && y==m-1)
    {
        return 1;
    }
    
    if(arr[x][y]==-1)
    {
        return 0;
    }
    
    return count_ways_to_dest(arr,x+1,y,n,m)+count_ways_to_dest(arr,x,y+1,n,m);
}

int max_subsequence_sum_no3_cons(int arr[],int n)
{
    if(n==0)
    {
        return 0;
    }
    
    if(n==1)
    {
        return arr[0];
    }
    
    if(n==2)
    {
        return arr[0]+arr[1];
    }
    
    
    return max(max_subsequence_sum_no3_cons(arr,n-1),max(
        arr[n-1]+max_subsequence_sum_no3_cons(arr,n-2),
        arr[n-1]+arr[n-2]+max_subsequence_sum_no3_cons(arr,n-3)));
                
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

float max_path_average(int arr[][MAX],int x,int y,int n,int m,int k,int sum)
{
    if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return 0;
    }
    
    if(x==n-1 && y==m-1)
    {
        return float(sum+arr[x][y])/float(k+1);
    }
    
    return max(max_path_average(arr,x+1,y,n,m,k+1,sum+arr[x][y]),
                max_path_average(arr,x,y+1,n,m,k+1,sum+arr[x][y]));
    
}

int break_n_into_3nos(int n)
{
   if(n==0 || n==1)
   {
       return n;
   }
   
  
   return max(break_n_into_3nos(n/2)+break_n_into_3nos(n/3)+break_n_into_3nos(n/4),n);
}

int high_low_tasks(int low[],int high[],int start,int end)
{
    if(start>end)
    {
        return 0;
    }
    
    return max(low[start]+high_low_tasks(low,high,start+1,end),
            high[start]+high_low_tasks(low,high,start+2,end));
}

int countIntegralSolutions(int n) 
{ 
    return ((n+1)*(n+2))/2; 
} 

int lcs(string s1,string s2,int n,int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    
    if(s1[n-1]==s2[m-1])
    {
        return 1+lcs(s1,s2,n-1,m-1);
    }
    
    return (lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
}

int max_length_snake_sequence(int arr[][MAX],int x,int y,int n,int m)
{
     if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return 0;
    }
    
    if(x==n-1 && y==m-1)
    {
        return 1;
    }
    
    int c1=0;
    if(abs(arr[x+1][y]-arr[x][y])==1)
    {
        c1=1+max_length_snake_sequence(arr,x+1,y,n,m);
    }
    
    int c2=0;
    if(abs(arr[x][y+1]-arr[x][y])==1)
    {
        c2=1+max_length_snake_sequence(arr,x,y+1,n,m);
    }
    
    return max(c1,c2);
}

int permutation(int n,int k)
{
    if(k==0)
    {
        return 1;
    }
    
    return permutation(n-1,k)+k*permutation(n-1,k-1);
}

int combination_ncr(int n,int r)
{
    if(r==0 || n==r)
    {
        return 1;
    }
    
    return combination_ncr(n-1,r-1)+combination_ncr(n-1,r);
}

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first<p2.first;
}

void max_length_chain_pair(vector<pair<int,int> > v)
{
    sort(v.begin(),v.end(),compare);
    
    vector<vector<pair<int,int> > > l1(v.size());
    
    l1[0].push_back(v[0]);
    
    for(int i=1;i<v.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[j].second < v[i].first && l1[i].size()<l1[j].size())
            {
                l1[i]=l1[j];
            }
        }
        
        l1[i].push_back(v[i]);
    }
    
    vector<pair<int,int> > maxChain; 
    for (vector<pair<int,int> > x : l1) 
        if (x.size() > maxChain.size()) 
            maxChain = x; 
  
    for (pair<int,int> p : maxChain) 
        cout << "(" << p.first << ", "
             << p.second << ") "; 
}

//2*n grids fill with 2*1
int tiling_problem(int n)
{
    if(n==1)
    {
        return 1;
    }
    
    if(n==2)
    {
        return 2;
    }
    
    return tiling_problem(n-1)+tiling_problem(n-2);
}

// n x m using 1 x m tiles 
int tiling_problem_m(int n,int m)
{
    if(m>n)
    {
        return 1;
    }
    
    if(n==m)
    {
        return 2;
    }
    
    return tiling_problem_m(n-1,m)+tiling_problem_m(n-m,m);
}

int main()
{
    // int maze[MAX][MAX] =  {{0,  0, 0, 0}, 
    //                   {0, -1, 0, 0}, 
    //                   {-1, 0, 0, 0}, 
    //                   {0,  0, 0, 0}}; 
    // cout << count_ways_to_dest(maze,0,0,4,4); 
    
    // int arr[]={3000, 2000, 1000, 3 ,10};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << max_subsequence_sum_no3_cons(arr,n);
    
    // int arr[] = {3, 5, 10, 15, 17, 12, 9}; 
    // int N = sizeof(arr)/sizeof(int); 
    // int K = 4;
    // cout << max_difference_k_makingpairs(arr, N, K);
    
    // int cost[MAX][MAX] = { {1, 2, 3}, 
    //     {6, 5, 4}, 
    //     {7, 3, 9} 
    // }; 
    // int n=3,m=3;
    // cout << max_path_average(cost,0,0,n,m,0,0);
    
    // cout << break_n_into_3nos(24);
    
    // int n = 5; 
    // int high[] = {3, 6, 8, 7, 6}; 
    // int low[] = {1, 5, 4, 5, 3}; 
    // cout << high_low_tasks(low,high,0, n ); 
    
    // cout << countIntegralSolutions(10);
    
    // int mat[MAX][MAX] = 
    // { 
    //     {9, 6, 5, 2}, 
    //     {8, 7, 6, 5}, 
    //     {7, 3, 1, 6}, 
    //     {1, 1, 1, 7}, 
    // }; 
    // int n=4,m=4;
    // cout << max_length_snake_sequence(mat,0,0,n,m); 
    
    // string X = "AGGTAB"; 
    // string Y = "GXTXAYB"; 
    // cout << "lcs " << lcs(X,Y,X.length(),Y.length());
    
    // vector<pair<int,int> > v = {{5, 29}, {39, 40}, {15, 28}, 
    //             {27, 40}, {50, 90}}; 
    
    // max_length_chain_pair(v);
    
    //cout << combination_ncr(10,2,8);
    
    // cout << tiling_problem(4);
    
    cout << tiling_problem_m(7,4);
     return 0;
}
