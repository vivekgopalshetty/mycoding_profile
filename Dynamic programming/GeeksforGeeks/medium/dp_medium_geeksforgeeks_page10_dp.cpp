//https://www.geeksforgeeks.org/medium/dynamic-programming/10/
//dynamic-programming

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999
#define inf 99999999
#define mod 1000000007 

int seq_len_elem_gt_or_twice_ofprev(int m,int n)
{
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(i<j)
            {
                dp[i][j]=0;
            }
            else if(j==1)
            {
                dp[i][j]=i;
            }
            else
            {
               dp[i][j]=dp[i/2][j-1]+dp[i-1][j];   
            }
        }
    }
    
    return dp[m][n];
}

struct CityPairs 
{ 
    int north, south; 
}; 

bool compare(struct CityPairs a, struct CityPairs b) 
{ 
    if (a.south == b.south) 
        return a.north < b.north; 
    return a.south < b.south; 
} 
  
int maxBridges(struct CityPairs values[], int n) 
{ 
    int lis[n]; 
    for (int i=0; i<n; i++) 
        lis[i] = 1; 
          
    sort(values, values+n, compare); 
  
    for (int i=1; i<n; i++) 
        for (int j=0; j<i; j++) 
            if (values[i].north >= values[j].north  
                && lis[i] < 1 + lis[j]) 
                lis[i] = 1 + lis[j]; 
          
          
    int max = lis[0]; 
    for (int i=1; i<n; i++) 
        if (max < lis[i]) 
            max = lis[i]; 
      
         
    return max;         
}

int minInsertionStepToSortArray(int arr[], int N) 
{ 
    int lis[N]; 
  
    for (int i = 0; i < N; i++) 
        lis[i] = 1; 
  
    for (int i = 1; i < N; i++) 
        for (int j = 0; j < i; j++) 
            if (arr[i] >= arr[j] && lis[i] < lis[j] + 1) 
                lis[i] = lis[j] + 1; 
  
    int max = 0; 
    for (int i = 0; i < N; i++) 
        if (max < lis[i]) 
            max = lis[i]; 
 
    return (N - max); 
}

int ways_to_reach_end(int arr[],int n)
{
    int count_jump[n]; 
    memset(count_jump, 0, sizeof(count_jump)); 

    for (int i=n-2; i>=0; i--) 
    { 
        if (arr[i] >= n - i - 1) 
            count_jump[i]++; 
  
        for (int j=i+1; j < n-1 && j <= arr[i] + i; j++) 
            if (count_jump[j] != -1) 
                 count_jump[i] += count_jump[j]; 
  
        if (count_jump[i] == 0) 
            count_jump[i] = -1; 
    } 
  
    for (int i=0; i<n; i++) 
        cout << count_jump[i] << " "; 
        
    return count_jump[0];
}

int longest_alternating_subseq(int arr[],int n)
{
    int lis[n+1][2];
    memset(lis,1,sizeof(lis));
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis[i][0]<lis[j][1]+1)
            {
                lis[i][0]=lis[i][1]+1;
            }
            
            if(arr[i]<arr[j] && lis[i][1]<lis[j][0]+1)
            {
                lis[i][1]=lis[j][0]+1;
            }
        }
    }
    
    int res=1;
    for(int i=0;i<n;i++)
    {
        res=max(res,max(lis[i][0],lis[i][1]));
    }
    
    return res;
}

//same as finding longest pallindromic subseq
int min_deletions_to_make_string_pall(string s)
{
    int n=s.length();
    int dp[n][n];
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    
    for(int cl=2;cl<=n;cl++)
    {
        for(int i=0;i<n-cl+1;i++)
        {
            int j=i+cl-1;
            if(s[i]==s[j] && cl==2)
            {
                dp[i][j]=2;
            }
            else if(s[i]==s[j])
            {
                dp[i][j]=2+dp[i+1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    
    return n-dp[0][n-1];
}


struct Temple 
{ 
    int L; 
    int R; 
}; 
 
int offeringNumber(int n, int templeHeight[]) 
{ 
    Temple chainSize[n]; 
    for (int i = 0; i < n; ++i) 
    { 
        chainSize[i].L = -1; 
        chainSize[i].R = -1; 
    } 
  
    chainSize[0].L = 1; 
    chainSize[n-1].R = 1; 

    for (int i=1; i<n; ++i) 
    { 
        if (templeHeight[i - 1] < templeHeight[i]) 
            chainSize[i].L = chainSize[i - 1].L + 1; 
        else
            chainSize[i].L = 1; 
    } 
    for (int i=n-2; i>=0; --i) 
    { 
        if (templeHeight[i + 1] < templeHeight[i]) 
            chainSize[i].R = chainSize[i + 1].R + 1; 
        else
            chainSize[i].R = 1; 
    } 
  
    int sum = 0; 
    for (int i = 0; i < n; ++i) 
        sum += max(chainSize[i].L, chainSize[i].R); 
    return sum; 
} 

int zigzag_sum(int mat[MAX][MAX],int n,int m)
{
    int dp[n][m];
    
    for(int i=0;i<m;i++)
    {
        dp[n-1][i]=mat[n-1][i];
        cout << dp[n-1][i] << " ";
    }
    cout << endl;
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
           int maxi=INT_MIN;
           int maxindex=-1;
           for(int k=0;k<m;k++)
           {
               if(j!=k)
               {
                   if(mat[i][k]>maxi)
                   {
                       maxi=mat[i][k];
                       maxindex=k;
                   }
               }
               
           }
           
           dp[i][j]=dp[i+1][j]+maxi;
        }
        
        for(int j=0;j<m;j++)
        {
          cout << dp[i][j] << " ";   
        }
        
        cout << endl;
    }
    
    return *max_element(dp[0],dp[0]+m);
}


int sum_of_all_substrings(string s)
{
    int n=s.length();
    int sumofdig[n+1];
    
    sumofdig[0]=s[0]-'0';
    int res=sumofdig[0];
    
    for(int i=1;i<n;i++)
    {
        int numi=s[i]-'0';
        sumofdig[i]=(i+1)*numi+10*sumofdig[i-1];
        
        res+=sumofdig[i];
    }
    
    return res;
}

int max_adj_diff_modify_arr(int arr[],int n)
{
    int dp[n+1][2];
    
    for(int i=0;i<n;i++)
    {
        dp[i][0]=dp[i][1]=0;
    }
    
    for(int i=0;i<n-1;i++)
    {
        /*  for [i+1][0] (i.e. current modified 
            value is 1), choose maximum from 
            dp[i][0] + abs(1 - 1) = dp[i][0] and 
            dp[i][1] + abs(1 - arr[i])   */
        dp[i+1][0]=max(dp[i][0],dp[i][1]+abs(1-arr[i]));
        
        /*  for [i+1][1] (i.e. current modified value 
            is arr[i+1]), choose maximum from 
            dp[i][0] + abs(arr[i+1] - 1)    and 
            dp[i][1] + abs(arr[i+1] - arr[i])*/
        dp[i+1][1]=max(dp[i][0] + abs(arr[i+1] - 1)
              ,dp[i][1]+abs(arr[i]-arr[i+1]));
    }
    
    return max(dp[n-1][0],dp[n-1][1]);
}

//using a,b,c only
int cnt_string_oneb_twocs_atmost(int n)
{
    1+(n*2)+(n*((n*n)-1)/2); 
}

int highway_billboard(int x[],int revenue[],int n,int m,int t)
{
    int maxRev[m+1]; 
    memset(maxRev, 0, sizeof(maxRev)); 
  
    int nxtbb = 0; 
    for (int i = 1; i <= m; i++) 
    { 
        if (nxtbb < n) 
        {
            if (x[nxtbb] != i) 
                maxRev[i] = maxRev[i-1]; 
            else
            { 
                if (i <= t) 
                    maxRev[i] = max(maxRev[i-1], revenue[nxtbb]); 
                else
                    maxRev[i] = max(maxRev[i-t-1]+revenue[nxtbb], 
                                                  maxRev[i-1]); 
  
                nxtbb++; 
            } 
        } 
        else
            maxRev[i] = maxRev[i - 1]; 
    } 
  
    return maxRev[m]; 
} 


int max_submatrix_with_all_ones(int arr[MAX][MAX],int n,int m)
{
    
    int dp[n][m];
    
    for(int i=0;i<n;i++)
    {
        dp[i][0]=arr[i][0];
    }
    
    for(int j=0;j<m;j++)
    {
        dp[0][j]=arr[0][j];
    }
    
    int maxi=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]==1)
            {
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
            else
            {
                dp[i][j]=0;
            }
            maxi=max(maxi,dp[i][j]);
        }
    }
    
    return maxi;
}

int max_submatrix_with_all_anynumber(int arr[MAX][MAX],int n,int m)
{
    
    int dp[n][m];
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=0;
        }
    }
    
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 || j==0)
            {
              dp[i][j]=1;
            }
            else 
            {
               if (arr[i][j] == arr[i-1][j] && 
                    arr[i][j] == arr[i][j-1] && 
                    arr[i][j] == arr[i-1][j-1] ) 
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), 
                                      dp[i-1][j-1] ) + 1; 
  
                else
                {
                    dp[i][j]=1;
                }
            }
            maxi=max(maxi,dp[i][j]);
        }
    }
    
    return maxi;
}

int countEndless(bool input[][MAX], int n) 
{ 
    bool row[n][n], col[n][n]; 
  
    for (int j=0; j<n; j++) 
    { 
        bool isEndless = 1; 
        for (int i=n-1; i>=0; i--) 
        { 
            if (input[i][j] == 0) 
                isEndless = 0; 
            col[i][j] = isEndless; 
        } 
    } 
  
    for (int i=0; i<n; i++) 
    { 
        bool isEndless = 1; 
        for (int j= n-1; j>=0; j--) 
        { 
            if (input[i][j] == 0) 
                isEndless = 0; 
            row[i][j] = isEndless; 
        } 
    } 
    int ans = 0; 
    for (int i=0; i<n; i++) 
        for (int j=1; j<n; j++) 
            if (row[i][j] && col[i][j]) 
                ans++; 
  
    return ans; 
} 

int main()
{
    // int n=4;
    // int m=10;
    // cout << seq_len_elem_gt_or_twice_ofprev(m,n);
    
    // int arr[]={1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << ways_to_reach_end(arr,n);
    
    // string s="geeksforgeeks";
    // cout << min_deletions_to_make_string_pall(s);
    
    //   int mat[MAX][MAX] = { {4, 2, 1}, 
    //                         {3, 9, 6}, 
    //                         {11, 3, 15}}; 
                    
    //   cout << zigzag_sum(mat,3,3);
    
    // string num = "1234"; 
    // cout << sum_of_all_substrings(num);
    
    // int arr[] = {3, 2, 1, 4, 5};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << max_adj_diff_modify_arr(arr,n);
    
    //  int a[MAX][MAX] = { {2, 2, 3, 3, 4, 4},
    //                     {5, 5, 7, 7, 7, 4},
    //                     {1, 2, 7, 7, 7, 4},
    //                     {4, 4, 7, 7, 7, 4},
    //                     {5, 5, 5, 1, 2, 7},
    //                     {8, 7, 9, 4, 4, 4} 
    //                   }; 
  
    // cout << max_submatrix_with_all_anynumber(a,6,6);
    
    // bool input[][MAX] = { {1, 0, 1, 1}, 
    //                      {0, 1, 1, 1}, 
    //                      {1, 1, 1, 1}, 
    //                      {0, 1, 1, 0}}; 
    // int n = 4; 
    // cout << countEndless(input, n); 
}