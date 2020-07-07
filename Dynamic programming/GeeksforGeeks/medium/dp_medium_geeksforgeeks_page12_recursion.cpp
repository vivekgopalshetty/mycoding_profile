//https://www.geeksforgeeks.org/medium/dynamic-programming/12/
//dynamic-programming

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999
#define inf 99999999
#define mod 1000000007
int countSub(string str) 
{ 
    vector<int> last(255, -1); 
    int n = str.length();
    int dp[n + 1]; 
    dp[0] = 1;
    for (int i = 1; i <= n; i++) { 
       
        dp[i] = 2 * dp[i - 1]; 
  
        if (last[str[i - 1]] != -1) 
            dp[i] = dp[i] - dp[last[str[i - 1]]]; 
  
        last[str[i - 1]] = (i - 1); 
    } 
  
    return dp[n]; 
} 

int min_cost(int cost[],int n,int w)
{
    int dp[n+1][w+1];
    
     for(int i=1;i<=n;i++)
    {
        dp[i][0]=0;
    }
    
    for(int j=0;j<=w;j++)
    {
        dp[0][j]=INT_MAX;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(cost[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], 
                     dp[i][j-cost[i-1]] + cost[i-1]); 
            }
        }
    }
}

int cnt_t_in_s(string s,string t)
{
    int n=s.length();
    int m=t.length();
    
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;     
    }
    
     for(int j=0;j<=m;j++)
    {
        dp[0][j]=1;     
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                 dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    return dp[n][m];
}

//better way is to lcs and find diff
int min_cost_to_make_str_indentical(string s,string t,
                        int costx,int costy)
{
    int n=s.length();
    int m=t.length();
    int dp[n+1][m+1];
    
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=costx*i;
    }
    
    for(int j=1;j<=m;j++)
    {
        dp[0][j]=costy*j;
    }
    
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=min(dp[i-1][j]+costy,
                    dp[i][j-1]+costx);
            }
        }
    }
    
    return dp[n][m];
}

void combs_sorted_bin_of_len_k(int k)
{
    string str="";
    vector<string> dp[k+2][k+2];
    for(int len=0;len<=k;len++)
    {
        dp[len][0].push_back(str);
        str=str+"0";
    }
    
    for(int len=1;len<=k;len++)
    {
        for(int n=1;n<=len;n++)
        {
            // prefix 0 to all combinations of length len-1  
            // with n ones 
            for (string str : dp[len - 1][n]) 
                dp[len][n].push_back("0" + str); 
  
            // prefix 1 to all combinations of length len-1  
            // with n-1 ones 
            for (string str : dp[len - 1][n - 1]) 
                dp[len][n].push_back("1" + str); 
        }
    }
    
    for (int n = 1; n <= k; n++)  
    { 
        for (string str : dp[k][n]) 
            cout << str << " "; 
            
        cout << endl; 
    } 
    
}

struct task
{
    int start;
    int finish;
    int profit;
};

bool sortbyfinish(task t1,task t2)
{
    return t1.finish<t2.finish;
}

int findsum(vector<task> v)
{
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i].profit;
    }
    
    return sum;
}
int weighted_job_schedulling(int start[],int finish[],int profit[],int n)
{
    task a[n];
    for(int i=0;i<n;i++)
    {
        struct task t1={.start=start[i],.finish=finish[i],.profit=profit[i]};
        a[i]=t1;
        // arr[i]->first=start[i];
        //   arr[i]->finish=finish[i];
        //     arr[i]->profit=profit[i];
        
    }
    
    vector<task> arr(a,a+n);
    sort(arr.begin(),arr.end(),sortbyfinish);

    vector<vector<task>> dp(n);
    dp[0].push_back(arr[0]);
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i].start>=arr[j].finish && findsum(dp[i])<findsum(dp[j]))
            {
                dp[i]=dp[j];
            }
        }
        dp[i].push_back(arr[i]);
    }
    
    vector<task> maxi;
    int maxval=0;
    for(int i=0;i<n;i++)
    {
        if(findsum(dp[i])>maxval)
        {
            maxval=findsum(dp[i]);
            maxi=dp[i];
        }
    }
    
    int prof=0;
    for(int i=0;i<maxi.size();i++)
    {
        prof+=maxi[i].profit;
        cout << maxi[i].start << " " << maxi[i].finish << " "<< maxi[i].profit << endl; 
    }
    
    return prof;
}

int findsum2(vector<int> v)
{
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
    }
    return sum;
}

int printing_LIS(int arr[],int n)
{
    vector<int> dp[n];
    dp[0].push_back(arr[0]);
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && findsum2(dp[j])>findsum2(dp[i]))
            {
                dp[i]=dp[j];
            }
        }
        dp[i].push_back(arr[i]);
    }
    
    vector<int> maxi;
    int maxval=0;
    for(int i=0;i<n;i++)
    {
        if(findsum2(dp[i])>maxval)
        {
            maxval=findsum2(dp[i]);
            maxi=dp[i];
        }
    }
    
    int prof=0;
    for(int i=0;i<maxi.size();i++)
    {
        prof+=maxi[i];
        cout << maxi[i] << " "; 
    }
    
    return prof;
    
}



int printing_bitonic(int arr[],int n)
{
    vector<int> dp_for[n];
    dp_for[0].push_back(arr[0]);
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && findsum2(dp_for[j])>findsum2(dp_for[i]))
            {
                dp_for[i]=dp_for[j];
            }
        }
        dp_for[i].push_back(arr[i]);
    }
    
    vector<int> dp_back[n];
    dp_back[n-1].push_back(arr[n-1]);
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j] && findsum2(dp_back[j])>findsum2(dp_back[i]))
            {
                dp_back[i]=dp_back[j];
            }
        }
        dp_back[i].push_back(arr[i]);
    }
    
    for (int i = 0; i < n; i++) 
        reverse(dp_back[i].begin(), dp_back[i].end());
        
    vector<int> maxi;
    vector<int> mini;
    int maxval=0;
    for(int i=0;i<n;i++)
    {
        if(findsum2(dp_for[i])+findsum2(dp_back[i])-arr[i]>maxval)
        {
            maxval=findsum2(dp_for[i])+findsum2(dp_back[i])-arr[i];
            maxi=dp_for[i];
            mini=dp_back[i];
        }
    }
    
    int prof=0;
    for(int i=0;i<maxi.size()-1;i++)
    {
        prof+=maxi[i];
        cout << maxi[i] << " "; 
    }
    
    cout << "::" ;
    for(int i=0;i<mini.size();i++)
    {
        prof+=mini[i];
        cout << mini[i] << " "; 
    }
    
    cout << endl ;
    return prof;
    
}

int LCS(string X, string Y, int m, int n) 
{ 
    // Build L[m+1][n+1] in bottom up fashion 
    int L[m+1][n+1];
    for (int i = 0; i <= m; i++) 
    { 
        for (int j = 0; j <= n; j++) 
        { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
    return L[m][n]; 
} 


bool check_k_pallindrome(string s,int k)
{
    int n=s.length();
    string t=s;
    reverse(s.begin(),s.end());
    
    return (n-LCS(s,t,n,n) <= k);
}

int min_time_no_skip_two_cons(int arr[],int n)
{
    int dp[n];
    
    int incl=arr[0];
    int excl=0;
    dp[0]=min(incl,excl); 
    //without using this array we 
    //can solve by returning min(incl,excl)
    
    for(int i=1;i<n;i++)
    {
       int incl_new=arr[i]+min(incl,excl);
       int excl_new=incl;
       
       dp[i]=min(incl_new,excl_new);
       incl=incl_new;
       excl=excl_new;
    
    }
    
    return dp[n-1];
}

int main() {
	
    // string s="ggg";
    // string p="";
    // cout << cnt_distinct_subseq(s,p);
    
    // int W = 5;
    // int cost[] = {-1, -1, 4, 5, -1};
    // int n=sizeof(cost)/sizeof(cost[0]);
    // cout << min_cost(cost,n,W);
    
    // string a = "GeeksforGeeks";
    // string b = "Gks";
    // cout << cnt_t_in_s(a,b);

    // string X = "ababcdbcbccd";
    // string Y = "acdbcbababdb";
    // int costX = 10;
    // int costY = 20;
    // cout << min_cost_to_make_str_indentical(X,Y,costX,costY);
    
    // combs_sorted_bin_of_len_k(3);
    

    // int start[]={3,1,6,2};
    // int finish[]={10,2,19,100};
    // int profit[]={20,50,100,200};
    // int n = sizeof(start) / sizeof(start[0]); 
 
    // cout << weighted_job_schedulling(start,finish,profit,n); 
    
    // int arr[] = { 1, 11, 2, 10, 4, 5, 2, 1 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << printing_LIS(arr, n); 
    
    // int arr[] = { 1, 11, 2, 10, 4, 5, 2, 1 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << printing_bitonic(arr, n); 
    
    // int arr1[] = {10, 5, 2, 7, 10}; 
    // int n1 = sizeof(arr1)/sizeof(arr1[0]); 
    // cout << min_time_no_skip_two_cons(arr1, n1) << endl; 
  
}