//https://www.geeksforgeeks.org/medium/dynamic-programming/3/
//dynamic-programming

#include <bits/stdc++.h>
using namespace std;
#define MAX 50

//not done 
//https://www.geeksforgeeks.org/maximum-sum-path-in-a-matrix-from-top-to-bottom-and-back/
// int max_sum_twice(int arr[][MAX],int n,int m)
// {
//     int cost[n][m];
//     cost[0][0]=arr[0][0];
//     for(int i=1;i<n;i++)
//     {
//         cost[i][0]=cost[i-1][0]+arr[i][0];
//     }
    
//     for(int j=1;j<m;j++)
//     {
//         cost[0][j]=cost[0][j-1]+arr[0][j];
//     }
    
    
//     for(int i=1;i<n;i++)
//     {
//         for(int j=1;j<m;j++)
//         {
//             cost[i][j]=arr[i][j]+max(cost[i-1][j-1],
//             max(cost[i][j-1],cost[i-1][j]));
            
           
//         }
//     }
    
//       int vis[n][m]={0};
//     for(int i=1;i<n;i++)
//     {
//         for(int j=1;j<m;j++)
//         {
//             int maxi=0;
//             int maxj=0;
//             if(cost[i-1][j]>cost[i][j-1] && cost[i-1][j]>cost[i-1][j-1])
//             {
//                 maxi=i-1;
//                 maxj=j;
//             }
//             else if(cost[i-1][j-1]>cost[i][j-1] && cost[i-1][j-1]>cost[i-1][j])
//             {
//                 maxi=i-1;
//                 maxj=j-1;
//             }
//             else if(cost[i][j-1]>cost[i-1][j-1] && cost[i][j-1]>cost[i-1][j])
//             {
//                 maxi=i;
//                 maxj=j-1;
//             }
            
//             vis[maxi][maxj]=1;
//             cout << arr[maxi][maxj] << endl;
//         }
//     }
//     for(int i=1;i<n;i++)
//     {
//         for(int j=1;j<m;j++)
//         {
//           cout << vis[i][j] << " ";
//         }
//         cout << endl;
//     }
    
//     return cost[n-1][m-1];
// }

void bellman_ford(int graph[][3],int v,int e,int src)
{
    int dist[v];
    for(int i=0;i<v;i++)
    {
        dist[i]=INT_MAX;
    }
    
    dist[src]=0;
    
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(dist[graph[j][0]]+graph[j][2]<
            dist[graph[j][1]])
            {
                dist[graph[j][1]]=dist[graph[j][0]]+graph[j][2];
            }
        }
    }
    
    for (int i = 0; i < e; i++) { 
        int x = graph[i][0]; 
        int y = graph[i][1]; 
        int weight = graph[i][2]; 
        if (dist[x] != INT_MAX && 
                   dist[x] + weight < dist[y]) 
            cout << "Graph contains negative"
                    " weight cycle"
                 << endl; 
    } 
  
    cout << "Vertex Distance from Source" << endl; 
    for (int i = 0; i < v; i++) 
        cout << i << "\t\t" << dist[i] << endl; 
}
  
int dp_mincub[1000];
int min_cubes_req(int k)
{
    if(dp_mincub[k]!=0)
    {
        return dp_mincub[k];
    }
    
   if (k < 8) 
        return k; 
        
    int res = k; 
    for (int i = 1; i <= k; i++) { 
        if ((i * i * i) > k) 
            return res; 
        res = min(res,min_cubes_req(k - (i * i * i)) + 1); 
    } 
    
    return dp_mincub[res]=res;
    
}

void print_answer(string s,int l,int h)
{
    for(int i=l;i<=h;i++)
    {
        cout << s[i] ;
    }
    
    cout << endl;
}

void longest_pallindrome(string s)
{
    int maxlen=1;
    int n=s.length();
    
    int start=0;
    bool dp[n][n];
    memset(dp,0,sizeof(dp));
     for(int i=0;i<n;i++)
    {
        dp[i][i]=true;
    }
    
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            maxlen=2;
            dp[i][i+1]=true;
            start=i;
        }
    }
    
    for(int k=3;k<=n;++k)
    {
        for(int i=0;i<n-k+1;++i)
        {
             // starting index i and length k 
            int j=i+k-1;
            if(dp[i+1][j-1] && s[i]==s[j])
            {
                dp[i][j]=true;
                if(k>maxlen)
                {
                    start=i;
                    maxlen=k;
                }
            }
            
        }
    }
    
    print_answer(s,start,start+maxlen-1);
    cout << maxlen;
}

void longest_pallindrome_v2(string str)
{
    int maxlen=1;
    int n=str.length();
    
    int start=0;
    int low,high;
    
    
    for(int i=1;i<n;i++)
    {
        low=i-1;
        high=i;
       while(low>=0 && high<n && str[low]==str[high])
       {
           if(high-low+1>maxlen)
           {
               start=low;
               maxlen=high-low+1;
           }
           --low;
           ++high;
       }
       
       low = i - 1;  
       high = i + 1;
       while (low >= 0 && high < n && str[low] == str[high])  
        {  
            if (high - low + 1 > maxlen)  
            {  
                start = low;  
                maxlen = high - low + 1;  
            }  
            --low;  
            ++high;  
        }  
    }
    
    print_answer(str,start,start+maxlen-1);
    cout << maxlen;
}

int binary_string_with_3cons1s(int n)
{
    int dp[n+2][3];
    
    dp[2][0]=2;
    dp[2][1]=1;
    dp[2][2]=1;
    
    for(int i=3;i<=n+1;i++)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][1];
    }
    
    return pow(2,n)-dp[n+1][0];
}

int max_sum_subarray_alteringsigns(int a[],int n)
{
    int dp[n+1][3];
    memset(dp,0,sizeof(dp));
    int arr[n+1];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        arr[i]=a[i-1];
    }
    
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=max(arr[i],dp[i-1][0]+arr[i]);
        
        dp[i][1]=max(0,dp[i-1][0])-arr[i];
        
        if(i>=2)
        {
            dp[i][1]=max(dp[i][1],dp[i-1][1]+arr[i]);
        }
        
        if(i>=2)
        {
            dp[i][2]=dp[i-1][1]-arr[i];
        }
        
        if(i>=3)
        {
            dp[i][2]=max(dp[i][2],dp[i-1][2]+arr[i]);
        }
        
        ans = max(ans, dp[i][0]); 
        ans = max(ans, dp[i][1]); 
        ans = max(ans, dp[i][2]);
    }
    
    return ans;
}


int subsequence_not_less_thank(int arr[],int k,int n)
{
    int dp[n+1];
    
    dp[0]=1;
    
    for(int i=1;i<k;i++)
    {
        dp[i]=max(dp[i-1],arr[i]);
    }
    
    for(int i=k;i<n;i++)
    {
        dp[i]=max(dp[i-(1+k)]+arr[i],arr[i]);
    }
    
    return *max_element(dp,dp+n);
}

int max_number_of_composite(int n)
{
    int maxn=16;
    int dp[maxn]={-1};
    dp[0]=0;
    for(int i=0;i<maxn;i++)
    {
        for(int j:{4,6,9})
        {
            if(i>=j  && dp[i-j]!=-1)
            {
                dp[i]=max(dp[i],dp[i-j]+1);
            }
        }
    }
    
    if(n<16)
    {
        return dp[n];
    }
    else 
    {
        int t=(n-maxn)/4+1;
        return t+dp[n-4*t];
    }
    
    return -1;
}

bool comp(int a,int i,vector<vector<int> > v)
{
   int temp=a;
   int k;
   while(temp>0)
   {
       k=temp%10;
       temp=temp/10;
       if(v[i][k]==1)
       {
           return true;
       }
   }
   
   return false;
}

int ways_to_score_r(int r,int b,int w,int arr[],int dp[MAX][MAX][MAX])
{
    if(w<=0 && r>0)
    {
        return 0;
    }
    
    if(r<0)
    {
        return 0; 
    }
    
    if(b<=0 && r!=0)
    {
        return 0;
    }
    
    if(r==0 && b==0)
    {
        return 1;
    }
    
    if(dp[r][b][w]!=-1)
    {
        return dp[r][b][w];
    }
    
    int ways=0;
    for(int i=0;i<7;i++)
    {
        if(arr[i]==-1)
        {
            ways+=ways_to_score_r(r,b-1,w-1,arr,dp);
        }
        else
        {
            ways+=ways_to_score_r(r-arr[i],b-1,w,arr,dp);
        }
    }
    
    return dp[r][b][w]=ways;
}

int min_cost_path_jumps_lessthank(int arr[],int n,int k)
{
    int dp[n+1];
    dp[0]=0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < i + k + 1; j++) { 
            dp[j] = min(dp[j], dp[i] + abs(arr[i] - arr[j])); 
        } 
    } 
    
    return dp[n-1];
  
}

//make changes
int max_sum_3arrays_nocons(int arr1[],int arr2[],int arr3[],int n)
{
    int dp[n+1][3];
    
    dp[0][0]=arr1[0];
    dp[0][1]=arr2[0];
    dp[0][2]=arr3[0];
    
    for(int i=1;i<n;i++)
    {
        dp[i][0]=max(arr2[i]+dp[i-1][0],arr3[i]+dp[i-1][0]);
        dp[i][1]=max(arr1[i]+dp[i-1][1],arr3[i]+dp[i-1][1]);
        dp[i][2]=max(arr1[i]+dp[i-1][2],arr2[i]+dp[i-1][2]);
    }
    
    return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}

int min_steps_delete_elems(int start,int end,string s,int dp[][MAX])
{
    if(start>end)
    {
        return 0;
    }
    
    if(start==end)
    {
        return 1;
    }
    
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
    
    int res=1+min_steps_delete_elems(start+1,end,s,dp);
    
    for(int i=start+1;i<=end;i++)
    {
        if(s[start]==s[i])
        {
            res=min(res,min_steps_delete_elems(start,i-1,s,dp)+
                    min_steps_delete_elems(i+1,end,s,dp));
        }
    }
    
    return dp[start][end]=res;
}

//wrong
int min_prod_dist_lessk(int arr[],int n,int k)
{
    
    int dp[n+1];
    dp[0]=INT_MAX;
    
    for(int i=0;i<=k;i++)
    {
        for(int j=i+1;j<i+k+1;j++)
        {
            dp[i]=min(dp[i],dp[i]*arr[j]);
        }
    }
    
    return dp[n-1];
}

int dfs(vector<vector<int> > adj,int i,int v,int e)
{
   stack<int> s;
   s.push(i);
   int cnt=0;
   int vis[v]={0};
   
   while(!s.empty())
   {
       int k=s.top();
       s.pop();
       
       if(vis[k]!=1)
       {
           cnt++;
       }
       
       for(int i=0;i<adj[k].size();i++)
       {
           if(vis[adj[k][i]]!=1)
           {
               s.push(adj[k][i]);
           }
       }
   }
   
   return cnt;
}

int longest_path_DAG(int graph[][MAX],int v,int e)
{
    vector<vector<int> > adj;
    for(int i=0;i<e;i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
    }
    
    int maxi=0;
    for(int i=0;i<v;i++)
    {
        maxi=max(maxi,dfs(adj,i,v,e));
    }
    
    return maxi;
}

int findSubarraySum(int ind, int flips, int n, int a[], int k,int dp[][MAX]) 
{ 
    if (flips > k) 
        return -1e9; 
  
    if (ind == n) 
        return 0; 
 
    if (dp[ind][flips] != -1) 
        return dp[ind][flips]; 
  
    int ans = 0; 
 
    ans = max(0, a[ind] 
          + findSubarraySum(ind + 1, flips, n, a, k,dp)); 
    ans = max(ans, -a[ind] 
          + findSubarraySum(ind + 1, flips + 1, n, a, k,dp)); 

    return dp[ind][flips] = ans; 
} 
  
int findMaxSubarraySum(int a[], int n, int k) 
{ 
    //int dp[n][k+1];
    int dp[n][MAX];
    memset(dp, -1, sizeof(dp)); 
  
    int ans = -1e9; 

    for (int i = 0; i < n; i++) 
        ans = max(ans, findSubarraySum(i, 0, n, a, k,dp)); 
  
    return ans; 
} 

int dp_knap[MAX][MAX][MAX];

int maxWeight(int* arr, int n, int w1_r, int w2_r, int i) 
{ 
    if (i == n) 
        return 0; 
    if (dp_knap[i][w1_r][w2_r] != -1) 
        return dp_knap[i][w1_r][w2_r]; 
  
    int fill_w1 = 0, fill_w2 = 0, fill_none = 0; 
  
    if (w1_r >= arr[i]) 
        fill_w1 = arr[i] +  
         maxWeight(arr, n, w1_r - arr[i], w2_r, i + 1); 
  
    if (w2_r >= arr[i]) 
        fill_w2 = arr[i] +  
         maxWeight(arr, n, w1_r, w2_r - arr[i], i + 1); 
  
    fill_none = maxWeight(arr, n, w1_r, w2_r, i + 1); 
  
    dp_knap[i][w1_r][w2_r] = max(fill_none, max(fill_w1, fill_w2)); 
  
    return dp_knap[i][w1_r][w2_r]; 
}

int removing_subsequence(string s,int arr[],int n)
{
    long long valofc=0,valofo=0,valofd=0,valofe=0;
    
    for(int i=0;i<n;i++)
    {
        //remove c
        if(s[i]=='c')
        {
            valofc+=arr[i];
        }
        //remove co
        else if(s[i]=='o')
        {
            valofo=min(valofc,valofo+arr[i]);
        }
        //remove cod
        else if(s[i]=='d')
        {
            valofd=min(valofo,valofd+arr[i]);
        }
        //remove code
        else if(s[i]=='e')
        {
            valofe=min(valofd,valofe+arr[i]);
        }
    }
    
    return valofe;
}

int longest_subsequence_common_digits(int arr[],int n)
{
    vector<vector<int>> dp(n , vector<int> (10,0) );
    
   for(int i=0;i<n;i++)
   {
       int temp=arr[i];
       int k;
       while(temp>0)
       {
            k=temp%10;
           temp=temp/10;
           dp[i][k]=1;
       }
   }
   
   int ans[n+1];
   ans[0]=1;
   for(int i=1;i<n;i++)
   {
       ans[i]=1;
       for(int j=0;j<i;j++)
       {
           if(comp(arr[i],j,dp) && ans[i]<ans[j]+1)
           {
               ans[i]=ans[j]+1;
           }
       }
   }
   
   return *max_element(ans,ans+n);
}

int main() {
    
    // int arr[][MAX]={{1, 0, 3, -1},
    //       {3, 5, 1, -2},
    //       {-2, 0, 1, 1},
    //       {2, 1, -1, 1}};
          
    // int n=4;int m=4;
    // cout << max_sum_twice(arr,n,m);
    
    // int v = 5; 
    // int e = 8; 
 
    // int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 }, 
    //                   { 1, 2, 3 }, { 1, 3, 2 },  
    //                   { 1, 4, 2 }, { 3, 2, 5 },  
    //                   { 3, 1, 1 }, { 4, 3, -3 } }; 
  
    // bellman_ford(graph, v, e, 1); 
    
    // string s="forgeeksskeegfor";
    // longest_pallindrome(s);
    
    // string s="forgeeksskeegfor";
    // longest_pallindrome_v2(s);
    
    //cout << binary_string_with_3cons1s(10);
    
    // int arr[] = { -5, 3, 2, 7, -8, 3, 7, -9, 10, 12, -6 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << max_sum_subarray_alteringsigns(arr, n); 
    
    // int arr[] = { 6, 7, 1, 3, 8, 2, 4 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // int k = 2; 
    // cout << subsequence_not_less_thank(arr, k, n); 
  
    // cout << max_number_of_composite(12);
    
    // int arr[]={12, 23, 45, 43, 36, 97};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // cout << longest_subsequence_common_digits(arr,n);
    
    //  int R = 40, B = 10, W = 4; 
    //  int arr[]={-1,0,1,2,4,3,6};
    //  int dp[MAX][MAX][MAX]; 
    //  memset(dp, -1, sizeof dp); 
    //  cout << ways_to_score_r(40,10,4,arr,dp);
    
    // int a[] = { 6, 8, 2, 7, 4, 2, 7 }; 
    // int b[] = { 7, 8, 5, 8, 6, 3, 5 }; 
    // int c[] = { 8, 3, 2, 6, 8, 4, 1 }; 
    // int n = sizeof(a) / sizeof(a[0]); 
    // cout << max_sum_3arrays_nocons(a,b,c,n);
    
    // int arr[]={ 83, 26, 37, 35, 33, 35, 56 };
    // int k=3;
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << min_cost_path_jumps_lessthank(arr,n,k);
    
    // string s = "abcddcba"; 
    // int n = s.length(); 
    // int dp[MAX][MAX];
    // memset(dp,-1,sizeof(dp));
    // cout << min_steps_delete_elems(0,n-1,s,dp);
    
    // string str = "geekcodergeeks"; 
    // int arr[] = { 1, 2, 1, 3, 4, 2, 6, 4, 6, 2, 3, 3, 3, 2 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << removing_subsequence(str, arr, n); 
    
	return 0;
}