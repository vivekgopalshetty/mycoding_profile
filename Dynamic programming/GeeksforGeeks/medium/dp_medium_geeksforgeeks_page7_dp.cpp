//https://www.geeksforgeeks.org/medium/dynamic-programming/7/
//dynamic-programming

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999


int counting_derangements(int n)
{
    int dp[n+1];
    
    dp[0]=1;
    dp[1]=0;
    dp[2]=1;
    
    for(int i=2;i<=n;i++)
    {
        dp[i]=(i-1)*(dp[i-2]+dp[i-1]);
    }
    
    return dp[n];
}

int binomialcoff(int n,int k)
{
    int c[MAX];
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,k);j>=0;j--)
        {
            c[j]+=c[j-1];
        }
    }
}

int dp_c[MAX][MAX];
void binomialcoff_2indexed(int n,int k)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=min(i,k);j++)
        {
            if(i==0 || j==i)
            {
                dp_c[i][j]=1;
            }
            else
            {
                dp_c[i][j]=dp_c[i-1][j-1]+dp_c[i-1][j];
            }
        }
    }
}

//partial derangements
int recontres_partial_derangements(int n,int k)
{
    int dp[n+1][k+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j==0 && i==0)
            {
                dp[i][j]=1;
            }
            else if(j==0 && i==1)
            {
                dp[i][j]=0;
            }
            else if(j==0)
            {
                dp[i][j]=(i-1)*(dp[i-1][0]+dp[i-2][0]);
            }
            else
            {
                dp[i][j]=dp_c[i][j]*dp[i-j][0];
            }
        }
    }
    
    return dp[n][k];
    
}

int maximize_sum(int arr[],int n)
{
    int maxi=*max_element(arr,arr+n);
    
    int ans[maxi+1]={0};
    for(int i=0;i<n;i++)
    {
        ans[arr[i]]++;
    }
    
    for(int i=2;i<=maxi;i++)
    {
        ans[i]=max(ans[i-1],ans[i-2]+ans[i]*i);
    }
    
    return ans[maxi];
}

bool transform_s1_to_s2(string s1,string s2)
{
    int n=s1.length();
    int m=s2.length();
    
    bool dp[n+1][m+1];
    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= m; j++) { 
            dp[i][j] = false; 
        } 
    } 
    
    dp[0][0]=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(dp[i][j])
            {
                if(toupper(s1[i])==s2[j] && j < s2.length())
                {
                    dp[i+1][j+1]=true;
                }
                
                if(!isupper(s1[i]))
                {
                    dp[i+1][j]=true;
                }
            }
        }
    }
    
    return dp[n][m];
}

int maxSubArraySumRepeated(int a[], int n, int k) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < n*k; i++) 
    { 
        max_ending_here = max_ending_here + a[i%n]; 
  
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    
    return max_so_far; 
} 

int static const dp_s=9;
int cnt_monotonic_digits(int k)
{
    int dp[k+1][dp_s+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<k;i++)
    {
        dp[i][0]=1;    
    }
    
    for(int i=0;i<dp_s;i++)
    {
        dp[0][i]=i+1;
    }
    
    for(int i=1;i<k;i++)
    {
        for(int j=1;j<dp_s;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    
    return dp[k-1][dp_s-1];
}

int longest_pallindromic_subseq(string s)
{
    int n=s.length();
    int dp[n+1][n+1];
    //memset(dp,1,sizeof(dp));
    int j;
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    
    for(int cl=2;cl<=n;cl++)
    {
        for(int i=0;i<n-cl+1;i++)
        {
            j=i+cl-1;
            if(s[i]==s[j] && cl==2)
            {
                dp[i][j]=2;
            }
            else if(s[i]==s[j])
            {
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
            
        }
    }
    
    int l=0;
    int r=n-1;
    int si=dp[0][n-1];
    vector<char> res(si);
    int h=0;
    while(l<=r){
        if(l+1==r){
            res[h]=s[l];
            res[si-h-1]=s[l];
            h++;
            break;
        }
        if(l==r){
            res[h]=s[l];
            h++;
            break;
        }
        if(dp[l][r]==dp[l+1][r]){
            l++;
        }
        else if(dp[l][r]==dp[l][r-1]){
            r--;
        }
        else if(dp[l][r]==dp[l+1][r-1]+2){
            res[h]=s[l];
            res[si-h-1]=s[l];
            h++;
            l++;
            r--;
        }
    }
    for(int i=0;i<si;i++){
        cout<<res[i];
    }
    
    return dp[0][n-1];
}

string printing_longest_pallindrome_using_lcs(string &X, string &Y) 
{ 
    int m = X.length(); 
    int n = Y.length(); 
  
    int L[m+1][n+1]; 
  
    /* Following steps build L[m+1][n+1] in bottom 
       up fashion. Note that L[i][j] contains 
       length of LCS of X[0..i-1] and Y[0..j-1] */
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
  
    // Following code is used to print LCS 
    int index = L[m][n]; 
  
    // Create a string length index+1 and 
    // fill it with \0 
    string lcs(index+1, '\0'); 
  
    // Start from the right-most-bottom-most 
    // corner and one by one store characters 
    // in lcs[] 
    int i = m, j = n; 
    while (i > 0 && j > 0) 
    { 
        // If current character in X[] and Y 
        // are same, then current character 
        // is part of LCS 
        if (X[i-1] == Y[j-1]) 
        { 
            // Put current character in result 
            lcs[index-1] = X[i-1]; 
            i--; 
            j--; 
  
            // reduce values of i, j and index 
            index--; 
        } 
  
        // If not same, then find the larger of 
        // two and go in the direction of larger 
        // value 
        else if (L[i-1][j] > L[i][j-1]) 
            i--; 
        else
            j--; 
    } 
  
    return lcs; 
} 

//with O(N) space
int longest_pallindromic_subseq_lessapce(string s)
{
    int n = s.length(); 
	int a[n]; 
	for (int i = n - 1; i >= 0; i--) { 

		int back_up = 0; 
		for (int j = i; j < n; j++) {
			if (j == i) 
				a[j] = 1; 
			else if (s[i] == s[j]) 
			{ 
				int temp = a[j]; 
				a[j] = back_up + 2; 
				back_up = temp; 
			}
			else
			{ 
				back_up = a[j]; 
				a[j] = max(a[j - 1], a[j]); 
			} 
		} 
	} 
	
	return a[n - 1]; 
}

//usually reverse is better
int max_sum_top_to_bottom(int arr[MAX][MAX],int n,int m)
{
    int dp[n+1][m+1];
    
    for(int i=0;i<m;i++)
    {
        dp[0][i]=arr[0][i];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j==0)
            {
                dp[i][j]=dp[i-1][j+1]+arr[i][j];
            }
            else if(j==n-1)
            {
                dp[i][j]=dp[i-1][j-1]+arr[i][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j+1],dp[i-1][j-1])+arr[i][j];
            }
        }
    }
    
    return *max_element(dp[n-1],dp[n-1]+m);
}

void max_sum_subarray_k_nonoverlapp(int arr[],int n,int k)
{
    for(int j=0;j<k;j++)
    {
        int max_ending_here=0;
        int max_so_far=INT_MIN;
        int start=0,s=0,end=0;
        for(int i=0;i<n;i++)
        {
            max_ending_here+=arr[i];
            if(max_so_far<max_ending_here)
            {
                max_so_far=max_ending_here;
                start=s;
                end=i;
            }
            
            if(max_ending_here<0)
            {
                max_ending_here=0;
                s=i+1;
            }
        }
        
        cout << max_so_far << ":" <<start << "-" << end <<  endl;
        
        for(int i=start;i<=end;i++)
        {
            arr[i]=-1*INF;
        }
    }
}

int cnt_ways_to_sum_n(int n)
{
    int arr[n+1];
    
    for(int i=0;i<=n;i++)
    {
        arr[i]=i;
    }
    
    int ways[n+1]={0};
    ways[0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=arr[i];j<=n;j++)
        {
            ways[j]+=ways[j-arr[i]];
        }
    }
    
    return ways[n];
}

int cnt_ways_to_sum_n_elemgr_eq_m(int n,int m)
{
   int arr[n+1]={0};
   int cnt=0;
   for(int i=m;i<=n;i++)
   {
       cnt++;
       arr[i-m]=i;
   }
   
   int ways[n+1]={0};
   ways[0]=1;
   for(int i=1;i<m;i++)
   {
       ways[i]=0;
   }
   
   for(int i=0;i<cnt;i++)
   {
       for(int j=arr[i];j<=n;j++)
       {
           ways[j]+=ways[j-arr[i]];
       }
   }
   
   return ways[n];
}

// Entringer Number E(n, k) are the 
//number of permutations of {1, 2, …, n + 1}, starting with k + 1,
int entringer_no(int n,int k)
{
     int dp[n + 1][k + 1]; 
    memset(dp, 0, sizeof(dp)); 
 
    dp[0][0] = 1; 
    for (int i = 1; i <= n; i++)  
        dp[i][0] = 0;     
  
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= i; j++)  
            dp[i][j] = dp[i][j - 1] +  
                       dp[i - 1][i - j]; 
    }
    return dp[n][k];
}

int numberofways(string A, string B, int N, int M) 
{ 
    vector<int> pos[MAX]; 
  
    // Insert all positions of all characters 
    // in string B. 
    for (int i = 0; i < M; i++) 
        pos[B[i]].push_back(i + 1); 
  
    // Longest Common Subsequence 
    int dpl[N + 2][M + 2]; 
    memset(dpl, 0, sizeof(dpl)); 
    for (int i = 1; i <= N; i++) { 
        for (int j = 1; j <= M; j++) { 
            if (A[i - 1] == B[j - 1]) 
                dpl[i][j] = dpl[i - 1][j - 1] + 1; 
            else
                dpl[i][j] = max(dpl[i - 1][j], 
                                dpl[i][j - 1]); 
        } 
    } 
    int LCS = dpl[N][M]; 
  
    // Longest Common Subsequence from reverse 
    int dpr[N + 2][M + 2]; 
    memset(dpr, 0, sizeof(dpr)); 
    for (int i = N; i >= 1; i--) { 
        for (int j = M; j >= 1; j--) { 
            if (A[i - 1] == B[j - 1]) 
                dpr[i][j] = dpr[i + 1][j + 1] + 1; 
            else
                dpr[i][j] = max(dpr[i + 1][j], 
                                dpr[i][j + 1]); 
        } 
    } 
  
    // inserting character between position 
    // i and i+1 
    int ans = 0; 
    for (int i = 0; i <= N; i++) { 
        for (int j = 0; j < MAX; j++) { 
            for (auto x : pos[j]) { 
                if (dpl[i][x - 1] + dpr[i + 1][x + 1] == LCS) { 
                    ans++; 
                    break; 
                } 
            } 
        } 
    } 
  
    return ans; 
}


int increasing_subseq_sizek(int arr[],int n,int k)
{
    int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<n;i++)
    {
        dp[0][i]=1;
    }
    
    for(int l=1;l<k;l++)
    {
        for(int i=l;i<n;i++)
        {
            dp[l][i]=0;
            for(int j=l-1;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    dp[l][i]+=dp[l-1][j];
                }
            }
        }
    }
    
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+=dp[k-1][i];
    }
    
    return cnt;
}

int cnt_pallindromic_subseq_sizelessthan_k(string s,int k)
{
    int n=s.length();
    int dp[n+1][n+1][k+1];
    
    for(int j=0;j<k;j++)
    {
        for(int i=0;i<n;i++)
        {
            dp[i][i][j]=1;
        }
    }
    
    for(int l=0;l<k;l++)
    {
        for(int cl=2;cl<n;cl++)
        {
            for(int i=0;i<n-cl+1;i++)
            {
                int j=i+cl-1;
                if(s[i]==s[j] && cl==2)
                {
                    dp[i][j][l]=2;
                }
                else if(s[i]==s[j])
                {
                    dp[i][j][l]=dp[i][j-1][l]+2;
                }
                else
                {
                    dp[i][j][l]=max(dp[i+1][j][l],dp[i][j-1][l]);
                }
            }
        }
    }
    
    return dp[0][n-1][k-1];
}

bool subset_sum_problem(int arr[],int n,int sum)
{
    bool dp[n+1][sum+1];
    
    dp[0][0]=true;
    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=false;
    }
    
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=true;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<arr[j-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else if(j>=arr[j-1])
            {
               dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];   
            }
        }
    }
    
    return dp[n][sum];
}

//they say we use this for continous
int subset_sum_problem(int A[],int n, int k) {
   
    map<int,int> m;
    int currsum = 0,
    maxlen = 0;
    
    for(int i = 0;i < n;i++)
    {
        currsum += A[i];
        if(currsum == k)
            maxlen = Math.max(maxlen, i+1);
        
        if(map.containsKey(currsum-k))
            maxlen = Math.max(maxlen, i - map.get(currsum-k));
    }
    return maxlen;
}

bool subset_sum_problem_max_sizealso(int arr[],int n,int sum)
{
    bool dp[n+1][sum+1];
    int count[n+1][sum+1];
    
    dp[0][0]=true;
    count[0][0]=0;
    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=false;
        count[0][i]=-1;
    }
    
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=true;
        count[0][i]=0;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<arr[j-1])
            {
                dp[i][j]=dp[i-1][j];
                count[i][j] = count[i-1][j];  
            }
            else if(j>=arr[j-1])
            {
               dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];   
            }
            
            if(dp[i][j])
            {
                count[i][j]=max(count[i-1][j],count[i-1][j-arr[i - 1]] + 1);
            }
        }
    }
    
    return count[n][sum];
}

int longest_divisible_pair_subset(int arr[],int n)
{
    int dp[n+1];

    dp[0]=1;    
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            int maxi=max(arr[i],arr[j]);
            int mini=min(arr[i],arr[j]);
            if(maxi!=0 && mini!=0 && maxi%mini==0 && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    
    return *max_element(dp,dp+n);
}
int main()
{
    // int n=10;
    // cout << counting_derangements(n);
    
    // int n=7;
    // int k=2;
    // binomialcoff_2indexed(n,k);
    // cout <<  recontres_partial_derangements(n,k);
    
    // string s1 = "daBcd"; 
    // string s2 = "ABC"; 
    // cout << transform_s1_to_s2(s1,s2);
    
    // cout << cnt_monotonic_digits(10);
    
    // string s="GEEKS FOR GEEKS";
    // cout << longest_pallindromic_subseq(s);
    
    // string s="GEEKS FOR GEEKS";
    // cout << longest_pallindromic_subseq_lessapce(s);
    
    // int mat[MAX][MAX] = { { 5, 6, 1, 7 }, 
    //                         { -2, 10, 8, -1 }, 
    //                         { 3, -7, -9, 11 }, 
    //                         { 12, -4, 2, 6 } }; 
    // int n = 4;
    // int m = 4;
    // cout << max_sum_top_to_bottom(mat,n,m);
    
    // int arr2[] = {4, 1, 1, -1, -3,  
    //              -5, 6, 2, -6, -2};  
    // int k2 = 3; 
    // int n2 = sizeof(arr2)/sizeof(arr2[0]); 
    // max_sum_subarray_k_nonoverlapp(arr2,n2,k2); 
  
    // cout << cnt_ways_to_sum_n(67);
    
    // int n=167;
    // int m=26;
    // cout << cnt_ways_to_sum_n_elemgr_eq_m(n,m);
    
    // cout << entringer_no(4,3);
    
    // int arr[]={12, 8, 11, 13, 10, 15, 14, 16, 20};
    // int n = sizeof(arr)/sizeof(arr[0]); 
    // int  k = 4;
    // cout << increasing_subseq_sizek(arr,n,k);
    
    // string s = "aabab";
    // int k = 2;
    // cout << cnt_pallindromic_subseq_sizelessthan_k(s,k);
    
    // int set[] = { 2, 3, 5, 10 };  
    // int sum = 20;  
    // int n = 4;  
    // cout<< subset_sum_problem_max_sizealso(set, n, sum);  
    
    int a[] = { 1, 3, 6, 13, 17, 18 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << longest_divisible_pair_subset(a, n) ;
}

