//https://www.geeksforgeeks.org/medium/dynamic-programming/9/
//recustion

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999
#define inf 99999999
#define mod 1000000007 

bool subset_sum_problem(int arr[],int n,int sum)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    
    for(int j=0;j<=sum;j++)
    {
        dp[0][j]=false;
    }
    
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<arr[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            
            if(j>=arr[i-1])
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    
    return dp[n][sum];
}

// O(sum) space
bool subset_sum_problem_sum0n(int arr[],int n,int sum)
{
    bool dp[2][sum+1];
    
    dp[0][0]=true;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
            {
                dp[i%2][j]=true;
            }
            else if(i==0)
            {
                dp[i%2][j]=false;
            }
            if(j<arr[i-1])
            {
                dp[i%2][j]=dp[(i+1)%2-1][j];
            }
            
            if(j>=arr[i-1])
            {
                dp[i%2][j]=dp[(i+1)%2-1][j] || dp[(i+1)%2-1][j-arr[i-1]];
            }
        }
    }
    
    return dp[n][sum];
}


int ways_to_trans_s1_to_s2(string a,string b)
{
    int n=a.length();
    int m=b.length();
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++)
    {
        for(int j=i;j<n;j++)
        {
           if (i == 0) { 
                if (j == 0) 
                    dp[i][j] = (a[j] == b[i]) ? 1 : 0; 
                else if (a[j] == b[i]) 
                    dp[i][j] = dp[i][j - 1] + 1; 
                else
                    dp[i][j] = dp[i][j - 1]; 
            } 
            else
            {
                if (a[j] == b[i]) 
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]; 
                else
                    dp[i][j] = dp[i][j - 1]; 
            } 
        }
    }
    
    return dp[m-1][n-1];
}

string nth_digit_with_n_numbers(int n,int num)
{
    
    vector<int> v;
    while(num>0)
    {
        v.push_back(num%n);
        num/=n;
    }
    
    reverse(v.begin(),v.end());
    
    string ans="";
    for(int i=0;i<v.size();i++)
    {
        ans+=to_string(v[i]);
    }
    
    return ans;
}

int dp_sum[MAX][MAX];
int min_sum_descre_seq_sizek(int arr[],int i,int k)
{
   if (dp_sum[i][k] != -1) 
        return dp_sum[i][k]; 

    // Corner cases 
    if (i < 0) 
        return inf; 
    if (k == 1) { 
        int ans = inf; 
        for (int j = 0; j <= i; j++) 
            ans = min(ans, arr[j]); 
        return ans; 
    } 
  
    // Recursive computation. 
    int ans = inf; 
    for (int j = 0; j < i; j++) 
        if (arr[i] >= arr[j]) 
            ans = min(ans, min(min_sum_descre_seq_sizek(arr, j, k), 
                               min_sum_descre_seq_sizek(arr, j, k - 1) + arr[i])); 
        else { 
            ans = min(ans, min_sum_descre_seq_sizek(arr, j, k)); 
        } 
  
    dp_sum[i][k] = ans; 
    return dp_sum[i][k];    
}

int max_len_one_subseq_other_substr(string s1,string s2)
{
    int n=s1.length();
    int m=s2.length();
    
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=0;
        }
    }
    
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
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    
    return dp[n][m];
}

int dp_mincuts[MAX][MAX];
int min_cuts_paper(int n,int m)
{
    if(n==m)
    {
        return 1;
    }
    
    if(dp_mincuts[n][m]!=-1)
    {
        return dp_mincuts[n][m];
    }
    
    int vert_min=INT_MAX;
    int horz_min=INT_MAX;
    
    for(int i=1;i<=m/2;i++)
    {
        horz_min=min(min_cuts_paper(i,n)+min_cuts_paper(m-i,n),horz_min);
    }
    
    for(int i=1;i<=n/2;i++)
    {
        vert_min=min(min_cuts_paper(m,i)+min_cuts_paper(m,n-i),vert_min);
    }
    
    return dp_mincuts[n][m]=min(horz_min,vert_min);
}

int n_digits_non_decreasing(int n)
{
  int a[n + 1][10]; 
  
    for (int i = 0; i <= 9; i++) 
        a[0][i] = 1; 
  
    for (int i = 1; i <= n; i++) 
        a[i][9] = 1; 
  
    for (int i = 1; i <= n; i++) 
        for (int j = 8; j >= 0; j--) 
            a[i][j] = a[i - 1][j] + a[i][j + 1]; 
  
    return a[n][0]; 
}

int longest_pallindromic_subseq(string s)
{
    int n=s.length();
    int dp[n][n];
   // memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    
    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<n-len+1;i++)
        {
            int j=i+len-1;
            if (s[i] == s[j] && len == 2) 
            {
               dp[i][j] = 2; 
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
    
    return dp[0][n-1];
}

void printSubStr(string str,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        cout << str[i];
    }
}

int longest_pallindromic_substr(string s)
{
    int n=s.length();
    bool table[n][n];
    memset(table,0,sizeof(table));
    for (int i = 0; i < n; ++i) 
        table[i][i] = true; 
  
    int start = 0;
    int maxlen=1;
    for (int i = 0; i < n-1; ++i) 
    { 
        if (s[i] == s[i+1]) 
        { 
            table[i][i+1] = true; 
            start = i; 
            maxlen = 2; 
        } 
    } 
    
    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<n-len+1;i++)
        {
            int j=i+len-1;
            if(s[i]==s[j] && table[i+1][j-1])
            {
                table[i][j]=true;
                if(len>maxlen)
                {
                    start=i;
                    maxlen=len;
                }
                
            }
        }
    }
    
   printSubStr( s, start, start + maxlen - 1 ); 
    return 0;
}

int cnt_pallind_substr(string s)
{
    int n=s.length();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    bool is_pall[n][n];
    memset(is_pall,false,sizeof(is_pall));
    
    for(int i=0;i<n;i++)
    {
        is_pall[i][i]=true;
    }
    
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=1;
            is_pall[i][i+1]=true;
        }
    }
    
    for(int len=2;len<n;len++)
    {
        for(int i=0;i<n-len;i++)
        {
            int j=len+i;
            if(is_pall[i+1][j-1] && s[i]==s[j])
            {
                is_pall[i][j]=true;
            }
            
            if(is_pall[i][j])
            {
                dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+1;
            }
            else
            {
                dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
            }
        }
    }
    
    return dp[0][n-1];
}

int painting_fence_algo(int n,int k)
{
    long long int dp[n + 1]; 
    memset(dp, 0, sizeof(dp)); 

    dp[1] = k; 
    dp[2] = k * k; 
  
    for (int i = 3; i <= n; i++) { 
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod; 
    } 
  
    return dp[n]; 
    
}

long long int countBT(int h) { 
       
    long long int dp[h + 1]; 
    //base cases 
    dp[0] = dp[1] = 1; 
    for(int i = 2; i <= h; i++) { 
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod; 
    } 
    return dp[h]; 
} 

int min_write_ins_copy_remove(int N,int insert,int copy,int remove)
{
    if (N == 0) 
       return 0; 
    if (N == 1) 
       return insert; 
  
    int dp[N + 1]; 
    memset(dp, 0, sizeof(dp)); 
  
    for (int i = 1; i <= N; i++) 
    { 
        if (i % 2 == 0) 
            dp[i] = min(dp[i-1] + insert, 
                        dp[i/2] + copy); 
        else
            dp[i] = min(dp[i-1] + insert, 
                        dp[(i+1)/2] + copy + remove); 
    } 
    return dp[N]; 

}

int max_sum_non_adj_2_rows(int arr[2][MAX],int n)
{
   int incl=max(arr[0][0],arr[1][0]);
   
   int excl=0;
   int excl_new;
   
   for(int i=1;i<n;i++)
   {
       excl_new=max(incl,excl);
       
       incl = excl + max(arr[0][i],arr[1][i]);
       
       excl=excl_new;
   }
   
   return max(excl,incl);
}

int max_sum_subarray_with_atleastsize_k(int arr[],int n,int k)
{
   int dp[n];
   dp[0]=arr[0];
   int max_ending_here=arr[0];
   
   //including arr[i] max till here
   for(int i=1;i<n;i++)
   {
      max_ending_here=max(max_ending_here+arr[i],arr[i]);
      dp[i]=max_ending_here;
      
   }
   
    int sum = 0; 
    for (int i = 0; i < k; i++) 
        sum += arr[i]; 
        
    int result = sum; 
    for (int i = k; i < n; i++) 
    { 
        sum = sum + arr[i] - arr[i-k]; 
        result = max(result, sum); 
        result = max(result, sum + dp[i-k]); 
    } 
    
    return result;
}


int coin_change_prob(int arr[],int m,int n)
{
    int ways[n+1];
    for(int i=0;i<=n;i++)
    {
        ways[i]=0;
    }
    
    ways[0]=1;
    
    for(int i=0;i<m;i++)
    {
        for(int j=arr[i];j<=n;j++)
        {
            ways[j]+=ways[j-arr[i]];
        }
    }
    
    return ways[n];
}

//check above func no repetition
int coin_change_prob_repetion_allowed(int arr[],int m,int n)
{
    int ways[n+1];
    for(int i=0;i<=n;i++)
    {
        ways[i]=0;
    }
    
    ways[0]=1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>=arr[j])
            {
                ways[i]+=ways[i-arr[j]];
            }
            
        }
    }
    
    return ways[n];
}


int main() {
    // 	int arr[] = { 6, 2, 5 }; 
    //  int sum = 7; 
    //  int n = sizeof(arr) / sizeof(arr[0]); 
    //  cout << subset_sum_problem(arr,n,sum);

    // string s1 = "aabba"; 
    // string s2 = "ab";
    // cout << ways_to_trans_s1_to_s2(s1,s2);
    
    // int num=10;
    // int arr[]={0,1,2,3,4,5}; // with these numbers
    // int n=6;
    // cout << nth_digit_with_n_numbers(n,num);
    
    // int arr[]={58,12,11,12,82,30,20,77,16,86}; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // int k = 3;
    // cout << min_sum_descre_seq_sizek(arr,n,k);
	
    // 	int n=30;
    // 	int m=35;
    // 	memset(dp_mincuts,-1,sizeof(dp_mincuts));
    // 	cout << min_cuts_paper(n,m);
    
    //cout  << n_digits_non_decreasing(4);
    
    // string s="forgeeksskeegfor";
    // cout << longest_pallindromic_subseq(s);
    
    // string s="forgeeksskeegfor";
    // longest_pallindromic_substr(s);
    
    // string s="abaab";
    // cout  << cnt_pallind_substr(s);
    
    // int grid[2][MAX] = {{ 1, 2, 3, 4, 5 ,10, 2 , 3 ,5 , 6, 7 ,10,11}, 
    //                     { 6, 7, 8, 9, 10 ,2 , 5 , 7 ,8 , 3, 3, 5 ,6}}; 
  
    // int n = 13; 
    // cout << max_sum_non_adj_2_rows(grid, n ); 
    
    // int arr[] = {1, 5, 6}; 
    // int m = sizeof(arr) / sizeof(arr[0]); 
    // int n = 7; 
    // cout << coin_change_prob(arr,m,n);
    
    int arr[] = {1, 5, 6}; 
    int m = sizeof(arr) / sizeof(arr[0]); 
    int n = 7; 
    cout << coin_change_prob_repetion_allowed(arr,m,n);
	return 0;
}