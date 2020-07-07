//https://www.geeksforgeeks.org/medium/dynamic-programming/11/
//dynamic-programming

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999
#define inf 99999999
#define mod 1000000007

vector<int> lis(vector<int> arr,int n)
{
    int dp[n];
    vector<vector<int>> v(n);
    
    v[0].push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        v[i]={};
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && v[i].size()<v[j].size())
            {
                v[i]=v[j];
            }
        }
        
        v[i].push_back(arr[i]);
    }
    
    int maxSize = 1; 
    vector<int> lis; 
    for (vector<int> x : v) 
    {     
        if (x.size() > maxSize) 
        { 
            lis = x; 
            maxSize = x.size(); 
        } 
    } 
  
    return lis; 
}

void repeated_lis(int input[],int n)
{
  vector<int> arr(input, input + n); 
  
    while (arr.size()) 
    { 
        vector<int> lis1 = lis(arr, arr.size()); 
  
        if (lis1.size() < 2) 
            break; 

        for (int i=0; i<arr.size() && lis1.size()>0; i++) 
        { 
            if (arr[i] == lis1[0]) 
            { 
                arr.erase(arr.begin()+i) ; 
                i--; 
                lis1.erase(lis1.begin()) ; 
            } 
        } 
    } 
  
    int i; 
    for (i=0; i < arr.size(); i++) 
        cout  << arr[i] << " "; 
  
    if (i == 0) 
        cout << "-1";
}

//https://www.geeksforgeeks.org/probability-getting-least-k-heads-n-tosses-coins/
//great concept of represting big number with log to base 2
double prob_of_atleast_kheads(int n,int k)
{
    //ans is n==6 and k==4 then 6c4+6c5+6c6 reprenting these 
    //large number will be impossible
    //log2 (nCi) = log2 ( n! ) - log2(i!) - log2( (n-i)! ) 
    //so Pi (log2 (nCi)) = dp[n] - dp[i] - dp[n-i] - n
    //Pi (nCi) = 2 dp[n] - dp[i] - dp[n-i] - n
    
    double dp[n+100];
    for(int i=2;i<=n;i++)
    {
        dp[i]=log2(i)+dp[i-1];
    }
    
    double ans=0;
    for(int i=k;i<n;i++)
    {
        double res=dp[n]-dp[i]-dp[n-i]-n;
        ans+=pow(2.0,res);
    }
    
    return ans;
}

bool check_if_all_people_can_vote(int arr[],int n,int x)
{
    int dp[n+1][x+1];
    memset(dp,0,sizeof(dp));
    
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(j>=arr[i])
            {
                dp[i][j]=max(arr[i]+dp[i-1][j-arr[i]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    return (sum-dp[n][x]<=x);
}

//logic is correct somewhere small mistake
int min_sum_3d_array(int arr[MAX][MAX][MAX],int n,int m,int k)
{
    int dp[n][m][k];
    
    dp[0][0][0]=arr[0][0][0];    
    for(int i=1;i<n;i++)
    {
        dp[i][0][0]=dp[i-1][0][0]+arr[i][0][0];
    }
    
    for(int j=1;j<m;j++)
    {
        dp[0][j][0]=dp[0][j-1][0]+arr[0][j][0];
    }
    
    for(int l=1;l<k;l++)
    {
        dp[0][0][l]=dp[0][0][l-1]+arr[0][0][l];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j][0]=min(INT_MAX,min(arr[i-1][j][0],
                             arr[i][j-1][0]))+arr[i][j][0];
        }
    }
    
     for(int j=1;j<m;j++)
    {
        for(int l=1;l<k;l++)
        {
            dp[0][j][l]=min(INT_MAX,min(arr[0][j-1][l],
                             arr[0][j][l-1]))+arr[0][j][l];
        }
    }
    
     for(int i=1;i<n;i++)
    {
        for(int l=1;l<k;l++)
        {
            dp[i][0][l]=min(INT_MAX,min(arr[i-1][0][l],
                             arr[i][0][l-1]))+arr[i][0][l];
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            for(int l=1;l<k;l++)
            {
                dp[i][j][l]=min(dp[i-1][j][l],min(dp[i][j-1][l],dp[i][j][l-1]))
                              +arr[i][j][l];
            }
        }
    }
    
    return dp[n-1][m-1][k-1];
}

int max_dot_prod_inserting_0s_in2ndarr(int arr1[],int arr2[],int n,int m)
{
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j==0 || i==0)
            {
                dp[i][j]=0;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j-1]+(arr1[i-1]*arr2[j-1]),dp[i-1][j]);
            }
        }
    }
    
    return dp[n][m];
}

int unbounded_knapsack(int val[],int w[],int weight,int n)
{
    int dp[weight+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=weight;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(w[j]<=i)
            {
                dp[i]=max(dp[i],dp[i-w[i]]+val[i]);
            }
        }
    }
    
    return dp[weight];
}

int write_n_as_sumof_pos_ints(int n)
{
    int ways[n+1];
    for(int i=0;i<=n;i++)
    {
        ways[i]=0;
    }
    
    ways[0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            ways[j]+=ways[j-i];
        }
    }
    
    return ways[n];
}

void find_all_distinct_subset_sum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    bool dp[n+1][sum+1];    
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }

    for(int i=1;i<=n;i++)
    {
        dp[i][arr[i-1]]=true;
        for(int j=1;j<=sum;j++)
        {
            if(dp[i-1][j]==true)
            {
                dp[i][j]=true;
                dp[i][j+arr[i-1]]=true;
            }
        }
    }
    
    for (int j=0; j<=sum; j++) 
        if (dp[n][j]==true) 
            cout << j << " "; 
}

int maxSumSubarrayRemovingOneEle(int arr[], int n) 
{ 
    int fw[n], bw[n]; 
  
    int cur_max = arr[0], max_so_far = arr[0]; 
    fw[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        cur_max = max(arr[i], cur_max + arr[i]); 
        max_so_far = max(max_so_far, cur_max); 
        fw[i] = cur_max; 
    } 
  
    cur_max = max_so_far = bw[n-1] = arr[n-1]; 
    for (int i = n-2; i >= 0; i--) 
    { 
        cur_max = max(arr[i], cur_max + arr[i]); 
        max_so_far = max(max_so_far, cur_max); 
        bw[i] = cur_max; 
    } 
  
    int fans = max_so_far; 
    for (int i = 1; i < n - 1; i++) 
        fans = max(fans, fw[i - 1] + bw[i + 1]); 
  
    return fans; 
} 

//wrong code
int sum_of_avg_sum_subsets(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    
    double dp[n+1][sum+1];
    bool tb[n+1][sum+1];
    memset(tb,0,sizeof(tb));
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=n;i++)
    {
        tb[i][0]=true;    
    }
    
    for(int i=1;i<=n;i++)
    {
        tb[i][arr[i-1]]=true;
        dp[i][arr[i-1]]=arr[i-1];
        for(int j=1;j<=sum;j++)
        {
            if(tb[i-1][j])
            {
                dp[i][j]=arr[i-1];
                tb[i][j+arr[i-1]]=true;
            }
        }
    }
    
    double res=0;
    for(int i=1;i<=n;i++)
    {
        double temp=0;
        for(int j=0;j<=sum;j++)
        {
            cout << dp[i][j] << " ";
        }
        
        cout << endl;
        res+=temp/i;
    }
    
    return res;
}

int max_sum_increasing_decreasing(int arr[],int n)
{
    int dp[n+1][2];
    memset(dp,0,sizeof(dp));
    dp[0][0]=arr[0]; //incs
    dp[0][1]=arr[0]; //decs
    
    int flag=0;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[i])
            {
                dp[i][1]=max(dp[i][1],dp[j][0]+arr[i]);
                flag=1;
            }
            else if(arr[i]>arr[j] && flag==1)
            {
                dp[i][0]=max(dp[i][0],dp[j][1]+arr[i]);
            }
        }
    }
    
    int result = INT_MIN; 
    for (int i = 0 ; i < n; i++) 
    { 
        if (result < dp[i][0]) 
            result = dp[i][0]; 
        if (result < dp[i][1]) 
            result = dp[i][1]; 
    } 
    
    return result;
}

int countSub( int arr[], int n )
{
    int cSub[n];

    /* Initialize cSub values for all indexes */
    for (int i = 0; i < n; i++ )
        cSub[i] = 1;


    for (int i = 1; i < n; i++ )
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j])
                cSub[i] += cSub[j];

    int result = 0;
    for (int i = 0; i < n; i++ )
          result += cSub[i];

    return result;
}

int cnt_distinct_subeq(string s,string t)
{
    int n=s.length();
    int m=t.length();
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=0;    
    }
    
     for(int j=0;j<=n;j++)
    {
        dp[0][j]=1;    
    }
    
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==s[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            }
            else
            {
                dp[i][j]=dp[i][j-1];   
            }
        }
    }
    
    return dp[m][n];
}

int ugly_number(int n)
{
    unsigned ugly[n];  
    unsigned i2 = 0, i3 = 0, i5 = 0; 
    unsigned next_multiple_of_2 = 2; 
    unsigned next_multiple_of_3 = 3; 
    unsigned next_multiple_of_5 = 5; 
    unsigned next_ugly_no = 1; 
  
    ugly[0] = 1; 
    for (int i=1; i<n; i++) 
    { 
       next_ugly_no = min(next_multiple_of_2, 
                           min(next_multiple_of_3, 
                               next_multiple_of_5)); 
       ugly[i] = next_ugly_no; 
       if (next_ugly_no == next_multiple_of_2) 
       { 
           i2 = i2+1; 
           next_multiple_of_2 = ugly[i2]*2; 
       } 
       if (next_ugly_no == next_multiple_of_3) 
       { 
           i3 = i3+1; 
           next_multiple_of_3 = ugly[i3]*3; 
       } 
       if (next_ugly_no == next_multiple_of_5) 
       { 
           i5 = i5+1; 
           next_multiple_of_5 = ugly[i5]*5; 
       } 
    } 
    return next_ugly_no; 
}
int superugly_number(int arr[],int k,int n)
{
    vector<int> nextMultiple(arr, arr+k); 
  
    int multiple_Of[k]; 
    memset(multiple_Of, 0, sizeof(multiple_Of)); 
  
    set<int> ugly; 
    ugly.insert(1); 
  
    while (ugly.size() != n) 
    { 
        int next_ugly_no = *min_element(nextMultiple.begin(), 
                                    nextMultiple.end()); 
  
        ugly.insert(next_ugly_no); 
 
        for (int j=0; j<k; j++) 
        { 
            if (next_ugly_no == nextMultiple[j]) 
            { 
                multiple_Of[j]++; 
                set<int>::iterator it = ugly.begin(); 
                for (int i=1; i<=multiple_Of[j]; i++) 
                    it++; 
  
                nextMultiple[j] = arr[j] * (*it); 
                break; 
            } 
        } 
    } 
  
    // n'th super ugly number 
    set<int>::iterator it = ugly.end(); 
    it--; 
    return *it; 
}

int cnt_all_pallidromic_substr(string s)
{
    int n=s.length();
    int dp[n+1][n+1];
    
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    
    int ans=0;
    for(int cl=2;cl<n;cl++)
    {
        for(int i=0;i<n-cl+1;i++)
        {
            int j=i+cl-1;
            if(s[i]==s[j] && cl==2)
            {
                ans++;
                dp[i][j]=dp[i+1][j-1]+1;
            }
            else if(s[i]==s[j] && dp[i+1][j-1]>0)
            {
                ans++;
                dp[i][j]=dp[i+1][j-1]+1; 
            }
        }
    }
    
    return ans;
}
int min_one_of_every3cons_picked(int arr[],int n)
{
    int sum[n];
    
    sum[0]=arr[0];
    sum[1]=arr[1];
    sum[2]=arr[2];
    
    for(int i=3;i<n;i++)
    {
        sum[i]=arr[i]+min(sum[i-1],min(sum[i-2],sum[i-3]));
    }
    
    return min(sum[n-3],min(sum[n-2],sum[n-3]));
}



int main() {
	
    // 	int arr[] = {1, 2, 5, 3, 6, 4, 1};
    // 	int n=sizeof(arr)/sizeof(arr[0]);
    // 	repeated_lis(arr,n);
    	
	// cout << prob_of_atleast_kheads(1000,500); 
	
    // 	int n = 3, x = 4; 
    //  int a[] = {2, 4, 2}; 
    //  cout << check_if_all_people_can_vote(a, n, x);

    // int  arr[MAX][MAX][MAX]= { { {1, 2, 4}, {3, 4, 5}, {5, 2, 1}}, 
    // { {4, 8, 3}, {5, 2, 1}, {3, 4, 2}}, 
    // { {2, 4, 1}, {3, 1, 4}, {6, 3, 8}} };
                    
    // cout << min_sum_3d_array(arr,3,3,3);
    
    // int A[] = {1, 2, 3, 6, 1, 4};
    // int B[] = {4, 5, 1};     
    // cout << max_dot_prod_inserting_0s_in2ndarr(A,B,6,3);
    
    // int n=7;
    // cout << write_n_as_sumof_pos_ints(n);
    
    // int arr[]={2, 3, 4, 5, 6};
    // int n=5;
    // find_all_distinct_subset_sum(arr,n);
    
    // string T = "ge"; 
    // string S = "geeksforgeeks"; 
    // cout << cnt_distinct_subeq(S, T) << endl; 
    
    // int arr[] = { 2, 3, 5, 7 }; 
    // int N = sizeof(arr) / sizeof(int); 
    // cout << sum_of_avg_sum_subsets(arr,N);
    
    // int arr[]= {8, 2, 3, 5, 7, 9, 10}; 
    // int n = sizeof(arr)/sizeof(arr[0]); 
    // cout <<  max_sum_increasing_decreasing(arr , n ) << endl; 
    
    // int a[] = {2,5}; 
    // int size = sizeof(a) / sizeof(a[0]); 
    // cout << superugly_number(a, size, 5)<<endl; 
    
    string str = "abaab"; 
    cout << cnt_all_pallidromic_substr(str) << endl; 
    return 0; 
	
}