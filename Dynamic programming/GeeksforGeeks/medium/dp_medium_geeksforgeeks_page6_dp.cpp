//https://www.geeksforgeeks.org/medium/dynamic-programming/6/
//dynamic-programming

#include <bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999

int numberOfBST(int n) 
{ 
    int dp[n + 1]; 
    fill_n(dp, n + 1, 0); 
 
    dp[0] = 1; 
    dp[1] = 1; 
  
    for (int i = 2; i <= n; i++) { 
        for (int j = 1; j <= i; j++) { 
            dp[i] = dp[i] + (dp[i - j] * dp[j - 1]); 
        } 
    } 
  
    return dp[n]; 
}

int dp_wines[MAX][MAX];
int sell[MAX][MAX];
int max_profit_wines(int arr[],int start,
           int end,int year)
{
    if(dp_wines[start][end]!=-1)
    {
        return dp_wines[start][end];
    }
    
    if(start>end)
    {
        return 0;
    }
    
    int x=arr[start]*year+
    max_profit_wines(arr,start+1,end,year+1);
    
    int y=arr[end]*year+
    max_profit_wines(arr,start,end-1,year+1);
    
    int ans=max(x,y);
    dp_wines[start][end]=ans;
    
    if(x>=y)
    {
        sell[start][end]=0;
    }
    else
    {
        sell[start][end]=1;
    }
    
    return ans;
}

void end_beg_printer(int n)
{
     int i = 0, j = n - 1; 
  
    while (i <= j) { 
        if (sell[i][j] == 0) { 
            cout << "beg "; 
            i++; 
        }  else { 
            cout << "end "; 
            j--; 
        } 
    } 
}

int longest_inc_cons_subseq(int arr[],int n)
{
    int dp[n];
    memset(dp,0,sizeof(dp));
    
    unordered_map<int,int> m;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(m.find(arr[i]-1)!=m.end())
        {
            int lastind=m[arr[i]-1]-1;
            dp[i]=1+dp[lastind];
        }
        else
        {
            dp[i]=1;
        }
        
        m[arr[i]]=i+1;
        maxi=max(maxi,dp[i]);
    }
    
    return maxi;
}

int longest_till_i_andinclude_kind(int a[],int n,int k,int ith)
{
    int dp[n+1][n+1];
     for (int i = 0; i < n; i++) { 
        if (a[i] > a[0])  
            dp[0][i] = a[i] + a[0];         
        else 
            dp[0][i] = a[i];         
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]>a[i] && j>i)
            {
                if (dp[i - 1][i] + a[j] > dp[i - 1][j])  
                    dp[i][j] = dp[i - 1][i] + a[j];                 
                else 
                    dp[i][j] = dp[i - 1][j]; 
            }
            else 
               dp[i][j] = dp[i - 1][j]; 
            
        }
    }
    
    return dp[ith][k];
}

bool isPower(long val,int base)
{
    while(val>1)
    {
        if(val%base!=0)
        {
            return false;
        }
        val/=base;
    }
    
    return true;
}

int partitions_binary(string binstr)
{
    int i,j;
    int n=binstr.length();
    
    long val;
    int dp[n];
    
    dp[n-1]=(binstr[n-1]-'0')==0 ? -1 : 1;
    
    for(int i=n-2;i>=0;i--)
    {
        val=0;
        if((binstr[i]-'0')==0)
        {
            dp[i]=-1;
            continue;
        }
        
        dp[i]=INT_MAX;
        for(int j=i;j<n;j++)
        {
            val=(val*2)+(long)(binstr[j]-'0');
            
            if(isPower(val,4) or isPower(val,6))
            {
                if(j==n-1)
                {
                    dp[i]=1;
                }
                else
                {
                    if (dp[j + 1] != -1) 
                        dp[i] = min(dp[i], dp[j + 1] + 1); 
                }
            }
        }
        
        if (dp[i] == INT_MAX) 
            dp[i] = -1; 
    }
    
    cout << dp[0] ;
}

//wrong we have to run this function to all index
//and also we to add to moving all sides 
int decreasing_paths(int arr[][MAX],int n,int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=1;
        }
    }
    
    
    dp[0][0]=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i][0]>arr[i-1][0])
        {
            dp[i][0]=dp[i-1][0]+1;
        }
    }
    
    for(int j=1;j<m;j++)
    {
        if(arr[0][j]>arr[0][j-1])
        {
            dp[0][j]=dp[0][j-1]+1;
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]>arr[i][j-1])
            {
                dp[i][j]=dp[i][j-1]+1;
            }
    
            if(arr[i][j]>arr[i-1][j])
            {
                dp[i][j]=dp[i-1][j]+1;
            }
            
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return dp[n-1][m-1];
}


int dp_tree1[MAX];
void dfs_tree_maxfrom_root_leaves(vector<int> v[],int arr[],int u,int parent)
{
    dp_tree1[u]=arr[u-1];
    
    int maxi=0;
    for(int child:v[u])
    {
        if(child==parent)
          continue;
         
        dfs_tree_maxfrom_root_leaves(v,arr,child,u);
        maxi=max(maxi,dp_tree1[child]);
    }
    
    dp_tree1[u]+=maxi;
}

void partitions_arr_eq_sum(int arr[],int n)
{
    int i, currSum; 
   
    int sum = accumulate(arr, arr+n, 0); 
    if (sum & 1) { 
        cout << "-1"; 
        return; 
    } 
    
    int k = sum >> 1; 

    bool dp[n + 1][k + 1]; 
  
    for (i = 1; i <= k; i++) 
        dp[0][i] = false; 
  
    for (i = 0; i <= n; i++) 
        dp[i][0] = true; 
        
    for(int i=1;i<=n;i++)
    {
        for(int currSum=1;currSum<=k;currSum++)
        {
            if(arr[i-1]<=currSum)
            {
                 dp[i][currSum] = dp[i-1][currSum] || dp[i - 1][currSum-arr[i-1]];
            }
            else
            {
                 dp[i][currSum] = dp[i - 1][currSum]; 
            }
        }
    }
    
    vector<int> set1, set2; 
  
    if (!dp[n][k]) { 
        cout << "-1\n"; 
        return; 
    }
    
    i = n; 
    currSum = k; 
  
    while (i > 0 && currSum >= 0) { 
        if (dp[i - 1][currSum]) { 
            i--; 
            set2.push_back(arr[i]); 
        } 
        else if (dp[i - 1][currSum - arr[i - 1]]) { 
            i--; 
            currSum -= arr[i]; 
            set1.push_back(arr[i]); 
        } 
    } 
  
    for (i = 0; i < set1.size(); i++)  
        cout << set1[i] << " "; 
  
    cout << "\n";
    
    for (i = 0; i < set2.size(); i++)  
        cout << set2[i] << " ";     
} 

int cnt_circular_petrolpmps(int a[],int b[],int n,int c)
{
    int need[100+1];
    
    for(int i=0;i<n;i++)
    {
        a[i+n]=a[i];
        b[i+n]=b[i];
    }
    
    int s=0;
    int tank=0;
    
    for(int i=0;i<2*n;i++)
    {
        tank+=a[i];
        tank=max(tank,c);
        tank-=b[i];
        
        if(tank<0)
        {
            tank=0;
            s=i+1;
        }
    }
    
    if(s>=n)
    {
        return 0;
    }
    
    int ans=1;
    need[s+n]=0;
    
    for(int i=1;i<n;i++)
    {
        int id=s+n-i;
        need[id]=max(0,need[id]+b[id]-min(a[id],c));
        
        if(need[id]==0)
        {
            ans++;
        }
    }
    
    return ans;
}

int submatrices_zeros_and_ones(int mat[MAX][MAX],int n,int m,int l,int b)
{
    int dp_ones[n+1][m+1];
    int dp_zeros[n+1][m+1];
    int subans_ones[n+1];
    int subans_zeros[n+1];
    
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 || j==0)
            {
                dp_ones[i][j]=mat[i][j];
                dp_zeros[i][j]=mat[i][j];
            }
            else
            {
                if(mat[i][j]==1 && mat[i-1][j]==1  && 
                mat[i][j-1]==1 && mat[i-1][j-1]==1)
                {
                    cnt1++;
                    dp_ones[i][j]=1;
                }
                
                 if(mat[i][j]==0 && mat[i-1][j]==0  && 
                mat[i][j-1]==0 && mat[i-1][j-1]==0)
                {
                    cnt2++;
                    dp_zeros[i][j]=0;
                }
            }
        }
    }
    
    subans_ones[2]=cnt1;
    subans_zeros[2]=cnt2;
    for(int k=2;k<n;k++)
    {
        cnt1=0;
        // cnt2=0;
        for(int i=n-1;i>=k;i--)
        {
            for(int j=m-1;j>=k;j--)
            {
                 if(dp_ones[i][j]==1 && dp_ones[i-1][j]==1 && 
                    dp_ones[i][j-1]==1 && dp_ones[i-1][j-1]==1)
                 {
                     cnt1++;
                     dp_ones[i][j]=1;
                 }
                 
                 if(dp_zeros[i][j]==0 && dp_zeros[i-1][j]==0 && 
                  dp_zeros[i][j-1]==0 && dp_zeros[i-1][j-0]==0)
                 {
                     cnt2++;
                     dp_zeros[i][j]=0;
                 }
            }
        }
        
        subans_ones[k+1]=cnt1;
        subans_zeros[k+1]=cnt2;
    }
    
    if(b==0)
    {
        return subans_zeros[l];
    }
    return subans_ones[l];
}

int max_sum_less_thanlen_m(int arr[MAX][MAX],int n,int m,int len)
{
    //max continous subarray for all arrays
    int dp[n+1][m+1];
    int i,j;
    int current_arr[n+1];
    int maxsum[n+1];
    for(int i=1;i<=n;i++)
    {
       int len=arr[i-1][0];
       
       for(int j=1;j<=len;j++)
       {
           current_arr[j]=arr[i-1][j];
           current_arr[j]+=current_arr[j-1];
           maxsum[j]=INF;
       }
       
        for (int j = 1; j <= len && j <= 6; j++)  
            for (int k = 1; k <= len; k++)  
                if (j + k - 1 <= len)  
                    maxsum[j] = max(maxsum[j], 
                                   current_arr[j + k - 1] -  
                                   current_arr[k - 1]);
                                   
        for (int j = 0; j <= 6; j++) 
            dp[i][j] = dp[i - 1][j]; 
    }
    
    for (int j = 1; j <= 6; j++)  
    {
            for (int cur = 1; cur <= j && cur <= len; cur++)  
                dp[i][j] = max(dp[i][j], 
                               dp[i - 1][j - cur] +  
                                        maxsum[cur]); 
    } 
  
    int ans = 0; 
    for (int i = 0; i <= 6; i++)  
        ans = max(ans, dp[5][i]);     
  
    return ans; 
}

int cnt_array_sizen_sumk(int n,int k)
{
    //ans=n-1Ck-1 binomial coefficent(n-1,k-1)
    n=n-1;
    k=k-1;
    int c[k+1];
    memset(c,0,sizeof(c));
    c[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,k);j>0;j--)
        {
            c[j]=c[j]+c[j-1];
        }
    }
    
    return c[k];
}

int max_res_afterops(int arr[],int n,int maxi,int res)
{
    int dp[n+1][maxi+1];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=maxi;j++)
        {
            if(i==0)
            {
                if(res-arr[i]==j || res+arr[i]==j)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j]=0;
                }
            }
            else
            {
                if(res-arr[i]>0 && res+arr[i]<=maxi)
                {
                    dp[i][j]=dp[i-1][res-arr[j]] || dp[i-1][res+arr[j]]; 
                }
                else if(res-arr[i]>0)
                {
                    dp[i][j]=dp[i-1][res-arr[j]];
                }
                else if(res+arr[i]<=maxi)
                {
                    dp[i][j]=dp[i-1][res+arr[j]];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
    }
    
    for(int i=maxi;i>=0;i--)
    {
        if(dp[n-1][i]>0)
        {
            return i;
        }
    }
    
    return -1;
}

int space_optimized_lcs(string s1,string s2)
{
    int dp[2][s2.length()];
    int n=s1.length();
    int m=s2.length();
    int currow=0;
    int res=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[currow][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[currow][j]=1+dp[1-currow][j-1];
                res=max(res,1+dp[currow-1][j-1]);
            }
            else 
            {
                dp[currow-1][j-1]=0;
            }
        }
        currow=1-currow;
    }
    
    return res;
}

int max_prod_subarray(int arr[],int n)
{
    int max_so_far=arr[0];
    int max_ending_here=arr[0];
    int min_ending_here=arr[0];
    
    for(int i=1;i<n;i++)
    {
        int temp=max_ending_here;
        max_ending_here=max(arr[i],max(min_ending_here*arr[i],max_ending_here*arr[i]));
        
        min_ending_here=min(arr[i],min(temp*arr[i],min_ending_here*arr[i]));
        
        max_so_far=max(max_so_far,max(max_ending_here,min_ending_here));
    }
    
    return max_so_far;
}

int forming_string(string s)
{
    int n=s.length();
    int dp[n+1];
    
    for(int i=0;i<n;i++)
    {
        dp[i]=INT_MAX;
    }
    string s1="";
    string s2="";
    dp[0]=1;
    s1+=s[0];
    for(int i=1;i<n;i++)
    {
        s1+=s[i];
        s2 = s.substr(i + 1, i + 1); 
        
        dp[i]=min(dp[i],dp[i-1]+1);
         if (s1 == s2) 
            dp[i * 2 + 1] = min(dp[i] + 1, dp[i * 2 + 1]); 
    }
    
    return dp[n-1];
}
   
int dp_div[MAX][MAX]; 
bool check_divsible(int arr[],int& n,int& M,int start,int modulo)
{
    modulo = ((modulo % M) + M) % M; 
    
    if(dp_div[start][modulo]!=-1)
    {
        return dp_div[start][modulo];
    }
    
    if(start==n)
    {
        if(modulo==0)
        {
            return true;
        }
        return false;
    }
    
    bool res1=check_divsible(arr,n,M,start+1,modulo+arr[start]);
    bool res2=check_divsible(arr,n,M,start+1,modulo-arr[start]);
    
    return dp_div[start][modulo]=res1 || res2;
}

void printGolomb(int n) 
{ 
    int dp[n + 1]; 

    dp[1] = 1; 
    cout << dp[1] << " "; 

    for (int i = 2; i <= n; i++)  
    { 
        dp[i] = 1 + dp[i - dp[dp[i - 1]]]; 
        cout << dp[i] << " "; 
    } 
}

int main() {
    
    // int price[] = { 2, 4, 6, 2, 5 }; 
    // int n = sizeof(price) / sizeof(price[0]);
    // memset(dp_wines,-1,sizeof(dp_wines));
    // cout << max_profit_wines(price,0, n-1, 1) << endl; 
    // end_beg_printer(n);
    
    // int a[] = {3, 10, 3, 11, 4, 5, 6, 7, 8, 12};
    // int n = sizeof(a) / sizeof(a[0]);
    // cout << longest_inc_cons_subseq(a,n);
    
    // int n = 14; 
    // vector<int> v[n + 1]; 
    // v[1].push_back(2), v[2].push_back(1); 
    // v[1].push_back(3), v[3].push_back(1); 
    // v[1].push_back(4), v[4].push_back(1); 
    // v[2].push_back(5), v[5].push_back(2); 
    // v[2].push_back(6), v[6].push_back(2); 
    // v[3].push_back(7), v[7].push_back(3); 
    // v[4].push_back(8), v[8].push_back(4); 
    // v[4].push_back(9), v[9].push_back(4); 
    // v[4].push_back(10), v[10].push_back(4); 
    // v[5].push_back(11), v[11].push_back(5); 
    // v[5].push_back(12), v[12].push_back(5); 
    // v[7].push_back(13), v[13].push_back(7); 
    // v[7].push_back(14), v[14].push_back(7); 
    // int a[] = { 3, 2, 1, 10, 1, 3, 9, 1, 5, 3, 4, 5, 9, 8 }; 
    // memset(dp_tree1,0,sizeof(dp_tree1));
    // dfs_tree_maxfrom_root_leaves(v,a,1,0); 
    // cout << dp_tree1[1];
    
    // int a[] = { 1, 101, 2, 3, 100, 4, 5 }; 
    // int n = sizeof(a) / sizeof(a[0]); 
    // int index = 4, k = 6; 
    // cout << longest_till_i_andinclude_kind(a, n, index, k); 
	
    // 	string binaryNo = "100110110"; 
    //     cout << partitions(binaryNo);
    
    // int n = 2; 
    // int mat[MAX][MAX] = { { 1, 2 }, { 1, 3 } }; 
    // cout << decreasing_paths(mat,n,n);
    
    // int arr[] = { 5, 5, 1, 11 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // partitions_arr_eq_sum(arr, n); 
    
    // int mat[MAX][MAX] = { { 0, 0, 1, 1 },
    //               { 0, 0, 1, 0 },
    //               { 0, 1, 1, 1 },
    //               { 1, 1, 1, 1 },
    //               { 0, 1, 1, 1 }};
    // int n=5;
    // int m=4;int q=3;int b=1;
    // cout << submatrices_zeros_and_ones(mat,n,m,q,b);
    
    // int mat[MAX][MAX]={{3, 2, 3, 5},
    //         {2, 7, -1},
    //         {2, 8, 10},
    //         {4, 5, 2, 6, 1},
    //         {3, 2, 3, -2}};
    // int n=5;
    // int m=4;
    // cout << max_sum_less_thanlen_m(mat,n,m,10);
    
    // int n = 3; 
    // int c = 3; 
    // int N=100;
    // int a[2 * N] = { 3, 1, 2 }; 
    // int b[2 * N] = { 2, 2, 2 }; 
    // cout << cnt_circular_petrolpmps(a,b,n,c);
    
    // int n=3;
    // int k=7;
    // // actually in problem n and k but in calculation reverse;
    // cout << cnt_array_sizen_sumk(k,n);
    
    // int arr[] = {-2, -3, 0, -2, -40};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << max_prod_subarray(arr,n);
    
    //cout << forming_string("aaaaaaaaaaaa");
    
    int arr[] = { 1, 2, 3, 4, 6 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int M = 4; 
    memset(dp_div,-1,sizeof(dp_div));
    cout << check_divsible(arr,n,M,0,0);
	return 0;
	
}