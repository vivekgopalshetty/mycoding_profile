//https://www.geeksforgeeks.org/medium/dynamic-programming/8/
//dynamic-programming

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999

int subsequence_atleastk_dist(int arr[],int n,int k)
{
    int dp[n+1];
    
    dp[0]=arr[0];
    for(int i=1;i<=k;i++)
    {
        dp[i]=max(arr[i],arr[i-1]);
    }
    
    for(int i=k+1;i<n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-k-1]+arr[i]);
    }
    
    return dp[n-1];
}

map<int,int> next_greater_elem(int arr[],int n)
{
    stack<int> s;
    map<int,int> v;
    s.push(arr[0]);
    int i=0;
    for(i=1;i<n;i++)
    {
        if(s.empty())
        {
            s.push(arr[i]);
            continue;
        }
        
        while(s.empty()==false && s.top()<arr[i])
        {
            cout << s.top() << "-->" << arr[i] << endl;
            v[s.top()]=i;
            s.pop();
        }
        
        s.push(arr[i]);
    }
    
    while(s.empty()==false)
    {
        cout << s.top() << "-->" << -1 << endl;
        v[s.top()]=-1;
        s.pop();
    }
    
    return v;
}

void number_of_nges(int arr[],int n)
{
    map<int,int> v;
    v=next_greater_elem(arr,n);
    
    int dp[n+1];
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        if(v[arr[i]]==-1)
        {
            dp[i]=0;
        }
        else
        {
            dp[i]=dp[v[arr[i]]]+1;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << "::" << dp[i] << endl;
    }
}

int length_longest_balanced_seq(string st)
{
    stack<char> s;
    int cnt=0;
    for(int i=0;i<st.length();i++)
    {
        if(s.empty())
        {
            s.push(st[i]);
        }
        else
        {
            if(st[i]==')' && s.top()=='(')
            {
                s.pop();
                cnt=cnt+2;
            }
            else
            {
                s.push(st[i]);
            }
        }
    }
    return cnt;
}

int cnt_str_with_adjacent_chars_diff1(int n)
{
    int dp[n+1][27];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=25;i++)
    {
        dp[1][i]=1;
    }
    
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=25;j++)
        {
            if(j==0)
            {
                dp[i][j]=dp[i-1][j+1];
            }
            else
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];  
            }
        }
    }
    
    long int sum = 0; 
    for (int i = 0; i <= 25; i++) 
        sum = (sum + dp[n][i]); 
    return sum; 
}

int longest_common_subsequence(string s1,string s2)
{
    int n=s1.length();
    int m=s2.length();
    int dp[n+1][m+1];
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
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    
    int i=n;
    int j=m;
    string res="";
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            res+=s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    
    reverse(res.begin(),res.end());
    cout << res <<" ";
    return dp[n][m];
}

int longest_repeated_sequence(string s)
{
    int n=s.length();
    int m=s.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s[i-1]==s[j-1] && i!=j)
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    
    int i=n;
    int j=m;
    string res="";
    while(i>0 && j>0)
    {
        if(dp[i][j] == dp[i-1][j-1] + 1)
        {
            res+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    
    reverse(res.begin(),res.end());
    cout << res <<" ";
    return dp[n][m];
}

int dp_prod[MAX][MAX][MAX];
int lcs_with_atmost_kchanges(int arr1[],int arr2[],int n,int m,int k)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    
    if(dp_prod[n][m][k]!=-1)
    {
        return dp_prod[n][m][k];
    }
    
    int c4=INT_MIN;
    if(arr1[n-1]==arr2[m-1])
    {
        c4=1+lcs_with_atmost_kchanges(arr1,arr2,n-1,m-1,k);
    }
    int c1=lcs_with_atmost_kchanges(arr1,arr2,n-1,m,k);
    int c2=INT_MIN;
    if(k>0)
    {
       c2=1+lcs_with_atmost_kchanges(arr1,arr2,n-1,m-1,k-1);   
    }
    
    int c3=lcs_with_atmost_kchanges(arr1,arr2,n,m-1,k);
    
    return dp_prod[n][m][k]=max(max(c1,c2),max(c3,c4));
}

int cnt_subseq_prod_less_thank(int arr[],int n,int k)
{
    int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=dp[i][j-1];
            if(arr[j-1]>0 && arr[j-1]<=i)
            {
                dp[i][j]+=dp[i/arr[j-1]][j-1]+1;
            }
        }
    }
    
    
   return dp[k][n];
}


int min_cell_jumps(int mat[MAX][MAX],int n,int m)
{
    int dp[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=INT_MAX;
        }
    }
    
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dp[i][j]!=INT_MAX && (j+mat[i][j])<m
                && dp[i][j]+1 < dp[i][j+mat[i][j]])
            {
                dp[i][j+mat[i][j]]=1+dp[i][j];
            }
            
            if(dp[i][j]!=INT_MAX &&  (i+mat[i][j])<n
                && dp[i][j]+1 < dp[i+mat[i][j]][j])
            {
                dp[i+mat[i][j]][j]=1+dp[i][j];
            }
        }
    }
    
    if (dp[n - 1][m - 1] != INT_MAX) 
        return dp[n - 1][m - 1]; 
  
    return -1;
    
}

int largest_rect_area_with_eq0s1s(int mat[MAX][MAX],int n,int m)
{
    int dp0s[n][m];
    int dp1s[n][m];
    
    if(mat[0][0]==0)
    {
        dp0s[0][0]=1;
        dp1s[0][0]=0;
    }
    else
    {
        dp0s[0][0]=0;
        dp1s[0][0]=1;
    }
    
    for(int i=1;i<n;i++)
    {
        if(mat[i][0]==0)
        {
            dp0s[i][0]=dp0s[i-1][0]+1;
            dp1s[i][0]=dp1s[i-1][0];
        }
        else
        {
            dp0s[i][0]=dp0s[i-1][0];
            dp1s[i][0]=dp1s[i-1][0]+1;
        }
        
    }
    
    for(int j=1;j<m;j++)
    {
         if(mat[0][j]==0)
        {
            dp0s[0][j]=dp0s[0][j-1]+1;
            dp1s[0][j]=dp1s[0][j-1];
        }
        else
        {
            dp0s[0][j]=dp0s[0][j-1];
            dp1s[0][j]=dp1s[0][j-1]+1;
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
             if(mat[i][j]==0)
            {
                dp0s[i][j]=dp0s[i][j-1]+dp0s[i-1][j]-dp0s[i-1][j-1]+1;
                dp1s[i][j]=dp1s[i][j-1]+dp1s[i-1][j]-dp1s[i-1][j-1];
            }
            else
            {
                dp1s[i][j]=dp1s[i][j-1]+dp1s[i-1][j]-dp1s[i-1][j-1]+1;
                dp0s[i][j]=dp0s[i][j-1]+dp0s[i-1][j]-dp0s[i-1][j-1];
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            continue;
        }
    }
    
    //more to code
    return 0;
}

//same as shortest supersequence
int shortest_psb_comb_2string(string s1,string s2)
{
    int n=s1.length();
    int m=s2.length();
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0)
            {
                dp[i][j]=j;
            }
            else if(j==0)
            {
                dp[i][j]=i;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else 
            {
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    int res=dp[n][m];
    
    int i=n;
    int j=m;
    
    string v="";
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            v+=s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
        {
            v+=s1[i-1];
            i--;
        }
        else
        {   v+=s2[j-1];
            j--;
        }
    }
    
    while(i>0)
    {
        v+=s1[i-1];
        i--;
    }
    
    while(j>0)
    {
        v+=s2[j-1];
        j--;
    }
    
    reverse(v.begin(),v.end());
    cout << v << endl;
    return dp[n][m];
}

int cnt_ways_to_build_house_office(int n)
{
    int dp[n+1][3];
    
    dp[0][0]=1; //HH
    dp[0][1]=1; //HO
    dp[0][2]=1; //OH
    
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
        dp[i][1]=dp[i-1][0]+dp[i-1][2];
        dp[i][2]=dp[i-1][0]+dp[i-1][1];
    }

    return dp[n][0];
}

int cnt_triplets_sum_xcube(int arr[],int n)
{
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
       m[arr[i]]=i;
    }
    
    set<set<int>> s;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int l=1;l<=24;l++)
            {
                int cube=l*l*l;
                if(m.find(cube-(arr[i]+arr[j]))!=m.end()
                 && m[cube-(arr[i]+arr[j])]!=i && m[cube-(arr[i]+arr[j])]!=j)
                {
                    s.insert({arr[i],arr[j],cube-arr[i]-arr[j]});
                    break;
                }
            }
        }
    }
    
    return s.size();
}

int max_sum_bitonic_subarray(int arr[],int n)
{
    int fis[n];
    int lis[n];
    
    fis[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            fis[i]=fis[i-1]+arr[i];
        }
        else
        {
            fis[i]=arr[i];
        }
    }
    
    lis[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1])
        {
            lis[i]=lis[i+1]+arr[i];
        }
        else
        {
            lis[i]=arr[i];
        }
    }
    
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(fis[i]+lis[i]-arr[i],maxi);
    }
    
    return maxi;
}

bool findWinner(int x, int y, int n) 
{ 
    int dp[n + 1]; 
    dp[0] = false; 
    dp[1] = true; 
  
    for (int i = 2; i <= n; i++) { 
        if (i - 1 >= 0 and !dp[i - 1]) 
            dp[i] = true; 
        else if (i - x >= 0 and !dp[i - x]) 
            dp[i] = true; 
        else if (i - y >= 0 and !dp[i - y]) 
            dp[i] = true; 
        else
            dp[i] = false; 
    } 
 
    return dp[n]; 
}

//thinking the reverse way 
//asked question max games played by a player
//we calculated to play x games how many players should play
int max_games_by_player(int N)
{
    int dp[N]; 
	dp[0] = 1;	 
	dp[1] = 2; 
	

	int i = 2; 
	do { 
		dp[i] = dp[i - 1] + dp[i - 2]; 
	} while (dp[i++] <= N); 

	return (i - 2); 
}

//(i-j)<=(arr[i]-arr[j]) 
int minRemove(int arr[], int n) 
{ 
	int LIS[n], len = 0; 
	for (int i = 0; i < n; i++) 
		LIS[i] = 1; 

	// Find LIS of array 
	for (int i = 1; i < n; i++) { 
		for (int j = 0; j < i; j++) { 
			if (arr[i] > arr[j] && (i-j)<=(arr[i]-arr[j])){ 
				LIS[i] = max(LIS[i], LIS[j] + 1); 
			} 
		} 
		len = max(len, LIS[i]); 
	} 

	return n - len; 
} 

int main() {
//     int arr[] = {4, 5, 8, 7, 5, 4, 3, 4, 6, 5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int k = 2;
//     cout << subsequence_atleastk_dist(arr,n,k);

    // int arr[] = {11, 13, 21, 3}; 
    // int n = sizeof(arr) / sizeof(arr[0]);
    // next_greater_elem(arr,n);
    
    // int arr[]={3, 4, 2, 7, 5, 8, 10, 6};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // number_of_nges(arr,n);
    
    //cout << length_longest_balanced_seq("(((((()))))))))");
    
    //cout << cnt_str_with_adjacent_chars_diff1(3);
    
    // string s1="AGGTAB";
    // string s2="GXTXAYB";
    // cout << longest_common_subsequence(s1,s2);
    
    // string s1="AABEBCDD";
    // cout << longest_repeated_sequence(s1);
    
    // int arr1[] = { 1, 2, 3, 4, 5 };
    // int arr2[] = { 5, 3, 1, 4, 2 };
    // int n=sizeof(arr1)/sizeof(arr1[0]);
    // int m=sizeof(arr2)/sizeof(arr2[0]);
    // memset(dp_prod,-1,sizeof(dp_prod));
    // int k = 1;
    // cout << lcs_with_atmost_kchanges(arr1,arr2,n,m,k);
    
    // int arr[]={1,2,3,4};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int k=10;
    // cout << cnt_subseq_prod_less_thank(arr,n,k);
    
    // int mat[MAX][MAX] = { {2, 3, 2, 1, 4},
    //                 {3, 2, 5, 8, 2},
    //                 {1, 1, 2, 2, 1}};
                    
    // int n=3;
    // int m=5;
    // cout << min_cell_jumps(mat,n,m);
    
    // int mat[MAX][MAX] = { {0, 0, 1, 1},
    //                 {0, 1, 1, 0},
    //                 {1, 1, 1, 0},
    //                 {1, 0, 0, 1} };
    // int n=4;
    // int m=4;
    // cout << largest_rect_area_with_eq0s1s(mat,n,m);
    
    //same as printing supersequence of 2 strings
    // string a = "algorithm", b = "rhythm"; 
    // cout << shortest_psb_comb_2string(a, b); 
    
    // int n=5;
    // cout << cnt_ways_to_build_house_office(n);
    
    // int arr[] = { 2, 5, 1, 20, 6 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << cnt_triplets_sum_xcube(arr, n); 
    
    // int arr[] ={9, 12, 14, 8, 6, 5, 10, 20};
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << max_sum_bitonic_subarray(arr,n);
    
    cout << max_games_by_player(182);
	return 0;
	
}