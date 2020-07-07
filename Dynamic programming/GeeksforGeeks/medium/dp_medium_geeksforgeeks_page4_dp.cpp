//https://www.geeksforgeeks.org/medium/dynamic-programming/4/
//dynamic-programming

#include <bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99940400

int ways_range_sum(int n,int start,int end)
{
    int tl=start;
    int tr=end;
    
    int L[2]={0};
    int R[2]={0};
    L[start%2]=start;
    R[end%2]=end;
    
    start++;
    end--;
    if(tr>=start && tl<=end)
    {
        L[start%2]=start;
        R[end%2]=end;
    }
    
    int cnt0=0,cnt1=0;
    if(R[0] && L[0])
        cnt0=(R[0]-L[0])/2+1;
    if(R[1] && L[1])
        cnt1=(R[1]-L[1])/2+1;
        
    int dp[n][2];
    dp[1][0]=cnt0;
    dp[1][1]=cnt1;
    for (int i = 2; i <= n; i++) { 

        dp[i][0] = (cnt0 * dp[i - 1][0] 
                    + cnt1 * dp[i - 1][1]); 
  
        dp[i][1] = (cnt0 * dp[i - 1][1] 
                    + cnt1 * dp[i - 1][0]); 
    } 
  
    return dp[n][0];
}

int find_sub_matrix_with_sum(int arr[][MAX],int n,int m,int s,int k)
{
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]
                        -dp[i][j]+arr[i][j];
        }
    }
    
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
     for (int i = 0; i < n; i += k) 
        for (int j = 0; j < n; j += k) { 
            int sum = dp[i+k][j+k]-dp[i+k][j]-dp[i][j+k]
                        +dp[i][j];
  
            if (sum == s) 
                return true; 
        } 
  
    return false; 
}

int MOD=998244353;
int dp_colour[MAX][MAX];
int colour_nboxes_mcol_withk(int idx,int n,
                    int m,int k,int diff)
{
    if(idx>n)
    {
        if(diff==k)
        {
            return 1;
        }
        return 0;
    }
    
    if(dp_colour[idx][diff]!=-1)
    {
        return dp_colour[idx][diff];
    }
    int ans=colour_nboxes_mcol_withk(idx+1,n,m,k,diff);
    ans+=(m-1)*colour_nboxes_mcol_withk(idx+1,n,m,k,diff+1);
    
    return dp_colour[idx][diff]=ans%MOD;
    
}


//wrong
// int maze_rat_jumps_s(int mat[][MAX],int n,int m,int s)
// {
//     int crf[n+1][m+1];
    
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             crf[i][j]=false;
//         }
//     }
//     crf[n-1][m-1]=true;
    
//     for(int i=n-1;i>=0;i--)
//     {
//         if(int j=m-1;j>=0;j--)
//         {
//             if(i!=n-1 && j!=m-1)
//             {
//                 for(int k=0;k<=mat[i][j];k++)
//                 {
//                     if(j-k<m && mat[i][j-k]!=0)
//                     {
//                         crf[i][j]=true;
//                     }
//                 }
                
//                 for(int k=0;k<=mat[i][j];k++)
//                 {
//                     if(i-k<n && mat[i-k][j]!=0)
//                     {
//                         crf[i][j]=true;
//                     }
//                 }
//             }
//         }
//     }
    
// }

bool convert_x_to_y(int mat[][MAX],int x,int y,int n,int m)
{
    int dist[n][n], i, j, k; 
  
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n; j++) { 
            if (mat[i][j] == 0) 
                dist[i][j] = INF; 
            else
                dist[i][j] = 1; 
  
            if (i == j) 
                dist[i][j] = 1; 
        } 
    } 
    
    for (k = 0; k < n; k++) { 
        for (i = 0; i < n; i++) { 
            for (j = 0; j < n; j++) { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 
    
     if (dist[x][y] < INF) 
        return dist[x][y]; 
    else
        return -1; 
    
}

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

void printGraph(vector<int> adj[], int V) 
{ 
    for (int v = 0; v < V; ++v) { 
        cout << "\n Adjacency list of vertex "
             << v << "\n head "; 
        for (auto x : adj[v]) 
            cout << "-> " << x; 
        printf("\n"); 
    } 
} 
  
void findMinOperationUtil(int dp[][2], vector<int> adj[], 
                          int A[], int src, int parent) 
{ 
    dp[src][0] = dp[src][1] = 0; 
    for (auto V : adj[src]) { 
        if (V == parent) 
            continue; 
 
        findMinOperationUtil(dp, adj, A, V, src); 
  
        dp[src][0] = max(dp[src][0], dp[V][0]); 
  
        dp[src][1] = max(dp[src][1], dp[V][1]); 
    } 

    A[src - 1] += dp[src][0] - dp[src][1]; 
    if (A[src - 1] > 0) { 
        dp[src][1] += A[src - 1]; 
    } 
    else { 
        dp[src][0] += abs(A[src - 1]); 
    } 
} 
  
int findMinOperation(vector<int> adj[], int A[], int V) 
{ 
    int dp[V + 1][2]; 
    memset(dp, 0, sizeof dp); 
  
    findMinOperationUtil(dp, adj, A, 1, 0); 
  
    int minOperations = dp[1][0] + dp[1][1]; 
    return minOperations; 
} 


const int M = 20; 
int dp_digit[M][M][2]; 
int K; 
int countInRangeUtil(int pos, int cnt, int tight, 
                     vector<int> num) 
{ 
    if (pos == num.size()) { 
        if (cnt <= K) 
            return 1; 
        return 0; 
    } 
 
    if (dp_digit[pos][cnt][tight] != -1) 
        return dp_digit[pos][cnt][tight]; 
  
    int ans = 0; 
    int limit = (tight ? 9 : num[pos]); 
  
    for (int dig = 0; dig <= limit; dig++) { 
        int currCnt = cnt; 
        if (dig != 0) 
            currCnt++; 
  
        int currTight = tight; 
        if (dig < num[pos]) 
            currTight = 1; 
  
        ans += countInRangeUtil(pos + 1, currCnt, 
                                currTight, num); 
    } 
    return dp_digit[pos][cnt][tight] = ans; 
} 
  
int countInRange(int x) 
{ 
    vector<int> num; 
    while (x) { 
        num.push_back(x % 10); 
        x /= 10; 
    } 
    reverse(num.begin(), num.end()); 
  
    memset(dp_digit, -1, sizeof(dp_digit)); 
    return countInRangeUtil(0, 0, 0, num); 
} 

int dp_digit_k[M][M][2][2];

int digit_dp_digoccurs_ktimes(vector<int> num,int idx,int tight,int cnt,int nonz,int digit)
{
    if(num.size()==idx)
    {
        if(cnt==K)
        {
            return 1;
        }
        return 0;
    }
    
    if(dp_digit_k[idx][cnt][tight][nonz]!=-1)
    {
        return dp_digit_k[idx][cnt][tight][nonz];
    }
    
    int ans=0;
    int limit=tight ? 9: num[idx];
    for(int i=0;i<=limit;i++)
    {
        int cur_count=cnt;
        if(num[i]==digit)
        {
            if (digit != 0 || (!digit && nonz)) 
            {
                cur_count++;
            }
        }
        
        int currTight=tight;
        if(i<num[idx])
        {
            currTight=1;
        }
        
        ans+=digit_dp_digoccurs_ktimes(num,idx+1,cur_count,currTight,
                                           nonz || (i != 0),digit);
    }
    
    return dp_digit_k[idx][cnt][tight][nonz]=ans;
}

int solve(int x,int digit) 
{ 
    vector<int> num; 
    while (x) { 
        num.push_back(x % 10); 
        x /= 10; 
    } 
    reverse(num.begin(), num.end()); 
    
    memset(dp_digit_k, -1, sizeof(dp_digit_k)); 
    return digit_dp_digoccurs_ktimes(num,0, 0, 0,0,digit); 
} 

int nCr(int n,int r)
{
    int ans=1;
    if(r>n-r)
    {
        r=n-r;
    }
    for(int i=0;i<r;i++)
    {
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}

int derangements(int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=0;
    dp[2]=1;
    
    for(int i=3;i<=n;i++)
    {
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    
    return dp[n];
}

int cnt_perm_atleast_n_k_inpos(int n,int k)
{
    int ans = 0; 
    for (int i = n - k; i <= n; i++) { 
        int ways = nCr(n, i); 
        ans += ways * derangements(n - i); 
    } 
    return ans;     
}

int k_series_fibonaci(int n)
{
    int fib[n+1];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<n;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
        cout << fib[i] << " ";
    }
    
    return 0;
}

int maxPlus(int arr[MAX][MAX]) 
{ 
    int N=10;int n=10;int m=10; //random for now actually user has to give
    int ans = INT_MIN; 
    int left[N][N], right[N][N], up[N][N], down[N][N]; 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            left[i][j] = max(0LL, (j ? left[i][j - 1] : 0LL))   
                                             + arr[i][j]; 
            up[i][j] = max(0LL, (i ? up[i - 1][j] : 0LL)) 
                                              + arr[i][j]; 
        } 
    } 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            right[i][j] = max(0LL, (j + 1 == m ? 0LL: right[i][j + 1])) 
                                                            + arr[i][j]; 
            down[i][j] = max(0LL, (i + 1 == n ? 0LL: down[i + 1][j])) 
                                                            + arr[i][j]; 
        } 
    } 
  
    for (int i = 1; i < n - 1; ++i) 
        for (int j = 1; j < m - 1; ++j) 
            ans = max(ans, up[i - 1][j] + down[i + 1][j]  
                        + left[i][j - 1] + right[i][j + 1] + arr[i][j]); 
  
    return ans; 
} 

int coin_change_problem(int coins[],int n,int res)
{
    int ways[res+1]={0};
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<res;j++)
        {
            if(coins[i]<=j)
            {
                ways[j]+=ways[j-coins[i]];
            }
        }
    }
    
    return ways[res];
}

int min_no_increasing_subsequence(int arr[],int n)
{
    int dp[n+1];
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i]*-1; //this step changes codea
    }
    
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    
    return *max_element(dp,dp+n);
}

int MatrixChainOrder(int p[], int n) 
{ 
    int dp[n][n]; 
  
    /* dp[i, j] = Minimum number of scalar multiplications needed to compute the matrix M[i]M[i+1]...M[j]  
                = M[i..j] where dimension of M[i] is p[i-1] x p[i] */
                  
    for (int i=1; i<n; i++) 
        dp[i][i] = 0; 
  
    // Simply following above recursive formula. 
    for (int L=1; L<n-1; L++)  
    for (int i=1; i<n-L; i++)      
        dp[i][i+L] = min(dp[i+1][i+L] + p[i-1]*p[i]*p[i+L], 
                    dp[i][i+L-1] + p[i-1]*p[i+L-1]*p[i+L]);      
      
    return dp[1][n-1]; 
} 
int main() {
	
    // 	int n=10;
    //  int l=1;
    //  int r=6;
    //  cout << ways_range_sum(n,l,r);

    // int grid[MAX][MAX] = { { 1, 2, 3, 4 }, 
    //                   { 5, 6, 7, 8 }, 
    //                   { 9, 10, 11, 12 }, 
    //                   { 13, 14, 15, 16 } }; 
    // int K = 2; 
    // int S = 14; 
    // cout << find_sub_matrix_with_sum(grid,4,4,S,K);
    
    // int n=5;
    // int m=3;
    // int k=2;
    // memset(dp_colour,-1,sizeof(dp_colour));
    // cout << m*colour_nboxes_mcol_withk(2,n,m,k,0);
  
    // int mat[MAX][MAX] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    //                         { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    //                         { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 
    //                         { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 
    //                         { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 
    //                         { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    //                         { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    //                         { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    //                         { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    //                         { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } }; 
  
    // int x = 2, y = 3; 
    // int n = 10  , m = 10 ;
    // cout << convert_x_to_y(mat,x,y,n,m);
    
    // int L = 1, R = 1000; 
    // K = 3; 
    // cout << countInRange(R) - countInRange(L - 1) << endl; 
  
    // L = 9995, R = 10005, K = 2; 
    // cout << countInRange(R) - countInRange(L - 1) << endl; 
    
    // int L = 11, R = 100; 
    // int d = 2, K = 1; 
    // cout << solve(R,d) - solve(L - 1,d) << endl;
    
    // int n=5;
    // int k=3;
    // cout << cnt_perm_atleast_n_k_inpos(n,k);
    
    // int arr[] = { 8, 4, 1, 2, 9 ,-10 } ; 
    // int n = sizeof(arr)/sizeof(arr[0]); 
    // cout <<min_no_increasing_subsequence(arr, n); 
    
    int arr[] = {10, 20, 30, 40, 30} ; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    cout << MatrixChainOrder(arr, size); 
	return 0;
}